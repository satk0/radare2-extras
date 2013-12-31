// Copyright 2006-2009, BeatriX
// File coded by BeatriX
//
// This file is part of BeaEngine.
//
//    BeaEngine is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Lesser General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    BeaEngine is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Lesser General Public License for more details.
//
//    You should have received a copy of the GNU Lesser General Public License
//    along with BeaEngine.  If not, see <http://www.gnu.org/licenses/>.

// ====================================== Routines_MODRM
void __stdcall MOD_RM(ARGTYPE*);
void __stdcall Reg_Opcode(ARGTYPE*);

void __stdcall Addr_EAX(ARGTYPE*);
void __stdcall Addr_ECX(ARGTYPE*);
void __stdcall Addr_EDX(ARGTYPE*);
void __stdcall Addr_EBX(ARGTYPE*);
void __stdcall Addr_SIB(ARGTYPE*);
void __stdcall Addr_disp32(ARGTYPE*);
void __stdcall Addr_ESI(ARGTYPE*);
void __stdcall Addr_EDI(ARGTYPE*);

void __stdcall Addr_EAX_disp8(ARGTYPE*);
void __stdcall Addr_ECX_disp8(ARGTYPE*);
void __stdcall Addr_EDX_disp8(ARGTYPE*);
void __stdcall Addr_EBX_disp8(ARGTYPE*);
void __stdcall Addr_SIB_disp8(ARGTYPE*);
void __stdcall Addr_EBP_disp8(ARGTYPE*);
void __stdcall Addr_ESI_disp8(ARGTYPE*);
void __stdcall Addr_EDI_disp8(ARGTYPE*);

void __stdcall Addr_EAX_disp32(ARGTYPE*);
void __stdcall Addr_ECX_disp32(ARGTYPE*);
void __stdcall Addr_EDX_disp32(ARGTYPE*);
void __stdcall Addr_EBX_disp32(ARGTYPE*);
void __stdcall Addr_SIB_disp32(ARGTYPE*);
void __stdcall Addr_EBP_disp32(ARGTYPE*);
void __stdcall Addr_ESI_disp32(ARGTYPE*);
void __stdcall Addr_EDI_disp32(ARGTYPE*);

void __stdcall _EAX(ARGTYPE*);
void __stdcall _ECX(ARGTYPE*);
void __stdcall _EDX(ARGTYPE*);
void __stdcall _EBX(ARGTYPE*);
void __stdcall _ESP(ARGTYPE*);
void __stdcall _EBP(ARGTYPE*);
void __stdcall _ESI(ARGTYPE*);
void __stdcall _EDI(ARGTYPE*);

int __stdcall SIB_0(ARGTYPE*, int);
int __stdcall SIB_1(ARGTYPE*, int);
int __stdcall SIB_2(ARGTYPE*, int);
int __stdcall SIB_3(ARGTYPE*, int);

// ====================================== Routines_Disasm
void __stdcall EbGb(PDISASM);
void __stdcall EvGv(PDISASM);
void __stdcall EvIb(PDISASM);
void __stdcall ExGx(PDISASM);
void __stdcall EvIv(PDISASM);
void __stdcall EbIb(PDISASM);
void __stdcall Eb(PDISASM);
void __stdcall Ev(PDISASM);
void __stdcall GvEv(PDISASM);
void __stdcall GvEb(PDISASM);
void __stdcall GxEx(PDISASM);
void __stdcall GvEw(PDISASM);
void __stdcall GbEb(PDISASM);
void __stdcall ALIb(PDISASM);
void __stdcall eAX_Iv(PDISASM);
int __stdcall AnalyzeOpcode (PDISASM);
int __stdcall Security(int);
void __stdcall CalculateRelativeAddress(long long *, long);
int __stdcall CopyFormattedNumber(char*,char*, long long);
void __stdcall BuildCompleteInstruction(PDISASM);
void __stdcall BuildCompleteInstructionATSyntax(PDISASM);
void __stdcall InitVariables (PDISASM);
void __stdcall FillFlags(PDISASM, int);
void __stdcall FillSegmentsRegisters (PDISASM);
void __stdcall FixArgSizeForMemoryOperand (PDISASM);
void __stdcall FixREXPrefixes (PDISASM);

// ====================================== opcodes_prefix
void __stdcall PrefLock(PDISASM);
void __stdcall PrefREPNE(PDISASM);
void __stdcall PrefREPE(PDISASM);
void __stdcall PrefSEGCS(PDISASM);
void __stdcall PrefSEGDS(PDISASM);
void __stdcall PrefSEGES(PDISASM);
void __stdcall PrefSEGFS(PDISASM);
void __stdcall PrefSEGGS(PDISASM);
void __stdcall PrefSEGSS(PDISASM);
void __stdcall PrefOpSize(PDISASM);
void __stdcall PrefAdSize(PDISASM);
void __stdcall Esc_2byte(PDISASM);
void __stdcall Esc_tableA4(PDISASM);
void __stdcall Esc_tableA5(PDISASM);


// ====================================== opcodes_A_M
void __stdcall FailDecode(PDISASM);
void __stdcall aaa_(PDISASM);
void __stdcall aad_(PDISASM);
void __stdcall aas_(PDISASM);
void __stdcall aam_(PDISASM);
void __stdcall add_EbGb(PDISASM);
void __stdcall add_EvGv(PDISASM);
void __stdcall add_GbEb(PDISASM);
void __stdcall add_GvEv(PDISASM);
void __stdcall add_ALIb(PDISASM);
void __stdcall add_eAX_Iv(PDISASM);
void __stdcall adc_ALIb(PDISASM);
void __stdcall adc_eAX_Iv(PDISASM);
void __stdcall adc_EbGb(PDISASM);
void __stdcall adc_EvGv(PDISASM);
void __stdcall adc_GbEb(PDISASM);
void __stdcall adc_GvEv(PDISASM);
void __stdcall and_EbGb(PDISASM);
void __stdcall and_ALIb(PDISASM);
void __stdcall and_eAX_Iv(PDISASM);
void __stdcall and_EvGv(PDISASM);
void __stdcall and_GbEb(PDISASM);
void __stdcall and_GvEv(PDISASM);
void __stdcall arpl_(PDISASM);
void __stdcall bound_(PDISASM);
void __stdcall bswap_eax(PDISASM);
void __stdcall bswap_ebp(PDISASM);
void __stdcall bswap_ebx(PDISASM);
void __stdcall bswap_ecx(PDISASM);
void __stdcall bswap_edi(PDISASM);
void __stdcall bswap_edx(PDISASM);
void __stdcall bswap_esi(PDISASM);
void __stdcall bswap_esp(PDISASM);
void __stdcall bsf_GvEv(PDISASM);
void __stdcall bsr_GvEv(PDISASM);
void __stdcall btc_EvGv(PDISASM);
void __stdcall btr_EvGv(PDISASM);
void __stdcall bt_EvGv(PDISASM);
void __stdcall bts_EvGv(PDISASM);
void __stdcall callf_(PDISASM);
void __stdcall call_(PDISASM);
void __stdcall cdq_(PDISASM);
void __stdcall clts_(PDISASM);
void __stdcall cmc_(PDISASM);
void __stdcall cmovo_(PDISASM);
void __stdcall cmovno_(PDISASM);
void __stdcall cmovb_(PDISASM);
void __stdcall cmovnb_(PDISASM);
void __stdcall cmove_(PDISASM);
void __stdcall cmovne_(PDISASM);
void __stdcall cmovbe_(PDISASM);
void __stdcall cmovnbe_(PDISASM);
void __stdcall cmovs_(PDISASM);
void __stdcall cmovns_(PDISASM);
void __stdcall cmovp_(PDISASM);
void __stdcall cmovnp_(PDISASM);
void __stdcall cmovl_(PDISASM);
void __stdcall cmovnl_(PDISASM);
void __stdcall cmovle_(PDISASM);
void __stdcall cmovnle_(PDISASM);
void __stdcall cmpx_EbGb(PDISASM);
void __stdcall cmpx_EvGv(PDISASM);
void __stdcall cmp_EbGb(PDISASM);
void __stdcall cmp_EvGv(PDISASM);
void __stdcall cmp_GbEb(PDISASM);
void __stdcall cmp_GvEv(PDISASM);
void __stdcall cmp_ALIb(PDISASM);
void __stdcall cmp_eAX_Iv(PDISASM);
void __stdcall cmpsb_(PDISASM);
void __stdcall cmps_(PDISASM);
void __stdcall cwde_(PDISASM);
void __stdcall clc_(PDISASM);
void __stdcall cld_(PDISASM);
void __stdcall cli_(PDISASM);
void __stdcall cpuid_(PDISASM);
void __stdcall daa_(PDISASM);
void __stdcall das_(PDISASM);
void __stdcall dec_eax(PDISASM);
void __stdcall dec_ecx(PDISASM);
void __stdcall dec_edx(PDISASM);
void __stdcall dec_ebx(PDISASM);
void __stdcall dec_esp(PDISASM);
void __stdcall dec_ebp(PDISASM);
void __stdcall dec_esi(PDISASM);
void __stdcall dec_edi(PDISASM);
void __stdcall enter_(PDISASM);
void __stdcall femms_(PDISASM);
void __stdcall hlt_(PDISASM);
void __stdcall invd_(PDISASM);
void __stdcall inc_eax(PDISASM);
void __stdcall inc_ecx(PDISASM);
void __stdcall inc_edx(PDISASM);
void __stdcall inc_ebx(PDISASM);
void __stdcall inc_esp(PDISASM);
void __stdcall inc_ebp(PDISASM);
void __stdcall inc_esi(PDISASM);
void __stdcall inc_edi(PDISASM);
void __stdcall iret_(PDISASM);
void __stdcall in_ALDX(PDISASM);
void __stdcall in_ALIb(PDISASM);
void __stdcall in_eAX_Ib(PDISASM);
void __stdcall insb_(PDISASM);
void __stdcall ins_(PDISASM);
void __stdcall into_(PDISASM);
void __stdcall in_eAX(PDISASM);
void __stdcall int_(PDISASM);
void __stdcall int1_(PDISASM);
void __stdcall int3_(PDISASM);
void __stdcall imul_GvEvIv(PDISASM);
void __stdcall imul_GvEv(PDISASM);
void __stdcall imul_GvEvIb(PDISASM);
void __stdcall jo_(PDISASM);
void __stdcall jno_(PDISASM);
void __stdcall jc_(PDISASM);
void __stdcall jnc_(PDISASM);
void __stdcall je_(PDISASM);
void __stdcall jne_(PDISASM);
void __stdcall jbe_(PDISASM);
void __stdcall jnbe_(PDISASM);
void __stdcall js_(PDISASM);
void __stdcall jns_(PDISASM);
void __stdcall jp_(PDISASM);
void __stdcall jnp_(PDISASM);
void __stdcall jl_(PDISASM);
void __stdcall jnl_(PDISASM);
void __stdcall jle_(PDISASM);
void __stdcall jnle_(PDISASM);
void __stdcall jo_near(PDISASM);
void __stdcall jno_near(PDISASM);
void __stdcall jc_near(PDISASM);
void __stdcall jnc_near(PDISASM);
void __stdcall je_near(PDISASM);
void __stdcall jne_near(PDISASM);
void __stdcall jbe_near(PDISASM);
void __stdcall ja_near(PDISASM);
void __stdcall js_near(PDISASM);
void __stdcall jns_near(PDISASM);
void __stdcall jp_near(PDISASM);
void __stdcall jnp_near(PDISASM);
void __stdcall jl_near(PDISASM);
void __stdcall jnl_near(PDISASM);
void __stdcall jle_near(PDISASM);
void __stdcall jnle_near(PDISASM);
void __stdcall jecxz_(PDISASM);
void __stdcall jmp_near(PDISASM);
void __stdcall jmp_far(PDISASM);
void __stdcall jmp_short(PDISASM);
void __stdcall lahf_(PDISASM);
void __stdcall lar_GvEw(PDISASM);
void __stdcall lds_GvM(PDISASM);
void __stdcall leave_(PDISASM);
void __stdcall lea_GvM(PDISASM);
void __stdcall les_GvM(PDISASM);
void __stdcall lodsb_(PDISASM);
void __stdcall lodsw_(PDISASM);
void __stdcall loop_(PDISASM);
void __stdcall loope_(PDISASM);
void __stdcall loopne_(PDISASM);
void __stdcall lsl_GvEw(PDISASM);
void __stdcall lss_Mp(PDISASM);
void __stdcall lfs_Mp(PDISASM);
void __stdcall lgs_Mp(PDISASM);
void __stdcall mov_RdCd(PDISASM);
void __stdcall mov_RdDd(PDISASM);
void __stdcall mov_CdRd(PDISASM);
void __stdcall mov_DdRd(PDISASM);
void __stdcall mov_EbGb(PDISASM);
void __stdcall mov_EvGv(PDISASM);
void __stdcall mov_GbEb(PDISASM);
void __stdcall mov_GvEv(PDISASM);
void __stdcall mov_ALOb(PDISASM);
void __stdcall mov_eAXOv(PDISASM);
void __stdcall mov_ObAL(PDISASM);
void __stdcall mov_OveAX(PDISASM);
void __stdcall mov_ALIb(PDISASM);
void __stdcall mov_CLIb(PDISASM);
void __stdcall mov_DLIb(PDISASM);
void __stdcall mov_BLIb(PDISASM);
void __stdcall mov_AHIb(PDISASM);
void __stdcall mov_CHIb(PDISASM);
void __stdcall mov_DHIb(PDISASM);
void __stdcall mov_BHIb(PDISASM);
void __stdcall movs_(PDISASM);
void __stdcall movsw_(PDISASM);
void __stdcall movzx_GvEb(PDISASM);
void __stdcall movsx_GvEb(PDISASM);
void __stdcall movzx_GvEw(PDISASM);
void __stdcall movsx_GvEw(PDISASM);
void __stdcall mov_EAX(PDISASM);
void __stdcall mov_ECX(PDISASM);
void __stdcall mov_EDX(PDISASM);
void __stdcall mov_EBX(PDISASM);
void __stdcall mov_ESP(PDISASM);
void __stdcall mov_EBP(PDISASM);
void __stdcall mov_ESI(PDISASM);
void __stdcall mov_EDI(PDISASM);
void __stdcall mov_EbIb(PDISASM);
void __stdcall mov_EvIv(PDISASM);
void __stdcall mov_EwSreg(PDISASM);
void __stdcall mov_SregEw(PDISASM);

// ====================================== opcodes_N_Z
void __stdcall nop_(PDISASM);
void __stdcall nop_Ev(PDISASM);
void __stdcall hint_nop(PDISASM);
void __stdcall or_EbGb(PDISASM);
void __stdcall or_EvGv(PDISASM);
void __stdcall or_GbEb(PDISASM);
void __stdcall or_GvEv(PDISASM);
void __stdcall or_ALIb(PDISASM);
void __stdcall or_eAX_Iv(PDISASM);
void __stdcall outsb_(PDISASM);
void __stdcall outsw_(PDISASM);
void __stdcall out_IbAL(PDISASM);
void __stdcall out_Ib_eAX(PDISASM);
void __stdcall out_DXAL(PDISASM);
void __stdcall out_DXeAX(PDISASM);
void __stdcall pop_Ev(PDISASM);
void __stdcall pop_eax(PDISASM);
void __stdcall pop_ecx(PDISASM);
void __stdcall pop_edx(PDISASM);
void __stdcall pop_ebx(PDISASM);
void __stdcall pop_esp(PDISASM);
void __stdcall pop_ebp(PDISASM);
void __stdcall pop_esi(PDISASM);
void __stdcall pop_edi(PDISASM);
void __stdcall pop_ds(PDISASM);
void __stdcall pop_es(PDISASM);
void __stdcall pop_fs(PDISASM);
void __stdcall pop_gs(PDISASM);
void __stdcall pop_ss(PDISASM);
void __stdcall popfd_(PDISASM);
void __stdcall popad_(PDISASM);
void __stdcall push_eax(PDISASM);
void __stdcall push_ecx(PDISASM);
void __stdcall push_edx(PDISASM);
void __stdcall push_ebx(PDISASM);
void __stdcall push_esp(PDISASM);
void __stdcall push_ebp(PDISASM);
void __stdcall push_esi(PDISASM);
void __stdcall push_edi(PDISASM);
void __stdcall push_cs(PDISASM);
void __stdcall push_ds(PDISASM);
void __stdcall push_es(PDISASM);
void __stdcall push_fs(PDISASM);
void __stdcall push_gs(PDISASM);
void __stdcall push_ss(PDISASM);
void __stdcall pushfd_(PDISASM);
void __stdcall pushad_(PDISASM);
void __stdcall push_Iv(PDISASM);
void __stdcall push_Ib(PDISASM);
void __stdcall pushfd_(PDISASM);
void __stdcall pushad_(PDISASM);
void __stdcall retn_(PDISASM);
void __stdcall ret_(PDISASM);
void __stdcall retf_(PDISASM);
void __stdcall retf_Iw(PDISASM);
void __stdcall rdtsc_(PDISASM);
void __stdcall rdmsr_(PDISASM);
void __stdcall rdpmc_(PDISASM);
void __stdcall rsm_(PDISASM);
void __stdcall sysenter_(PDISASM);
void __stdcall sysexit_(PDISASM);
void __stdcall sahf_(PDISASM);
void __stdcall salc_(PDISASM);
void __stdcall scasb_(PDISASM);
void __stdcall scas_(PDISASM);
void __stdcall stc_(PDISASM);
void __stdcall sti_(PDISASM);
void __stdcall stos_(PDISASM);
void __stdcall stosw_(PDISASM);
void __stdcall syscall_(PDISASM);
void __stdcall sysret_(PDISASM);
void __stdcall sbb_EbGb(PDISASM);
void __stdcall sbb_EvGv(PDISASM);
void __stdcall sbb_GbEb(PDISASM);
void __stdcall sbb_GvEv(PDISASM);
void __stdcall sbb_ALIb(PDISASM);
void __stdcall sbb_eAX_Iv(PDISASM);
void __stdcall seto_(PDISASM);
void __stdcall setno_(PDISASM);
void __stdcall setb_(PDISASM);
void __stdcall setnb_(PDISASM);
void __stdcall sete_(PDISASM);
void __stdcall setne_(PDISASM);
void __stdcall setbe_(PDISASM);
void __stdcall setnbe_(PDISASM);
void __stdcall sets_(PDISASM);
void __stdcall setns_(PDISASM);
void __stdcall setp_(PDISASM);
void __stdcall setnp_(PDISASM);
void __stdcall setnge_(PDISASM);
void __stdcall setge_(PDISASM);
void __stdcall setle_(PDISASM);
void __stdcall setnle_(PDISASM);
void __stdcall shld_EvGvIb(PDISASM);
void __stdcall shld_EvGvCL(PDISASM);
void __stdcall shrd_EvGvIb(PDISASM);
void __stdcall shrd_EvGvCL(PDISASM);
void __stdcall std_(PDISASM);
void __stdcall sub_ALIb(PDISASM);
void __stdcall sub_eAX_Iv(PDISASM);
void __stdcall sub_EbGb(PDISASM);
void __stdcall sub_EvGv(PDISASM);
void __stdcall sub_GbEb(PDISASM);
void __stdcall sub_GvEv(PDISASM);
void __stdcall test_ALIb(PDISASM);
void __stdcall test_eAX_Iv(PDISASM);
void __stdcall test_EbGb(PDISASM);
void __stdcall test_EvGv(PDISASM);
void __stdcall test_GbEb(PDISASM);
void __stdcall test_GvEv(PDISASM);
void __stdcall ud2_(PDISASM);
void __stdcall vmread_(PDISASM);
void __stdcall vmwrite_(PDISASM);
void __stdcall wbinvd_(PDISASM);
void __stdcall wait_(PDISASM);
void __stdcall wrmsr_(PDISASM);
void __stdcall xadd_EbGb(PDISASM);
void __stdcall xadd_EvGv(PDISASM);
void __stdcall xchg_EbGb(PDISASM);
void __stdcall xchg_ebp(PDISASM);
void __stdcall xchg_ebx(PDISASM);
void __stdcall xchg_ecx(PDISASM);
void __stdcall xchg_edi(PDISASM);
void __stdcall xchg_edx(PDISASM);
void __stdcall xchg_esi(PDISASM);
void __stdcall xchg_esp(PDISASM);
void __stdcall xchg_EvGv(PDISASM);
void __stdcall xlat_(PDISASM);
void __stdcall xor_ALIb(PDISASM);
void __stdcall xor_eAX_Iv(PDISASM);
void __stdcall xor_EbGb(PDISASM);
void __stdcall xor_EvGv(PDISASM);
void __stdcall xor_GbEb(PDISASM);
void __stdcall xor_GvEv(PDISASM);

// ====================================== opcodes_Grp1
void __stdcall G1_EbIb(PDISASM);
void __stdcall G1_EbIb2(PDISASM);
void __stdcall G1_EvIv(PDISASM);
void __stdcall G1_EvIb(PDISASM);

// ====================================== opcodes_Grp2
void __stdcall G2_EbIb(PDISASM);
void __stdcall G2_EvIb(PDISASM);
void __stdcall G2_Ev1(PDISASM);
void __stdcall G2_Eb1(PDISASM);
void __stdcall G2_EbCL(PDISASM);
void __stdcall G2_EvCL(PDISASM);

// ====================================== opcodes_Grp3
void __stdcall G3_Eb(PDISASM);
void __stdcall G3_Ev(PDISASM);

// ====================================== opcodes_Grp4
void __stdcall G4_Eb(PDISASM);

// ====================================== opcodes_Grp5
void __stdcall G5_Ev(PDISASM);

// ====================================== opcodes_Grp6
void __stdcall G6_(PDISASM);

// ====================================== opcodes_Grp7
void __stdcall G7_(PDISASM);

// ====================================== opcodes_Grp8
void __stdcall G8_EvIb(PDISASM);

// ====================================== opcodes_Grp9
void __stdcall G9_(PDISASM);

// ====================================== opcodes_Grp12
void __stdcall G12_(PDISASM);

// ====================================== opcodes_Grp13
void __stdcall G13_(PDISASM);

// ====================================== opcodes_Grp14
void __stdcall G14_(PDISASM);

// ====================================== opcodes_Grp15
void __stdcall G15_(PDISASM);

// ====================================== opcodes_Grp16
void __stdcall G16_(PDISASM);

// ====================================== opcodes_FPU
void __stdcall D8_(PDISASM);
void __stdcall D9_(PDISASM);
void __stdcall DA_(PDISASM);
void __stdcall DB_(PDISASM);
void __stdcall DC_(PDISASM);
void __stdcall DD_(PDISASM);
void __stdcall DE_(PDISASM);
void __stdcall DF_(PDISASM);

// ====================================== opcodes_MMX
void __stdcall emms_(PDISASM);
void __stdcall movd_EP(PDISASM);
void __stdcall movd_PE(PDISASM);
void __stdcall movq_PQ(PDISASM);
void __stdcall movq_QP(PDISASM);
void __stdcall movq_WV(PDISASM);
void __stdcall pabsb_(PDISASM);
void __stdcall pabsd_(PDISASM);
void __stdcall pabsw_(PDISASM);
void __stdcall packssdw_(PDISASM);
void __stdcall packsswb_(PDISASM);
void __stdcall packuswb_(PDISASM);
void __stdcall paddb_(PDISASM);
void __stdcall paddd_(PDISASM);
void __stdcall paddsb_(PDISASM);
void __stdcall paddsw_(PDISASM);
void __stdcall paddusb_(PDISASM);
void __stdcall paddusw_(PDISASM);
void __stdcall paddw_(PDISASM);
void __stdcall pandn_(PDISASM);
void __stdcall pand_(PDISASM);
void __stdcall pcmpeqb_(PDISASM);
void __stdcall pcmpeqd_(PDISASM);
void __stdcall pcmpeqw_(PDISASM);
void __stdcall pcmpgtb_(PDISASM);
void __stdcall pcmpgtd_(PDISASM);
void __stdcall pcmpgtw_(PDISASM);
void __stdcall pmulhw_(PDISASM);
void __stdcall pmullw_(PDISASM);
void __stdcall pmaddwd_(PDISASM);
void __stdcall por_(PDISASM);
void __stdcall pslld_(PDISASM);
void __stdcall psllq_(PDISASM);
void __stdcall psllw_(PDISASM);
void __stdcall psrld_(PDISASM);
void __stdcall psrlq_(PDISASM);
void __stdcall psrlw_(PDISASM);
void __stdcall psrad_(PDISASM);
void __stdcall psraw_(PDISASM);
void __stdcall psubb_(PDISASM);
void __stdcall psubd_(PDISASM);
void __stdcall psubsb_(PDISASM);
void __stdcall psubsw_(PDISASM);
void __stdcall psubusb_(PDISASM);
void __stdcall psubusw_(PDISASM);
void __stdcall psubw_(PDISASM);
void __stdcall punpckhbw_(PDISASM);
void __stdcall punpckhdq_(PDISASM);
void __stdcall punpckhwd_(PDISASM);
void __stdcall punpcklbw_(PDISASM);
void __stdcall punpckldq_(PDISASM);
void __stdcall punpcklwd_(PDISASM);
void __stdcall pxor_(PDISASM);

// ====================================== opcodes_SSE
void __stdcall addps_VW(PDISASM);
void __stdcall addsubpd_(PDISASM);
void __stdcall andnps_VW(PDISASM);
void __stdcall andps_VW(PDISASM);
void __stdcall blendpd_(PDISASM);
void __stdcall blendps_(PDISASM);
void __stdcall blendvpd_(PDISASM);
void __stdcall blendvps_(PDISASM);
void __stdcall cmpps_VW(PDISASM);
void __stdcall crc32_GvEb(PDISASM);
void __stdcall crc32_GvEv(PDISASM);
void __stdcall comiss_VW(PDISASM);
void __stdcall cvtdq2ps_(PDISASM);
void __stdcall cvtpd2dq_(PDISASM);
void __stdcall cvtpi2ps_(PDISASM);
void __stdcall cvtps2pd_(PDISASM);
void __stdcall cvtps2pi_(PDISASM);
void __stdcall cvttps2pi_(PDISASM);
void __stdcall dppd_(PDISASM);
void __stdcall dpps_(PDISASM);
void __stdcall divps_VW(PDISASM);
void __stdcall extractps_(PDISASM);
void __stdcall haddpd_VW(PDISASM);
void __stdcall hsubpd_VW(PDISASM);
void __stdcall insertps_(PDISASM);
void __stdcall lddqu_(PDISASM);
void __stdcall maskmovq_(PDISASM);
void __stdcall maxps_VW(PDISASM);
void __stdcall minps_VW(PDISASM);
void __stdcall movaps_VW(PDISASM);
void __stdcall movaps_WV(PDISASM);
void __stdcall movhps_MV(PDISASM);
void __stdcall movhps_VM(PDISASM);
void __stdcall movlps_MV(PDISASM);
void __stdcall movlps_VM(PDISASM);
void __stdcall movmskps_(PDISASM);
void __stdcall movntdqa_(PDISASM);
void __stdcall movnti_(PDISASM);
void __stdcall movntps_(PDISASM);
void __stdcall movntq_(PDISASM);
void __stdcall movups_VW(PDISASM);
void __stdcall movups_WV(PDISASM);
void __stdcall mpsadbw_(PDISASM);
void __stdcall mulps_VW(PDISASM);
void __stdcall orps_VW(PDISASM);
void __stdcall packusdw_(PDISASM);
void __stdcall paddq_(PDISASM);
void __stdcall pavgb_(PDISASM);
void __stdcall pavgw_(PDISASM);
void __stdcall palignr_(PDISASM);
void __stdcall pblendvb_(PDISASM);
void __stdcall pblendw_(PDISASM);
void __stdcall pcmpeqq_(PDISASM);
void __stdcall pcmpestri_(PDISASM);
void __stdcall pcmpestrm_(PDISASM);
void __stdcall pcmpgtq_(PDISASM);
void __stdcall pcmpistri_(PDISASM);
void __stdcall pcmpistrm_(PDISASM);
void __stdcall pextrb_(PDISASM);
void __stdcall pextrd_(PDISASM);
void __stdcall pextrw2_(PDISASM);
void __stdcall pextrw_(PDISASM);
void __stdcall phaddd_(PDISASM);
void __stdcall phaddsw_(PDISASM);
void __stdcall phaddw_(PDISASM);
void __stdcall phminposuw_(PDISASM);
void __stdcall phsubd_(PDISASM);
void __stdcall phsubsw_(PDISASM);
void __stdcall phsubw_(PDISASM);
void __stdcall pinsrb_(PDISASM);
void __stdcall pinsrd_(PDISASM);
void __stdcall pinsrw_(PDISASM);
void __stdcall pmaxsb_(PDISASM);
void __stdcall pmaxsd_(PDISASM);
void __stdcall pmaxsw_(PDISASM);
void __stdcall pmaxub_(PDISASM);
void __stdcall pmaxud_(PDISASM);
void __stdcall pmaxuw_(PDISASM);
void __stdcall pminsb_(PDISASM);
void __stdcall pminsd_(PDISASM);
void __stdcall pminsw_(PDISASM);
void __stdcall pminub_(PDISASM);
void __stdcall pminud_(PDISASM);
void __stdcall pminuw_(PDISASM);
void __stdcall pmaddubsw_(PDISASM);
void __stdcall pmovmskb_(PDISASM);
void __stdcall pmovsxbd_(PDISASM);
void __stdcall pmovsxbq_(PDISASM);
void __stdcall pmovsxbw_(PDISASM);
void __stdcall pmovsxdq_(PDISASM);
void __stdcall pmovsxwd_(PDISASM);
void __stdcall pmovsxwq_(PDISASM);
void __stdcall pmovzxbd_(PDISASM);
void __stdcall pmovzxbq_(PDISASM);
void __stdcall pmovzxbw_(PDISASM);
void __stdcall pmovzxdq_(PDISASM);
void __stdcall pmovzxwd_(PDISASM);
void __stdcall pmovzxwq_(PDISASM);
void __stdcall pmuldq_(PDISASM);
void __stdcall pmulhrsw_(PDISASM);
void __stdcall pmulhuw_(PDISASM);
void __stdcall pmulhw_(PDISASM);
void __stdcall pmulld_(PDISASM);
void __stdcall pmullw_(PDISASM);
void __stdcall pmuludq_(PDISASM);
void __stdcall popcnt_(PDISASM);
void __stdcall psadbw_(PDISASM);
void __stdcall pshufb_(PDISASM);
void __stdcall pshufw_(PDISASM);
void __stdcall psignb_(PDISASM);
void __stdcall psignd_(PDISASM);
void __stdcall psignw_(PDISASM);
void __stdcall psubq_(PDISASM);
void __stdcall ptest_(PDISASM);
void __stdcall punpcklqdq_(PDISASM);
void __stdcall punpckhqdq_(PDISASM);
void __stdcall rcpps_(PDISASM);
void __stdcall roundpd_(PDISASM);
void __stdcall roundps_(PDISASM);
void __stdcall roundsd_(PDISASM);
void __stdcall roundss_(PDISASM);
void __stdcall rsqrtps_(PDISASM);
void __stdcall shufps_(PDISASM);
void __stdcall sqrtps_VW(PDISASM);
void __stdcall subps_VW(PDISASM);
void __stdcall ucomiss_VW(PDISASM);
void __stdcall unpckhps_(PDISASM);
void __stdcall unpcklps_(PDISASM);
void __stdcall xorps_VW(PDISASM);
