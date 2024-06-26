#[allow(dead_code)]
mod r2api_ext;

use iced_x86::{
    Decoder, DecoderOptions, Formatter, GasFormatter, Instruction, InstructionInfoFactory,
    IntelFormatter, MasmFormatter, Mnemonic, OpAccess, Register,
};
use libc::malloc;
use std::ffi::{c_char, c_int, c_void, CStr};
use std::ptr::{null, null_mut};

use crate::r2api_ext::*;
use r2api::*;

macro_rules! static_cstr {
    ($str: tt) => {
        unsafe { CStr::from_bytes_with_nul_unchecked(concat!($str, "\x00").as_bytes()).as_ptr() }
    };
}

/// r2c_strdup creates a new libc malloc()ed C String from a Rust string.
unsafe fn r2c_strdup(s: &str) -> *mut c_char {
    let out_ptr = libc::malloc(s.len() + 1) as *mut c_char;
    assert!(!out_ptr.is_null(), "malloc failed");
    let out = std::slice::from_raw_parts_mut(out_ptr, s.len() + 1);
    out[..s.len()].copy_from_slice(std::mem::transmute::<&[u8], &[c_char]>(s.as_bytes()));
    out[s.len()] = 0;
    out_ptr
}

static mut REGISTER_CSTRS: Vec<Vec<u8>> = Vec::new();

unsafe extern "C" fn init(_s: *mut RArchSession) -> bool {
    REGISTER_CSTRS = vec![vec![]; 256];
    for reg in Register::values() {
        REGISTER_CSTRS[reg.number()] = format!("{:?}\x00", reg).to_lowercase().into_bytes();
    }
    true
}

unsafe extern "C" fn fini(_s: *mut RArchSession) -> bool {
    REGISTER_CSTRS.clear();
    true
}

unsafe extern "C" fn mnemonics(_s: *mut RArchSession, id: c_int, json: bool) -> *mut c_char {
    if id != -1 {
        let mnemonic = match Mnemonic::try_from(id as usize) {
            Ok(v) => format!("{:?}", v).to_lowercase(),
            Err(_) => return null_mut(),
        };
        if json {
            r2c_strdup(&format!(r#"["{}"]"#, mnemonic))
        } else {
            r2c_strdup(&mnemonic)
        }
    } else if json {
        let mnemonics = Mnemonic::values()
            .map(|m| format!("{:?}", m).to_lowercase())
            .collect::<Vec<String>>();
        let out = serde_json::to_string(&mnemonics).unwrap();
        r2c_strdup(&out)
    } else {
        let mut strlen = 0usize;
        for value in Mnemonic::values() {
            strlen += format!("{:?}\n", value).len();
        }
        let str_ptr = malloc(strlen + 1) as *mut c_char;
        let mut str_slice = std::slice::from_raw_parts_mut(str_ptr as *mut u8, strlen + 1);
        for value in Mnemonic::values() {
            let value_str = format!("{:?}\n", value).to_lowercase();
            str_slice[..value_str.len()].copy_from_slice(value_str.as_bytes());
            str_slice = &mut str_slice[value_str.len()..];
        }
        str_slice[0] = 0;
        str_ptr
    }
}

unsafe extern "C" fn decode(
    session_ptr: *mut RArchSession,
    op_ptr: *mut RAnalOp,
    mask: RArchDecodeMask,
) -> bool {
    let session = session_ptr.as_ref().unwrap();
    let config = session.config.as_ref().unwrap();
    let op = op_ptr.as_mut().unwrap();

    let data = std::slice::from_raw_parts(op.bytes, op.size as usize);

    let mut instruction = Instruction::default();
    let mut decoder = Decoder::with_ip(config.bits as u32, data, op.addr, DecoderOptions::NONE);
    if !decoder.can_decode() {
        return false;
    }
    decoder.decode_out(&mut instruction);

    op.size = instruction.len() as c_int;
    op.id = instruction.mnemonic() as c_int;

    if mask & R_ARCH_OP_MASK_DISASM != 0 {
        let mut att_fmt = GasFormatter::new();
        let mut intel_fmt = IntelFormatter::new();
        let mut masm_fmt = MasmFormatter::new();

        let formatter: &mut dyn Formatter = match config.syntax {
            R_ARCH_SYNTAX_NONE | R_ARCH_SYNTAX_INTEL => &mut intel_fmt,
            R_ARCH_SYNTAX_ATT => &mut att_fmt,
            R_ARCH_SYNTAX_MASM => &mut masm_fmt,
            _ => {
                if r_log_match(R_LOG_LEVEL_ERROR as c_int, static_cstr!("x86.iced")) {
                    r_log_message(
                        R_LOG_LEVEL_ERROR,
                        static_cstr!("x86.iced"),
                        static_cstr!("lib.rs"),
                        line!() as c_int,
                        static_cstr!("arch.x86.iced only support intel, masm, at&t syntax"),
                    );
                }
                return false;
            }
        };

        let mut output = String::new();
        formatter.format(&instruction, &mut output);
        op.mnemonic = r2c_strdup(&output);
    }

    if mask & R_ARCH_OP_MASK_OPEX != 0 {
        let op_json = serde_json::to_vec(&instruction).expect("JSON serialize failed");

        let opex_ptr: *mut RStrBuf = &mut op.opex;
        r_strbuf_init(opex_ptr);
        r_strbuf_append_n(opex_ptr, op_json.as_ptr() as *const c_char, op_json.len());
    }

    if mask & R_ARCH_OP_MASK_VAL != 0 {
        op_fillval(session, op, &instruction);
    }

    true
}

unsafe fn op_fillval(session: &RArchSession, op: &mut RAnalOp, instruction: &Instruction) {
    let config = session.config.as_ref().unwrap();
    let bits = config.bits;

    let ret = r_list_newf(Some(std::mem::transmute(r_anal_value_free as usize)));
    if ret.is_null() {
        return;
    }

    // PC register
    let val = malloc(std::mem::size_of::<RAnalValue>()) as *mut RAnalValue;
    let val = match val.as_mut() {
        Some(v) => v,
        None => {
            r_list_free(ret);
            return
        },
    };
    *val = RAnalValue {
        type_: RArchValueType_R_ANAL_VAL_REG,
        access: R_PERM_W,
        reg: if bits == 64 {
            static_cstr!("rip")
        } else {
            static_cstr!("eip")
        },
        ..RAnalValue::default()
    };
    r_list_append(ret, val as *mut RArchValue as *mut c_void);

    let mut info_factory = InstructionInfoFactory::new();
    let info = info_factory.info(instruction);

    for used_register in info.used_registers() {
        let register = &used_register.register();
        let access = &used_register.access();

        let val = malloc(std::mem::size_of::<RAnalValue>()) as *mut RAnalValue;
        let val = match val.as_mut() {
            Some(v) => v,
            None => {
                r_list_free(ret);
                return
            },
        };
        *val = RAnalValue {
            type_: RArchValueType_R_ANAL_VAL_REG,
            access: match access {
                OpAccess::Write
                | OpAccess::CondWrite
                | OpAccess::ReadWrite
                | OpAccess::ReadCondWrite => R_PERM_W,
                _ => R_PERM_R,
            },
            reg: if REGISTER_CSTRS[register.number()].is_empty() {
                null()
            } else {
                REGISTER_CSTRS[register.number()].as_ptr() as *const c_char
            },
            ..RAnalValue::default()
        };
        r_list_append(ret, val as *mut RArchValue as *mut c_void);
    }

    // TODO
    //for used_memory in info.used_memory() {
    //}

    op.access = ret;
}

#[repr(transparent)]
pub struct UnsafeSync<T>(pub T);

unsafe impl<T> Sync for UnsafeSync<T> {}

static ARCH_PLUGIN: UnsafeSync<RArchPlugin> = UnsafeSync(RArchPlugin {
    meta: RPluginMeta {
        name: static_cstr!("x86.iced") as *mut c_char,
        desc: static_cstr!("iced-x86 disassembler") as *mut c_char,
        author: static_cstr!("ripatel") as *mut c_char,
        version: null_mut(),
        license: static_cstr!("MIT") as *mut c_char,
        status: R_PLUGIN_STATUS_BROKEN,
    },
    arch: static_cstr!("x86") as *mut c_char,
    cpus: null_mut(),
    endian: R_SYS_ENDIAN_LITTLE,
    bits: 16 | 32 | 64,
    addr_bits: 0,
    init: Some(init),
    fini: Some(fini),
    info: None,
    regs: None,
    encode: None,
    decode: Some(decode),
    patch: None,
    mnemonics: Some(mnemonics),
    preludes: None,
    esilcb: None,
    // Unfortunately, we can't use ..RArchPlugin::default() here.
    // The Default trait is currently not const.
});

/// The primary entrypoint for the x86.iced plugin.
/// radare2 discovers this symbol via [`libc::dlsym`].
#[no_mangle]
pub static radare_plugin: UnsafeSync<RLibStruct> = UnsafeSync(RLibStruct {
    type_: R_LIB_TYPE_ARCH,
    data: &ARCH_PLUGIN.0 as *const RArchPlugin as *mut c_void,
    version: static_cstr!("5.9.0"),
    free: None,
    pkgname: null(),
});
