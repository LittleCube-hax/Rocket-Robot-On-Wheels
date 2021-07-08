#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <mem.h>

struct unkfunc_800922C4 {
    u32 *unk0;
    Gfx *unk4;
    Gfx *unk8;
};

extern struct {
    u32 unk0;
    Gfx *unk4;
    Gfx *unk8;
} D_800AAF80;

extern struct MaterialGfx *D_800AF4F8;

void func_80092050(void) {
    struct MaterialGfx *material;

    material = D_800AF4F8;
    while (material != 0) {
        func_80092094(material);
        material = *material->unkC;
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_405", func_80092094);


// wip
// Gfx *func_800922C4(struct MaterialGfx *arg0, u32 arg1)
// {
//     Gfx var[0x80];
//     struct unkfunc_800922C4 var3;

//     var3.unk0 = sizeof(var);
//     var3.unk4 = var3.unk8 = var;

//     func_800926B8(&var3, arg0);
//     arg0->gfxCount = ((u32)var3.unk8 - (u32)var3.unk4) / sizeof(Gfx);

//     if (arg0 ||
//      0x80000000 != arg0->materialData & 0xF0000000) ||
//      arg0->materialData->unk16 ||
//      arg0->materialData->unk18 ||
//      arg0->materialData->unk1C) {
//         u8 *mem = main_alloc_bzero(0x1C);
//         arg0->unkC = mem;
//         D_800AAF80.unk4 += arg0->gfxCount;
//         arg0->unk8 = D_800AAF80.unk4 - arg0->gfxCount + 0x200000;


//         {
//             void *val2 = D_800AF4F8;
//             D_800AF4F8 = arg0;
//             arg0->unkC->unk0 = val2;
//         }
//         arg0->unk4 = arg1 == 0;

//         // arg0->unkC->unk0 = D_800AF4F8;
//         // D_800AF4F8 = arg0->unk0;

//     } else {
//         arg0->unk8 = main_alloc_copy(arg0->unk4 * sizeof(Gfx), val);
//     }
//     return arg0->unk8;
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_405", func_800922C4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_405", func_800923E8);

// wip long function
// creates a displaylist from a material (textured or solid)
// void func_800926B8(s32 arg0, struct MaterialGfx *arg1, s32 *arg2)
// {
//     gDPPipeSync(arg1->gfx++);
//     if ((*arg2 & 0xF0000000) == 0)
//     {
//         gDPSetCombineMode(arg1->gfx++, G_CC_SHADE, G_CC_SHADE);
//         gDPSetCombineLERP(arg1->gfx++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, COMBINED, COMBINED, 0, PRIMITIVE, 0);
//         gSPSetGeometryMode(arg1->gfx++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
//         gSPTexture(arg1->gfx++, 0x0000, 0x0000, 0, G_TX_RENDERTILE, G_OFF);
//     }
//     else
//     {

//     }
//     gSPEndDisplayList(arg1->gfx++);
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_405", func_800926B8);

extern struct MaterialGfx *materialTable;

// wip
// struct unkfunc_80093DDC *func_80093DDC(struct unkfunc_80093DDC *arg0, s32 arg1) {
//     struct unkfunc_80093DDC sp10;
//     struct unkfunc_80093DDC sp18;
//     struct unkfunc_80093DDC sp20;
//     struct unkfunc_80093DDC sp28;
//     struct unkfunc_80093DDC *temp_v1_2;
//     s32 temp_v1;
//     struct MaterialGfx *temp_a0;
//     s8 phi_v1;
//     struct TexturedMaterial *materialData;

//     temp_a0 = &materialTable[arg1];
//     materialData = temp_a0->materialData;
//     temp_v1 = ((u32)materialData) & 0xF0000000;
//     if (temp_v1 == 0) {
//         temp_v1_2 = &sp20;
//         sp20.unk0_0 = 2;
//         sp20.unk0_4 = 1;
//         // sp20 = (((sp20 & 0xF0FFFFFF) | 0x2000000) & 0xFFFFFFF) | 0x10000000;
//         temp_v1_2->unk1 = 1;
//         temp_v1_2->unk2 = 1;
//         sp28 = sp20;
//         if (sp28.unk2 == 5) {
//             phi_v1 = 7;
//         } else if (sp28.unk2 == 3) {
//             phi_v1 = 5;
//         } else if (sp28.unk2 == 4) {
//             phi_v1 = 6;
//         } else if (sp28.unk0_4 == 2) {
//             phi_v1 = 4;
//         } else if (sp28.unk2 == 1) {
//             phi_v1 = 3;
//         } else if (sp28.unk1 == 2) {
//             phi_v1 = 2;
//         } else {
//             phi_v1 = sp28.unk1 == 1;
//         }
//         sp20.unk3 = phi_v1;
//         sp18 = sp20;
//         sp10 = sp20;
//         *arg0 = sp10;
//     } else {
//         if (temp_v1 != 0x80000000) {
//             materialData = load_textured_material(materialData);
//         }
//         sp10 = materialData->header.unk4;
//         *arg0 = sp10;
//     }
//     return arg0;
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_405", func_80093DDC);

void texture_handler_copy(u32 assetAddress, UNUSED struct TextureCompressionHeader *header, struct Texture *asset)
{
    dma_read(assetAddress, asset->imageData, asset->header.imageBytes);
}
