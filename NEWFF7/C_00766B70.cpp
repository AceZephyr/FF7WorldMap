/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- 

#include "ff7.h"
#include "wm_data.h"
#include "menu_data.h"
#include "loadmenu.h"
////////////////////////////////////////
int D_00E3A87C_STEPFRAC;
int D_00E3A880;
int D_00E3A884;
int D_00E3A888_DANGER;
int D_00E3A88C;
int D_00E3A890;
int D_00E3A894;
////////////////////////////////////////
void __00766B70() {
	int i;

	for(i = 0; i < 0x400; i ++)
		D_00DBFD38.f_0ba4[i] = 0;
}

int C_00766B9F() {
	return /*local_1*/(D_00DC08DC < 1000)?0:
		/*local_2*/(D_00DC08DC < 1580)?
			((D_00DC0956 & 1) | ((D_00DC08DC >= 1620) << 1)) + 1
			:
			((D_00DC08DC >= 1620) | (((D_00DC0C62 & 0x10)?1:0) << 1)) + 5
	;
}

int C_00766C33() {
	return (D_00DC08DC >= 1000 && D_00DC08DC < 1200);
}

int C_00766C6E() {
	return D_00DC0CDA;
}

void C_007671CB(void);
void C_00767218(unsigned char *, unsigned char *, int);

void C_00766C7A(int *bp08, int *bp0c, int bp10) {
	struct {
		struct VECTOR local_7;
		int i;//local_3
		int local_2;
		int dwChecksum;//local_1
	}lolo;

	//-- some checksum? --
	lolo.dwChecksum = 0;
	for(lolo.i = 0x380; lolo.i < 0x400; lolo.i ++)
		lolo.dwChecksum += D_00DBFD38.f_0ba4[lolo.i];
	if(lolo.dwChecksum & 0xff)
		C_0074C9A0(2);//<empty>:some error management?
	//-- --
	D_00E3A884 = /*lolo.local_8*/bp08?*bp08:0;
	D_00E3A894 = /*lolo.local_9*/bp0c?*bp0c:0;
	lolo.local_2 = (D_00DC0CD4 >> 0xc) & 3;
	C_0074D3D1((lolo.local_2 >= 0 && lolo.local_2 < 3)?lolo.local_2: 0);
	if((D_00E3A884 == 0 && D_00E3A894 == 0) || D_00E3A884 == 1 || D_00E3A884 == 2)
		C_0074D2B9(D_00DC0CD4 & 0xfff);
	C_0076831F((D_00DC0CD4 >> 0xe) & 3);
	C_00767218(D_00DC09E5, D_00DBFD38.f_04f8, 0);
	C_00753A01_RNGSEED(D_00DBFD38.dwPlayTime);//wm:randomize
	C_00758D17(D_00DC0CD0);
	C_00750466(D_00DC0C92);
	C_00760FB0((struct t_wm_local_8_rrr *)&D_00DC0C94);
	if(bp10) {
		D_00DC08FA &= ~0x300;
		//goto 00766EC2
	} else {
		C_00758AC4(D_00DC0CD7);
		if(D_00E3A884 == 1) {//else 00766E9A
			for(lolo.i = 0; lolo.i < 3; lolo.i ++) {
				if(D_00DC0CC4[lolo.i]) {
					C_007610B3();
					C_0076197B(lolo.i + 0x15);
					lolo.local_7.f_00_X = D_00DC0CC4[lolo.i] & 0xffff;
					lolo.local_7.f_04_Y = 0;
					lolo.local_7.f_08_Z = (D_00DC0CC4[lolo.i] >> 0x10) & 0xffff;
					C_007621EF(&lolo.local_7);
				}
			}//end for
		} else {
			for(lolo.i = 0; lolo.i < 3; lolo.i ++)
				D_00DC0CC4[lolo.i] = 0;
		}
	}
	C_007671CB();
}

void C_00766ECB() {
	struct {
		struct VECTOR local_6;
		int i;//local_2
		int dwChecksum;//local_1
	}lolo;

	if(C_0074D28E() == 0 && C_0074D330() != 3)
		C_0074D2B9(0);
	D_00DC0CD4 = (C_0074D298() & 0xfff) | ((C_0074D28E() << 0xc) & 0x3000) | ((C_00768343() << 0xe) & 0xc000);
	D_00DC0CD9 = C_00761735_PLAYER_CURRENT_MODEL();//current transportation mode?
	if(D_00DC0CD9 == 3 && C_0076192A(C_00766526()))
		D_00DC0CD9 = 0x2b;
	C_0076609E();
	D_00DC0CDA = C_0074D330();
	D_00DC0CD0 = C_00758D76();
	D_00DC0C92 = C_0075045C();
	if(D_00DC0CDA == 3) {//else 00766FF2
		D_00DC0CD7 = C_00758D0B();
		for(lolo.i = 0; lolo.i < 3; lolo.i ++) {
			if(C_00762047(lolo.i + 0x15)) {
				C_00762763(&lolo.local_6);
				D_00DC0CC4[lolo.i] = (lolo.local_6.f_00_X & 0xffff) | (lolo.local_6.f_08_Z << 0x10);
			} else {
				D_00DC0CC4[lolo.i] = 0;
			}
		}
	}
	//-- set some checksum? --
	lolo.dwChecksum = 0;
	for(lolo.i = 0x380; lolo.i < 0x3ff; lolo.i ++)
		lolo.dwChecksum += D_00DBFD38.f_0ba4[lolo.i];
	D_00DC0CDB = -lolo.dwChecksum;
	//-- --
}

void C_00767039(int *bp08, int *bp0c, int *bp10) {
	if(bp08)
		*bp08 = D_00E3A884;
	if(bp0c)
		*bp0c = D_00E3A894;
	if(bp10)
		*bp10 = D_00E3A88C | ((D_00E3A880 != 0) << 0x1d);
	D_00DC08FA |= 0x300;
	C_00766ECB();
}

void C_00767097() {
	if(D_00DC0CD9 >= 3) {
		if(D_00DC0CD9 < 0x2b) {
			C_00762047(D_00DC0CD9);
			C_00766574();//"O" button near a vehicle?
		} else {
			C_00762047(0x13);
			C_00766574();//"O" button near a vehicle?
			C_00762047(3);
			C_00766574();//"O" button near a vehicle?
		}
		C_0074D4C0(C_00761EB6());
	}
}

void C_007670F9(int bp08) {
	struct t_wm_local_0c_xxx *local_1;

	D_00E3A884 = 0;
	D_00E3A894 = bp08;
	local_1 = &(D_00E37D30[(((bp08 >> 8) * 2 - 2) & 0x1fe) | (bp08 & 1)]);
	D_00CC0D88.wEventParam = local_1->f_06;
	D_00CC0D88.f_04 = local_1->f_00;
	D_00CC0D88.f_06 = local_1->f_02;
	D_00CC0D88.f_22 = local_1->f_04;
	D_00CC0D88.f_24 = local_1->f_08;
}

void C_0076717C(int bp08) {
	if(bp08 & 0x40000000)
		C_007670F9(0x2100);
	D_00E3A884 = 1;
	D_00E3A88C = bp08;
}

//set countdown?
void C_007671AD(int bp08) {
	D_00DBFD38.dwTimer = bp08;
	D_00E3A880 = 1;
	D_00DC093B = 1;
}

void C_007671CB() {
	D_00E3A880 = 0;
	D_00DC093B = 0;
}

void C_007671E1() {
	D_00E3A884 = 2;
	D_00E3A894 = 0;
	D_00E3A88C = 0;
}

int C_00767204() {
	return D_00E3A884;
}

int C_0076720E() {
	return D_00E3A894;
}

void C_00767218(unsigned char *bp08, unsigned char*bp0c, int bp10) {
	struct {
		int local_5;
		int local_4;
		unsigned local_3;
		unsigned local_2;
		unsigned local_1;
	}lolo;

	lolo.local_5 = (1 << bp08[0]) | (1 << bp08[1]) | (1 << bp08[2]);
	lolo.local_4 = (1 << bp0c[0]) | (1 << bp0c[1]) | (1 << bp0c[2]);
	if(bp10)
		C_00766255(lolo.local_5, lolo.local_4);
	lolo.local_1 = lolo.local_5 & ~lolo.local_4;
	for(lolo.local_2 = 0; lolo.local_2 < 3; lolo.local_2 ++) {
		if(lolo.local_1 & (1 << bp08[lolo.local_2]))
			bp08[lolo.local_2] = 0xff;
	}
	for(lolo.local_1 = ~lolo.local_5 & lolo.local_4, lolo.local_2 = lolo.local_3 = 0; lolo.local_1; lolo.local_2 ++, lolo.local_1 >>= 1) {
		if(lolo.local_1 & 1) {
			while(lolo.local_3 < 3 && bp08[lolo.local_3] != 0xff)
				lolo.local_3 ++;
			if(lolo.local_3 >= 3)
				break;
			bp08[lolo.local_3] = lolo.local_2;
			lolo.local_3 ++;
		}
	}
}

int C_0076736E() {
	return /*local_3*/(D_00DC09E5[0] != 0 && D_00DC09E5[1] != 0 && D_00DC09E5[2] != 0)?
		/*local_2*/(D_00DC09E5[0] != 2 && D_00DC09E5[1] != 2 && D_00DC09E5[2] != 2)?
			/*local_1*/(D_00DC09E5[0] != 8 && D_00DC09E5[1] != 8 && D_00DC09E5[2] != 8)?0:2
			:1
		:0
	;
}

void C_0076741C() {
	C_00767218(D_00DC09E5, D_00DBFD38.f_04f8, C_0074D330() != 2);
	if(C_0074D330() != 2)
		(C_00766560()?C_00766553:C_00762102)(C_0076736E());
}

//save location name?
void C_00767473(int bp08) {
	int local_2;
	unsigned char *local_1;

	local_1 = C_0074D915(bp08);//get string from "mes"
	local_2 = 0x368;
	while(local_2 < 0x380 && (D_00DBFD38.f_0ba4[local_2 ++] = *(local_1 ++)) != 0xff);
}

void C_007674D2(int bp08) {
	D_00DC0CD8 = bp08;
}

int C_007674DF() {
	return D_00DC0CD8;
}

int C_007674EB() {
	return (D_00DB958A & 8)?1:0;
}

void C_00767515(void);

void C_00767501() {
	D_00E3A888_DANGER = 0;
	C_00767515();
}

void C_00767515() {
	D_00E3A87C_STEPFRAC = -0x8c;
}

void C_00767524() {
	D_00E3A87C_STEPFRAC = -0x1e;
}

void C_00767533(int bp08) {
	D_00E3A890 = bp08;
}

int C_00767641_ENC_CHECK(void);

void C_00767540_WALKFRAME_DOSTEPFRAC() {
	struct {
		struct VECTOR local_11;
		int local_7;
		int local_6;
		int local_5;
		struct VECTOR local_4;
	}lolo;

	lolo.local_5 = C_0074D330();
	if(D_00CC0D88.f_3b == 0 && lolo.local_5 != 2 && C_00758A6C() == 0 && C_0074D4B6()) {
		lolo.local_7 = C_007621C0();
		C_00762798_SET_VECTOR_TO_PLAYER_POS(&lolo.local_4);
		C_00762802(&lolo.local_11);
		if(C_00761769_PLAYERMODEL_MASK(0x47) && D_00E3A890) {//else 00767633
			if(lolo.local_7 == 0 && (lolo.local_4.f_00_X != lolo.local_11.f_00_X || lolo.local_4.f_08_Z != lolo.local_11.f_08_Z)) {//else 00767631
				if(D_00E3A87C_STEPFRAC == 8 || D_00E3A87C_STEPFRAC == 0x10)
					C_006CC4A8();
				if(D_00E3A87C_STEPFRAC ++ >= 0x10) {//else 00767631
					D_00E3A87C_STEPFRAC = 0;
					lolo.local_6 = C_00767641_ENC_CHECK();
					if(lolo.local_6 != -1) {//else 00767631
						C_00762465(&lolo.local_11);
						C_0074D7CD(lolo.local_6);
					}
				}
			}
		} else {
			D_00E3A87C_STEPFRAC = 0;
		}
	}
}

char D_0096DEA0[][4] = {
	{0x00,0x09,0x00,0x11},
	{0x00,0x00,0x00,0x11},
	{0x00,0x09,0x01,0x11},
	{0x00,0x14,0x00,0x11},
	{0x00,0x09,0x08,0x11},
	{0x00,0x00,0x19,0x11},
	{0x00,0x09,0x13,0x11},
	{0x00,0x00,0x01,0x11},
	{0x00,0x00,0x01,0x11},
	{0x00,0x09,0x0E,0x11},
	{0x00,0x09,0x19,0x11},
	{0x00,0x0A,0x09,0x11},
	{0x00,0x09,0x19,0x11},
	{0x00,0x00,0x08,0x0B},
	{0x00,0x00,0x08,0x00},
	{0x00,0x00,0x01,0x00}
};

unsigned char D_0096DEE0[] = {0x00,0x00,0x20,0x00,0x00,0x40,0x00,0x40,0xFF,0x00,0x80,0x00,0x80,0x00,0x00,0x80};

int C_00767C55_LUREVAL_MAYBE(void);
int C_00767C77_PREEMPT_MAYBE(void);
int C_00767C9E_PREEMPT_128(void);
int C_00767CB5_CHOCOLURE_VAL(void);
int C_00767CC1(void);
int C_00767CD0_ALWAYS_1(void);
int C_00767CDA(void);
int C_00767D2C_ALWAYS_1(void);

int C_00767641_ENC_CHECK() {
	struct {
		//local_15 and above for compiler
		int local_14;
		int local_13;
		int local_12;
		int local_11;
		int enc;
		int local_9;
		int ground_type;
		int world_region;
		int local_6;
		int threshold;
		int local_4;
		int local_3;
		int local_2;
		struct t_wm_local_20_xxx_ENCDATA *encdata;
	}lolo;

	lolo.local_2 = 0;
	lolo.local_6 = 0;
	lolo.local_9 = 0;
	lolo.enc = -1;
	lolo.ground_type = C_00762136_PLAYER_GROUND_TYPE(); // player 4a & 0x1F
	lolo.world_region = C_00762162(); // (player 4a >> 9) & 0x1F
	if(C_00767C55_LUREVAL_MAYBE()) {//else 00767C0B
		if(lolo.world_region < 0)
			lolo.world_region = 0;
		else if(lolo.world_region > 0xf)
			lolo.world_region = 0xf;
		if(lolo.ground_type == 0x10) // change "side of hill" to "normal ground"
			lolo.ground_type = 0;
		if(lolo.ground_type == 0x18) // change "gold saucer desert" to "desert"
			lolo.ground_type = 8;
		if(D_0096DEA0[lolo.world_region][0] == lolo.ground_type)
			lolo.ground_type = 0;
		else if(D_0096DEA0[lolo.world_region][1] == lolo.ground_type)
			lolo.ground_type = 1;
		else if(D_0096DEA0[lolo.world_region][2] == lolo.ground_type)
			lolo.ground_type = 2;
		else if(D_0096DEA0[lolo.world_region][3] == lolo.ground_type)
			lolo.ground_type = 3;
		else
			lolo.ground_type = 0;
		lolo.encdata = &(D_00DE6B78.f_0a0[lolo.world_region][lolo.ground_type]);
		lolo.local_4 = (lolo.encdata->encrate >> 8) & 0xff;
		D_00E3A888_DANGER += /*lolo.local_15*/lolo.local_4?(C_00767C55_LUREVAL_MAYBE() << 0xa) / lolo.local_4:0x7fff;
		if(C_00753BE8_RAND() < (D_00E3A888_DANGER >> 8) && (lolo.encdata->encrate & 1)) {//else 00767C0B
			// if that passes we get a battle
			// yuffie check
			if(C_00753BE8_RAND() < D_0096DEE0[lolo.world_region] && (C_00762136_PLAYER_GROUND_TYPE() == 1 || C_00762136_PLAYER_GROUND_TYPE() == 0x19) && C_00767CC1()) {//else 00767853
				lolo.local_11 = C_006CB8D6(0);
				for(lolo.local_12 = 0; lolo.local_12 < 8 && lolo.local_11 > D_00DE6B78.f_000[lolo.local_12][0]; lolo.local_12 ++);
				if(lolo.local_12 >= 8)
					lolo.local_12 = 7;
				lolo.enc = (D_00DE6B78.f_000[lolo.local_12][1] & 0x3ff) + (C_00762136_PLAYER_GROUND_TYPE() == 0x19);
				lolo.local_9 = 1;
				//goto 00767C0B
			} else {
				D_00E3A888_DANGER = 0;
				if(C_00762191_ON_CHOCO_TRACKS() && C_00767CB5_CHOCOLURE_VAL() && C_00761769_PLAYERMODEL_MASK(7)) { // player model must be a human for the last one
					lolo.local_3 = (C_00753BE8_RAND() << 0xc) / C_00767CB5_CHOCOLURE_VAL();
					lolo.threshold = lolo.encdata->alt0;
					if(lolo.threshold > lolo.local_3) {
						lolo.enc = lolo.encdata->alt0 & 0x3ff;
					} else if((lolo.threshold += lolo.encdata->alt1) > lolo.local_3) {
						lolo.enc = lolo.encdata->alt1 & 0x3ff;
					} else if((lolo.threshold += lolo.encdata->alt2) > lolo.local_3) {
						lolo.enc = lolo.encdata->alt2 & 0x3ff;
					} else if((lolo.threshold += lolo.encdata->alt3) > lolo.local_3) {
						lolo.enc = lolo.encdata->alt3 & 0x3ff;
					}
					for(lolo.local_13 = 0; lolo.local_13 < 0x20 && D_00DE6B78.f_020[lolo.local_13][0] != lolo.enc; lolo.local_13 ++);
					if(lolo.local_13 < 0x20)
						C_007674D2(D_00DE6B78.f_020[lolo.local_13][1]);
					lolo.local_6 = lolo.enc != -1;
				}
				lolo.local_2 = C_00753BE8_RAND() < C_00767C77_PREEMPT_MAYBE();
				if(lolo.local_2 == 0) {//else 00767AC3
					// back attack 1+2
					if(C_00767CD0_ALWAYS_1() && lolo.enc < 0) {//else 00767A38
						lolo.local_3 = C_00753BE8_RAND() << (C_00767C9E_PREEMPT_128() + 8);
						lolo.threshold = lolo.encdata->sp0;
						if(lolo.threshold > lolo.local_3) {
							lolo.enc = lolo.encdata->sp0 & 0x3ff;
						} else {
							lolo.threshold += lolo.encdata->sp1;
							if(lolo.threshold > lolo.local_3) {
								lolo.enc = lolo.encdata->sp1 & 0x3ff;
							}
						}
					}
					// side attack
					if(C_00767CDA() && lolo.enc < 0) {//else 00767A78
						lolo.local_3 = C_00753BE8_RAND() << 8;
						lolo.threshold = lolo.encdata->sp2;
						if(lolo.threshold > lolo.local_3) {
							lolo.enc = lolo.encdata->sp2 & 0x3ff;
						}
					}
					// pincer
					if(C_00767D2C_ALWAYS_1() && lolo.enc < 0) {//else 00767AC3
						lolo.local_3 = C_00753BE8_RAND() << (C_00767C9E_PREEMPT_128() + 8);
						lolo.threshold = lolo.encdata->sp3;
						if(lolo.threshold > lolo.local_3) {
							lolo.enc = lolo.encdata->sp3 & 0x3ff;
						}
					}
				}
				if(lolo.enc < 0) {//else 00767C0B
					lolo.local_14 = 0;
					do {
						lolo.local_3 = C_00753BE8_RAND() << 8;
						lolo.threshold = lolo.encdata->std0;
						if(lolo.threshold > lolo.local_3) {
							lolo.enc = lolo.encdata->std0 & 0x3ff;
						} else if((lolo.threshold += lolo.encdata->std1) > lolo.local_3) {
							lolo.enc = lolo.encdata->std1 & 0x3ff;
						} else if((lolo.threshold += lolo.encdata->std2) > lolo.local_3) {
							lolo.enc = lolo.encdata->std2 & 0x3ff;
						} else if((lolo.threshold += lolo.encdata->std3) > lolo.local_3) {
							lolo.enc = lolo.encdata->std3 & 0x3ff;
						} else if((lolo.threshold += lolo.encdata->std4) > lolo.local_3) {
							lolo.enc = lolo.encdata->std4 & 0x3ff;
						} else if((lolo.threshold += lolo.encdata->std5) > lolo.local_3) {
							lolo.enc = lolo.encdata->std5 & 0x3ff;
						}
					} while(lolo.local_14 ++ < 1 && lolo.enc == D_00DC0C90_LASTENC);
				}
			}
		}
	}
	if(lolo.enc != -1) {
		D_00DC0C90_LASTENC = lolo.enc;
		C_0075E5B3(1);
		C_0075E5C0((lolo.local_6 != 0) + 4);
	}

	return lolo.enc | (lolo.local_2 << 0x1f) | (lolo.local_9 << 0x1e);
}

int C_00767C55_LUREVAL_MAYBE() {
	return D_00DBCAD9 * ((D_00DBCAD9 > 0x10) + 1);
}

int C_00767C77_PREEMPT_MAYBE() {
	int local_1 = D_00DBCADB & 0x7f;
	return local_1 * ((local_1 > 0x10) + 1);
}

int C_00767C9E_PREEMPT_128() {
	return (D_00DBCADB & 0x80)?1:0;
}

int C_00767CB5_CHOCOLURE_VAL() {
	return D_00DBCADA;
}

int C_00767CC1() {
	return D_00DC0A61 & 1;
}

int C_00767CD0_ALWAYS_1() {
	return 1;
}

int C_00767CDA() {
	int local_2;
	int local_1;

	local_1 = 0;
	for(local_2 = 0; local_2 < 3; local_2 ++)
		local_1 += D_00DBFD38.f_04f8[local_2] != 0xff;

	return local_1 > 1;
}

int C_00767D2C_ALWAYS_1() {
	return 1;
}
