/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#ifndef __WM_DATA_H__
#define __WM_DATA_H__

#include "psx.h"

#define inline_abs(a) ((a)>0?(a):-(a))
#define BIT_ISSET_2(mask,bit) (((mask)>>((bit)&0x1f))&1)

struct t_wm_file_04 {
	unsigned short f_00;
	unsigned short f_02;
};

struct t_wm_local_0c_xxx {
	short f_00;
	short f_02;
	short f_04;
	short f_06;
	unsigned char f_08;
	char __09[3];
};

struct t_wm_local_20_xxx_ENCDATA {
	unsigned short encrate;
	unsigned short std0;
	unsigned short std1;
	unsigned short std2;
	unsigned short std3;
	unsigned short std4;
	unsigned short std5;
	unsigned short sp0;
	unsigned short sp1;
	unsigned short sp2;
	unsigned short sp3;
	unsigned short alt0;
	unsigned short alt1;
	unsigned short alt2;
	unsigned short alt3;
	char __1e[2];
};

struct t_wm_8a0 {//"enc_w.bin"
	unsigned short f_000[/*0x10*/8][2];//D_00DE6B78
	unsigned short f_020[/*0x40*/0x20][2];//D_00DE6B98
	struct t_wm_local_20_xxx_ENCDATA f_0a0[/*0x40*/0x10][4];//D_00DE6C18
};

//aka struct t_wm_local_dunno__
struct t_wm_b8 {
	char __00[1];//__00E2C430//__00E2C808
	char f_01;//__00E2C431//__00E2C809
	char __02[2];//__00E2C432//__00E2C80A
	unsigned char f_04;//__00E2C434//__00E2C80C
	char __05[0x20 - 0x05];//__00E2C435//__00E2C80D
	unsigned short f_20;//__00E2C450//__00E2C828
	char __22[2];//__00E2C452//__00E2C82A
	int f_24;//__00E2C454//__00E2C82C
	char __28[8];//__00E2C458//__00E2C830
	int f_30;//__00E2C460//__00E2C83800E2C83C
	int f_34;//__00E2C464//__
	float f_38;//__00E2C468//__00E2C840
	struct t_animationHeader **f_3c;//__00E2C46C//__00E2C844
	struct tSkeleton *f_40;//__00E2C470//__00E2C848
	struct t_plytopd_74 f_44;//__00E2C474//__00E2C84C
};

struct t_wm_vertexinfo {
	//-- struct POLY_G4? --
	/*00*/char __00[4];
	/*04*/unsigned char r0,g0,b0,__07; short x0,y0;
	/*0c*/unsigned char r1,g1,b1,__0f; short x1,y1;
	/*14*/unsigned char r2,g2,b2,__17; short x2,y2;
	/*1c*/unsigned char r3,g3,b3,__1f; short x3,y3;
	//-- --
	/*24*/unsigned rgba0;
	/*28*/unsigned rgba1;
	/*2c*/unsigned rgba2;
	/*30*/unsigned rgba3;
};

struct t_wm_local_08_MESHHEADER {
	struct t_wm_local_0c_TRIANGLE *f_00_triPtr;
	short f_04_numTriangles;
	short f_06_numVertices;
};

//== struct VECTOR
//struct t_wm_local_10 {
//	int f_00;
//	int f_04;
//	int f_08;
//	char __0c[4];
//};

struct t_wm_local_0c_TRIANGLE {
	unsigned char f_00_vert0idx;
	unsigned char f_01_vert1idx;
	unsigned char f_02_vert2idx;
	//
	unsigned char f_03_walkability;
	//
	unsigned char f_04_u0,f_05_v0;
	unsigned char f_06_u1,f_07_v1;
	unsigned char f_08_u2,f_09_v2;
	//
	char __0a[1];
	unsigned char f_0b;
};

//== struct t_wm_local_xxx
struct t_wm_local_18 {
	/*00*/struct t_wm_local_18 *pNext;
	/*04*/struct t_wm_local_0c_TRIANGLE *f_04;
	/*08*/struct SVECTOR *f_08;
	/*0c*/struct SVECTOR *f_0c;
	/*10*/short f_10;
	/*12*/short f_12;
	/*14*/short f_14;
	/*16*/short f_16;
};

struct t_wm_local_04_bis {
	short f_00;
	char f_02;
	char f_03;
};

struct t_wm_local_30 {
	/*00*/struct POLY_FT4 f_00;
	/*28*/struct t_dx_sfx_e0 *f_28;
	/*2c*/unsigned f_2c;
};

struct t_local_unknown_c0_WMOBJ {
	/*00*/struct t_local_unknown_c0_WMOBJ *pNext;
	/*04*/struct t_local_unknown_c0_WMOBJ *f_04;
	/*08*/struct t_local_unknown_c0_WMOBJ *f_08;
	/*0c*/struct VECTOR f_0c_POSITION;
	/*1c*/struct VECTOR f_1c;//another type?
	/*2c*/struct t_wm_local_04_bis f_2c[4];
	/*3c*/short f_3c;
	/*3e*/short f_3e;
	/*40*/short f_40;
	/*42*/short f_42;
	/*44*/short f_44;
	/*46*/short f_46;
	/*48*/short f_48;
	/*4a*/short f_4a;
	/*4c*/short f_4c;
	/*4e*/short f_4e;
	/*50*/unsigned char f_50_model;//model type?
	/*51*/unsigned char f_51;
	/*52*/unsigned char f_52;
	/*53*/unsigned char f_53;
	/*54*/unsigned char f_54;
	/*55*/unsigned char f_55;
	/*56*/unsigned char f_56;
	/*57*/unsigned char f_57;
	/*58*/unsigned char f_58;
	/*59*/unsigned char f_59;
	/*5a*/char __5a[0x5c - 0x5a];
	/*5c*/char f_5c;
	/*5d*/char f_5d;
	/*5e*//*unsigned */char f_5e;
	/*5f*/char f_5f;
	/*60*/struct t_wm_local_08_MESHHEADER f_60[6];
	/*90*/struct t_wm_local_30 f_90;
};
////////////////////////////////////////
extern int D_0096B414;//from wmfile?
extern short D_0096B418[];
extern short D_0096B448[];

extern int D_00DFC480;

extern int D_00E045EC;
extern char D_00E28C48[];//debug string
extern struct fBGRA D_00E28F40[];
extern tRGBA D_00E2B778[];
extern struct t_dx_sfx_e0 *D_00E2BBD8[/*0x200*/];
extern struct t_dx_sfx_e0 *D_00E2C3D8;
extern struct t_dx_sfx_e0 *D_00E2C3DC;
extern struct t_dx_sfx_e0 *D_00E2C3E0;
extern struct t_dx_sfx_e0 *D_00E2C3E4;
extern struct t_dx_sfx_e0 *D_00E2C3E8;
extern struct t_dx_sfx_e0 *D_00E2C3EC;
extern struct t_dx_sfx_e0 *D_00E2C3F0;
extern struct t_dx_sfx_e0 *D_00E2C3F4[3];
extern struct t_dx_sfx_e0 *D_00E2C400;
extern struct t_dx_sfx_e0 *D_00E2C404;
extern struct t_dx_sfx_e0 *D_00E2C408;
extern struct t_dx_sfx_e0 *D_00E2C40C;
extern struct t_dx_sfx_e0 *D_00E2C410;
extern struct t_dx_sfx_e0 *D_00E2C414;
extern int D_00E2C41C;
extern int D_00E2C420;
extern int D_00E2C424;
extern int D_00E2C428;
extern struct t_wm_b8 D_00E2C430[/*3*/];
extern struct t_dx_sfx_e0 *D_00E2C658[/*0x6c*/];//check
extern struct t_wm_b8 D_00E2C808[/*0xd*/];
extern struct t_wm_file_04 *D_00E2D168;//check
extern struct VECTOR D_00E2D1E0;
extern struct SVECTOR D_00E2D1F0;
extern struct SVECTOR D_00E2D1F8;
extern short D_00E2D200;
extern struct SVECTOR D_00E2D5D8;
extern unsigned char *D_00E2D5F8;
extern struct POLY_GT3 *D_00E2D5FC;//[0xd00]
extern int D_00E3564C;
extern struct t_light_5ac *D_00E360F4;//light system(2)
extern struct t_light_5ac *D_00E360F8;//light system(1)
extern int D_00E3610C;
extern struct t_wm_local_0c_TRIANGLE *D_00E36110;
extern int *D_00E36114;
extern unsigned char D_00E36118[8 + 0x1000];//"mes"
extern short D_00E37120[/*0x200*/];//"atn.tbl"
extern int D_00E37520;
extern int D_00E37524;

extern int D_00E37D28;
extern struct t_wm_local_0c_xxx D_00E37D30[];
extern struct t_wm_local_0c_TRIANGLE *D_00E38330;
extern struct t_g_drv_0c D_00E38338[];
extern unsigned D_00DE67E8;
extern unsigned D_00DE68F8;
extern void (*D_00DE68FC)(void);

extern float D_00DE6900;
extern int D_00DE69D8;
extern int D_00DE69DC;
extern int D_00DE69E0;
extern int D_00DE69E4;
extern int D_00DE6A04;

extern struct t_wm_8a0 D_00DE6B78;//"enc_w.bin"
////////////////////////////////////////
//-- C_0074BA80.cpp --
extern void C_0074C179(void);//render_0(surface)(callback)
extern void C_0074C3F0(void);//render_2(undersea)(callback)
extern void C_0074C589(void);//render_3(snowfield)(callback)
extern int C_0074C969(void);//get "isRendering"?
extern void C_0074C973(int);//set "isRendering"?
extern void C_0074C980(int);//set "allowsFrameSkip"?
//-- C_0074C9A0.cpp --
extern void C_0074C9A0(int);//<empty>:some error management?
extern int C_0074C9A5(void);
extern struct POLY_GT3 *C_0074C9AF(unsigned);
extern char *C_0074CA00(int, int);
extern void C_0074CBB5(int);//set earthquake effect
extern void *C_0074CBC2(void);
extern int C_0074CC07_updateObjMeshMaybe(struct t_wm_local_18 *, struct SVECTOR *, struct t_wm_local_08_MESHHEADER *, short *, struct t_wm_local_0c_TRIANGLE **, short *, unsigned char);
extern int C_0074D28E(void);
extern int C_0074D298(void);
extern void C_0074D2A7(int);
extern void C_0074D2B9(int);
extern void C_0074D2D7(int);
extern int C_0074D30F(void);
extern int C_0074D319(void);
extern void C_0074D323(int);
extern int C_0074D330(void);
extern void C_0074D33A(struct SVECTOR *);
extern void C_0074D3A7(void);
extern short C_0074D3C6(void);
extern void C_0074D3D1(int);
extern void C_0074D438(int, int);
extern int C_0074D4B6(void);
extern void C_0074D4C0(short);
extern int C_0074D4DC(void);
extern int C_0074D4ED(void);
extern void C_0074D4F7(int);//set "highwind" state?
extern int C_0074D504(void);//get "highwind" state?
extern void C_0074D50E(struct t_wm_b8 *, struct SVECTOR *, struct MATRIX *, int);
extern void C_0074D6BB(void);
extern void C_0074D731(int);
extern void C_0074D74C(int);
extern void C_0074D7CD(int);
extern int C_0074D8CF(void);
extern void C_0074D8EF(int);
extern unsigned char *C_0074D915(short);//get string from "mes"
extern void C_0074D955(int);
extern void C_0074DA26(int);
extern void C_0074DA33(int);
extern void C_0074DA40(int);
extern void C_0074DB2B(int);
extern void C_0074DB38(int);
extern void C_0074DB45(int);
extern int C_0074DB8C(int *, int *, int *, int);
//-- C_0074FFC0.cpp --
extern void C_00750134(struct VECTOR *, struct SVECTOR *, short *, short *);
extern void C_00750202(struct VECTOR *);
extern void C_0075027C(struct VECTOR *, int);
extern void C_0075042B(struct VECTOR *);
extern int C_0075045C(void);
extern void C_00750466(int);
extern void C_00750473(void);
extern void C_007506B6(void);
extern void C_007506C0(void);
extern void C_00750784(void);
extern void C_0075079D(short, int);
extern void C_0075334D(void);
extern int C_0075335C(void);
extern int C_00753366(short, short);
extern void C_007533AF(void);
extern void C_0075378A(int);
extern void C_007537A1(int);
extern void C_007537AE(int *);
//-- C_00753860.cpp --
extern void C_00753860(void);
extern void C_00753879(void);
extern void C_00753888(void);
extern void C_0075389C(void);
extern int C_007538B0(void);
extern void C_007538BA(void);
extern int C_007538C9(short);
extern void C_0075395E(short);
extern void C_00753A01_RNGSEED(int);//wm:randomize
extern int C_00753BE8_RAND(void);//wm:random?
extern int C_00753C23(struct VECTOR *, struct VECTOR *);
extern void C_00753D00(struct SVECTOR *, short);
extern short C_00753DA9(int, int);
extern short C_00753F2E(struct VECTOR *, struct VECTOR *);
extern void C_00753F53(void);
extern struct t_wm_vertexinfo *C_007540E5(void);
extern void C_00754100(short);
extern void C_007543D3(void);
extern void C_007547A6(short);
extern void C_00754E10(int);
extern void C_00754E1D(void);
extern void C_00754EBC(int, int);
extern void C_00754EEF(int, int);
extern void C_00754F72(int, int);
extern void C_00754FE2(int, int, int);
extern void C_00755013(int);
extern void C_0075502C(int);
extern void C_007550A7(struct VECTOR *);//sky color transition?
extern void C_00755045(int, int, int);
extern void C_00755076(int, int, int);
extern int C_0075542D(struct VECTOR *);
extern short C_0075545F(struct VECTOR *);
extern void C_00755495(void);
extern void C_0075551A(void);
extern void C_00755B70(int, int);
extern void C_00755B97(int, int);
extern int C_00755C2F(void);
extern void C_00755C40(void);
extern void C_00755CFF(int);
extern void C_00755F95(void);
extern void C_0075611B(void);
extern int C_007561EC(void);
extern void C_007561F6(struct t_wm_local_18 *);
extern void C_007562FF(void);
extern void C_00756A95(void);
extern void C_00756B0C(struct t_wm_local_18 *);
extern void C_00756FF9(struct t_wm_local_18 *, struct t_wm_local_0c_TRIANGLE *);
extern void C_007570E8(int);
extern void C_007573D9(void);
extern void C_00758A32(int);
extern int C_00758A3F(void);
extern int C_00758A6C(void);
extern void C_00758AC4(int);
extern int C_00758B12(int, int);
extern int C_00758D0B(void);
extern void C_00758D17(unsigned);
extern int C_00758D76(void);
extern void C_00758DA5(short, short);
extern void C_007591C2(int *, int *);
extern void C_007591F3(void);
//-- wmfile.cpp --
extern int C_007592E0(int);//wmfile:texture does not exist?
extern int C_0075931B(const char *, int, void *, int);//wmfile:read file(archive)
extern int C_007593CD(const char *, int, int, void *, int);//wmfile:read file
extern void C_00759A65(int);//wmfile:load some animations(2)?
extern int C_00759EE0(void);//wmfile:get some animations count(1)?
extern void C_00759EEA(void);//wmfile:release some animations(1)?
extern void C_0075A01D(void);//wmfile:release some animations(2)?
extern void C_0075A1C6(int);//wmfile:secure init?
extern void C_0075A921(void);//wmfile:clean textures & models?
//-- wmdefine.cpp --
extern void C_0075AB50(void);//wmdefine:init?
extern void C_0075ABF3(void);//wmdefine:clean?
//-- C_0075AC80.cpp --
extern void C_0075AC80(void);
extern void C_0075AD28(struct t_local_unknown_c0_WMOBJ *, int);
extern void C_0075BB25(void);
extern void C_0075BBB3(struct t_local_unknown_c0_WMOBJ *, int);
extern void C_0075BFE5(int, int, int, int);
extern void C_0075C01B(int);
extern void C_0075C02B(void);
extern void C_0075D482(struct t_wm_local_30 *, short *);
extern void C_0075D544(short, short, short, short, struct t_wm_local_30 *, short);
extern void C_0075DEAA(struct t_local_unknown_c0_WMOBJ *);
extern void C_0075E024(void *);
extern void C_0075E029(LPD3DMATRIX);
extern void C_0075E0BA(struct t_wm_b8 *, struct t_local_unknown_c0_WMOBJ *, short, short, struct SVECTOR *);
extern void C_0075E4D6(short, short);
extern void C_0075E59A(int);
extern void C_0075E5B3(int);
extern void C_0075E5C0(int);
extern void C_0075E63A(void);
extern int C_0075E64D(void);
extern void C_0075E657(int);
extern void C_0075E683(void);
extern void C_0075E697(int);
extern void C_0075E6A8(int, int);
extern void C_0075E6BD(void);
extern void C_0075E6CC(int);
extern void C_0075E720(int);
//-- C_0075E7A0.cpp --
extern struct t_light_5ac *C_0075E7A0(int);//wm:create light system(1)
extern struct t_light_5ac *C_0075E9B3(int);//wm:create light system(2)
extern void C_0075EACE(void);//wm:secure clean light(2)
extern void C_0075EAF6(void);//wm:secure clean light(1)
extern void C_0075EB1E(void);//wm:clean lights?
extern void C_0075EB2D(int);//wm:change light params?
extern void C_0075EE10(struct MATRIX *);//wm:set some global light color?
//-- C_0075EE50.cpp --
extern void C_0075EE50(struct t_script_20 *);
extern void C_0075EE86(int);
extern void C_0075EEBB(short, short, short);
extern int C_0075EF01(void);
extern int C_0075EF13(void);
extern void C_0075EF46(void);//manage text event?
extern short C_0075F00E(void);
extern void C_0075F038(short *);
extern void C_0075F06C(int, int);
//-- C_0075F090.cpp --
extern int C_0075F090(float);
extern void C_0075F0AD(struct SVECTOR *, int);
extern void C_0075F263(void);
extern void C_0075F68C(struct t_wm_local_0c_TRIANGLE *, struct t_wm_local_0c_TRIANGLE *, struct SVECTOR *, struct POLY_GT3 *);
extern int C_0076085F(struct t_wm_local_0c_TRIANGLE *, struct SVECTOR *, int *);
extern void C_00760E1D(struct t_wm_local_0c_TRIANGLE *, struct t_wm_local_0c_TRIANGLE *, int);
//-- C_00760FB0.cpp --
extern void C_00760FB0(struct t_wm_local_8_rrr *);
extern struct t_local_unknown_c0_WMOBJ *C_007610B3(void);
extern void C_0076110B(void);
extern int C_00761176(void);
extern void C_007611AE(void);
extern void C_0076142D(void);
extern int C_00761521(void);
extern void C_0076154F(void);
extern void C_007615BA(void);
extern void C_007615D6(void);
extern void C_0076160D(void);
extern void C_00761644(short, short);
extern void C_007616B3(void);
extern void C_007616CB(void);
extern struct t_wm_local_08_MESHHEADER *C_007616E3(void);
extern int C_0076170B(void);
extern int C_00761735_PLAYER_CURRENT_MODEL(void);//current transportation mode?
extern struct t_local_unknown_c0_WMOBJ *C_0076175F(void);
extern int C_00761769_PLAYERMODEL_MASK(int);
extern int C_00761805(int, unsigned char);
extern int C_00761844(void);
extern int C_007618B7(void);
extern int C_0076192A(unsigned char);
extern void C_0076197B(int);
extern void C_00761B19(short);
extern void C_00761B83(short);
extern void C_00761BAC(short);
extern void C_00761DF5(short);
extern short C_00761EB6(void);
extern short C_00761EEC(void);
extern void C_00761F22(int);
extern int C_00761F44(void);
extern int C_00761F77(void);
extern void C_00761FAA(int);
extern int C_00761FE8(void);
extern int C_0076201E(void);
extern int C_00762047(int);
extern int C_007620B6(void);
extern void C_00762102(int);
extern void C_0076211B(int);
extern int C_00762136_PLAYER_GROUND_TYPE(void);
extern int C_00762162(void);
extern int C_00762191_ON_CHOCO_TRACKS(void);
extern int C_007621C0(void);
extern void C_007621EF(struct VECTOR *);
extern void C_00762465(struct VECTOR *);
extern void C_0076247D(struct VECTOR *);
extern void C_007624C5(struct VECTOR *);
extern void C_00762702(int);
extern void C_0076271B(int);
extern void C_00762763(struct VECTOR *);
extern void C_00762798_SET_VECTOR_TO_PLAYER_POS(struct VECTOR *);
extern void C_007627CD(struct VECTOR *);
extern void C_00762802(struct VECTOR *);
extern void C_00762837(void);
extern void C_007628B5(void);
extern void C_00762933(void);
extern void C_00762955(int);
extern struct t_local_unknown_c0_WMOBJ *C_0076296E(void);
extern void C_00762D52(void);
extern void C_00762D74(struct t_wm_local_18 *);
extern void C_00762E87(int, int);
extern void C_00762F75(int, int, int);
extern int C_00762F9A(int, int);
extern void C_0076312D(struct SVECTOR *);
extern void C_0076315C(void);
extern void C_0076323A(void);
extern void C_00763C35(void *);
extern void C_00763D6C(int);
extern void C_00764014(int, int);
extern void C_007640BC(int);
extern void C_007641A7_ScriptLoop(void);
extern void C_00765F61(void);
extern int C_0076603F(void);
extern void C_0076609E(void);
extern void C_00766255(int, int);
extern void C_007663A8(struct VECTOR *);
//-- C_007663E0.cpp --
extern void C_007663E0(void);
extern void C_00766417(int);
extern void C_007664C2(unsigned char);
extern unsigned char C_00766526(void);
extern void C_00766553(int);
extern int C_00766560(void);
extern void C_00766574(void);//"O" button near a vehicle?
extern void C_0076667C(void);//"X" button short trigger?
extern void C_007667A3(void);
extern void C_007667B2(int);
extern int C_00766B53(void);
extern void C_00766B5D(int);
//-- C_00766B70.cpp --
extern int C_00766B9F(void);
extern int C_00766C33(void);
extern int C_00766C6E(void);
extern void C_00766C7A(int *, int *, int);
extern void C_00766ECB(void);
extern void C_00767039(int *, int *, int *);
extern void C_00767097(void);
extern void C_007670F9(int);
extern void C_0076717C(int);
extern void C_007671AD(int);
extern void C_007671E1(void);
extern int C_00767204(void);
extern int C_0076720E(void);
extern int C_0076736E(void);
extern void C_0076741C(void);
extern void C_00767473(int);//save location name?
extern int C_007674DF(void);
extern int C_007674EB(void);
extern void C_00767501(void);
extern void C_00767515(void);
extern void C_00767524(void);
extern void C_00767533(int);
extern void C_00767540_WALKFRAME_DOSTEPFRAC(void);
//-- C_00767D40.cpp --
extern void C_00767D40(void);//reset map/radar
extern void C_00767D68(short);//render map/radar
extern void C_0076831F(short);//set map/radar state
extern short C_00768343(void);//get map/radar state
extern void C_0076834E(void);
//-- C_007688E0.cpp --
extern void C_007688E0(void);
extern void C_007689F7(void);
extern struct t_wm_b8 *C_00768A37(short);
extern void C_00768BE2(short);
extern void C_00768C3D(void);
extern void C_00768C4C(int);
extern int C_00768C59(void);
//-- C_00768C70.cpp --
extern void C_00768C7A(void);
extern int C_00768E3D(short);
extern void C_00768EC3(short, short, short);
extern void C_00768F48(short, short, short, short, short);
extern int C_00769050(unsigned char, unsigned char);
extern int C_007693A1(unsigned char, unsigned char, unsigned char, unsigned char, short *);
////////////////////////////////////////

#endif
