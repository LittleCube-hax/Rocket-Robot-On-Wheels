#include <include_asm.h>
#include <ultra64.h>

extern f32 D_8001B3D8;

void func_80045B60(f32 *arg0, s32 arg1, u8 *dataPtr)
{
    arg0[0x8F] = D_8001B3D8;
    func_800875E8(arg0, arg1, dataPtr);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_141", func_80045B88);
