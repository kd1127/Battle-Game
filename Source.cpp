//	バトルゲーム２
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MONUM 60		//	通常モンスターの総数
#define INUM 5	//	アイテム所持制限(トーナメントモードのみ)
#define _CRT_SECURE_NO_WARNINGS

//	(構造体)Player
typedef struct MonsterP{
	char name[30];
	int HP;
	int TP;
	int atk;
	int def;
	int spd;
}MstP;

//	(構造体)CPU
typedef struct MonsterC{
	char name[30];
	int HP;
	int TP;
	int atk;
	int def;
	int spd;
}MstC;

//	(構造体)LB
typedef struct LBoss{
	char name[20];
	int HP;
	int TP;
	int atk;
	int def;
	int spd;
} LB;

//	大域変数の宣言
MstP MP[MONUM] = {
	{ "ブルースライム", 3000, 8, 680, 240, 370 },
	{ "アイアンスライム", 1500, 25, 600, 500, 400 },
	{ "レッドスライム", 3200, 7, 750, 150, 320 },
	{ "怪魚", 3400, 12, 670, 280, 330 },
	{ "海グモ", 2500, 18, 760, 350, 200 },
	{ "海蛇", 2950, 15, 670, 200, 390 },
	{ "魔法使い", 2700, 40, 650, 320, 270 },
	{ "コカトリス", 3050, 19, 710, 200, 300 },
	{ "ハービー", 2800, 23, 700, 260, 330 },
	{ "トレント", 3900, 26, 640, 380, 180 },
	{ "ゴブリン", 3500, 6, 720, 270, 210 },
	{ "スケルトン", 3300, 13, 740, 260, 220 },
	{ "半獣狩人", 3150, 10, 690, 210, 260 },
	{ "鋼鉄魚人", 2500, 9, 610, 450, 170 },
	{ "コボルト", 3700, 17, 700, 310, 320 },
	{ "ゾンビ", 5000, 0, 770, 100, 80 },
	{ "オーガ", 4500, 0, 800, 70, 120 },
	{ "グリフォン", 3250, 20, 730, 290, 270 },
	{ "コドラ", 2700, 10, 760, 340, 160 },
	{ "鉄砲魚", 3450, 13, 700, 260, 300 },
	{ "上魔道士", 3300, 70, 660, 330, 300 },
	{ "竜騎士", 4000, 30, 740, 300, 340 },
	{ "グレーターデーモン", 4200, 28, 780, 270, 180 },
	{ "大王イカ", 4000, 12, 800, 220, 200 },
	{ "ドラゴンフライ", 3450, 13, 730, 260, 290 },
	{ "ファイアエレメンタル", 4300, 20, 650, 250, 200 },
	{ "コールドエレメンタル", 4200, 35, 600, 380, 260 },
	{ "フレイムジャイアント", 3050, 15, 710, 320, 230 },
	{ "フロストジャイアント", 3300, 24, 670, 320, 260 },
	{ "ケルベロス", 3650, 11, 780, 190, 280 },
	{ "ヴァンパイアバット", 3550, 22, 695, 220, 310 },
	{ "ミイラ男", 3800, 0, 720, 340, 150 },
	{ "ガーゴイル", 3700, 27, 730, 270, 290 },
	{ "バシリスク", 2950, 24, 700, 300, 270 },
	{ "ポイズンスネイク", 3100, 31, 740, 280, 290 },
	{ "ダークゴブリン", 2750, 6, 800, 120, 350 },
	{ "下級ソルジャー", 3250, 33, 680, 310, 300 },
	{ "ワイバーン", 3500, 10, 690, 360, 210 },
	{ "人喰いシャーク", 3900, 23, 750, 250, 310 },
	{ "軍隊蟻", 2900, 37, 700, 320, 130 },
	{ "ジャイアントラット", 4100, 9, 765, 350, 10 },
	{ "ゴースト", 3600, 40, 710, 230, 150 },
	{ "グレムリン", 2800, 43, 745, 220, 360 },
	{ "キングコブラ", 3900, 14, 770, 210, 330 },
	{ "下級忍者A", 3600, 12, 760, 330, 250 },
	{ "下級忍者B", 3200, 36, 680, 270, 380 },
	{ "ゴーストナイト", 2700, 28, 670, 340, 320 },
	{ "翼竜", 4300, 11, 760, 300, 220 },
	{ "妖術士", 3500, 60, 730, 270, 260 },
	{ "リザードマン", 3300, 15, 790, 250, 220 },
	{ "グリーンスライム", 3400, 18, 720, 290, 310 },
	{ "マッドマン", 2600, 9, 700, 400, 50 },
	{ "人喰い植物", 3450, 17, 690, 290, 340 },
	{ "ジャイアント", 4700, 6, 790, 160, 180 },
	{ "キマイラ", 3850, 23, 785, 310, 210 }
};

MstC MC[MONUM] = {
	{ "ブルースライム", 3000, 8, 680, 240, 370 },
	{ "アイアンスライム", 1500, 25, 600, 500, 400 },
	{ "レッドスライム", 3200, 7, 750, 150, 320 },
	{ "怪魚", 3400, 12, 670, 280, 330 },
	{ "海グモ", 2500, 18, 760, 350, 200 },
	{ "海蛇", 2950, 15, 670, 200, 390 },
	{ "魔法使い", 2700, 40, 650, 320, 270 },
	{ "コカトリス", 3050, 19, 710, 200, 300 },
	{ "ハービー", 2800, 23, 700, 260, 330 },
	{ "トレント", 3900, 26, 640, 380, 180 },
	{ "ゴブリン", 3500, 6, 720, 270, 210 },
	{ "スケルトン", 3300, 13, 740, 260, 220 },
	{ "半獣狩人", 3150, 10, 690, 210, 260 },
	{ "鋼鉄魚人", 2500, 9, 610, 450, 170 },
	{ "コボルト", 3700, 17, 700, 310, 320 },
	{ "ゾンビ", 5000, 0, 770, 100, 80 },
	{ "オーガ", 4500, 0, 800, 70, 120 },
	{ "グリフォン", 3250, 20, 730, 290, 270 },
	{ "コドラ", 2700, 10, 760, 340, 160 },
	{ "鉄砲魚", 3450, 13, 700, 260, 300 },
	{ "上魔道士", 3300, 70, 660, 330, 300 },
	{ "竜騎士", 4000, 30, 740, 300, 340 },
	{ "グレーターデーモン", 4200, 28, 780, 270, 180 },
	{ "大王イカ", 4000, 12, 800, 220, 200 },
	{ "ドラゴンフライ", 3450, 13, 730, 260, 290 },
	{ "ファイアエレメンタル", 4300, 20, 650, 250, 200 },
	{ "コールドエレメンタル", 4200, 35, 600, 380, 260 },
	{ "フレイムジャイアント", 3050, 15, 710, 320, 230 },
	{ "フロストジャイアント", 3300, 24, 670, 320, 260 },
	{ "ケルベロス", 3650, 11, 780, 190, 280 },
	{ "ヴァンパイアバット", 3550, 22, 695, 220, 310 },
	{ "ミイラ男", 3800, 0, 720, 340, 150 },
	{ "ガーゴイル", 3700, 27, 730, 270, 290 },
	{ "バシリスク", 2950, 24, 700, 300, 270 },
	{ "ポイズンスネイク", 3100, 31, 740, 280, 290 },
	{ "ダークゴブリン", 2750, 6, 800, 120, 350 },
	{ "下級ソルジャー", 3250, 33, 680, 310, 300 },
	{ "ワイバーン", 3500, 10, 690, 360, 210 },
	{ "人喰いシャーク", 3900, 23, 750, 250, 310 },
	{ "軍隊蟻", 2900, 37, 700, 320, 130 },
	{ "ジャイアントラット", 4100, 9, 765, 350, 10 },
	{ "ゴースト", 3600, 40, 710, 230, 150 },
	{ "グレムリン", 2800, 43, 745, 220, 360 },
	{ "キングコブラ", 3900, 14, 770, 210, 330 },
	{ "下級忍者A", 3600, 12, 760, 330, 250 },
	{ "下級忍者B", 3200, 36, 680, 270, 380 },
	{ "ゴーストナイト", 2700, 28, 670, 340, 320 },
	{ "翼竜", 4300, 11, 760, 300, 220 },
	{ "妖術士", 3500, 60, 730, 270, 260 },
	{ "リザードマン", 3300, 15, 790, 250, 220 },
	{ "グリーンスライム", 3400, 18, 720, 290, 310 },
	{ "マッドマン", 2600, 9, 700, 400, 50 },
	{ "人喰い植物", 3450, 17, 690, 290, 340 },
	{ "ジャイアント", 4700, 6, 790, 160, 180 },
	{ "キマイラ", 3850, 23, 785, 310, 210 }
};

//	大域変数
FILE* fp;
errno_t error;										//	ファイル用変数
int sentaku = 0;									//	メインメニュー選択
int HP = 0, TP = 0, atk = 0, def = 0, spd = 0;		//	プレイヤー用変数
int HP2 = 0, TP2 = 0, atk2 = 0, def2 = 0, spd2 = 0;	//	CPU用変数
char name[30], name2[30];							//	モンスター名格納変数
int stk1 = 0, st2 = 0, r = 0;						//	PACでPlayerがコマンドを選択するときに使う変数、PMSTでモンスターを選択するときに使う変数、CMSTでモンスターを乱数で決定するときに使う変数
int flag000 = 0;
int flag10 = 0, flag11 = 0, flag12 = 0, flag13 = 0, flag14 = 0;
int flag15 = 0, flag16 = 0, flag17 = 0, flag18 = 0, flag19 = 0;		//	特殊技が使用されたかどうかのフラグ(Player)
int flag025 = 0, flag026 = 0, flag027 = 0, flag028 = 0;
int flag20 = 0, flag21 = 0, flag22 = 0, flag23 = 0, flag24 = 0;		//	補助特殊技が使用されたかどうかのフラグ(フラグ20～24)(Player)

int flag30 = 0, flag31 = 0, flag32 = 0, flag33 = 0, flag34 = 0;
int flag35 = 0, flag36 = 0, flag37 = 0, flag38 = 0, flag39 = 0;		//	特殊技が使用されたかどうかのフラグ(CPU)
int flag40 = 0, flag41 = 0, flag42 = 0, flag43 = 0;
int flag25 = 0, flag26 = 0, flag27 = 0, flag28 = 0, flag29 = 0;		//	補助特殊技が使用されたかどうかのフラグ(フラグ25～29)(CPU)
int r7 = 0;											//	CACで行動を決めるときに使用する変数

int st3 = 0, st4 = 0, st5 = 0, st6 = 0, st7 = 0;	//	SAcommandで技を選択するときに使用(st3～)(Player)
int st8 = 0, st9 = 0, st10 = 0, st11 = 0, st12 = 0;
int st13 = 0, st14 = 0, st15 = 0, st16 = 0, st17 = 0;
int st18 = 0, st19 = 0, st20 = 0, st21 = 0, st22 = 0;
int st23 = 0, st24 = 0, st25 = 0, st26 = 0, st27 = 0;
int st28 = 0, st29 = 0, st30 = 0, st31 = 0, st32 = 0;
int st33 = 0, st34 = 0, st35 = 0, st36 = 0, st37 = 0;
int st38 = 0, st39 = 0, st40 = 0, st41 = 0, st42 = 0;
int st43 = 0, st44 = 0, st45 = 0, st46 = 0, st47 = 0;
int st48 = 0, st49 = 0, st50 = 0, st51 = 0, st52 = 0;
int st53 = 0, st54 = 0, st55 = 0;
int flag = 0;										//	SAcommandで使用するフラグ用変数

int r13 = 0, r14 = 0, r15 = 0, r16 = 0, r17 = 0, r18 = 0, r19 = 0;	//	(CPU専用関数)CSAcommandで技を選択するときに使用(r10～)
int r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0;
int r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0, r32 = 0, r33 = 0;
int r34 = 0, r35 = 0, r36 = 0, r37 = 0, r38 = 0, r39 = 0, r40 = 0;
int r41 = 0, r42 = 0, r43 = 0, r44 = 0, r45 = 0, r46 = 0, r47 = 0;
int r48 = 0, r49 = 0, r50 = 0, r51 = 0, r52 = 0, r53 = 0, r54 = 0;
int r55 = 0, r56 = 0, r57 = 0, r58 = 0, r59 = 0, r60 = 0, r61 = 0;
int r62 = 0, r63 = 0, r64 = 0, r65 = 0;
int cflag = 0, tflg = 0;

//	アイテム関連変数(バトルモードのみ)
int ist = 0;			//	どのアイテムを選択したかの変数
int c1, c2, c3, c4, c5;	//	アイテムを何回使用したかのフラグ(ハーブ)
int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10;	//	ハーブ(上)&フラグ
int e1, e2, e3, e4, e5, e6, e7, e8, e9, e10;	//	ハーブ(特上)&フラグ
int g1, g2, g3, g4, g5, g6, g7, g8, g9, g10;	//	バジル&フラグ
int h1, h2, h3, h4, h5, h6, h7, h8, h9, h10;	//	バジル(上)＆フラグ
int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;	//	バジル(特上)＆フラグ
int j1, j2, j3, j4, j5, j6, j7, j8, j9, j10;	//	バジル(極)＆フラグ
int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;	//	ベリィ＆フラグ
int l1, l2, l3, l4, l5, l6, l7, l8, l9, l10;	//	ベリィ(上)＆フラグ
int m1, m2, m3, m4, m5, m6, m7, m8, m9, m10;	//	ベリィ(特上)＆フラグ
int n1, n2, n3, n4, n5, n6;						//	//	幻のハーブ＆フラグ
char herb_t[][10] = { "ハーブ", "ハーブ", "ハーブ", "ハーブ", "ハーブ" };
char uherb_t[][15] = { "ハーブ(上)", "ハーブ(上)", "ハーブ(上)", "ハーブ(上)", "ハーブ(上)" };
char suherb_t[][20] = { "ハーブ(特上)", "ハーブ(特上)", "ハーブ(特上)", "ハーブ(特上)", "ハーブ(特上)" };
char baziru_t[][10] = { "バジル", "バジル", "バジル", "バジル", "バジル" };
char ubaziru_t[][15] = { "バジル(上)", "バジル(上)", "バジル(上)", "バジル(上)", "バジル(上)" };
char subaziru_t[][20] = { "バジル(特上)", "バジル(特上)", "バジル(特上)", "バジル(特上)", "バジル(特上)" };
char ulbaziru_t[][15] = { "バジル(極)", "バジル(極)", "バジル(極)", "バジル(極)", "バジル(極)" };
char very_t[][10] = { "ベリィ", "ベリィ", "ベリィ", "ベリィ", "ベリィ" };
char uvery_t[][15] = { "ベリィ(上)", "ベリィ(上)", "ベリィ(上)", "ベリィ(上)", "ベリィ(上)" };
char ulvery_t[][15] = { "ベリィ(極)", "ベリィ(極)", "ベリィ(極)", "ベリィ(極)", "ベリィ(極)" };
char pherb_t[][15] = { "幻のハーブ", "幻のハーブ", "幻のハーブ" };
int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0;			//	ハーブが使用されたかどうかのフラグ

//	ショップ関連変数(トーナメントモードのみ)
int count = 0, puc = 0, puc2 = 0, puc3 = 0, puc4 = 0, puc5 = 0;	//	配列添え字用変数、HPシード用カウント
int puc6 = 0, puc7 = 0, puc8 = 0, puc9 = 0, puc10 = 0, puc11 = 0;		//	パワーアップ系アイテム用カウント
int puc12 = 0, puc13 = 0, puc14 = 0, puc15 = 0, puc16 = 0, puc17 = 0;
int ifg = 0, ifg2 = 0, ifg3 = 0, ifg4 = 0, ifg5 = 0, ifg6 = 0, ifg7 = 0;		//	パワーアップ系アイテムが使用された時に使用するフラグ
int ifg8 = 0, ifg9 = 0, ifg10 = 0, ifg11 = 0, ifg12 = 0, ifg13 = 0, ifg14 = 0, ifg15 = 0, ifg16 = 0, ifg17 = 0;

//	回復系アイテム
int hf = 0;						//	ハーブ
int zhf = 0;					//	ハーブ(上)
int thf = 0;					//	ハーブ(特上)
int bz = 0;						//	バジル
int ubz = 0;					//	バジル(上)
int tbz = 0;					//	バジル(特上)
int gbz = 0;					//	バジル(極)
int br = 0;						//	ベリィ
int ubr = 0;					//	ベリィ(上)
int gbr = 0;					//	ベリィ(極)
int mhb = 0;					//	幻のハーブ

//	特殊技を習得するのに使用するフラグ
int fg1 = 0, fg2 = 0, fg3 = 0, fg4 = 0, fg5 = 0, fg6 = 0, fg7 = 0, fg8 = 0, fg9 = 0, fg10 = 0;
int fg11 = 0, fg12 = 0, fg13 = 0, fg14 = 0, fg15 = 0, fg16 = 0, fg17 = 0, fg18 = 0, fg19 = 0, fg20 = 0;
int fg21 = 0, fg22 = 0, fg23 = 0;
int sac = 0;	//	関数BookStoreで本を何回購入したかのカウント

//	トーナメントモードで使用する変数
int shozikin = 10000, bp = 0;					//	初期の所持金、バトルポイント
char TMI[50][50];

//	BScommandで使う変数
int wk = 2, wk2 = 4, wk3 = 2, wk4 = 1, wk5 = 3, wk6 = 2, wk7 = 8, wk8 = 4, wk9 = 4, wk10 = 4;
int wk11 = 2, wk12 = 4, wk13 = 2, wk14 = 1, wk15 = 4, wk16 = 0, wk17 = 0, wk18 = 5, wk19 = 3;
int wk20 = 2, wk21 = 10, wk22 = 4, wk23 = 3, wk24 = 2, wk25 = 3, wk26 = 2, wk27 = 3, wk28 = 1;
int wk29 = 3, wk30 = 2, wk31 = 3, wk32 = 0, wk33 = 4, wk34 = 2, wk35 = 2, wk36 = 1, wk37 = 6;
int wk38 = 3, wk39 = 3, wk40 = 3, wk41 = 1, wk42 = 6, wk43 = 4, wk44 = 2, wk45 = 2, wk46 = 3;
int wk47 = 4, wk48 = 2, wk49 = 5, wk50 = 4, wk51 = 2, wk52 = 2, wk53 = 2, wk54 = 1, wk55 = 2;
//	各モンスターの技の個数を格納した変数
int work = 0;	//	モンスターの技の個数を格納する変数

/*	ゲーム説明	*/
void GameExplanation(){
	puts("");
}

//	プレイヤーの攻撃ダメージ計算
int PDamage()
{
	int r = 0;							//	乱数値取得変数
	int r2 = 0, r3 = 0;					//	加算か減算かを決定する乱数、上下ダメージ数
	int gensan3 = 0, flag = 0;

	srand((unsigned int)time(NULL));

	r = (rand() % 16 + 1);	//	約６％の確率でクリティカルヒットが出る

	srand((unsigned int)time(NULL));

	r2 = (rand() % 2 + 1);	//	正の値か負の値か

	if (r2 = 1){						//	r2の値が1ならば
		r3 = (rand() % 20 + 1);		//	正の値を得る
	}
	else{							//	r2の値が1以外ならば
		r3 = (rand() % -20 - 20);	//	負の値を得る
	}

	if (atk < def2){
		printf("ミス！CPUには攻撃が当たらない！\n");
		flag = 1;
	}

	if (flag == 0){
		switch (r){
		case 1:					//	クリティカルヒットのダメージ計算
			gensan3 = ((atk - def2) + r3) * 2;
			HP2 = HP2 - gensan3;
			printf("クリティカルヒット！CPUに%dのダメージ！\n", gensan3);
			break;
		case 2:					//	rの値が2～16ならば通常のダメージ
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
			gensan3 = (atk - def2) + r3;
			HP2 = HP2 - gensan3;
			printf("Playerの攻撃！CPUに%dのダメージ！\n", gensan3);
			break;
		}
	}
	return HP2;
}

//	CPUダメージ計算
int CDamage()
{
	int r4 = 0;							//	乱数値取得変数
	int r5 = 0, r6 = 0;					//	加算か減算かを決定する乱数、上下ダメージ数
	int gensan4 = 0, flag2 = 0;

	srand((unsigned int)time(NULL));

	r4 = (rand() % 16 + 1);	//	約６％の確率でクリティカルヒットが出る

	srand((unsigned int)time(NULL));

	r5 = (rand() % 2 + 1);	//	正の値か負の値か

	if (r5 = 1){						//	r5の値が1ならば
		r6 = (rand() % 20 + 1);		//	正の値を得る
	}
	else{							//	r5の値が1以外ならば
		r6 = (rand() % -20 - 1);	//	負の値を得る
	}

	if (atk2 < def){
		printf("ミス！Playerには攻撃が当たらない！\n");
		flag2 = 1;
	}

	if (flag2 == 0){
		switch (r4){
		case 1:					//	クリティカルヒットのダメージ計算
			if (stk1 == 2){
				gensan4 = (double)(((atk2 - def) + r6) * 2) * 0.25;
			}
			else{
				gensan4 = ((atk2 - def) + r6) * 2;
			}
			HP = HP - gensan4;
			printf("クリティカルヒット！Playerに%dのダメージ！\n", gensan4);
			break;
		case 2:					//	r4の値が2～16ならば通常のダメージ
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
			if (stk1 == 2){		//	相手が防御したとき
				gensan4 = ((atk2 - def) + r6) * 0.25;
			}
			else{		//	通常時
				gensan4 = (atk2 - def) + r6;
			}
			HP = HP - gensan4;
			printf("CPUの攻撃！Playerに%dのダメージ！\n", gensan4);
			break;
		}
	}

	return HP;
}

//	Playerモンスター決定関数
void PMST(){
	int kloop = 1, kloop2 = 1, st3 = 0, flg0 = 0;			//	関数内変数

	puts("----Player----");

	kloop = 1;
	while (kloop == 1){
		puts("モンスターを決めてください。");
		puts("1:ブルースライム 2:アイアンスライム 3:レッドスライム 4:怪魚 5:海グモ 6:海蛇");
		puts("7:魔法使い 8:コカトリス 9:ハービー 10:トレント 11:ゴブリン\n12:スケルトン 13:半獣狩人 14:鋼鉄魚人 15:コボルト 16:ゾンビ 17:オーガ");
		puts("18:グリフォン 19:コドラ 20:鉄砲魚 21:上魔道士 22:竜騎士 23:グレーターデーモン");
		puts("24:大王イカ 25:ドラゴンフライ 26:ファイアエレメンタル 27:コールドエレメンタル");
		puts("28:フレイムジャイアント 29:フロストジャイアント 30:ケルベロス 31:ヴァンパイアバット");
		puts("32:ミイラ男 33:ガーゴイル 34:バシリスク 35:ポイズンスネイク 36:ダークゴブリン");
		puts("37:下級ソルジャー 38:ワイバーン 39:人喰いシャーク 40:軍隊蟻 41:ジャイアントラット");
		puts("42:ゴースト 43:グレムリン 44:キングコブラ 45:下級忍者A 46:下級忍者B");
		puts("47:ゴーストナイト 48:翼竜 49:妖術士 50:リザードマン 51:グリーンスライム");
		puts("52:マッドマン 53:人喰い植物 54:ジャイアント 55:キマイラ");
		scanf_s("%d", &st2);

		flg0 = 0;

		if (st2 >= 1 && st2 <= 55){
			strcpy_s(name, MP[st2 - 1].name);
			HP = MP[st2 - 1].HP;
			TP = MP[st2 - 1].TP;
			atk = MP[st2 - 1].atk;
			def = MP[st2 - 1].def;
			spd = MP[st2 - 1].spd;
		}


		if (st2 == 1){		//	1を選択した場合の処理
			work = wk;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 2){		//	2を選択した場合の処理
			work = wk2;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 3){		//	3を選択した場合の処理
			work = wk3;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 4){		//	4を選択した場合の処理
			work = wk4;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 5){		//	5を選択した場合の処理
			work = wk5;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 6){		//	6を選択した場合の処理
			work = wk6;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 7){		//	7を選択した場合の処理
			work = wk7;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 8){		//	8を選択した場合の処理
			work = wk8;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 9){		//	9を選択した場合の処理
			work = wk9;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 10){		//	10を選択した場合の処理
			work = wk10;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 11){		//	11を選択した場合の処理
			work = wk11;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 12){		//	12を選択した場合の処理
			work = wk12;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 13){		//	13を選択した場合の処理
			work = wk13;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 14){		//	14を選択した場合の処理
			work = wk14;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 15){		//	15を選択した場合の処理
			work = wk15;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 16){		//	16を選択した場合の処理
			work = wk16;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 17){		//	17を選択した場合の処理
			work = wk17;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 18){		//	18を選択した場合の処理
			work = wk18;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 19){		//	19を選択した場合の処理
			work = wk19;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 20){		//	20を選択した場合の処理
			work = wk20;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 21){		//	21を選択した場合の処理
			work = wk21;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 22){		//	22を選択した場合の処理
			work = wk22;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 23){		//	23を選択した場合の処理
			work = wk23;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 24){		//	24を選択した場合の処理
			work = wk24;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 25){		//	25を選択した場合の処理
			work = wk25;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 26){		//	26を選択した場合の処理
			work = wk26;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 27){		//	27を選択した場合の処理
			work = wk27;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 28){		//	28を選択した場合の処理
			work = wk28;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 29){		//	29を選択した場合の処理
			work = wk29;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 30){		//	30を選択した場合の処理
			work = wk30;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 31){		//	31を選択した場合の処理
			work = wk31;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 32){		//	32を選択した場合の処理
			work = wk32;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 33){		//	33を選択した場合の処理
			work = wk33;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 34){		//	34を選択した場合の処理
			work = wk34;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 35){		//	35を選択した場合の処理
			work = wk35;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 36){		//	36を選択した場合の処理
			work = wk36;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 37){		//	37を選択した場合の処理
			work = wk37;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 38){		//	38を選択した場合の処理
			work = wk38;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 39){		//	39を選択した場合の処理
			work = wk39;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 40){		//	40を選択した場合の処理
			work = wk40;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 41){		//	41を選択した場合の処理
			work = wk41;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 42){		//	42を選択した場合の処理
			work = wk42;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 43){		//	43を選択した場合の処理
			work = wk43;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 44){		//	44を選択した場合の処理
			work = wk44;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 45){		//	45を選択した場合の処理
			work = wk45;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 46){		//	46を選択した場合の処理
			work = wk46;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 47){		//	47を選択した場合の処理
			work = wk47;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 48){		//	48を選択した場合の処理
			work = wk48;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 49){		//	49を選択した場合の処理
			work = wk49;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 50){		//	50を選択した場合の処理
			work = wk50;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 51){		//	51を選択した場合の処理
			work = wk51;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 52){		//	52を選択した場合の処理
			work = wk52;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 53){		//	53を選択した場合の処理
			work = wk53;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 54){		//	54を選択した場合の処理
			work = wk54;			//	大域変数workに各モンスターの技の個数を代入
		}
		else if (st2 == 55){		//	55を選択した場合の処理
			work = wk55;			//	大域変数workに各モンスターの技の個数を代入
		}
		else{
			puts("エラー！！もう一度入力してください。");
			printf("name=%s: HP=%d: TP=%d: atk=%d: def=%d: spd=%d\n\n\n", name, HP, TP, atk, def, spd);
			flg0 = 1;
		}

		if (flg0 == 1){
			kloop = 1;
			kloop2 = 0;
		}
		else{
			kloop2 = 1;
		}

		while (kloop2 == 1){
			puts("選択したモンスターでいいですか？(1=YES:2=NO)");
			printf("name=%s: HP=%d: TP=%d: atk=%d: def=%d: spd=%d\n", name, HP, TP, atk, def, spd);
			scanf_s("%d", &st3);

			if (st3 == 1){
				kloop = 0;
				kloop2 = 0;
			}
			else if (st3 == 2){
				kloop = 1;
				kloop2 = 0;
			}
			else{
				puts("１か２を入力してください。");
				kloop2 = 1;
			}
		}
	}
}

//	CPUモンスター決定関数6
void CMST(){
	int flag = 0;
	char ch[5];

	if (flag == 0){
		srand((unsigned int)time(NULL));
		flag = 1;
	}

	r = (rand() % 55 + 1);

	puts("----CPU----");

	puts("モンスターを決めてください。");
	puts("1:ブルースライム 2:アイアンスライム 3:レッドスライム 4:怪魚 5:海グモ 6:海蛇");
	puts("7:魔法使い 8:コカトリス 9:ハービー 10:トレント 11:ゴブリン\n12:スケルトン 13:半獣狩人 14:鋼鉄魚人 15:コボルト 16:ゾンビ 17:オーガ");
	puts("18:グリフォン 19:コドラ 20:鉄砲魚 21:上魔道士 22:竜騎士 23:グレーターデーモン");
	puts("24:大王イカ 25:ドラゴンフライ 26:ファイアエレメンタル 27:コールドエレメンタル");
	puts("28:フレイムジャイアント 29:フロストジャイアント 30:ケルベロス 31:ヴァンパイアバット");
	puts("32:ミイラ男 33:ガーゴイル 34:バシリスク 35:ポイズンスネイク 36:ダークゴブリン");
	puts("37:下級ソルジャー 38:ワイバーン 39:人喰いシャーク 40:軍隊蟻 41:ジャイアントラット");
	puts("42:ゴースト 43:グレムリン 44:キングコブラ 45:下級忍者A 46:下級忍者B");
	puts("47:ゴーストナイト 48:翼竜 49:妖術士 50:リザードマン 51:グリーンスライム");
	puts("52:マッドマン 53:人喰い植物 54:ジャイアント 55:キマイラ");

	strcpy_s(name2, MC[r - 1].name);
	HP2 = MC[r - 1].HP;
	TP2 = MC[r - 1].TP;
	atk2 = MC[r - 1].atk;
	def2 = MC[r - 1].def;
	spd2 = MC[r - 1].spd;

	printf("name=%s: HP=%d: TP=%d: atk=%d: def=%d: spd=%d\n", name2, HP2, TP2, atk2, def2, spd2);

	puts("適当なキーを入力してください。");
	scanf_s("%s", ch, 5);
	
}

//	行動順決定をする関数
int Act(int Kcount){
	int ar = 0;
	int gensan = 0, gensan2 = 0;
	Kcount = -1;
	int flag = 0;					//	Kcountの値を取得したら他の処理をできなくするフラグ

	gensan = spd - spd2;			//	Player
	gensan2 = spd2 - spd;			//	CPU

	srand((unsigned int)time(NULL));

	ar = rand() % 10 + 1;

	if (gensan >= 100){
		Kcount = 0;					//	Playerが先攻
		flag = 1;
	}
	if (gensan2 >= 100){
		Kcount = 5;					//	CPUが先攻
		flag = 1;
	}
	if (gensan >= 80 && flag == 0){
		switch (ar){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			Kcount = 0;			//	Playerが先攻
			break;
		case 10:
			Kcount = 5;			//	CPUが先攻
			break;
		}
		flag = 1;
	}
	if (gensan2 >= 80 && flag == 0){
		switch (ar){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			Kcount = 5;			//	CPUが先攻
			break;
		case 10:
			Kcount = 0;			//	Playerが先攻
			break;
		}
		flag = 1;
	}
	if (gensan >= 50 && flag == 0){
		switch (ar){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			Kcount = 0;			//	Playerが先攻
			break;
		case 9:
		case 10:
			Kcount = 5;			//	CPUが先攻
			break;
		}
		flag = 1;
	}
	if (gensan2 >= 50 && flag == 0){
		switch (ar){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			Kcount = 5;			//	CPUが先攻
			break;
		case 9:
		case 10:
			Kcount = 0;			//	Playerが先攻
			break;
		}
		flag = 1;
	}
	if (gensan >= 30 && flag == 0){
		switch (ar){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			Kcount = 0;			//	Playerが先攻
			break;
		case 8:
		case 9:
		case 10:
			Kcount = 5;			//	CPUが先攻
			break;
		}
		flag = 1;
	}
	if (gensan2 >= 30 && flag == 0){
		switch (ar){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			Kcount = 5;			//	CPUが先攻
			break;
		case 8:
		case 9:
		case 10:
			Kcount = 0;			//	Playerが先攻
			break;
		}
		flag = 1;
	}
	if (gensan >= 1 && flag == 0){
		switch (ar){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			Kcount = 0;			//	Playerが先攻
			break;
		case 7:
		case 8:
		case 9:
		case 10:
			Kcount = 5;			//	CPUが先攻
			break;
		}
		flag = 1;
	}
	if (gensan2 >= 1 && flag == 0){
		switch (ar){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			Kcount = 5;			//	CPUが先攻
			break;
		case 7:
		case 8:
		case 9:
		case 10:
			Kcount = 0;			//	Playerが先攻
			break;
		}
		flag = 1;
	}

	if (spd == spd2){
		switch (ar){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			Kcount = 0;			//	Playerが先攻
			break;
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
			Kcount = 5;			//	CPUが先攻
			break;
		}
	}

	return Kcount;
}

//	特殊攻撃用のダメージ計算関数(Player)
int PSAD(){
	int r8 = 0, r9 = 0;			//	乱数を得る変数(正負かどうか、ダメージが正負になるかどうか)
	int gensan5 = 0;
	st3 = 0, st4 = 0, st5 = 0, st6 = 0, st7 = 0, st8 = 0, st9 = 0, st10 = 0;
	st11 = 0, st12 = 0, st13 = 0, st14 = 0, st15 = 0, st16 = 0, st17 = 0, st18 = 0;
	st19 = 0, st20 = 0, st21 = 0, st22 = 0, st23 = 0, st24 = 0, st25 = 0, st26 = 0;
	st27 = 0, st28 = 0, st29 = 0, st30 = 0, st31 = 0, st32 = 0, st33 = 0, st34 = 0;
	st35 = 0, st36 = 0, st37 = 0, st38 = 0, st39 = 0, st40 = 0, st41 = 0, st42 = 0;
	st43 = 0, st44 = 0, st45 = 0, st46 = 0, st47 = 0, st48 = 0, st49 = 0, st50 = 0;
	st51 = 0, st52 = 0, st53 = 0, st54 = 0, st55 = 0;

	srand((unsigned int)time(NULL));

	r8 = (rand() % 2 + 1);

	srand((unsigned int)time(NULL));

	if (r8 == 1){		//	r8が１の場合
		r9 = (rand() % 20 + 1);
	}
	else{				//	r8が２の場合
		r9 = (rand() % -20 - 1);
	}

	//	Fire,Blizzard,thunderが使用された場合の処理
	if (flag10 == 1){
		gensan5 = ((atk - def2) + r9) * (double)1.3;
		HP2 = HP2 - gensan5;
		printf("CPUに%dのダメージ!\n", gensan5);
	}
	//	FireSword,BlizzardSword, ThunderSwordが使用された場合の処理
	if (flag11 == 1){
		gensan5 = ((atk - def2) + r9) * (double)1.2;
		HP2 = HP2 - gensan5;
		printf("CPUに%dのダメージ!\n", gensan5);
	}
	//	痛恨の一撃が使用された場合の処理
	if (flag12 == 1){
		gensan5 = ((atk - def2) + r9) * (double)1.5;
		HP2 = HP2 - gensan5;
		printf("痛恨の一撃！CPUに%dのダメージ!\n", gensan5);
	}
	//	ジャンプ攻撃が使用された場合の処理
	if (flag13 == 1){
		gensan5 = ((atk - def2) + r9) * (double)1.25;
		HP2 = HP2 - gensan5;
		printf("CPUに%dのダメージ!\n", gensan5);
	}
	//	メテオが使用された場合の処理
	if (flag14 == 1){
		gensan5 = ((atk - def2) + r9) * (double)3;
		HP2 = HP2 - gensan5;
		printf("CPUに%dのダメージ!\n", gensan5);
	}
	//	突進が使用された場合の処理
	if (flag15 == 1){
		gensan5 = ((atk - def2) + r9) * (double)1.1;
		HP2 = HP2 - gensan5;
		printf("CPUに%dのダメージ!\n", gensan5);
	}
	//	ファイアブレス、コールドブレス、サンダーブレスが使用された場合の処理
	if (flag16 == 1){
		gensan5 = ((atk - def2) + r9) * (double)1.25;
		HP2 = HP2 - gensan5;
		printf("CPUに%dのダメージ!\n", gensan5);
	}
	//	ヘルファイア、ダイヤモンドダストが使用された場合の処理
	if (flag025 == 1){
		gensan5 = ((atk - def2) + r9) * (double)1.4;
		HP2 = HP2 - gensan5;
		printf("CPUに%dのダメージ!\n", gensan5);
	}

	return HP2;
}

//	特殊攻撃用のダメージ計算関数(CPU)
int CSAD(){
	int r10 = 0, r11 = 0;			//	乱数を得る変数(正負かどうか、ダメージが正負になるかどうか)
	int gensan6 = 0;

	srand((unsigned int)time(NULL));

	r10 = (rand() % 2 + 1);

	srand((unsigned int)time(NULL));

	if (r10 == 1){		//	r8が１の場合
		r11 = (rand() % 20 + 1);
	}
	else{				//	r8が２の場合
		r11 = (rand() % -20 - 1);
	}

	//	Fire,Blizzard,thunderが使用された場合の処理
	if (flag30 == 1){
		gensan6 = ((atk2 - def) + r11) * 1.3;
		HP = HP - gensan6;
		printf("Playerに%dのダメージ！\n", gensan6);
	}
	//	FireSword,BlizzardSword, ThunderSwordが使用された場合の処理
	if (flag31 == 1){
		gensan6 = ((atk2 - def) + r11) * 1.2;
		HP = HP - gensan6;
		printf("Playerに%dのダメージ！\n", gensan6);
	}
	//	痛恨の一撃が使用された場合の処理
	if (flag32 == 1){
		gensan6 = ((atk2 - def) + r11) * 1.5;
		HP = HP - gensan6;
		printf("痛恨の一撃！Playerに%dのダメージ！\n", gensan6);
	}
	//	ジャンプ攻撃が使用された場合の処理
	if (flag33 == 1){
		gensan6 = ((atk2 - def) + r11) * 1.25;
		HP = HP - gensan6;
		printf("Playerに%dのダメージ！\n", gensan6);
	}
	//	メテオが使用された場合の処理
	if (flag34 == 1){
		gensan6 = ((atk2 - def) + r11) * 3;
		HP = HP - gensan6;
		printf("Playerに%dのダメージ！\n", gensan6);
	}
	//	突進が使用された場合の処理
	if (flag35 == 1){
		gensan6 = ((atk2 - def) + r11) * 1.1;
		HP = HP - gensan6;
		printf("Playerに%dのダメージ！\n", gensan6);
	}
	//	ファイアブレス、コールドブレス、サンダーブレスが使用された場合の処理
	if (flag36 == 1){
		gensan6 = ((atk2 - def) + r11) * 1.25;
		HP = HP - gensan6;
		printf("Playerに%dのダメージ！\n", gensan6);
	}
	//	ヘルファイア、ダイヤモンドダストが使用された場合の処理
	if (flag40 == 1){
		gensan6 = ((atk2 - def) + r11) * (double)1.4;
		HP = HP - gensan6;
		printf("Playerに%dのダメージ!\n", gensan6);
	}

	flag30 = 0, flag31 = 0, flag32 = 0, flag33 = 0, flag34 = 0;
	flag35 = 0, flag36 = 0, flag37 = 0, flag38 = 0, flag39 = 0;
	flag40 = 0, flag41 = 0, flag42 = 0, flag43 = 0;
	flag25 = 0, flag26 = 0, flag27 = 0, flag28 = 0, flag29 = 0;

	return HP;
}

void PSAas(){		//	Player
	st3 = 0, st4 = 0, st5 = 0, st6 = 0, st7 = 0, st8 = 0, st9 = 0, st10 = 0;
	st11 = 0, st12 = 0, st13 = 0, st14 = 0, st15 = 0, st16 = 0, st17 = 0, st18 = 0;
	st19 = 0, st20 = 0, st21 = 0, st22 = 0, st23 = 0, st24 = 0, st25 = 0, st26 = 0;
	st27 = 0, st28 = 0, st29 = 0, st30 = 0, st31 = 0, st32 = 0, st33 = 0, st34 = 0;
	st35 = 0, st36 = 0, st37 = 0, st38 = 0, st39 = 0, st40 = 0, st41 = 0, st42 = 0;
	st43 = 0, st44 = 0, st45 = 0, st46 = 0, st47 = 0, st48 = 0, st49 = 0, st50 = 0;
	st51 = 0, st52 = 0, st53 = 0, st54 = 0, st55 = 0;

	//	シールドが使用された場合の処理
	if (flag20 == 1){
		def = def * 1.10;
		printf("Playerは防御力が上がった！\n");
	}
	//	シールドダウンが使用された場合の処理
	if (flag21 == 1){
		def2 = def2 * 0.8;
		printf("CPUは防御力が下がった！\n");
	}
	//	スピードアップが使用された場合の処理
	if (flag22 == 1){
		spd = spd * 1.15;
		printf("Playerは素早さが上がった！\n");
	}
	//	スピードダウンが使用された場合の処理
	if (flag23 == 1){
		spd2 = spd2 * 0.8;
		printf("CPUは素早さが下がった！\n");
	}
	//	鉄壁が使用された場合の処理
	if (flag24 == 1){
		def = def * 1.2;
		printf("Playerは防御力が上がった！\n");
	}
}

void CSAas(){		//	CPU
	//	シールドが使用された場合の処理
	if (flag25 == 1){
		def2 = def2 * 1.10;
		printf("CPUは防御力が上がった！\n");
	}
	//	シールドダウンが使用された場合の処理
	if (flag26 == 1){
		def = def * 0.8;
		printf("Playerは防御力が下がった！\n");
	}
	//	スピードアップが使用された場合の処理
	if (flag27 == 1){
		spd2 = spd2 * 1.15;
		printf("CPUは素早さが上がった！\n");
	}
	//	スピードダウンが使用された場合の処理
	if (flag28 == 1){
		spd = spd * 0.8;
		printf("Playerは素早さが下がった！\n");
	}
	//	鉄壁が使用された場合の処理
	if (flag29 == 1){
		def2 = def2 * 1.2;
		printf("CPUは防御力が上がった！\n");
	}

	flag30 = 0, flag31 = 0, flag32 = 0, flag33 = 0, flag34 = 0;
	flag35 = 0, flag36 = 0, flag37 = 0, flag38 = 0, flag39 = 0;
	flag40 = 0, flag41 = 0, flag42 = 0, flag43 = 0;
	flag25 = 0, flag26 = 0, flag27 = 0, flag28 = 0, flag29 = 0;
}

//	-----------Player専用関数～-------------------
void FireSword(){
	if (TP < 3){
		puts("TPがありません。");
	}
	else{
		puts("ファイアソードを繰り出した！");
		HP2 = PSAD();
		TP -= 3;
	}
}

void BlizzardSword(){
	if (TP < 3){
		puts("TPがありません。");
	}
	else{
		puts("ブリザードソードを繰り出した！");
		HP2 = PSAD();
		TP -= 3;
	}
}

void ThunderSword(){
	if (TP < 3){
		puts("TPがありません。");
	}
	else{
		puts("サンダーソードを繰り出した！");
		HP2 = PSAD();
		TP -= 3;
	}
}

void Fire(){
	if (TP < 5){
		puts("TPがありません。");
	}
	else{
		puts("ファイアを唱えた！");
		HP2 = PSAD();
		TP -= 5;
	}
}

void Blizzard(){
	if (TP < 5){
		puts("TPがありません。");
	}
	else{
		puts("ブリザードを唱えた！");
		HP2 = PSAD();
		TP -= 5;
	}
}

void Thunder(){
	if (TP < 5){
		puts("TPがありません。");
	}
	else{
		puts("サンダーを唱えた！");
		HP2 = PSAD();
		TP -= 5;
	}
}

void WindSlash(){
	if (TP < 5){
		puts("TPがありません。");
	}
	else{
		puts("ウィンドスラッシュを唱えた！");
		HP2 = PSAD();
		TP -= 5;
	}
}

void Shield(){
	if (TP < 7){
		puts("TPがありません。");
	}
	else{
		puts("シールドを唱えた！");
		PSAas();
		TP -= 7;
	}
}

void ShieldDown(){
	if (TP < 7){
		puts("TPがありません。");
	}
	else{
		puts("シールドダウンを唱えた！");
		PSAas();
		TP -= 7;
	}
}

void Meteo(){
	if (TP < 35){
		puts("TPがありません。");
	}
	else{
		puts("メテオを唱えた！");
		HP2 = PSAD();
		TP -= 35;
	}
}

void SpeedUp(){
	if (TP < 5){
		puts("TPがありません。");
	}
	else{
		puts("スピードアップを唱えた！");
		PSAas();
		TP -= 5;
	}
}

void SpeedDown(){
	if (TP < 5){
		puts("TPがありません。");
	}
	else{
		puts("スピードダウンを唱えた！");
		PSAas();
		TP -= 5;
	}
}

//	痛恨の一撃
void Regret(){
	if (TP < 6){
		puts("TPがありません。");
	}
	else{
		HP2 = PSAD();
		TP -= 6;
	}
}

void JumpAttack(){
	if (TP < 5){
		puts("TPがありません。");
	}
	else{
		puts("ジャンプアタックを繰り出した！");
		HP2 = PSAD();
		TP -= 5;
	}
}

void IronWall(){
	if (TP < 20){
		puts("TPがありません。");
	}
	else{
		puts("鉄壁で更に防御を固めた！");
		PSAas();
		TP -= 20;
	}
}

//	突進
void Rush(){
	if (TP < 3){
		puts("TPがありません。");
	}
	else{
		puts("突進を繰り出した！");
		HP2 = PSAD();
		TP -= 3;
	}
}

void FireBreath(){
	if (TP < 5){
		puts("TPがありません。");
	}
	else{
		puts("ファイアブレスを吐いた！");
		HP2 = PSAD();
		TP -= 5;
	}
}

void ColdBreath(){
	if (TP < 5){
		puts("TPがありません。");
	}
	else{
		puts("コールドブレスを吐いた！");
		HP2 = PSAD();
		TP -= 5;
	}
}

void ThunderBreath(){
	if (TP < 5){
		puts("TPがありません。");
	}
	else{
		puts("サンダーブレスを吐いた！");
		HP2 = PSAD();
		TP -= 5;
	}
}

void ElementalSword(){
	if (TP < 6 || TP2 < 6){
		puts("TPがありません。");
	}
	else{
	}
}

void HellFire(){
	if (TP < 8){
		puts("TPがありません。");
	}
	else{
		puts("ヘルファイアを唱えた！");
		HP2 = PSAD();
		TP -= 8;
	}
}

void DiamondDust(){
	if (TP < 8){
		puts("TPがありません。");
	}
	else{
		puts("ダイヤモンドダストを唱えた！");
		HP2 = PSAD();
		TP -= 8;
	}
}

void ThunderBlast(){
	if (TP < 10 || TP2 < 10){
		puts("TPがありません。");
	}
	else{
	}
}

//	-----------CPU専用の関数～-----------------
void CFireSword(){
	if (TP2 < 3){
		puts("TPがありません。");
	}
	else{
		puts("ファイアソードを繰り出した！");
		HP = CSAD();
		TP2 -= 3;
	}
}

void CBlizzardSword(){
	if (TP2 < 3){
		puts("TPがありません。");
	}
	else{
		puts("ブリザードソードを繰り出した！");
		HP = CSAD();
		TP2 -= 3;
	}
}

void CThunderSword(){
	if (TP2 < 3){
		puts("TPがありません。");
	}
	else{
		puts("サンダーソードを繰り出した！");
		HP = CSAD();
		TP2 -= 3;
	}
}

void CFire(){
	if (TP2 < 5){
		puts("TPがありません。");
	}
	else{
		puts("ファイアを唱えた！");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CBlizzard(){
	if (TP2 < 5){
		puts("TPがありません。");
	}
	else{
		puts("ブリザードを唱えた！");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CThunder(){
	if (TP2 < 5){
		puts("TPがありません。");
	}
	else{
		puts("サンダーを唱えた！");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CWindSlash(){
	if (TP2 < 5){
		puts("TPがありません。");
	}
	else{
		puts("ウィンドスラッシュを唱えた！");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CShield(){
	if (TP2 < 7){
		puts("TPがありません。");
	}
	else{
		puts("シールドを唱えた！");
		CSAas();
		TP2 -= 7;
	}
}

void CShieldDown(){
	if (TP2 < 7){
		puts("TPがありません。");
	}
	else{
		puts("シールドダウンを唱えた！");
		CSAas();
		TP2 -= 7;
	}
}

void CMeteo(){
	if (TP2 < 35){
		puts("TPがありません。");
	}
	else{
		puts("メテオを唱えた！");
		HP = CSAD();
		TP2 -= 35;
	}
}

void CSpeedUp(){
	if (TP2 < 5){
		puts("TPがありません。");
	}
	else{
		puts("スピードアップを唱えた！");
		CSAas();
		TP2 -= 5;
	}
}

void CSpeedDown(){
	if (TP2 < 5){
		puts("TPがありません。");
	}
	else{
		puts("スピードダウンを唱えた！");
		CSAas();
		TP2 -= 5;
	}
}

//	痛恨の一撃
void CRegret(){
	if (TP2 < 6){
		puts("TPがありません。");
	}
	else{
		HP = CSAD();
		TP2 -= 6;
	}
}

void CJumpAttack(){
	if (TP2 < 5){
		puts("TPがありません。");
	}
	else{
		puts("ジャンプアタックを繰り出した！");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CIronWall(){
	if (TP2 < 20){
		puts("TPがありません。");
	}
	else{
		puts("鉄壁で更に防御を固めた！");
		CSAas();
		TP2 -= 20;
	}
}

//	突進
void CRush(){
	if (TP2 < 3){
		puts("TPがありません。");
	}
	else{
		puts("突進を繰り出した！");
		HP = CSAD();
		TP2 -= 3;
	}
}

void CFireBreath(){
	if (TP2 < 5){
		puts("TPがありません。");
	}
	else{
		puts("ファイアブレスを吐いた！");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CColdBreath(){
	if (TP2 < 5){
		puts("TPがありません。");
	}
	else{
		puts("コールドブレスを吐いた！");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CThunderBreath(){
	if (TP2 < 5){
		puts("TPがありません。");
	}
	else{
		puts("サンダーブレスを吐いた！");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CElementalSword(){
	if (TP2 < 6){
		puts("TPがありません。");
	}
	else{
	}
}

void CHellFire(){
	if (TP2 < 8){
		puts("TPがありません。");
	}
	else{
		puts("ヘルファイアを唱えた！");
		HP = CSAD();
		TP2 -= 8;
	}
}

void CDiamondDust(){
	if (TP2 < 8){
		puts("TPがありません。");
	}
	else{
		puts("ダイヤモンドダストを唱えた！");
		HP = CSAD();
		TP2 -= 8;
	}
}

void CThunderBlast(){
	if (TP2 < 10){
		puts("TPがありません。");
	}
	else{
	}
}

//	特殊技(Player専用)
void SpecialAttack(){
	flag10 = 0, flag11 = 0, flag12 = 0, flag13 = 0, flag14 = 0, flag15 = 0;
	flag15 = 0, flag16 = 0, flag20 = 0, flag21 = 0, flag22 = 0, flag23 = 0, flag24 = 0;
	flag025 = 0;

	//	特殊攻撃ファイアの処理
	if (st3 == 1 || st4 == 1 || st9 == 1 || st11 == 1 || st18 == 1 || st21 == 1 || st26 == 1 || st42 == 1 || st43 == 1){
		flag10 = 1;
		Fire();
	}
	//	特殊攻撃ブリザードの処理
	if (st6 == 1 || st9 == 2 || st11 == 2 || st12 == 1 || st21 == 2 || st24 == 1 || st27 == 1 || st42 == 2 || st43 == 2 || st51 == 1){
		flag10 = 1;
		Blizzard();
	}
	//	特殊攻撃サンダーの処理
	if (st4 == 2 || st9 == 3 || st10 == 1 || st11 == 3 || st12 == 2 || st18 == 2 || st21 == 3 || st37 == 4 || st42 == 3){
		flag10 = 1;
		Thunder();
	}
	//	特殊攻撃ウィンドスラッシュの処理
	if (st9 == 4 || st10 == 2 || st17 == 4 || st22 == 3 || st23 == 2 || st31 == 3 || st33 == 3 || st42 == 4 || st46 == 1){
		flag10 = 1;
		WindSlash();
	}
	//	特殊攻撃ファイアソードの処理
	if (st14 == 1 || st22 == 2 || st33 == 1 || st37 == 1 || st47 == 1){
		flag11 = 1;
		FireSword();
	}
	//	特殊攻撃ブリザードソードの処理
	if (st14 == 2 || st37 == 2 || st47 == 2 || st50 == 2){
		flag11 = 1;
		BlizzardSword();
	}
	//	特殊攻撃サンダーソードの処理
	if (st14 == 3 || st17 == 2 || st33 == 2 || st37 == 3 || st47 == 3 || st50 == 3){
		flag11 = 1;
		ThunderSword();
	}
	//	特殊攻撃,痛恨の一撃の処理
	if (st11 == 4 || st13 == 1 || st25 == 3 || st29 == 3 || st30 == 2 || st40 == 2 || st44 == 2 || st50 == 4 || st52 == 2 || st53 == 2 || st54 == 1){
		flag12 = 1;
		Regret();
	}
	//	特殊攻撃、ジャンプ攻撃の処理
	if (st13 == 2 || st14 == 4 || st17 == 1 || st36 == 1 || st37 == 5 || st45 == 2 || st46 == 2 || st50 == 1){
		flag13 = 1;
		JumpAttack();
	}
	//	特殊攻撃、メテオの処理
	if (st9 == 5 || st21 == 4 || st49 == 1){
		flag14 = 1;
		Meteo();
	}
	//	特殊攻撃、突進の処理
	if (st5 == 1 || st20 == 1 || st25 == 2 || st30 == 1 || st35 == 1 || st39 == 2 || st41 == 1 || st48 == 2 || st52 == 1){
		flag15 = 1;
		Rush();
	}
	//	特殊攻撃、ファイアブレスの処理
	if (st5 == 2 || st19 == 1 || st21 == 9 || st22 == 1 || st25 == 1 || st26 == 2 || st28 == 1 || st38 == 1 || st48 == 1){
		flag16 = 1;
		FireBreath();
	}
	//	特殊攻撃、コールドブレスの処理
	if (st18 == 5 || st19 == 2 || st20 == 2 || st24 == 2 || st29 == 1 || st31 == 1 || st38 == 2 || st39 == 1 || st47 == 4 || st55 == 2){
		flag16 = 1;
		ColdBreath();
	}
	//	特殊攻撃、サンダーブレスの処理
	if (st19 == 3 || st23 == 3 || st34 == 1 || st38 == 3 || st53 == 1){
		flag16 = 1;
		ThunderBreath();
	}
	//	補助特殊技、シールドの処理
	if (st4 == 3 || st7 == 1 || st8 == 1 || st9 == 6 || st10 == 3 || st12 == 3 || st21 == 5 || st27 == 2 || st40 == 3 || st43 == 3 || st49 == 2){
		flag20 = 1;
		Shield();
	}
	//	補助特殊技、シールドダウンの処理
	if (st3 == 2 || st8 == 2 || st12 == 4 || st15 == 1 || st17 == 3 || st18 == 3 || st21 == 6 || st33 == 4 || st35 == 2 || st37 == 6 || st44 == 1 || st46 == 3 || st49 == 3){
		flag21 = 1;
		ShieldDown();
	}
	//	補助特殊技、スピードアップの処理
	if (st7 == 2 || st9 == 7 || st10 == 4 || st18 == 4 || st21 == 7 || st29 == 2 || st31 == 2 || st39 == 3 || st42 == 6 || st43 == 4 || st45 == 1 || st49 == 4){
		flag22 = 1;
		SpeedUp();
	}
	//	補助特殊技、スピードダウンの処理
	if (st7 == 3 || st9 == 8 || st15 == 2 || st16 == 1 || st21 == 8 || st22 == 4 || st27 == 3 || st34 == 2 || st49 == 5 || st51 == 2){
		flag23 = 1;
		SpeedDown();
	}
	//	補助特殊技、鉄壁の処理
	if (st4 == 4 || st40 == 1){
		flag24 = 1;
		IronWall();
	}
	//	特殊攻撃、ヘルファイアの処理
	if (st21 == 10 || st23 == 1){
		flag025 = 1;
		HellFire();
	}
	//	特殊攻撃、ダイヤモンドダストの処理
	if (st42 == 5 || st55 == 1){
		flag025 = 1;
		DiamondDust();
	}
}

//	特殊技(CPU専用)
void CSpecialAttack(){
	flag25 = 0, flag26 = 0, flag27 = 0, flag28 = 0, flag29 = 0, flag30 = 0;
	flag31 = 0, flag32 = 0, flag33 = 0, flag34 = 0, flag35 = 0, flag36 = 0;

	//	特殊攻撃ファイアの処理
	if (r13 == 1 || r14 == 1 || r19 == 1 || r21 == 1 || r28 == 1 || r31 == 1 || r36 == 1 || r52 == 1 || r53 == 1){
		flag30 = 1;
		CFire();
	}
	//	特殊攻撃ブリザードの処理
	if (r16 == 1 || r19 == 2 || r21 == 2 || r22 == 1 || r31 == 2 || r34 == 1 || r37 == 1 || r52 == 2 || r53 == 2 || r61 == 1){
		flag30 = 1;
		CBlizzard();
	}
	//	特殊攻撃サンダーの処理
	if (r14 == 2 || r19 == 3 || r20 == 1 || r21 == 3 || r22 == 2 || r28 == 2 || r31 == 3 || r47 == 4 || r52 == 3){
		flag30 = 1;
		CThunder();
	}
	//	特殊攻撃ウィンドスラッシュの処理
	if (r19 == 4 || r20 == 2 || r27 == 4 || r32 == 3 || r33 == 2 || r41 == 3 || r43 == 3 || r52 == 4 || r56 == 1){
		flag30 = 1;
		CWindSlash();
	}
	//	特殊攻撃ファイアソードの処理
	if (r24 == 1 || r32 == 2 || r43 == 1 || r47 == 1 || r57 == 1){
		flag31 = 1;
		CFireSword();
	}
	//	特殊攻撃ブリザードソードの処理
	if (r24 == 2 || r47 == 2 || r57 == 2 || r60 == 2){
		flag31 = 1;
		CBlizzardSword();
	}
	//	特殊攻撃サンダーソードの処理
	if (r24 == 3 || r27 == 2 || r43 == 2 || r47 == 3 || r57 == 3 || r60 == 3){
		flag31 = 1;
		CThunderSword();
	}
	//	特殊攻撃,痛恨の一撃の処理
	if (r21 == 4 || r23 == 1 || r35 == 3 || r39 == 3 || r40 == 2 || r50 == 2 || r54 == 2 || r60 == 4 || r62 == 2 || r63 == 2 || r64 == 1){
		flag32 = 1;
		CRegret();
	}
	//	特殊攻撃、ジャンプ攻撃の処理
	if (r23 == 2 || r24 == 4 || r27 == 1 || r46 == 1 || r47 == 5 || r55 == 2 || r56 == 2 || r60 == 1){
		flag33 = 1;
		CJumpAttack();
	}
	//	特殊攻撃、メテオの処理
	if (r19 == 5 || r31 == 4 || r59 == 1){
		flag34 = 1;
		CMeteo();
	}
	//	特殊攻撃、突進の処理
	if (r15 == 1 || r30 == 1 || r35 == 2 || r40 == 1 || r45 == 1 || r49 == 2 || r51 == 1 || r58 == 2 || r62 == 1){
		flag35 = 1;
		CRush();
	}
	//	特殊攻撃、ファイアブレスの処理
	if (r29 == 1 || r15 == 2 || r31 == 9 || r32 == 1 || r35 == 1 || r36 == 2 || r38 == 1 || r48 == 1 || r58 == 1){
		flag36 = 1;
		CFireBreath();
	}
	//	特殊攻撃、コールドブレスの処理
	if (r28 == 5 || r29 == 2 || r30 == 2 || r34 == 2 || r39 == 1 || r41 == 1 || r48 == 2 || r49 == 1 || r57 == 4 || r65 == 2){
		flag36 = 1;
		CColdBreath();
	}
	//	特殊攻撃、サンダーブレスの処理
	if (r29 == 3 || r33 == 3 || r44 == 1 || r48 == 3 || r63 == 1){
		flag36 = 1;
		CThunderBreath();
	}
	//	補助特殊技、シールドの処理
	if (r14 == 3 || r17 == 1 || r18 == 1 || r19 == 6 || r20 == 3 || r22 == 3 || r31 == 5 || r37 == 2 || r50 == 3 || r53 == 3 || r59 == 2){
		flag25 = 1;
		CShield();
	}
	//	補助特殊技、シールドダウンの処理
	if (r13 == 2 || r18 == 2 || r22 == 4 || r25 == 1 || r27 == 3 || r28 == 3 || r31 == 6 || r43 == 4 || r45 == 2 || r47 == 6 || r54 == 1 || r56 == 3 || r59 == 3){
		flag26 = 1;
		CShieldDown();
	}
	//	補助特殊技、スピードアップの処理
	if (r17 == 2 || r19 == 7 || r20 == 4 || r28 == 4 || r31 == 7 || r39 == 2 || r41 == 2 || r49 == 3 || r52 == 6 || r53 == 4 || r55 == 1 || r59 == 4){
		flag27 = 1;
		CSpeedUp();
	}
	//	補助特殊技、スピードダウンの処理
	if (r17 == 3 || r19 == 8 || r25 == 2 || r26 == 1 || r31 == 8 || r32 == 4 || r37 == 3 || r44 == 2 || r59 == 5 || r61 == 2){
		flag28 = 1;
		CSpeedDown();
	}
	//	補助特殊技、鉄壁の処理
	if (r14 == 4 || r50 == 1){
		flag29 = 1;
		CIronWall();
	}
	//	特殊攻撃、ヘルファイアの処理
	if (r31 == 10 || r33 == 1){
		flag40 = 1;
		CHellFire();
	}
	//	特殊攻撃、ダイヤモンドダストの処理
	if (r52 == 5 || r65 == 1){
		flag40 = 1;
		CDiamondDust();
	}
}

//	関数BookStoreで購入した技を表示
void BScommand(){
	if (fg1 == 1 && sac == 1){		//	フラグが１で購入回数が1回目ならば
		printf("%d:ファイアソード", work);
	}
	else if (fg1 == 1 && sac == 2){							//	購入回数が2回目ならば
		printf("%d:ファイアソード", work);
	}

	if (fg2 == 1 && sac == 1){
		printf("%d:ブリザードソード", work);
	}
	else if (fg2 == 1 && sac == 2){
		printf("%d:ブリザードソード", work);
	}

	if (fg3 == 1 && sac == 1){
		printf("%d:サンダーソード", work);
	}
	else if (fg3 == 1 && sac == 2){
		printf("%d:サンダーソード", work);
	}

	if (fg4 == 1 && sac == 1){
		printf("%d:痛恨の一撃", work);
	}
	else if (fg4 == 1 && sac == 2){
		printf("%d:痛恨の一撃", work);
	}

	if (fg5 == 1 && sac == 1){
		printf("%d:ジャンプ攻撃", work);
	}
	else if (fg5 == 1 && sac == 2){
		printf("%d:ジャンプ攻撃", work);
	}

	if (fg6 == 1 && sac == 1){
		printf("%d:突進\n", work);
	}
	else if (fg6 == 1 && sac == 2){
		printf("%d:突進\n", work);
	}

	if (fg7 == 1 && sac == 1){
		printf("%d:ファイアブレス", work);
	}
	else if (fg7 == 1 && sac == 2){
		printf("%d:ファイアブレス", work);
	}
	if (fg8 == 1 && sac == 1){
		printf("%d:コールドブレス", work);
	}

	else if (fg8 == 1 && sac == 2){
		printf("%d:コールドブレス", work);
	}
	if (fg9 == 1 && sac == 1){
		printf("%d:サンダーブレス", work);
	}
	else if (fg9 == 1 && sac == 2){
		printf("%d:サンダーブレス", work);
	}

	if (fg10 == 1 && sac == 1){				//	使えるモンスターはなし
		printf("%d:エレメンタルソード", work);
	}
	else if (fg10 == 1 && sac == 2){
		printf("%d:エレメンタルソード", work);
	}

	if (fg11 == 1 && sac == 1){
		printf("%d:鉄壁", work);
	}
	else if (fg11 == 1 && sac == 2){
		printf("%d:鉄壁", work);
	}

	if (fg12 == 1 && sac == 1){
		printf("%d:ファイア", work);
	}
	else if (fg12 == 1 && sac == 2){
		printf("%d:ファイア", work);
	}

	if (fg13 == 1 && sac == 1){
		printf("%d:ブリザード", work);
	}
	else if (fg13 == 1 && sac == 2){
		printf("%d:ブリザード", work);
	}

	if (fg14 == 1 && sac == 1){
		printf("%d:サンダー", work);
	}
	else if (fg14 == 1 && sac == 2){
		printf("%d:サンダー", work);
	}

	if (fg15 == 1 && sac == 1){
		printf("%d:ウィンドスラッシュ", work);
	}
	else if (fg15 == 1 && sac == 2){
		printf("%d:ウィンドスラッシュ", work);
	}

	if (fg16 == 1 && sac == 1){
		printf("%d;シールド", work);
	}
	else if (fg16 == 1 && sac == 2){
		printf("%d;シールド", work);
	}

	if (fg17 == 1 && sac == 1){
		printf("%d;シールドダウン", work);
	}
	else if (fg17 == 1 && sac == 2){
		printf("%d;シールドダウン", work);
	}

	if (fg18 == 1 && sac == 1){
		printf("%d:スピードアップ", work);
	}
	else if (fg18 == 1 && sac == 2){
		printf("%d:スピードアップ", work);
	}

	if (fg19 == 1 && sac == 1){
		printf("%d:スピードダウン", work);
	}
	if (fg19 == 1 && sac == 2){
		printf("%d:スピードダウン", work);
	}
	printf("\n");
}

//	Player専用
void SAcommand(){
	st3 = 0, st4 = 0, st5 = 0, st6 = 0, st7 = 0;	//	SAcommandで技を選択するときに使用(st3～)(Player)
	st8 = 0, st9 = 0, st10 = 0, st11 = 0, st12 = 0;
	st13 = 0, st14 = 0, st15 = 0, st16 = 0, st17 = 0;
	st18 = 0, st19 = 0, st20 = 0, st21 = 0, st22 = 0;
	st23 = 0, st24 = 0, st25 = 0, st26 = 0, st27 = 0;
	st28 = 0, st29 = 0, st30 = 0, st31 = 0, st32 = 0;
	st33 = 0, st34 = 0, st35 = 0, st36 = 0, st37 = 0;
	st38 = 0, st39 = 0, st40 = 0, st41 = 0, st42 = 0;
	st43 = 0, st44 = 0, st45 = 0, st46 = 0, st47 = 0;
	st48 = 0, st49 = 0, st50 = 0, st51 = 0, st52 = 0;
	st53 = 0, st54 = 0, st55 = 0;
	flag = 0;										//	SAcommandで使用するフラグ

	puts("3=特殊技");

	//	ブルースライムの特殊技コマンド
	if (st2 == 1){
		puts("1:ファイア");
		puts("2:シールドダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st3);

		if ((st3 == 3 || st3 == 4) && TP <= 6){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
		}

		//	再入力フェーズ
		if (st3 != 1 && st3 != 2 && sac == 0){	//	技を購入していない場合
			printf("１か２を入力してください。\n");
			printf("\n");
			SAcommand();
		}
		if (sac == 1){
			if (st3 != 1 && st3 != 2 && st3 != 3){	//	１つ技を購入した場合
				printf("１～３までの数字を入力してください。\n");
				printf("\n");
				SAcommand();
			}
		}
		else if (sac == 2){
			if (st3 != 1 && st3 != 2 && st3 != 3 && st3 != 4){	//	２つ技を購入した場合
				printf("１～４までの数字を入力してください。\n");
				printf("\n");
				SAcommand();
			}
		}
	}
	//	アイアンスライムの特殊技コマンド
	if (st2 == 2){
		st4 = 0;

		puts("1:ファイア");
		puts("2:サンダー");
		puts("3:シールド");
		puts("4:鉄壁");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st4);

		if ((st4 == 3 || st4 == 4) && TP <= 6){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
		}
		if (st4 == 1 || st4 == 2 || st4 == 3 || st4 == 4){
			flag = 1;
		}
		else if ((st4 == 0 || st4 >= 5) && flag == 0){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			SAcommand();
		}
	}
	//	レッドスライム
	if (st2 == 3){
		puts("1:突進");
		puts("2:ファイアブレス");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st5);

		if (st5 != 1 && st5 != 2){
			printf("１か２を入力してください。\n");
			printf("\n");
			SAcommand();
		}
	}
	//	怪魚
	if (st2 == 4){
		puts("1:ブリザード");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st6);

		if (st6 != 1){
			printf("１を入力してください。\n");
			printf("\n");
			SAcommand();
		}
	}
	//	海グモ
	if (st2 == 5){
		puts("1:シールド");
		puts("2:スピードアップ");
		puts("3:スピードダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st7);

		if (st7 == 1 && TP <= 6){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
		}
		if (st7 == 1 || st7 == 2 || st7 == 3){
			flag = 1;
		}
		else if ((st7 == 0 || st7 >= 4) && flag == 0){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			SAcommand();
		}
	}
	//	海蛇
	if (st2 == 6){
		puts("1:シールド");
		puts("2:シールドダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st8);

		if (st8 != 1 && st8 != 2){
			printf("１か２を入力してください。\n");
			printf("\n");
			SAcommand();
		}
	}
	//	魔法使い
	if (st2 == 7){
		puts("1:ファイア");
		puts("2:ブリザード");
		puts("3:サンダー");
		puts("4:ウィンドスラッシュ");
		puts("5:メテオ");
		puts("6:シールド");
		puts("7:スピードアップ");
		puts("8:スピードダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st9);

		if ((st9 == 5 || st9 == 6) && TP <= 6){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
		}
		if (st9 == 5 && TP < 35){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
		}
		if (st9 == 1 || st9 == 2 || st9 == 3 || st9 == 4 || st9 == 5 || st9 == 6 || st9 == 7 || st9 == 8){
			flag = 1;
		}
		else if ((st9 == 0 || st9 >= 9) && flag == 0){
			puts("１～８までの数字を入力してください。");
			printf("\n");
			SAcommand();
		}
	}
	//	コカトリス
	if (st2 == 8){
		puts("1:サンダー");
		puts("2:ウィンドスラッシュ");
		puts("3:シールド");
		puts("4:スピードアップ");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st10);

		if (st10 != 1 && st10 != 2 && st10 != 3 && st10 != 4){
			printf("１～４までの数字を入力してください。\n");
			printf("\n");
			SAcommand();
		}
	}
	//	ハービー
	if (st2 == 9){
		puts("1:ファイア");
		puts("2:ブリザード");
		puts("3:サンダー");
		puts("4:痛恨の一撃");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st11);

		if (st11 == 4 && TP <= 5){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
		}
		if (st11 == 1 || st11 == 2 || st11 == 3 || st11 == 4){
			flag = 1;
		}
		else if ((st11 == 0 || st11 >= 5) && flag == 0){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			SAcommand();
		}
	}
	//	トレント
	if (st2 == 10){
		puts("1:ブリザード");
		puts("2:サンダー");
		puts("3:シールド");
		puts("4:シールドダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st12);

		if ((st12 == 3 || st12 == 4) && TP <= 6){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
		}
		if (st12 == 1 || st12 == 2 || st12 == 3 || st12 == 4){
			flag = 1;
		}
		else if ((st12 == 0 || st12 >= 5) && flag == 0){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			SAcommand();
		}
	}
	//	ゴブリン
	if (st2 == 11){
		puts("1:痛恨の一撃");
		puts("2:ジャンプ攻撃");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st13);

		if (st13 != 1 && st13 != 2){
			printf("１か２を入力してください。\n");
			printf("\n");
			SAcommand();
		}
	}
	//	スケルトン
	if (st2 == 12){
		puts("1:ファイアソード");
		puts("2:ブリザードソード");
		puts("3:サンダーソード");
		puts("4:ジャンプ攻撃");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st14);

		if (st14 == 4 && TP <= 4){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
		}
		if (st14 == 1 || st14 == 2 || st14 == 3 || st14 == 4){
			flag = 1;
		}
		else if ((st14 == 0 || st14 >= 5) && flag == 0){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			SAcommand();
		}
	}
	//	半獣狩人
	if (st2 == 13){
		puts("1:シールドダウン");
		puts("2:スピードダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st15);

		if (st15 != 1 && st15 != 2){
			printf("１か２を入力してください。\n");
			printf("\n");
			SAcommand();
		}
	}
	//	鋼鉄魚人
	if (st2 == 14){
		puts("1:スピードダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st16);

		if (st16 != 1){
			printf("１を入力してください。\n");
			printf("\n");
			SAcommand();
		}
	}
	//	コボルト
	if (st2 == 15){
		puts("1:ジャンプ攻撃");
		puts("2:サンダーソード");
		puts("3:シールドダウン");
		puts("4:ウィンドスラッシュ");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st17);

		if ((st17 == 1 || st17 == 3 || st17 == 4) && TP <= 4){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
		}
		if (st17 == 3 && TP <= 6){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
		}
		if (st17 == 1 || st17 == 2 || st17 == 3 || st17 == 4){
			flag = 1;
		}
		else if ((st17 == 0 || st17 >= 5) && flag == 0){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			SAcommand();
		}
	}
	//	グリフォン
	if (st2 == 18){
		puts("1:ファイア");
		puts("2:サンダー");
		puts("3:シールドダウン");
		puts("4:スピードアップ");
		puts("5:コールドブレス");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st18);

		if (st18 == 3 && TP <= 6){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
		}
		if (st18 == 1 || st18 == 2 || st18 == 3 || st18 == 4 || st18 == 5){
			flag = 1;
		}
		else if ((st18 == 0 || st18 >= 6) && flag == 0){
			puts("１～５までの数字を入力してください。");
			printf("\n");
			SAcommand();
		}
	}
	//	コドラ
	if (st2 == 19){
		puts("1:ファイアブレス");
		puts("2:コールドブレス");
		puts("3:サンダーブレス");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st19);

		if (st19 != 1 && st19 != 2 && st19 != 3){
			printf("１～３の数字を入力してください。\n");
			printf("\n");
			SAcommand();
		}
	}
	//	鉄砲魚
	if (st2 == 20){
		puts("1:突進");
		puts("2:コールドブレス");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st20);

		if (st20 == 2 && TP <= 4){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
		}
		if (st20 == 1 || st20 == 2){
			flag = 1;
		}
		else if ((st20 == 0 || st20 >= 3) && flag == 0){
			puts("１～２までの数字を入力してください。");
			printf("\n");
			SAcommand();
		}
	}
	//	上魔導士
	if (st2 == 21){
		puts("1:ファイア");
		puts("2:ブリザード");
		puts("3:サンダー");
		puts("4:メテオ");
		puts("5:シールド");
		puts("6:シールドダウン");
		puts("7:スピードアップ");
		puts("8:スピードダウン");
		puts("9:ファイアブレス");
		puts("10:ヘルファイア");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st21);

		if (st21 != 1 && st21 != 2 && st21 != 3 && st21 != 4 && st21 != 5 && st21 != 6 && st21 != 7 && st21 != 8 && st21 != 9 && st21 != 10){
			puts("１～１０までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st21 = 0;
		}

		if (st21 == 4 && TP < 35){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st21 = 0;
		}
		if (st21 == 10 && TP < 8){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st21 = 0;
		}
		if ((st21 == 5 || st21 == 6) && TP < 7){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st21 = 0;
		}
	}

	//	竜騎士
	if (st2 == 22){
		puts("1:ファイアブレス");
		puts("2:ファイアソード");
		puts("3:ウィンドスラッシュ");
		puts("4:スピードダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st22);

		if (st22 != 1 && st22 != 2 && st22 != 3 && st22 != 4){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st22 = 0;
		}

		if (st22 == 4 && TP < 7){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st22 = 0;
		}
		if ((st22 == 1 || st22 == 3) && TP < 5){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st22 = 0;
		}
	}
	//	グレーターデーモン
	if (st2 == 23){
		puts("1:ヘルファイア");
		puts("2:ウィンドスラッシュ");
		puts("3:サンダーブレス");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st23);

		if (st23 != 1 && st23 != 2 && st23 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st23 = 0;
		}

		if (st23 == 1 && TP < 8){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st23 = 0;
		}
	}
	//	大王イカ
	if (st2 == 24){
		puts("1:ブリザード");
		puts("2:コールドブレス");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st24);

		if (st24 != 1 && st24 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			SAcommand();
			st24 = 0;
		}
	}
	//	ドラゴンフライ
	if (st2 == 25){
		puts("1:ファイアブレス");
		puts("2:突進");
		puts("3:痛恨の一撃");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st25);

		if (st25 != 1 && st25 != 2 && st25 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st25 = 0;
		}
		if (st25 == 1 && TP < 5){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st25 = 0;
		}
		if (st25 == 3 && TP < 6){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st25 = 0;
		}
	}
	//	ファイアエレメンタル
	if (st2 == 26){
		puts("1:ファイア");
		puts("2:ファイアブレス");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st26);

		if (st26 != 1 && st26 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			SAcommand();
			st26 = 0;
		}

		if ((st26 == 1 || st26 == 2) && TP < 5){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st26 = 0;
		}
	}
	//	コールドエレメンタル
	if (st2 == 27){
		puts("1:ブリザード");
		puts("2:シールド");
		puts("3:スピードダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st27);

		if (st27 != 1 && st27 != 2 && st27 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st27 = 0;
		}

		if (st27 == 2 && TP < 7){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st27 = 0;
		}
	}
	//	フレイムジャイアント
	if (st2 == 28){
		puts("1:ファイアブレス");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st28);

		if (st28 != 1){
			puts("１を入力してください。");
			printf("\n");
			SAcommand();
			st28 = 0;
		}
	}
	//	フロストジャイアント
	if (st2 == 29){
		puts("1:コールドブレス");
		puts("2:スピードアップ");
		puts("3:痛恨の一撃");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st29);

		if (st29 != 1 && st29 != 2 && st29 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st29 = 0;
		}

		if (st29 == 3 && TP < 6){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st29 = 0;
		}
	}
	//	ケルベロス
	if (st2 == 30){
		puts("1:突進");
		puts("2:痛恨の一撃");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st30);

		if (st30 != 1 && st30 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			SAcommand();
			st30 = 0;
		}

		if (st30 == 2 && TP < 6){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st30 = 0;
		}
	}
	//	ヴァンパイアバット
	if (st2 == 31){
		puts("1:コールドブレス");
		puts("2:スピードアップ");
		puts("3:ウィンドスラッシュ");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st31);

		if (st31 != 1 && st31 != 2 && st31 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st31 = 0;
		}
	}
	//	ガーゴイル
	if (st2 == 33){
		puts("1:ファイアソード");
		puts("2:サンダーソード");
		puts("3:ウィンドスラッシュ");
		puts("4:シールドダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st33);

		if (st33 != 1 && st33 != 2 && st33 != 3 && st33 != 4){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st33 = 0;
		}

		if (st33 == 4 && TP < 7){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st33 = 0;
		}
		if (st33 == 3 && TP < 5){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st33 = 0;
		}
	}
	//	バシリスク
	if (st2 == 34){
		puts("1:サンダーブレス");
		puts("2:スピードダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st34);

		if (st34 != 1 && st34 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			SAcommand();
			st34 = 0;
		}

		if ((st34 == 1 || st34 == 2) && TP < 5){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st34 = 0;
		}
	}
	//	ポイズンスネイク
	if (st2 == 35){
		puts("1:突進");
		puts("2:シールドダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st35);

		if (st35 != 1 && st35 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			SAcommand();
			st35 = 0;
		}

		if (st35 == 2 && TP < 6){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st35 = 0;
		}
	}
	//	ダークゴブリン
	if (st2 == 36){
		puts("1:ジャンプ攻撃");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st36);

		if (st36 != 1){
			puts("１を入力してください。");
			printf("\n");
			SAcommand();
			st36 = 0;
		}
	}
	//	下級ソルジャー
	if (st2 == 37){
		puts("1:ファイアソード");
		puts("2:ブリザードソード");
		puts("3:サンダーソード");
		puts("4:サンダー");
		puts("5:ジャンプ攻撃");
		puts("6:シールドダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st37);

		if (st37 != 1 && st37 != 2 && st37 != 3 && st37 != 4 && st37 != 5 && st37 != 6){
			puts("１～６までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st37 = 0;
		}

		if ((st37 == 4 || st37 == 5) && TP < 5){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st37 = 0;
		}
		if (st37 == 6 && TP < 7){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st37 = 0;
		}
	}
	//	ワイバーン
	if (st2 == 38){
		puts("1:ファイアブレス");
		puts("2:コールドブレス");
		puts("3:サンダーブレス");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st38);

		if (st38 != 1 && st38 != 2 && st38 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st38 = 0;
		}
	}
	//	人食いシャーク
	if (st2 == 39){
		puts("1:コールドブレス");
		puts("2:突進");
		puts("3:スピードアップ");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st39);

		if (st39 != 1 && st39 != 2 && st39 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st39 = 0;
		}
	}
	//	軍隊蟻
	if (st2 == 40){
		puts("1:鉄壁");
		puts("2:痛恨の一撃");
		puts("3:シールド");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st40);

		if (st40 != 1 && st40 != 2 && st40 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st40 = 0;
		}
		if (st40 == 2 && TP < 6){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st40 = 0;
		}
	}
	//	ジャイアントラット
	if (st2 == 41){
		puts("1:突進");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st41);

		if (st41 != 1){
			puts("１を入力してください。");
			printf("\n");
			SAcommand();
			st41 = 0;
		}
	}
	//	ゴースト
	if (st2 == 42){
		puts("1:ファイア");
		puts("2:ブリザード");
		puts("3:サンダー");
		puts("4:ウィンドスラッシュ");
		puts("5:ダイヤモンドダスト");
		puts("6:スピードアップ");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st42);

		if (st42 != 1 && st42 != 2 && st42 != 3 && st42 != 4 && st42 != 5 && st42 != 6){
			puts("１～６での数字を入力してください。");
			printf("\n");
			SAcommand();
			st42 = 0;
		}
		if (st42 == 5 && TP < 8){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st42 = 0;
		}
	}
	//	グレムリン
	if (st2 == 43){
		puts("1:ファイア");
		puts("2:ブリザード");
		puts("3:シールド");
		puts("4:スピードアップ");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st43);

		if (st43 != 1 && st43 != 2 && st43 != 3 && st43 != 4){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st43 = 0;
		}
		if (st43 == 3 && TP < 7){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st43 = 0;
		}
	}
	//	キングコブラ
	if (st2 == 44){
		puts("1:シールドダウン");
		puts("2:痛恨の一撃");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st44);

		if (st44 != 1 && st44 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			SAcommand();
			st44 = 0;
		}
		if (st44 == 1 && TP < 7){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st44 = 0;
		}
	}
	//	下級忍者A
	if (st2 == 45){
		puts("1:スピードアップ");
		puts("2:ジャンプ攻撃");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st45);

		if (st45 != 1 && st45 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			SAcommand();
			st45 = 0;
		}
	}
	//	下級忍者B
	if (st2 == 46){
		puts("1:ウィンドスラッシュ");
		puts("2:ジャンプ攻撃");
		puts("3:シールドダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st46);

		if (st46 != 1 && st46 != 2 && st46 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st46 = 0;
		}
		if (st46 == 3 && TP < 7){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st46 = 0;
		}
	}
	//	ゴーストナイト
	if (st2 == 47){
		puts("1:ファイアソード");
		puts("2:ブリザードソード");
		puts("3:サンダーソード");
		puts("4:コールドブレス");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st47);

		if (st47 != 1 && st47 != 2 && st47 != 3 && st47 != 4){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st47 = 0;
		}
		if (st47 == 4 && TP < 5){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st47 = 0;
		}
	}
	//	翼竜
	if (st2 == 48){
		puts("1:ファイアブレス");
		puts("2:突進");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st48);

		if (st48 != 1 && st48 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			SAcommand();
			st48 = 0;
		}
		if (st48 == 1 && TP < 5){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st48 = 0;
		}
	}
	//	妖術師
	if (st2 == 49){
		puts("1:メテオ");
		puts("2:シールド");
		puts("3:シールドダウン");
		puts("4:スピードアップ");
		puts("5:スピードダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st49);

		if (st49 != 1 && st49 != 2 && st49 != 3 && st49 != 4 && st49 != 5){
			puts("１～５までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st49 = 0;
		}
		if (st49 == 1 && TP < 35){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st49 = 0;
		}
		if ((st49 == 2 || st49 == 3) && TP < 7){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st49 = 0;
		}
	}
	//	リザードマン
	if (st2 == 50){
		puts("1:ジャンプ攻撃");
		puts("2:ブリザードソード");
		puts("3:サンダーソード");
		puts("4:痛恨の一撃");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st50);

		if (st50 != 1 && st50 != 2 && st50 != 3 && st50 != 4){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			SAcommand();
			st50 = 0;
		}
		if (st50 == 1 && TP < 5){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st50 = 0;
		}
		if (st50 == 4 && TP < 6){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st50 = 0;
		}
	}
	//	グリーンスライム
	if (st2 == 51){
		puts("1:ブリザード");
		puts("2:スピードダウン");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st51);

		if (st51 != 1 && st51 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			SAcommand();
			st51 = 0;
		}
	}
	//	マッドマン
	if (st2 == 52){
		puts("1:突進");
		puts("2:痛恨の一撃");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st52);

		if (st52 != 1 && st52 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			SAcommand();
			st52 = 0;
		}
	}
	//	人喰い植物
	if (st2 == 53){
		puts("1:サンダーブレス");
		puts("2:痛恨の一撃");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st53);

		if (st53 != 1 && st53 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			SAcommand();
			st53 = 0;
		}
		if (st53 == 2 && TP < 6){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st53 = 0;
		}
	}
	//	ジャイアント
	if (st2 == 54){
		puts("1:痛恨の一撃");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st54);

		if (st54 != 1){
			puts("１を入力してください。");
			printf("\n");
			SAcommand();
			st54 = 0;
		}
	}
	//	キマイラ
	if (st2 == 55){
		puts("1:ダイヤモンドダスト");
		puts("2:コールドブレス");

		if (sac >= 1){
			BScommand();
		}

		printf("特定の数字を入力してください。--->");
		scanf_s("%d", &st55);

		if (st55 != 1 && st55 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			SAcommand();
			st55 = 0;
		}
		if (st55 == 1 && TP < 8){
			puts("TPが足りません。");
			printf("\n");
			SAcommand();
			st55 = 0;
		}
	}

	SpecialAttack();
}

void CSAcommand(){
	r13 = 0, r14 = 0, r15 = 0, r16 = 0, r17 = 0, r18 = 0, r19 = 0;
	r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0;
	r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0, r32 = 0, r33 = 0;
	r34 = 0, r35 = 0, r36 = 0, r37 = 0, r38 = 0, r39 = 0, r40 = 0;
	r41 = 0, r42 = 0, r43 = 0, r44 = 0, r45 = 0, r46 = 0, r47 = 0;
	r48 = 0, r49 = 0, r50 = 0, r51 = 0, r52 = 0, r53 = 0, r54 = 0;
	r55 = 0, r56 = 0, r57 = 0, r58 = 0, r59 = 0, r60 = 0, r61 = 0;
	r62 = 0, r63 = 0, r64 = 0, r65 = 0;

	//	ブルースライムの特殊技コマンド
	if (r == 1){
		puts("1:ファイア");
		puts("2:シールドダウン");
		r13 = (rand() % 2 + 1);

		if ((r13 == 1 && TP2 < 5) || (r13 == 2 && TP2 < 7)){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
		}
	}
	//	アイアンスライムの特殊技コマンド
	if (r == 2){
		puts("1:ファイア");
		puts("2:サンダー");
		puts("3:シールド");
		puts("4:鉄壁");
		r14 = (rand() % 4 + 1);

		if ((r14 == 3 || r14 == 4) && TP2 <= 6){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
		}
		if (r14 == 1 || r14 == 2 || r14 == 3 || r14 == 4){
			cflag = 1;
		}
		else if ((r14 == 0 || r14 >= 5) && cflag == 0){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			CSAcommand();
		}
	}
	//	レッドスライム
	if (r == 3){
		puts("1:突進");
		puts("2:ファイアブレス");
		r15 = (rand() % 2 + 1);
	}
	//	怪魚
	if (r == 4){
		puts("1:ブリザード");
		r16 = (rand() % 1 + 1);
	}
	//	海グモ
	if (r == 5){
		puts("1:シールド");
		puts("2:スピードアップ");
		puts("3:スピードダウン");
		r17 = (rand() % 3 + 1);

		if (r17 == 1 && TP2 <= 6){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
		}
		if (r17 == 1 || r17 == 2 || r17 == 3){
			cflag = 1;
		}
		else if ((r17 == 0 || r17 >= 4) && cflag == 0){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			CSAcommand();
		}
	}
	//	海蛇
	if (r == 6){
		puts("1:シールド");
		puts("2:シールドダウン");
		r18 = (rand() % 2 + 1);
	}
	//	魔法使い
	if (r == 7){
		puts("1:ファイア");
		puts("2:ブリザード");
		puts("3:サンダー");
		puts("4:ウィンドスラッシュ");
		puts("5:メテオ");
		puts("6:シールド");
		puts("7:スピードアップ");
		puts("8:スピードダウン");
		r19 = (rand() % 8 + 1);

		if ((r19 == 5 || r19 == 6) && TP2 <= 6){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
		}
		if (r19 == 5 && TP2 < 35){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
		}
		if (r19 == 1 || r19 == 2 || r19 == 3 || r19 == 4 || r19 == 5 || r19 == 6 || r19 == 7 || r19 == 8){
			cflag = 1;
		}
		else if ((r19 == 0 || r19 >= 9) && cflag == 0){
			puts("１～８までの数字を入力してください。");
			printf("\n");
			CSAcommand();
		}
	}
	//	コカトリス
	if (r == 8){
		puts("1:サンダー");
		puts("2:ウィンドスラッシュ");
		puts("3:シールド");
		puts("4:スピードアップ");
		r20 = (rand() % 4 + 1);
	}
	//	ハービー
	if (r == 9){
		puts("1:ファイア");
		puts("2:ブリザード");
		puts("3:サンダー");
		puts("4:痛恨の一撃");
		r21 = (rand() % 4 + 1);

		if (r21 == 4 && TP2 <= 5){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
		}
		if (r21 == 1 || r21 == 2 || r21 == 3 || r21 == 4){
			cflag = 1;
		}
		else if ((r21 == 0 || r21 >= 5) && cflag == 0){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			CSAcommand();
		}
	}
	//	トレント
	if (r == 10){
		puts("1:ブリザード");
		puts("2:サンダー");
		puts("3:シールド");
		puts("4:シールドダウン");
		r22 = (rand() % 4 + 1);

		if ((r22 == 3 || r22 == 4) && TP2 <= 6){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
		}
		if (r22 == 1 || r22 == 2 || r22 == 3 || r22 == 4){
			cflag = 1;
		}
		else if ((r22 == 0 || r22 >= 5) && cflag == 0){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			CSAcommand();
		}
	}
	//	ゴブリン
	if (r == 11){
		puts("1:痛恨の一撃");
		puts("2:ジャンプ攻撃");
		r23 = (rand() % 2 + 1);
	}
	//	スケルトン
	if (r == 12){
		puts("1:ファイアソード");
		puts("2:ブリザードソード");
		puts("3:サンダーソード");
		puts("4:ジャンプ攻撃");
		r24 = (rand() % 4 + 1);

		if (r24 == 4 && TP2 <= 4){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
		}
		if (r24 == 1 || r24 == 2 || r24 == 3 || r24 == 4){
			cflag = 1;
		}
		else if ((r24 == 0 || r24 >= 5) && cflag == 0){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			CSAcommand();
		}
	}
	//	半獣狩人
	if (r == 13){
		puts("1:シールドダウン");
		puts("2:スピードダウン");
		r25 = (rand() % 2 + 1);
	}
	//	鋼鉄魚人
	if (r == 14){
		puts("1:スピードダウン");
		r26 = (rand() % 1 + 1);
	}
	//	コボルト
	if (r == 15){
		puts("1:ジャンプ攻撃");
		puts("2:サンダーソード");
		puts("3:シールドダウン");
		puts("4:ウィンドスラッシュ");
		r27 = (rand() % 4 + 1);

		if ((r27 == 1 || r27 == 3 || r27 == 4) && TP2 <= 4){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
		}
		if (r27 == 3 && TP2 <= 6){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
		}
		if (r27 == 1 || r27 == 2 || r27 == 3 || r27 == 4){
			cflag = 1;
		}
		else if ((r27 == 0 || r27 >= 5) && cflag == 0){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			CSAcommand();
		}
	}
	//	グリフォン
	if (r == 18){
		puts("1:ファイア");
		puts("2:サンダー");
		puts("3:シールドダウン");
		puts("4:スピードアップ");
		puts("5:コールドブレス");
		r28 = (rand() % 5 + 1);

		if (r28 == 3 && TP2 <= 6){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
		}
		if (r28 == 1 || r28 == 2 || r28 == 3 || r28 == 4 || r28 == 5){
			cflag = 1;
		}
		else if ((r28 == 0 || r28 >= 6) && cflag == 0){
			puts("１～５までの数字を入力してください。");
			printf("\n");
			CSAcommand();
		}
	}
	//	コドラ
	if (r == 19){
		puts("1:ファイアブレス");
		puts("2:コールドブレス");
		puts("3:サンダーブレス");
		r29 = (rand() % 3 + 1);
	}
	//	鉄砲魚
	if (r == 20){
		puts("1:突進");
		puts("2:コールドブレス");
		r30 = (rand() % 2 + 1);

		if (r30 == 2 && TP2 <= 4){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
		}
		if (r30 == 1 || r30 == 2){
			cflag = 1;
		}
		else if ((r30 == 0 || r30 >= 3) && cflag == 0){
			puts("１～２までの数字を入力してください。");
			printf("\n");
			CSAcommand();
		}
	}
	//	上魔導士
	if (r == 21){
		r31 = 0;
		puts("1:ファイア");
		puts("2:ブリザード");
		puts("3:サンダー");
		puts("4:メテオ");
		puts("5:シールド");
		puts("6:シールドダウン");
		puts("7:スピードアップ");
		puts("8:スピードダウン");
		puts("9:ファイアブレス");
		puts("10:ヘルファイア");
		r31 = (rand() % 10 + 1);

		if (r31 != 1 && r31 != 2 && r31 != 3 && r31 != 4 && r31 != 5 && r31 != 6 && r31 != 7 && r31 != 8 && r31 != 9 && r31 != 10){
			puts("１～１０までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r31 = 0;
		}

		if (r31 == 4 && TP2 < 35){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r31 = 0;
		}
		if (r31 == 10 && TP2 < 8){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r31 = 0;
		}
		if ((r31 == 5 || r31 == 6) && TP2 < 7){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r31 = 0;
		}
	}
	//	竜騎士
	if (r == 22){
		puts("1:ファイアブレス");
		puts("2:ファイアソード");
		puts("3:ウィンドスラッシュ");
		puts("4:スピードダウン");
		r32 = (rand() % 4 + 1);

		if (r32 != 1 && r32 != 2 && r32 != 3 && r32 != 4){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r32 = 0;
		}

		if (r32 == 4 && TP2 < 7){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r32 = 0;
		}
		if ((r32 == 1 || r32 == 3) && TP2 < 5){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r32 = 0;
		}
	}
	//	グレーターデーモン
	if (r == 23){
		puts("1:ヘルファイア");
		puts("2:ウィンドスラッシュ");
		puts("3:サンダーブレス");
		r33 = (rand() % 3 + 1);

		if (r33 != 1 && r33 != 2 && r33 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r33 = 0;
		}

		if (r33 == 1 && TP2 < 8){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r33 = 0;
		}
	}
	//	大王イカ
	if (r == 24){
		puts("1:ブリザード");
		puts("2:コールドブレス");
		r34 = (rand() % 2 + 1);

		if (r34 != 1 && r34 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			CSAcommand();
			r34 = 0;
		}
	}
	//	ドラゴンフライ
	if (r == 25){
		puts("1:ファイアブレス");
		puts("2:突進");
		puts("3:痛恨の一撃");
		r35 = (rand() % 3 + 1);

		if (r35 != 1 && r35 != 2 && r35 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r35 = 0;
		}
		if (r35 == 1 && TP2 < 5){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r35 = 0;
		}
		if (r35 == 3 && TP2 < 6){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r35 = 0;
		}
	}
	//	ファイアエレメンタル
	if (r == 26){
		puts("1:ファイア");
		puts("2:ファイアブレス");
		r36 = (rand() % 2 + 1);

		if (r36 != 1 && r36 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			CSAcommand();
			r36 = 0;
		}

		if ((r36 == 1 || r36 == 2) && TP2 < 5){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r36 = 0;
		}
	}
	//	コールドエレメンタル
	if (r == 27){
		puts("1:ブリザード");
		puts("2:シールド");
		puts("3:スピードダウン");
		r37 = (rand() % 3 + 1);

		if (r37 != 1 && r37 != 2 && r37 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r37 = 0;
		}

		if (r37 == 2 && TP2 < 7){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r37 = 0;
		}
	}
	//	フレイムジャイアント
	if (r == 28){
		puts("1:ファイアブレス");
		r38 = 1;

		if (r38 != 1){
			puts("１を入力してください。");
			printf("\n");
			CSAcommand();
			r38 = 0;
		}
	}
	//	フロストジャイアント
	if (r == 29){
		puts("1:コールドブレス");
		puts("2:スピードアップ");
		puts("3:痛恨の一撃");
		r39 = (rand() % 3 + 1);

		if (r39 != 1 && r39 != 2 && r39 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r39 = 0;
		}

		if (r39 == 3 && TP2 < 6){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r39 = 0;
		}
	}
	//	ケルベロス
	if (r == 30){
		puts("1:突進");
		puts("2:痛恨の一撃");
		r40 = (rand() % 2 + 1);

		if (r40 != 1 && r40 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			CSAcommand();
			r40 = 0;
		}

		if (r40 == 2 && TP2 < 6){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r40 = 0;
		}
	}
	//	ヴァンパイアバット
	if (r == 31){
		puts("1:コールドブレス");
		puts("2:スピードアップ");
		puts("3:ウィンドスラッシュ");
		r41 = (rand() % 3 + 1);

		if (r41 != 1 && r41 != 2 && r41 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r41 = 0;
		}
	}
	//	ガーゴイル
	if (r == 33){
		puts("1:ファイアソード");
		puts("2:サンダーソード");
		puts("3:ウィンドスラッシュ");
		puts("4:シールドダウン");
		r43 = (rand() % 4 + 1);

		if (r43 != 1 && r43 != 2 && r43 != 3 && r43 != 4){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r43 = 0;
		}

		if (r43 == 4 && TP2 < 7){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r43 = 0;
		}
		if (r43 == 3 && TP2 < 5){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r43 = 0;
		}
	}
	//	バシリスク
	if (r == 34){
		puts("1:サンダーブレス");
		puts("2:スピードダウン");
		r44 = (rand() % 2 + 1);

		if (r44 != 1 && r44 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			CSAcommand();
			r44 = 0;
		}

		if ((r44 == 1 || r44 == 2) && TP2 < 5){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r44 = 0;
		}
	}
	//	ポイズンスネイク
	if (r == 35){
		puts("1:突進");
		puts("2:シールドダウン");
		r45 = (rand() % 2 + 1);

		if (r45 != 1 && r45 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			CSAcommand();
			r45 = 0;
		}

		if (r45 == 2 && TP2 < 6){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r45 = 0;
		}
	}
	//	ダークゴブリン
	if (r == 36){
		puts("1:ジャンプ攻撃");
		r46 = 1;

		if (r46 != 1){
			puts("１を入力してください。");
			printf("\n");
			CSAcommand();
			r46 = 0;
		}
	}
	//	下級ソルジャー
	if (r == 37){
		puts("1:ファイアソード");
		puts("2:ブリザードソード");
		puts("3:サンダーソード");
		puts("4:サンダー");
		puts("5:ジャンプ攻撃");
		puts("6:シールドダウン");
		r47 = (rand() % 6 + 1);

		if (r47 != 1 && r47 != 2 && r47 != 3 && r47 != 4 && r47 != 5 && r47 != 6){
			puts("１～６までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r47 = 0;
		}

		if ((r47 == 4 || r47 == 5) && TP2 < 5){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r47 = 0;
		}
		if (r47 == 6 && TP2 < 7){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r47 = 0;
		}
	}
	//	ワイバーン
	if (r == 38){
		puts("1:ファイアブレス");
		puts("2:コールドブレス");
		puts("3:サンダーブレス");
		r48 = (rand() % 3 + 1);

		if (r48 != 1 && r48 != 2 && r48 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r48 = 0;
		}
	}
	//	人食いシャーク
	if (r == 39){
		puts("1:コールドブレス");
		puts("2:突進");
		puts("3:スピードアップ");
		r49 = (rand() % 3 + 1);

		if (r49 != 1 && r49 != 2 && r49 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r49 = 0;
		}
	}
	//	軍隊蟻
	if (r == 40){
		puts("1:鉄壁");
		puts("2:痛恨の一撃");
		puts("3:シールド");
		r50 = (rand() % 3 + 1);

		if (r50 != 1 && r50 != 2 && r50 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r50 = 0;
		}
		if (r50 == 2 && TP2 < 6){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r50 = 0;
		}
		if (r50 == 1 && TP2 < 20){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r50 = 0;
		}
	}
	//	ジャイアントラット
	if (r == 41){
		puts("1:突進");
		r51 = 1;

		if (r51 != 1){
			puts("１を入力してください。");
			printf("\n");
			CSAcommand();
			r51 = 0;
		}
	}
	//	ゴースト
	if (r == 42){
		puts("1:ファイア");
		puts("2:ブリザード");
		puts("3:サンダー");
		puts("4:ウィンドスラッシュ");
		puts("5:ダイヤモンドダスト");
		puts("6:スピードアップ");
		r52 = (rand() % 6 + 1);

		if (r52 != 1 && r52 != 2 && r52 != 3 && r52 != 4 && r52 != 5 && r52 != 6){
			puts("１～６での数字を入力してください。");
			printf("\n");
			CSAcommand();
			r52 = 0;
		}
		if (r52 == 5 && TP2 < 8){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r52 = 0;
		}
	}
	//	グレムリン
	if (r == 43){
		puts("1:ファイア");
		puts("2:ブリザード");
		puts("3:シールド");
		puts("4:スピードアップ");
		r53 = (rand() % 4 + 1);

		if (r53 != 1 && r53 != 2 && r53 != 3 && r53 != 4){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r53 = 0;
		}
		if (r53 == 3 && TP2 < 7){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r53 = 0;
		}
	}
	//	キングコブラ
	if (r == 44){
		puts("1:シールドダウン");
		puts("2:痛恨の一撃");
		r54 = (rand() % 2 + 1);

		if (r54 != 1 && r54 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			CSAcommand();
			r54 = 0;
		}

		if (r54 == 1 && TP < 7){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r54 = 0;
		}
	}
	//	下級忍者A
	if (r == 45){
		puts("1:スピードアップ");
		puts("2:ジャンプ攻撃");
		r55 = (rand() % 2 + 1);

		if (r55 != 1 && r55 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			CSAcommand();
			r55 = 0;
		}
	}
	//	下級忍者B
	if (r == 46){
		puts("1:ウィンドスラッシュ");
		puts("2:ジャンプ攻撃");
		puts("3:シールドダウン");
		r56 = (rand() % 3 + 1);

		if (r56 != 1 && r56 != 2 && r56 != 3){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r56 = 0;
		}
		if (r56 == 3 && TP2 < 7){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r56 = 0;
		}
	}
	//	ゴーストナイト
	if (r == 47){
		puts("1:ファイアソード");
		puts("2:ブリザードソード");
		puts("3:サンダーソード");
		puts("4:コールドブレス");
		r57 = (rand() % 4 + 1);

		if (r57 != 1 && r57 != 2 && r57 != 3 && r57 != 4){
			puts("１～３までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r57 = 0;
		}
		if (r57 == 4 && TP2 < 5){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r57 = 0;
		}
	}
	//	翼竜
	if (r == 48){
		puts("1:ファイアブレス");
		puts("2:突進");
		r58 = (rand() % 2 + 1);

		if (r58 != 1 && r58 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			CSAcommand();
			r58 = 0;
		}
		if (r58 == 1 && TP < 5){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r58 = 0;
		}
	}
	//	妖術師
	if (r == 49){
		puts("1:メテオ");
		puts("2:シールド");
		puts("3:シールドダウン");
		puts("4:スピードアップ");
		puts("5:スピードダウン");
		r59 = (rand() % 5 + 1);

		if (r59 != 1 && r59 != 2 && r59 != 3 && r59 != 4 && r59 != 5){
			puts("１～５までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r59 = 0;
		}
		if (r59 == 1 && TP2 < 35){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r59 = 0;
		}
		if ((r59 == 2 || r59 == 3) && TP2 < 7){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r59 = 0;
		}
	}
	//	リザードマン
	if (r == 50){
		puts("1:ジャンプ攻撃");
		puts("2:ブリザードソード");
		puts("3:サンダーソード");
		puts("4:痛恨の一撃");
		r60 = (rand() % 4 + 1);

		if (r60 != 1 && r60 != 2 && r60 != 3 && r60 != 4){
			puts("１～４までの数字を入力してください。");
			printf("\n");
			CSAcommand();
			r60 = 0;
		}
		if (r60 == 1 && TP2 < 5){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r60 = 0;
		}
		if (r60 == 4 && TP2 < 6){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r60 = 0;
		}
	}
	//	グリーンスライム
	if (r == 51){
		puts("1:ブリザード");
		puts("2:スピードダウン");
		r61 = (rand() % 2 + 1);

		if (r61 != 1 && r61 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			CSAcommand();
			r61 = 0;
		}
	}
	//	マッドマン
	if (r == 52){
		puts("1:突進");
		puts("2:痛恨の一撃");
		r62 = (rand() % 2 + 1);

		if (r62 != 1 && r62 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			CSAcommand();
			r62 = 0;
		}
		if (r62 == 2 && TP2 < 6){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r62 = 0;
		}
	}
	//	人喰い植物
	if (r == 53){
		puts("1:サンダーブレス");
		puts("2:痛恨の一撃");
		r63 = (rand() % 2 + 1);

		if (r63 != 1 && r63 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			CSAcommand();
			r63 = 0;
		}
		if (r63 == 2 && TP2 < 6){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r63 = 0;
		}
	}
	//	ジャイアント
	if (r == 54){
		puts("1:痛恨の一撃");
		r64 = 1;

		if (r64 != 1){
			puts("１を入力してください。");
			printf("\n");
			SAcommand();
			r64 = 0;
		}
	}
	//	キマイラ
	if (r == 55){
		puts("1:ダイヤモンドダスト");
		puts("2:コールドブレス");
		r65 = (rand() % 2 + 1);

		if (r65 != 1 && r65 != 2){
			puts("１か２を入力してください。");
			printf("\n");
			CSAcommand();
			r65 = 0;
		}
		if (r65 == 1 && TP2 < 8){
			puts("TPが足りません。");
			printf("\n");
			CSAcommand();
			r65 = 0;
		}
	}

	CSpecialAttack();
}

//	バトルモード専用の予定～
void herb(){			//	ハーブ
	puts("ハーブを使った！HPが７００回復した！");
	HP += 700;
}

void uherb(){			//	ハーブ（上）
	puts("ハーブ(上)を使った！HPが１５００回復した！");
	HP += 1500;
}

void suherb(){			//	ハーブ(特上)
	puts("ハーブ(特上)を使った！HPが３０００回復した！");
	HP += 3000;
}

void baziru(){			//	バジル
	puts("バジルを使った！TPが５回復した！");
	TP += 5;
}

void ubaziru(){			//	バジル（上）
	puts("バジル(上)を使った！TPが１０回復した！");
	TP += 10;
}

void subaziru(){		//	バジル（特上）
	puts("バジル(特上)を使った！TPが２０回復した！");
	TP += 20;
}

void ulbaziru(){		//	バジル（極）
	puts("バジル(極)を使った！TPが５０回復した！");
	TP += 50;
}

void very(){			//	ベリィ
	puts("ベリィを使った！HPが１０００、TPが１５回復した！");
	HP += 1000;
	TP += 15;
}

void uvery(){			//	ベリィ（上）
	puts("ベリィ(上)を使った！HPが２０００、TPが３０回復した！");
	HP += 2000;
	TP += 30;
}

void ulvery(){			//	ベリィ（極）
	puts("ベリィ(極)を使った！HPが４０００、TPが６０回復した！");
	HP += 4000;
	TP += 60;
}

void pherb(){			//	幻のハーブ
	puts("幻のハーブを使った！TPが無限になった！");
	TP += 9999;			//	無限にすることができないが、値を9999にすることでTPが尽きることがない
}

void ITEM(){			//	試作
	int i, j;			//	繰り返し用変数
	int lp = 1;

	if (c1 == 1){
		strcpy_s(herb_t[c1 - 1], "");
	}
	if (c2 == 1){
		strcpy_s(herb_t[c2], "");
	}
	if (c3 == 1){
		strcpy_s(herb_t[c3 + 1], "");
	}
	if (c4 == 1){
		strcpy_s(herb_t[c4 + 2], "");
	}
	if (c5 == 1){
		strcpy_s(herb_t[c5 + 3], "");
	}
	if (d1 == 1){
		strcpy_s(uherb_t[d1 - 1], "");
	}
	if (d2 == 1){
		strcpy_s(uherb_t[d2], "");
	}
	if (d3 == 1){
		strcpy_s(uherb_t[d3 + 1], "");
	}
	if (d4 == 1){
		strcpy_s(uherb_t[d4 + 2], "");
	}
	if (d5 == 1){
		strcpy_s(uherb_t[d5 + 3], "");
	}
	if (e1 == 1){
		strcpy_s(suherb_t[e1 - 1], "");
	}
	if (e2 == 1){
		strcpy_s(suherb_t[e2], "");
	}
	if (e3 == 1){
		strcpy_s(suherb_t[e3 + 1], "");
	}
	if (e4 == 1){
		strcpy_s(suherb_t[e4 + 2], "");
	}
	if (e5 == 1){
		strcpy_s(suherb_t[e5 + 3], "");
	}
	if (g1 == 1){
		strcpy_s(baziru_t[g1 - 1], "");
	}
	if (g2 == 1){
		strcpy_s(baziru_t[g2], "");
	}
	if (g3 == 1){
		strcpy_s(baziru_t[g3 + 1], "");
	}
	if (g4 == 1){
		strcpy_s(baziru_t[g4 + 2], "");
	}
	if (g5 == 1){
		strcpy_s(baziru_t[g5 + 3], "");
	}
	if (h1 == 1){
		strcpy_s(ubaziru_t[h1 - 1], "");
	}
	if (h2 == 1){
		strcpy_s(ubaziru_t[h2], "");
	}
	if (h3 == 1){
		strcpy_s(ubaziru_t[h3 + 1], "");
	}
	if (h4 == 1){
		strcpy_s(ubaziru_t[h4 + 2], "");
	}
	if (h5 == 1){
		strcpy_s(ubaziru_t[h5 + 3], "");
	}
	if (i1 == 1){
		strcpy_s(subaziru_t[i1 - 1], "");
	}
	if (i2 == 1){
		strcpy_s(subaziru_t[i2], "");
	}
	if (i3 == 1){
		strcpy_s(subaziru_t[i3 + 1], "");
	}
	if (i4 == 1){
		strcpy_s(subaziru_t[i4 + 2], "");
	}
	if (i5 == 1){
		strcpy_s(subaziru_t[i5 + 3], "");
	}
	if (j1 == 1){
		strcpy_s(ulbaziru_t[j1 - 1], "");
	}
	if (j2 == 1){
		strcpy_s(ulbaziru_t[j2], "");
	}
	if (j3 == 1){
		strcpy_s(ulbaziru_t[j3 + 1], "");
	}
	if (j4 == 1){
		strcpy_s(ulbaziru_t[j4 + 2], "");
	}
	if (j5 == 1){
		strcpy_s(ulbaziru_t[j5 + 3], "");
	}
	if (k1 == 1){
		strcpy_s(very_t[k1 - 1], "");
	}
	if (k2 == 1){
		strcpy_s(very_t[k2], "");
	}
	if (k3 == 1){
		strcpy_s(very_t[k3 + 1], "");
	}
	if (k4 == 1){
		strcpy_s(very_t[k4 + 2], "");
	}
	if (k5 == 1){
		strcpy_s(very_t[k5 + 3], "");
	}
	if (l1 == 1){
		strcpy_s(uvery_t[l1 - 1], "");
	}
	if (l2 == 1){
		strcpy_s(uvery_t[l2], "");
	}
	if (l3 == 1){
		strcpy_s(uvery_t[l3 + 1], "");
	}
	if (l4 == 1){
		strcpy_s(uvery_t[l4 + 2], "");
	}
	if (l5 == 1){
		strcpy_s(uvery_t[l5 + 3], "");
	}
	if (m1 == 1){
		strcpy_s(ulvery_t[m1 - 1], "");
	}
	if (m2 == 1){
		strcpy_s(ulvery_t[m2], "");
	}
	if (m3 == 1){
		strcpy_s(ulvery_t[m3 + 1], "");
	}
	if (m4 == 1){
		strcpy_s(ulvery_t[m4 + 2], "");
	}
	if (m5 == 1){
		strcpy_s(ulvery_t[m5 + 3], "");
	}
	if (n1 == 1){
		strcpy_s(pherb_t[n1 - 1], "");
	}
	if (n2 == 1){
		strcpy_s(pherb_t[n2], "");
	}
	if (n3 == 1){
		strcpy_s(pherb_t[n3 + 1], "");
	}

	for (j = 0; j<5; j++){
		printf("%d=%s\n", j + 1, herb_t[j]);
	}
	for (j = 0; j<5; j++){
		printf("%d=%s\n", j + 6, uherb_t[j]);
	}
	for (j = 0; j<5; j++){
		printf("%d=%s\n", j + 11, suherb_t[j]);
	}
	for (j = 0; j<5; j++){
		printf("%d=%s\n", j + 16, baziru_t[j]);
	}
	for (j = 0; j<5; j++){
		printf("%d=%s\n", j + 21, ubaziru_t[j]);
	}
	for (j = 0; j<5; j++){
		printf("%d=%s\n", j + 26, subaziru_t[j]);
	}
	for (j = 0; j<5; j++){
		printf("%d=%s\n", j + 31, ulbaziru_t[j]);
	}
	for (j = 0; j<5; j++){
		printf("%d=%s\n", j + 36, very_t[j]);
	}
	for (j = 0; j<5; j++){
		printf("%d=%s\n", j + 41, uvery_t[j]);
	}
	for (j = 0; j<5; j++){
		printf("%d=%s\n", j + 46, ulvery_t[j]);
	}
	for (j = 0; j<3; j++){
		printf("%d=%s\n", j + 51, pherb_t[j]);
	}

	lp = 1;
	while (lp == 1){
		printf("どれを使いますか？--->");
		scanf_s("%d", &ist);

		if (ist == 1){					//	istが１、且つf1が０ならアイテム使用許可
			if (f1 == 0){
				herb();
				c1 = 1;
				lp = 0;
				f1 = 1;				//	使用済みであるということ
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 2){
			if (f2 == 0){
				herb();
				c2 = 1;
				lp = 0;
				f2 = 1;				//	使用済みであるということ
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 3){
			if (f3 == 0){
				herb();
				c3 = 1;
				lp = 0;
				f3 = 1;				//	使用済みであるということ
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 4){
			if (f4 == 0){
				herb();
				c4 = 1;
				lp = 0;
				f4 = 1;				//	使用済みであるということ
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 5){
			if (f5 == 0){
				herb();
				c5 = 1;
				lp = 0;
				f5 = 1;				//	使用済みであるということ
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}						//	この下よりハーブ(上)
		else if (ist == 6){
			if (d6 == 0){
				uherb();
				d1 = 1;
				lp = 0;
				d6 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 7){
			if (d7 == 0){
				uherb();
				d2 = 1;
				lp = 0;
				d7 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 8){
			if (d8 == 0){
				uherb();
				d3 = 1;
				lp = 0;
				d8 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 9){
			if (d9 == 0){
				uherb();
				d4 = 1;
				lp = 0;
				d9 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 10){
			if (d10 == 0){
				uherb();
				d5 = 1;
				lp = 0;
				d10 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}							//	この下よりハーブ(特上)
		else if (ist == 11){
			if (e6 == 0){
				suherb();
				e1 = 1;
				lp = 0;
				e6 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 12){
			if (e7 == 0){
				suherb();
				e2 = 1;
				lp = 0;
				e7 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 13){
			if (e8 == 0){
				suherb();
				e3 = 1;
				lp = 0;
				e8 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 14){
			if (e9 == 0){
				suherb();
				e4 = 1;
				lp = 0;
				e9 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 15){
			if (e10 == 0){
				suherb();
				e5 = 1;
				lp = 0;
				e10 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}						//	この下よりバジル
		else if (ist == 16){
			if (g6 == 0){
				baziru();
				g1 = 1;
				lp = 0;
				g6 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 17){
			if (g7 == 0){
				baziru();
				g2 = 1;
				lp = 0;
				g7 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 18){
			if (g8 == 0){
				baziru();
				g3 = 1;
				lp = 0;
				g8 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 19){
			if (g9 == 0){
				baziru();
				g4 = 1;
				lp = 0;
				g9 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 20){
			if (g10 == 0){
				baziru();
				g5 = 1;
				lp = 0;
				g10 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}						//	この下よりバジル(上)
		else if (ist == 21){
			if (h6 == 0){
				ubaziru();
				h1 = 1;
				lp = 0;
				h6 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 22){
			if (h7 == 0){
				ubaziru();
				h2 = 1;
				lp = 0;
				h7 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 23){
			if (h8 == 0){
				ubaziru();
				h3 = 1;
				lp = 0;
				h8 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 24){
			if (h9 == 0){
				ubaziru();
				h4 = 1;
				lp = 0;
				h9 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 25){
			if (h10 == 0){
				ubaziru();
				h5 = 1;
				lp = 0;
				h10 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}						//	この下よりバジル(特上)
		else if (ist == 26){
			if (i6 == 0){
				subaziru();
				i1 = 1;
				lp = 0;
				i6 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 27){
			if (i7 == 0){
				subaziru();
				i2 = 1;
				lp = 0;
				i7 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 28){
			if (i8 == 0){
				subaziru();
				i3 = 1;
				lp = 0;
				i8 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 29){
			if (i9 == 0){
				subaziru();
				i4 = 1;
				lp = 0;
				i9 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 30){
			if (i10 == 0){
				subaziru();
				i5 = 1;
				lp = 0;
				i10 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}						//	この下よりバジル(極)
		else if (ist == 31){
			if (j6 == 0){
				ulbaziru();
				j1 = 1;
				lp = 0;
				j6 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 32){
			if (j7 == 0){
				ulbaziru();
				j2 = 1;
				lp = 0;
				j7 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 33){
			if (j8 == 0){
				ulbaziru();
				j3 = 1;
				lp = 0;
				j8 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 34){
			if (j9 == 0){
				ulbaziru();
				j4 = 1;
				lp = 0;
				j9 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 35){
			if (j10 == 0){
				ulbaziru();
				j5 = 1;
				lp = 0;
				j10 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}				//	この下よりベリィ
		else if (ist == 36){
			if (k6 == 0){
				very();
				k1 = 1;
				lp = 0;
				k6 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 37){
			if (k7 == 0){
				very();
				k2 = 1;
				lp = 0;
				k7 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 38){
			if (k8 == 0){
				very();
				k3 = 1;
				lp = 0;
				k8 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 39){
			if (k9 == 0){
				very();
				k4 = 1;
				lp = 0;
				k9 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 40){
			if (k10 == 0){
				very();
				k5 = 1;
				lp = 0;
				k10 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}						//	この下よりベリィ(上)
		else if (ist == 41){
			if (l6 == 0){
				uvery();
				l1 = 1;
				lp = 0;
				l6 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 42){
			if (l7 == 0){
				uvery();
				l2 = 1;
				lp = 0;
				l7 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 43){
			if (l8 == 0){
				uvery();
				l3 = 1;
				lp = 0;
				l8 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 44){
			if (l9 == 0){
				uvery();
				l4 = 1;
				lp = 0;
				l9 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 45){
			if (l10 == 0){
				uvery();
				l5 = 1;
				lp = 0;
				l10 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}					//	この下よりベリィ(極)
		else if (ist == 46){
			if (m6 == 0){
				ulvery();
				m1 = 1;
				lp = 0;
				m6 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 47){
			if (m7 == 0){
				ulvery();
				m2 = 1;
				lp = 0;
				m7 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 48){
			if (m8 == 0){
				ulvery();
				m3 = 1;
				lp = 0;
				m8 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 49){
			if (m9 == 0){
				ulvery();
				m4 = 1;
				lp = 0;
				m9 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 50){
			if (m10 == 0){
				ulvery();
				m5 = 1;
				lp = 0;
				m10 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}					//	この下より幻のハーブ
		else if (ist == 51){
			if (n4 == 0){
				pherb();
				n1 = 1;
				lp = 0;
				n4 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 52){
			if (n5 == 0){
				pherb();
				n2 = 1;
				lp = 0;
				n5 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else if (ist == 53){
			if (n6 == 0){
				pherb();
				n3 = 1;
				lp = 0;
				n6 = 1;
			}
			else{
				puts("すでに使用しています。");
				lp = 1;
			}
		}
		else{
			puts("１～５３までの数字を入力してください。");
			lp = 1;
		}

		printf("\n");
	}
}

//	トーナメントモード専用のアイテム関数
void Titem(){
	int i, j;
	int tst = 0;		//	使用するアイテムを選択するために使用
	int tlp = 1;

	tflg = 0;
	//	現在所持しているアイテムの表示
	for (i = 0; i<INUM; i++){
		printf("%d:%s\n", i + 1, TMI[i]);
	}
	for (j = 0; j<INUM; j++){
		if (strcmp(TMI[j], "") == 0){
			tflg = 1;
			puts("アイテムがありません。");
			tlp = 0;
			j = 9999;
		}
		else{
			tlp = 1;
			j = 9999;
		}
	}

	while (tlp == 1){
		if (tflg == 1){
			tlp = 0;
		}
		else{
			printf("--->");
			scanf_s("%d", &tst);
		}

		if (tst == 1 && (strcmp(TMI[tst - 1], ""))){
			if (hf >= 1){					//	アイテム欄の一番上がハーブなら
				herb();						//	ハーブを使用する
				strcpy_s(TMI[tst - 1], "");		//	使用したらアイテム欄の一番上を空白にする
				hf--;
			}
			if (zhf >= 1){
				uherb();
				strcpy_s(TMI[tst - 1], "");
				zhf--;
			}
			if (thf >= 1){
				suherb();
				strcpy_s(TMI[tst - 1], "");
				thf--;
			}
			if (bz >= 1){
				baziru();
				strcpy_s(TMI[tst - 1], "");
				bz--;
			}
			if (ubz >= 1){
				ubaziru();
				strcpy_s(TMI[tst - 1], "");
				ubz--;
			}
			if (tbz >= 1){
				subaziru();
				strcpy_s(TMI[tst - 1], "");
				tbz--;
			}
			if (gbz >= 1){
				ulbaziru();
				strcpy_s(TMI[tst - 1], "");
				gbz--;
			}
			if (br >= 1){
				very();
				strcpy_s(TMI[tst - 1], "");
				br--;
			}
			if (ubr >= 1){
				uvery();
				strcpy_s(TMI[tst - 1], "");
				ubr--;
			}
			if (gbr == 1){
				ulvery();
				strcpy_s(TMI[tst - 1], "");
				gbr--;
			}
			if (mhb == 1){
				pherb();
				strcpy_s(TMI[tst - 1], "");
				mhb--;
			}
			tlp = 0;
		}
		else if (tst == 2 && (strcmp(TMI[tst - 1], ""))){
			if (hf >= 1){					//	アイテム欄の一番上がハーブなら
				herb();						//	ハーブを使用する
				strcpy_s(TMI[tst - 1], "");		//	使用したらアイテム欄の一番上を空白にする
				hf--;
			}
			if (zhf >= 1){
				uherb();
				strcpy_s(TMI[tst - 1], "");
				zhf--;
			}
			if (thf >= 1){
				suherb();
				strcpy_s(TMI[tst - 1], "");
				thf--;
			}
			if (bz >= 1){
				baziru();
				strcpy_s(TMI[tst - 1], "");
				bz--;
			}
			if (ubz >= 1){
				ubaziru();
				strcpy_s(TMI[tst - 1], "");
				ubz--;
			}
			if (tbz >= 1){
				subaziru();
				strcpy_s(TMI[tst - 1], "");
				tbz--;
			}
			if (gbz >= 1){
				ulbaziru();
				strcpy_s(TMI[tst - 1], "");
				gbz--;
			}
			if (br >= 1){
				very();
				strcpy_s(TMI[tst - 1], "");
				br--;
			}
			if (ubr >= 1){
				uvery();
				strcpy_s(TMI[tst - 1], "");
				ubr--;
			}
			if (gbr == 1){
				ulvery();
				strcpy_s(TMI[tst - 1], "");
				gbr--;
			}
			if (mhb == 1){
				pherb();
				strcpy_s(TMI[tst - 1], "");
				mhb--;
			}
			tlp = 0;
		}
		else if (tst == 3 && (strcmp(TMI[tst - 1], ""))){
			if (hf >= 1){					//	アイテム欄の一番上がハーブなら
				herb();						//	ハーブを使用する
				strcpy_s(TMI[tst - 1], "");		//	使用したらアイテム欄の一番上を空白にする
				hf--;
			}
			if (zhf >= 1){
				uherb();
				strcpy_s(TMI[tst - 1], "");
				zhf--;
			}
			if (thf >= 1){
				suherb();
				strcpy_s(TMI[tst - 1], "");
				thf--;
			}
			if (bz >= 1){
				baziru();
				strcpy_s(TMI[tst - 1], "");
				bz--;
			}
			if (ubz >= 1){
				ubaziru();
				strcpy_s(TMI[tst - 1], "");
				ubz--;
			}
			if (tbz >= 1){
				subaziru();
				strcpy_s(TMI[tst - 1], "");
				tbz--;
			}
			if (gbz >= 1){
				ulbaziru();
				strcpy_s(TMI[tst - 1], "");
				gbz--;
			}
			if (br >= 1){
				very();
				strcpy_s(TMI[tst - 1], "");
				br--;
			}
			if (ubr >= 1){
				uvery();
				strcpy_s(TMI[tst - 1], "");
				ubr--;
			}
			if (gbr == 1){
				ulvery();
				strcpy_s(TMI[tst - 1], "");
				gbr--;
			}
			if (mhb == 1){
				pherb();
				strcpy_s(TMI[tst - 1], "");
				mhb--;
			}
			tlp = 0;
		}
		else if (tst == 4 && (strcmp(TMI[tst - 1], ""))){
			if (hf >= 1){					//	アイテム欄の一番上がハーブなら
				herb();						//	ハーブを使用する
				strcpy_s(TMI[tst - 1], "");		//	使用したらアイテム欄の一番上を空白にする
				hf--;
			}
			if (zhf >= 1){
				uherb();
				strcpy_s(TMI[tst - 1], "");
				zhf--;
			}
			if (thf >= 1){
				suherb();
				strcpy_s(TMI[tst - 1], "");
				thf--;
			}
			if (bz >= 1){
				baziru();
				strcpy_s(TMI[tst - 1], "");
				bz--;
			}
			if (ubz >= 1){
				ubaziru();
				strcpy_s(TMI[tst - 1], "");
				ubz--;
			}
			if (tbz >= 1){
				subaziru();
				strcpy_s(TMI[tst - 1], "");
				tbz--;
			}
			if (gbz >= 1){
				ulbaziru();
				strcpy_s(TMI[tst - 1], "");
				gbz--;
			}
			if (br >= 1){
				very();
				strcpy_s(TMI[tst - 1], "");
				br--;
			}
			if (ubr >= 1){
				uvery();
				strcpy_s(TMI[tst - 1], "");
				ubr--;
			}
			if (gbr == 1){
				ulvery();
				strcpy_s(TMI[tst - 1], "");
				gbr--;
			}
			if (mhb == 1){
				pherb();
				strcpy_s(TMI[tst - 1], "");
				mhb--;
			}
			tlp = 0;
		}
		else if (tst == 5 && (strcmp(TMI[tst - 1], ""))){
			if (hf >= 1){					//	アイテム欄の一番上がハーブなら
				herb();						//	ハーブを使用する
				strcpy_s(TMI[tst - 1], "");		//	使用したらアイテム欄の一番上を空白にする
				hf--;
			}
			if (zhf >= 1){
				uherb();
				strcpy_s(TMI[tst - 1], "");
				zhf--;
			}
			if (thf >= 1){
				suherb();
				strcpy_s(TMI[tst - 1], "");
				thf--;
			}
			if (bz >= 1){
				baziru();
				strcpy_s(TMI[tst - 1], "");
				bz--;
			}
			if (ubz >= 1){
				ubaziru();
				strcpy_s(TMI[tst - 1], "");
				ubz--;
			}
			if (tbz >= 1){
				subaziru();
				strcpy_s(TMI[tst - 1], "");
				tbz--;
			}
			if (gbz >= 1){
				ulbaziru();
				strcpy_s(TMI[tst - 1], "");
				gbz--;
			}
			if (br >= 1){
				very();
				strcpy_s(TMI[tst - 1], "");
				br--;
			}
			if (ubr >= 1){
				uvery();
				strcpy_s(TMI[tst - 1], "");
				ubr--;
			}
			if (gbr == 1){
				ulvery();
				strcpy_s(TMI[tst - 1], "");
				gbr--;
			}
			if (mhb == 1){
				pherb();
				strcpy_s(TMI[tst - 1], "");
				mhb--;
			}
			tlp = 0;
		}
		else{
		}
	}
}

//	プレイヤー行動関数
void PAC(){
	int plo = 0;
	char ch[5];

	puts("----Player----");
	printf("name:%s HP=%d: TP=%d: atk:%d def:%d spd:%d\n", name, HP, TP, atk, def, spd);

	plo = 1;
	while (plo == 1){
		if (st2 == 16 || st2 == 17 || st2 == 32){					//	選択したモンスターがゾンビ、ミイラ男、又はオーガの場合
			puts("コマンド？");
			printf("1=攻撃: 2=防御 3=アイテム\n");
			scanf_s("%d", &stk1);

			if (stk1 == 1){			//	攻撃
				HP2 = PDamage();
				plo = 0;
			}
			else if (stk1 == 2){		//	防御
				puts("身を守っている。");
				plo = 0;
			}
			else if (stk1 == 3){		//	アイテム
				if (sentaku == 1){
					ITEM();					//	バトルモード
				}
				else if (sentaku == 2){
					Titem();				//	トーナメントモード
				}
				plo = 0;
			}
			else{
				puts("１～３までの数字を入力してください。");
				plo = 1;
			}
		}
		else{										//	ゾンビ、オーガ以外のモンスター
			puts("コマンド？");
			printf("1=攻撃: 2=防御: 3=特殊技: 4=アイテム\n");
			scanf_s("%d", &stk1);

			if (stk1 == 1){			//	攻撃
				HP2 = PDamage();
				plo = 0;
			}
			else if (stk1 == 2){		//	防御
				puts("身を守っている。");
				plo = 0;
			}
			else if (stk1 == 3){		//	特殊技
				if (st2 == 3 || st2 == 12 || st2 == 15 || st2 == 20 || st2 == 22 || st2 == 25 || st2 == 30 || st2 == 33 || st2 == 35 || st2 == 37 || st2 == 39 || st2 == 41 || st2 == 47 || st2 == 48 || st2 == 50 || st2 == 52){
					if (TP >= 3){		//	3以上
						SAcommand();
						plo = 0;
					}
					else{
						puts("TPがありません。");
						printf("\n");
						plo = 1;
					}
				}
				else if (st2 == 1 || st2 == 2 || st2 == 4 || st2 == 5 || st2 == 7 || st2 == 8 || st2 == 9 || st2 == 10 || st2 == 11 || st2 == 13 || st2 == 14 || st2 == 18 || st2 == 19 || st2 == 21 || st2 == 23 || st2 == 24 || st2 == 26 || st2 == 27 || st2 == 28 || st2 == 29 || st2 == 31 || st2 == 34 || st2 == 36 || st2 == 38 || st2 == 42 || st2 == 43 || st2 == 45 || st2 == 46 || st2 == 49 || st2 == 51 || st2 == 53 || st2 == 55){
					if (TP >= 5){		//	5以上
						SAcommand();
						plo = 0;
					}
					else{
						puts("TPがありません。");
						printf("\n");
						plo = 1;
					}
				}
				else if (st2 == 40 || st2 == 44 || st2 == 54){
					if (TP >= 6){			//	6以上
						SAcommand();
						plo = 0;
					}
					else{
						puts("TPがありません。");
						printf("\n");
						plo = 1;
					}
				}
				else if (st2 == 6){
					if (TP >= 7){			//	7以上
						SAcommand();
						plo = 0;
					}
					else{
						puts("TPがありません。");
						printf("\n");
						plo = 1;
					}
				}
			}
			else if (stk1 == 4){		//	アイテム
				if (sentaku == 1){
					ITEM();				//	バトルモード
					plo = 0;
				}
				else if (sentaku == 2){
					Titem();			//	トーナメントモード
					if (tflg == 1){
						plo = 1;
					}
					else{
						plo = 0;
					}
				}
			}
			else{
				puts("１～４までの数字を入力してください。");
				plo = 1;
			}
		}
	}
	printf("\n");
	puts("適当なキーを入力してください。");
	scanf_s("%s", ch, 5);
	printf("\n");
}

//	CPU行動関数
void CAC(){
	int clo = 0;
	r7 = 0;

	srand((unsigned int)time(NULL));

	r7 = (rand() % 2 + 1);

	puts("----CPU----");
	printf("name:%s HP=%d: TP=%d: atk:%d def:%d spd:%d\n", name2, HP2, TP2, atk2, def2, spd2);

	clo = 1;
	while (clo == 1){
		if (r == 16 || r == 17 || r == 32){				//	CPUが選択したモンスターがゾンビ、又はオーガの場合
			puts("コマンド？");
			printf("1=攻撃\n");
			//	攻撃
			HP = CDamage();
			clo = 0;
		}
		else{								//	ゾンビ、オーガ以外のモンスター
			puts("コマンド？");
			printf("1=攻撃: 2=特殊技\n");

			if (r7 == 1){			//	攻撃
				HP = CDamage();
				clo = 0;
			}
			else if (r7 == 2){		//	特殊技
				if (r == 3 || r == 12 || r == 15 || r == 20 || r == 22 || r == 25 || r == 30 || r == 33 || r == 35 || r == 37 || r == 39 || r == 41 || r == 47 || r == 48 || r == 50 || r == 52){
					if (TP2 >= 3){
						CSAcommand();
						clo = 0;
					}
					else{
						puts("TPがありません。");
						printf("\n");
						r7 = 0;
						r7 = (rand() % 2 + 1);
						clo = 1;
					}
				}
				else if (r == 1 || r == 2 || r == 4 || r == 5 || r == 7 || r == 8 || r == 9 || r == 10 || r == 11 || r == 13 || r == 14 || r == 18 || r == 19 || r == 21 || r == 23 || r == 24 || r == 26 || r == 27 || r == 28 || r == 29 || r == 31 || r == 34 || r == 36 || r == 38 || r == 42 || r == 43 || r == 45 || r == 46 || r == 49 || r == 51 || r == 53 || r == 55){
					if (TP2 >= 5){
						CSAcommand();
						clo = 0;
					}
					else{
						puts("TPがありません。");
						printf("\n");
						r7 = 0;
						r7 = (rand() % 2 + 1);
						clo = 1;
					}
				}
				else if (r == 40 || r == 44 || r == 54){
					if (TP2 >= 6){			//	6以上
						CSAcommand();
						clo = 0;
					}
					else{
						puts("TPがありません。");
						printf("\n");
						r7 = (rand() % 2 + 1);
						clo = 1;
					}
				}
				else if (r == 6){
					if (TP2 >= 7){
						CSAcommand();
						clo = 0;
					}
					else{
						puts("TPがありません。");
						printf("\n");
						r7 = 0;
						r7 = (rand() % 2 + 1);
						clo = 1;
					}
				}
			}
		}
	}
	printf("\n");
}

int GameEnd(int loop){
	int loop2 = 0;
	int ges;

	loop2 = 1;
	while (loop2 == 1){
		puts("ゲームを終わってもいいですか？(Yes=1: NO=2)");
		scanf_s("%d", &ges);

		if (ges == 1){
			puts("終了します・・・");
			exit(1);
		}
		else if (ges == 2){
			puts("メインメニューへ戻ります。");
			loop2 = 0;
			loop = 1;
		}
		else{
			puts("１か２を入力してください。");
			loop2 = 1;
		}
	}
	return loop;
}

void GameScore(char *name, int HP, int TP, int atk, int def, int spd, char *name2, int HP2, int TP2, int atk2, int def2, int spd2){
	printf("Player name=%s: HP=%d: TP=%d: atk=%d: def=%d: spd=%d\n", name, HP, TP, atk, def, spd);
	printf("CPU    name=%s: HP=%d: TP=%d: atk=%d: def=%d: spd=%d\n", name2, HP2, TP2, atk2, def2, spd2);
	fprintf(fp, "Player name=%s: HP=%d: TP=%d: atk=%d: def=%d: spd=%d\n", name, HP, TP, atk, def, spd);
	fprintf(fp, "CPU    name=%s: HP=%d: TP=%d: atk=%d: def=%d: spd=%d\n", name2, HP2, TP2, atk2, def2, spd2);
}

//	アイテム変数初期化関数
void Init(){
	c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;												//	アイテムを何回使用したかのフラグ(ハーブ)
	d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0, d8 = 0, d9 = 0, d10 = 0;	//	ハーブ(上)&フラグ
	e1 = 0, e2 = 0, e3 = 0, e4 = 0, e5 = 0, e6 = 0, e7 = 0, e8 = 0, e9 = 0, e10 = 0;	//	ハーブ(特上)&フラグ
	g1 = 0, g2 = 0, g3 = 0, g4 = 0, g5 = 0, g6 = 0, g7 = 0, g8 = 0, g9 = 0, g10 = 0;	//	バジル&フラグ
	h1 = 0, h2 = 0, h3 = 0, h4 = 0, h5 = 0, h6 = 0, h7 = 0, h8 = 0, h9 = 0, h10 = 0;	//	バジル(上)＆フラグ
	i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0, i9 = 0, i10 = 0;	//	バジル(特上)＆フラグ
	j1 = 0, j2 = 0, j3 = 0, j4 = 0, j5 = 0, j6 = 0, j7 = 0, j8 = 0, j9 = 0, j10 = 0;	//	バジル(極)＆フラグ
	k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0, k6 = 0, k7 = 0, k8 = 0, k9 = 0, k10 = 0;	//	ベリィ＆フラグ
	l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0, l6 = 0, l7 = 0, l8 = 0, l9 = 0, l10 = 0;	//	ベリィ(上)＆フラグ
	m1 = 0, m2 = 0, m3 = 0, m4 = 0, m5 = 0, m6 = 0, m7 = 0, m8 = 0, m9 = 0, m10 = 0;	//	ベリィ(特上)＆フラグ
	n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0;										//	幻のハーブ＆フラグ
	f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0;			//	ハーブが使用されたかどうかのフラグ

	strcpy_s(herb_t[0], "ハーブ");

	strcpy_s(herb_t[1], "ハーブ");

	strcpy_s(herb_t[2], "ハーブ");

	strcpy_s(herb_t[3], "ハーブ");

	strcpy_s(herb_t[4], "ハーブ");

	strcpy_s(uherb_t[0], "ハーブ(上)");

	strcpy_s(uherb_t[1], "ハーブ(上)");

	strcpy_s(uherb_t[2], "ハーブ(上)");

	strcpy_s(uherb_t[3], "ハーブ(上)");

	strcpy_s(uherb_t[4], "ハーブ(上)");

	strcpy_s(suherb_t[0], "ハーブ(特上)");

	strcpy_s(suherb_t[1], "ハーブ(特上)");

	strcpy_s(suherb_t[2], "ハーブ(特上)");

	strcpy_s(suherb_t[3], "ハーブ(特上)");

	strcpy_s(suherb_t[4], "ハーブ(特上)");

	strcpy_s(baziru_t[0], "バジル");

	strcpy_s(baziru_t[1], "バジル");

	strcpy_s(baziru_t[2], "バジル");

	strcpy_s(baziru_t[3], "バジル");

	strcpy_s(baziru_t[4], "バジル");

	strcpy_s(ubaziru_t[0], "バジル(上)");

	strcpy_s(ubaziru_t[1], "バジル(上)");

	strcpy_s(ubaziru_t[2], "バジル(上)");

	strcpy_s(ubaziru_t[3], "バジル(上)");

	strcpy_s(ubaziru_t[4], "バジル(上)");

	strcpy_s(subaziru_t[0], "バジル(特上)");

	strcpy_s(subaziru_t[1], "バジル(特上)");

	strcpy_s(subaziru_t[2], "バジル(特上)");

	strcpy_s(subaziru_t[3], "バジル(特上)");

	strcpy_s(subaziru_t[4], "バジル(特上)");

	strcpy_s(ulbaziru_t[0], "バジル(極)");

	strcpy_s(ulbaziru_t[1], "バジル(極)");

	strcpy_s(ulbaziru_t[2], "バジル(極)");

	strcpy_s(ulbaziru_t[3], "バジル(極)");

	strcpy_s(ulbaziru_t[4], "バジル(極)");

	strcpy_s(very_t[0], "ベリィ");

	strcpy_s(very_t[1], "ベリィ");

	strcpy_s(very_t[2], "ベリィ");

	strcpy_s(very_t[3], "ベリィ");

	strcpy_s(very_t[4], "ベリィ");

	strcpy_s(uvery_t[0], "ベリィ(上)");

	strcpy_s(uvery_t[1], "ベリィ(上)");

	strcpy_s(uvery_t[2], "ベリィ(上)");

	strcpy_s(uvery_t[3], "ベリィ(上)");

	strcpy_s(uvery_t[4], "ベリィ(上)");

	strcpy_s(ulvery_t[0], "ベリィ(極)");

	strcpy_s(ulvery_t[1], "ベリィ(極)");

	strcpy_s(ulvery_t[2], "ベリィ(極)");

	strcpy_s(ulvery_t[3], "ベリィ(極)");

	strcpy_s(ulvery_t[4], "ベリィ(極)");

	strcpy_s(pherb_t[0], "幻のハーブ");

	strcpy_s(pherb_t[1], "幻のハーブ");

	strcpy_s(pherb_t[2], "幻のハーブ");
}

void TM1(){				//	1回戦のモンスターを乱数により決定
	int flag = 0;
	char ch[5];

	r = 0;

	if (flag == 0){
		srand((unsigned int)time(NULL));
		flag = 1;
	}

	r = (rand() % 14 + 1);

	if (r == 3){
		r = r + 1;
	}
	if (r == 4 || r == 5){
		r = r + 2;
	}
	if (r == 6){
		r = r + 5;
	}
	if (r == 7){
		r = r + 6;
	}
	if (r == 8){
		r = r + 11;
	}
	if (r == 9){
		r = r + 17;
	}
	if (r == 10){
		r = r + 21;
	}
	if (r == 11){
		r = r + 23;
	}
	if (r == 12){
		r = r + 28;
	}
	if (r == 13){
		r = r + 29;
	}
	if (r == 14){
		r = r + 38;
	}

	puts("第1回戦の相手は・・・");

	if (r == 1){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 2){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 4){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 6){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 7){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 11){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 13){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 19){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 26){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 31){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 34){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 40){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 42){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 52){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}

	printf("name=%s\n", name2);

	puts("適当なキーを入力してください。");
	scanf_s("%s", ch, 5);
}

void TM2(){
	int flag = 0;
	char ch[5];

	r = 0;

	if (flag == 0){
		srand((unsigned int)time(NULL));
		flag = 1;
	}

	r = (rand() % 26 + 1);

	if (r == 1 || r == 2 || r == 3 || r == 4){
		r = r + 1;
	}
	if (r == 5 || r == 6){
		r = r + 2;
	}
	if (r == 7 || r == 8){
		r = r + 5;
	}
	if (r == 9 || r == 10){
		r = r + 7;
	}
	if (r == 11 || r == 12){
		r = r + 9;
	}
	if (r == 13 || r == 14 || r == 15){
		r = r + 12;
	}
	if (r == 16 || r == 17 || r == 18){
		r = r + 14;
	}
	if (r == 19 || r == 20){
		r = r + 16;
	}
	if (r == 21 || r == 22 || r == 23 || r == 24){
		r = r + 19;
	}
	if (r == 25){
		r = r + 25;
	}
	if (r == 26){
		r = r + 27;
	}

	puts("第2回戦の相手は・・・");

	if (r == 2){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 3){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 4){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 5){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 7){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 8){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 12){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 13){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 16){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 17){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 20){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 21){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 25){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 26){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 27){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 30){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 31){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 32){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 35){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 36){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 40){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 41){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 42){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 43){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 50){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}
	else if (r == 53){
		strcpy_s(name2, MC[r - 1].name);
		HP2 = MC[r - 1].HP;
		TP2 = MC[r - 1].TP;
		atk2 = MC[r - 1].atk;
		def2 = MC[r - 1].def;
		spd2 = MC[r - 1].spd;
	}

	printf("name=%s\n", name2);

	puts("適当なキーを入力してください。");
	scanf_s("%s", ch, 5);
}

void TM3(){
	int flag = 0;
	char ch[5];

	r = 0;

	if (flag == 0){
		srand((unsigned int)time(NULL));
		flag = 1;
	}

	r = (rand() % 31 + 1);

	if (r == 1){
		r = r + 1;
	}
	if (r == 2){
		r = r + 5;
	}
	if (r == 3 || r == 4){
		r = r + 6;
	}
	if (r == 5){
		r = r + 7;
	}
	if (r == 6 || r == 7 || r == 8 || r == 9 || r == 10){
		r = r + 8;
	}
	if (r == 11){
		r = r + 10;
	}
	if (r == 12 || r == 13){
		r = r + 12;
	}
	if (r == 14 || r == 15){
		r = r + 13;
	}
	if (r == 16){
		r = r + 14;
	}
	if (r == 17 || r == 18){
		r = r + 15;
	}
	if (r == 19){
		r = r + 17;
	}
	if (r == 20 || r == 21 || r == 22 || r == 23 || r == 24 || r == 25){
		r = r + 18;
	}
	if (r == 26 || r == 27 || r == 28){
		r = r + 19;
	}
	if (r == 29 || r == 30){
		r = r + 21;
	}
	if (r == 31){
		r = r + 22;
	}

	puts("第3回戦の相手は・・・");

	strcpy_s(name2, MC[r - 1].name);
	HP2 = MC[r - 1].HP;
	TP2 = MC[r - 1].TP;
	atk2 = MC[r - 1].atk;
	def2 = MC[r - 1].def;
	spd2 = MC[r - 1].spd;

	printf("name=%s\n", name2);

	puts("適当なキーを入力してください。");
	scanf_s("%s", ch, 5);
}

void ShopEvent(){
	int stk0 = 0, sk = 1;		//	関数内変数(選択)、再帰処理対策
	int i;

	puts("☆ショップ☆");
	puts("商品名			値段");
	puts("-------------------------------");
	puts("1:ハーブ		3000G");
	puts("2:ハーブ（上）		7000G");
	puts("3:バジル		5000G");
	puts("4:HPシード		5000G");
	puts("5:TPシード		5000G");
	puts("6:atkシード		3000G");
	puts("7:defシード		3000G");
	puts("8:spdシード		3000G");
	printf("--->");
	scanf_s("%d", &stk0);

	if (stk0 == 1 && shozikin >= 3000){		//	ハーブを買った場合
		shozikin -= 3000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "ハーブ");
				puts("ハーブを買った！");
				count++;
				hf++;
				break;
			}
			else{
				puts("(!)これ以上購入することができません。");
				break;
			}
		}
	}
	else if (stk0 == 2 && shozikin >= 7000){		//	ハーブ（上）を買った場合
		shozikin -= 7000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "ハーブ(上)");
				puts("ハーブ(上)を買った！");
				count++;
				zhf++;
				break;
			}
			else{
				puts("(!)これ以上購入することができません。");
				break;
			}
		}
	}
	else if (stk0 == 3 && shozikin >= 5000){		//	バジルを買った場合
		shozikin -= 5000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "バジル");
				puts("バジルを買った！");
				count++;
				bz++;
				break;
			}
			else{
				puts("(!)これ以上購入することができません。");
				break;
			}
		}
	}
	else if (stk0 == 4 && shozikin >= 5000){		//	HPシードを買った場合
		shozikin -= 5000;
		MP[st2 - 1].HP += 500;
		HP = MP[st2 - 1].HP;
		puts("HPシードを買った！");
		puts("HPが500上がった！");
		puc++;
	}
	else if (stk0 == 5 && shozikin >= 5000){		//	TPシードを買った場合
		shozikin -= 5000;
		MP[st2 - 1].TP += 10;
		TP = MP[st2 - 1].TP;
		puts("TPシードを買った！");
		puts("TPが10上がった！");
		puc4++;
	}
	else if (stk0 == 6 && shozikin >= 3000){		//	atkシードを購入した場合
		shozikin -= 3000;
		MP[st2 - 1].atk += 50;
		atk = MP[st2 - 1].atk;
		puts("atkシードを買った！");
		puts("atkが50上がった！");
		puc15++;
	}
	else if (stk0 == 7 && shozikin >= 3000){		//	defシードを購入した場合
		shozikin -= 3000;
		MP[st2 - 1].def += 50;
		def = MP[st2 - 1].def;
		puts("defシードを買った！");
		puts("defが50上がった！");
		puc7++;
	}
	else if (stk0 == 8 && shozikin >= 3000){		//	spdシードを購入した場合
		shozikin -= 3000;
		MP[st2 - 1].spd += 50;
		spd = MP[st2 - 1].spd;
		puts("spdシードを買った！");
		puts("spdが50上がった！");
		puc10++;
	}
	else{
		puts("お金が足りません。");
		ShopEvent();
		sk = 0;
		stk0 = 0;
	}

	if (stk0 == 4 || stk0 == 5 || stk0 == 6 || stk0 == 7){		//	パワーアップ系アイテムを買った場合
		printf("Name=%s: HP=%d: TP=%d: atk=%d: def=%d: spd=%d\n", name, HP, TP, atk, def, spd);
	}

	if (sk == 1){
		printf("\n\n\n");
	}
}

void ShopEvent2(){
	int stk1 = 0, i;		//	アイテム選択用変数、ループ用変数
	int sk = 1;

	puts("☆ショップ☆");
	puts("1:ハーブ				3000G");
	puts("2:ハーブ（上）	7000G");
	puts("3:ハーブ（特上）15000G");
	puts("4:バジル				5000G");
	puts("5:バジル（上）	10000G");
	puts("6:バジル（特上）17000G");
	puts("7:バジル（極）	30000G");
	puts("8:ベリィ				20000G");
	puts("9:ベリィ（上）	30000G");
	puts("10:ベリィ（極）	50000G");
	printf("--->");
	scanf_s("%d", &stk1);

	if (stk1 == 1 && shozikin >= 3000){		//	ハーブを買った場合
		shozikin -= 3000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "ハーブ");
				puts("ハーブを買った！");
				count++;
				hf++;
				break;
			}
			else{
				puts("(!)これ以上購入することができません。");
				break;
			}
		}
	}
	else if (stk1 == 2 && shozikin >= 7000){		//	ハーブ(上)
		shozikin -= 7000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "ハーブ(上)");
				puts("ハーブ(上)を買った！");
				count++;
				zhf++;
				break;
			}
			else{
				puts("(!)これ以上購入することができません。");
				break;
			}
		}
	}
	else if (stk1 == 3 && shozikin >= 15000){	//	ハーブ(特上)
		shozikin -= 15000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "ハーブ(特上)");
				puts("ハーブ(特上)を買った！");
				count++;
				thf++;
				break;
			}
			else{
				puts("(!)これ以上購入することができません。");
				break;
			}
		}
	}
	else if (stk1 == 4 && shozikin >= 5000){		//	バジル
		shozikin -= 5000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "バジル");
				puts("バジルを買った！");
				count++;
				bz++;
				break;
			}
			else{
				puts("(!)これ以上購入することができません。");
				break;
			}
		}
	}
	else if (stk1 == 5 && shozikin >= 10000){	//	バジル(上)
		shozikin -= 10000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "バジル(上)");
				puts("バジル(上)を買った！");
				count++;
				ubz++;
				break;
			}
			else{
				puts("(!)これ以上購入することができません。");
				break;
			}
		}
	}
	else if (stk1 == 6 && shozikin >= 17000){	//	バジル(特上)
		shozikin -= 17000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "バジル(特上)");
				puts("バジル(特上)を買った！");
				count++;
				tbz++;
				break;
			}
			else{
				puts("(!)これ以上購入することができません。");
				break;
			}
		}
	}
	else if (stk1 == 7 && shozikin >= 30000){	//	バジル(極)
		shozikin -= 30000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "バジル(極)");
				puts("バジル(極)を買った！");
				count++;
				gbz++;
				break;
			}
			else{
				puts("(!)これ以上購入することができません。");
				break;
			}
		}
	}
	else if (stk1 == 8 && shozikin >= 20000){	//	ベリィ
		shozikin -= 20000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "ベリィ");
				puts("ベリィを買った！");
				count++;
				br++;
				break;
			}
			else{
				puts("(!)これ以上購入することができません。");
				break;
			}
		}
	}
	else if (stk1 == 9 && shozikin >= 30000){	//	ベリィ(上)
		shozikin -= 30000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "ベリィ(上)");
				puts("ベリィ(上)を買った！");
				count++;
				ubr++;
				break;
			}
			else{
				puts("(!)これ以上購入することができません。");
				break;
			}
		}
	}
	else if (stk1 == 10 && shozikin >= 50000){	//	ベリィ(極)
		shozikin -= 50000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "ベリィ(極)");
				puts("ベリィ(極)を買った！");
				count++;
				gbr++;
				break;
			}
			else{
				puts("(!)これ以上購入することができません。");
				break;
			}
		}
	}
	else{
		puts("お金が足りません。");
		ShopEvent2();
		sk = 0;
		stk1 = 0;
	}

	if (sk == 1){
		printf("\n\n\n");
	}
}

void ShopEvent3(){
	int stk2 = 0;
	int sk = 1;

	puts("☆ショップ☆");
	puts("1:HPシード			5000G");
	puts("2:HPシード改			17000G");
	puts("3:HPシード真			40000G");
	puts("4:TPシード			5000G");
	puts("5:TPシード改			17000G");
	puts("6:TPシード真			40000G");
	puts("7:atkシード			3000G");
	puts("8:atkシード改			15000G");
	puts("9:atkシード真			35000G");
	puts("10:defシード			3000G");
	puts("11:defシード改		15000G");
	puts("12:defシード真		35000G");
	puts("13:spdシード			3000G");
	puts("14:spdシード改		15000G");
	puts("15:spdシード真		35000");
	puts("16:デラックスシード	30000G");
	puts("17:デラックスシード真	55000G");
	printf("--->");
	scanf_s("%d", &stk2);

	if (stk2 == 1 && shozikin >= 5000){				//	HPシード
		shozikin -= 5000;
		MP[st2 - 1].HP += 500;
		HP = MP[st2 - 1].HP;
		puts("HPシードを買った！");
		puc++;
	}
	else if (stk2 == 2 && shozikin >= 17000){		//	HPシード改
		shozikin -= 17000;
		MP[st2 - 1].HP += 1000;
		HP = MP[st2 - 1].HP;
		puts("HPシード改を買った！");
		puc2++;
	}
	else if (stk2 == 3 && shozikin >= 40000){		//	HPシード真
		shozikin -= 40000;
		MP[st2 - 1].HP += 2000;
		HP = MP[st2 - 1].HP;
		puts("HPシード真を買った！");
		puc3++;
	}
	else if (stk2 == 4 && shozikin >= 5000){			//	TPシード
		shozikin -= 5000;
		MP[st2 - 1].TP += 10;
		TP = MP[st2 - 1].TP;
		puts("TPシードを買った！");
		puc4++;
	}
	else if (stk2 == 5 && shozikin >= 17000){		//	TPシード改
		shozikin -= 17000;
		MP[st2 - 1].TP += 20;
		TP = MP[st2 - 1].TP;
		puts("TPシードを買った！");
		puc5++;
	}
	else if (stk2 == 6 && shozikin >= 40000){		//	TPシード真
		shozikin -= 40000;
		MP[st2 - 1].TP += 40;
		TP = MP[st2 - 1].TP;
		puts("TPシードを買った！");
		puc6++;
	}
	else if (stk2 == 7 && shozikin >= 3000){			//	atkシード
		shozikin -= 3000;
		MP[st2 - 1].atk += 50;
		atk = MP[st2 - 1].atk;
		puts("atkシードを買った！");
		puc15++;
	}
	else if (stk2 == 8 && shozikin >= 15000){		//	atkシード改
		shozikin -= 15000;
		MP[st2 - 1].atk += 100;
		atk = MP[st2 - 1].atk;
		puts("atkシード改を買った！");
		puc16++;
	}
	else if (stk2 == 9 && shozikin >= 35000){		//	atkシード真
		shozikin -= 35000;
		MP[st2 - 1].atk += 200;
		atk = MP[st2 - 1].atk;
		puts("atkシード真を買った！");
		puc17++;
	}
	else if (stk2 == 10 && shozikin >= 3000){		//	defシード
		shozikin -= 3000;
		MP[st2 - 1].def += 50;
		def = MP[st2 - 1].def;
		puts("defシードを買った！");
		puc7++;
	}
	else if (stk2 == 11 && shozikin >= 15000){		//	defシード改
		shozikin -= 15000;
		MP[st2 - 1].def += 100;
		def = MP[st2 - 1].def;
		puts("defシード改を買った！");
		puc8++;
	}
	else if (stk2 == 12 && shozikin >= 35000){		//	defシード真
		shozikin -= 35000;
		MP[st2 - 1].def += 200;
		def = MP[st2 - 1].def;
		puts("defシード真を買った！");
		puc9++;
	}
	else if (stk2 == 13 && shozikin >= 3000){		//	spdシード
		shozikin -= 3000;
		MP[st2 - 1].spd += 50;
		spd = MP[st2 - 1].spd;
		puts("spdシードを買った！");
		puc10++;
	}
	else if (stk2 == 14 && shozikin >= 15000){		//	spdシード改
		shozikin -= 15000;
		MP[st2 - 1].spd += 100;
		spd = MP[st2 - 1].spd;
		puts("spdシード改を買った！");
		puc11++;
	}
	else if (stk2 == 15 && shozikin >= 35000){		//	spdシード真
		shozikin -= 35000;
		MP[st2 - 1].spd += 200;
		spd = MP[st2 - 1].spd;
		puts("spdシード真を買った！");
		puc12++;
	}
	else if (stk2 == 16 && shozikin >= 30000){		//	デラックスシード
		shozikin -= 30000;
		MP[st2 - 1].HP += 750;
		MP[st2 - 1].TP += 20;
		MP[st2 - 1].def += 75;
		MP[st2 - 1].spd += 75;
		HP = MP[st2 - 1].HP;
		TP = MP[st2 - 1].TP;
		atk += 75;
		def = MP[st2 - 1].def;
		spd = MP[st2 - 1].spd;
		puts("デラックスシードを買った！");
		puc13++;
	}
	else if (stk2 == 17 && shozikin >= 55000){		//	デラックスシード真
		shozikin -= 55000;
		MP[st2 - 1].HP += 1500;
		MP[st2 - 1].TP += 40;
		MP[st2 - 1].def += 150;
		MP[st2 - 1].spd += 150;
		HP = MP[st2 - 1].HP;
		TP = MP[st2 - 1].TP;
		atk += 150;
		def = MP[st2 - 1].def;
		spd = MP[st2 - 1].spd;
		puts("デラックスシード真を買った！");
		puc14++;
	}
	else{
		puts("お金が足りません。");
		ShopEvent3();
		sk = 0;
		stk2 = 0;
	}

	printf("Name=%s: HP=%d: TP=%d: atk=%d: def=%d: spd=%d\n", name, HP, TP, atk, def, spd);

	if (sk == 1){
		printf("\n\n");
	}
}

void BookStore(){
	int stk3 = 0;		//	技を選択するときの変数
	int sk = 1;

	puts("☆ショップ☆");
	puts("1:ファイアソードの本		30000G");
	puts("2:ブリザードソードの本		30000G");
	puts("3:サンダーソードの本		30000G");
	puts("4:痛恨の一撃の本		60000G");
	puts("5:ジャンプ攻撃の本		35000G");
	puts("6:突進の本			25000G");
	puts("7:ファイアブレスの本		35000G");
	puts("8:コールドブレスの本		35000G");
	puts("9:サンダーブレスの本		35000G");
	puts("10:鉄壁の本			40000G");
	puts("11:ファイアの本			40000G");
	puts("12:ブリザードの本		40000G");
	puts("13:サンダーの本			40000G");
	puts("14:ウィンドスラッシュの本	40000G");
	puts("15:シールドの本			32000G");
	puts("16:シールドダウンの本		37000G");
	puts("17:スピードアップの本		32000G");
	puts("18:スピードダウンの本		37000G");
	printf("--->");
	scanf_s("%d", &stk3);

	if (stk3 == 1 && shozikin >= 30000 && fg1 == 0 && (st2 != 12 && st2 != 22 && st2 != 33 && st2 != 37 && st2 != 47)){		//	ファイアソード
		shozikin -= 30000;
		fg1 = 1;
		sac++;
		work++;
		puts("ファイアソードを覚えた！");
	}
	else if (stk3 == 2 && shozikin >= 30000 && fg2 == 0 && (st2 != 12 && st2 != 37 && st2 != 47 && st2 != 50)){	//	ブリザードソード
		shozikin -= 30000;
		fg2 = 1;
		sac++;
		work++;
		puts("ブリザードソードを覚えた！");
	}
	else if (stk3 == 3 && shozikin >= 30000 && fg3 == 0 && (st2 != 12 && st2 != 15 && st2 != 33 && st2 != 37 && st2 != 47 && st2 != 50)){	//	サンダーソード
		shozikin -= 30000;
		fg3 = 1;
		sac++;
		work++;
		puts("サンダーソードを覚えた！");
	}
	else if (stk3 == 4 && shozikin >= 60000 && fg4 == 0 && (st2 != 9 && st2 != 11 && st2 != 25 && st2 != 29 && st2 != 30 && st2 != 40 && st2 != 44 && st2 != 50 && st2 != 52 && st2 != 53 && st2 != 54)){	//	痛恨の一撃
		shozikin -= 60000;
		fg4 = 1;
		sac++;
		work++;
		puts("痛恨の一撃を覚えた！");
	}
	else if (stk3 == 5 && shozikin >= 35000 && fg5 == 0 && (st2 != 11 && st2 != 12 && st2 != 15 && st2 != 36 && st2 != 37 && st2 != 45 && st2 != 46 && st2 != 50)){	//	ジャンプ攻撃
		shozikin -= 35000;
		fg5 = 1;
		sac++;
		work++;
		puts("ジャンプ攻撃を覚えた！");
	}
	else if (stk3 == 6 && shozikin >= 25000 && fg6 == 0 && (st2 != 3 && st2 != 20 && st2 != 25 && st2 != 30 && st2 != 35 && st2 != 39 && st2 != 41 && st2 != 48 && st2 != 52)){	//	突進
		shozikin -= 25000;
		fg6 = 1;
		sac++;
		work++;
		puts("突進を覚えた！");
	}
	else if (stk3 == 7 && shozikin >= 35000 && fg7 == 0 && (st2 != 3 && st2 != 19 && st2 != 21 && st2 != 22 && st2 != 25 && st2 != 26 && st2 != 28 && st2 != 38 && st2 != 48)){	//	ファイアブレス
		shozikin -= 35000;
		fg7 = 1;
		sac++;
		work++;
		puts("ファイアブレスを覚えた！");
	}
	else if (stk3 == 8 && shozikin >= 35000 && fg8 == 0 && (st2 != 18 && st2 != 19 && st2 != 20 && st2 != 24 && st2 != 29 && st2 != 31 && st2 != 38 && st2 != 39 && st2 != 47 && st2 != 55)){	//	コールドブレス
		shozikin -= 35000;
		fg8 = 1;
		sac++;
		work++;
		puts("コールドブレスを覚えた！");
	}
	else if (stk3 == 9 && shozikin >= 35000 && fg9 == 0 && (st2 != 19 && st2 != 23 && st2 != 34 && st2 != 38 && st2 != 53)){	//	サンダーブレス
		shozikin -= 35000;
		fg9 = 1;
		sac++;
		work++;
		puts("サンダーブレスを覚えた！");
	}
	else if (stk3 == 10 && shozikin >= 40000 && fg11 == 0 && (st2 != 2 && st2 != 40)){	//	鉄壁
		shozikin -= 40000;
		fg11 = 1;
		sac++;
		work++;
		puts("鉄壁を覚えた！");
	}
	else if (stk3 == 11 && shozikin >= 40000 && fg12 == 0 && st2 != 1 && (st2 != 1 && st2 != 2 && st2 != 7 && st2 != 9 && st2 != 18 && st2 != 21 && st2 != 26 && st2 != 42 && st2 != 43)){	//	ファイア
		shozikin -= 40000;
		fg12 = 1;
		sac++;
		work++;
		puts("ファイアを覚えた！");
	}
	else if (stk3 == 12 && shozikin >= 40000 && fg13 == 0 && (st2 != 4 && st2 != 7 && st2 != 9 && st2 != 10 && st2 != 21 && st2 != 24 && st2 != 27 && st2 != 42 && st2 != 43 && st2 != 51)){	//	ブリザード
		shozikin -= 40000;
		fg13 = 1;
		sac++;
		work++;
		puts("ブリザードを覚えた！");
	}
	else if (stk3 == 13 && shozikin >= 40000 && fg14 == 0 && (st2 != 2 && st2 != 7 && st2 != 8 && st2 != 9 && st2 != 10 && st2 != 18 && st2 != 21 && st2 != 37 && st2 != 42)){	//	サンダー
		shozikin -= 40000;
		fg14 = 1;
		sac++;
		work++;
		puts("サンダーを覚えた！");
	}
	else if (stk3 == 14 && shozikin >= 40000 && fg15 == 0 && (st2 != 7 && st2 != 8 && st2 != 15 && st2 != 22 && st2 != 23 && st2 != 31 && st2 != 33 && st2 != 42 && st2 != 46)){	//	ウィンドスラッシュ
		shozikin -= 40000;
		fg15 = 1;
		sac++;
		work++;
		puts("ウィンドスラッシュを覚えた！");
	}
	else if (stk3 == 15 && shozikin >= 32000 && fg16 == 0 && (st2 != 2 && st2 != 5 && st2 != 6 && st2 != 7 && st2 != 8 && st2 != 10 && st2 != 21 && st2 != 27 && st2 != 40 && st2 != 43 && st2 != 49)){	//	シールド
		shozikin -= 32000;
		fg16 = 1;
		sac++;
		work++;
		puts("シールドを覚えた！");
	}
	else if (stk3 == 16 && shozikin >= 37000 && fg17 == 0 && (st2 != 1 && st2 != 6 && st2 != 10 && st2 != 13 && st2 != 15 && st2 != 18 && st2 != 21 && st2 != 33 && st2 != 35 && st2 != 37 && st2 != 44 && st2 != 46 && st2 != 49)){	//	シールドダウン
		shozikin -= 37000;
		fg17 = 1;
		sac++;
		work++;
		puts("シールドダウンを覚えた！");
	}
	else if (stk3 == 17 && shozikin >= 32000 && fg18 == 0 && (st2 != 5 && st2 != 8 && st2 != 18 && st2 != 29 && st2 != 31 && st2 != 39 && st2 != 42 && st2 != 43 && st2 != 45 && st2 != 49)){	//	スピードアップ
		shozikin -= 32000;
		fg18 = 1;
		sac++;
		work++;
		puts("スピードアップを覚えた！");
	}
	else if (stk3 == 18 && shozikin >= 37000 && fg19 == 0 && (st2 != 5 && st2 != 13 && st2 != 14 && st2 != 21 && st2 != 22 && st2 != 27 && st2 != 34 && st2 != 37 && st2 != 49 && st2 != 51)){	//	スピードダウン
		shozikin -= 37000;
		fg19 = 1;
		sac++;
		work++;
		puts("スピードダウンを覚えた！");
	}
	else{
		if (fg1 == 1 || fg2 == 1 || fg3 == 1 || fg4 == 1 || fg5 == 1 || fg6 == 1 || fg7 == 1 || fg8 == 1 || fg9 == 1 || fg10 == 1 || fg11 == 1 || fg12 == 1 || fg13 == 1 || fg14 == 1 || fg15 == 1 || fg16 == 1 || fg17 == 1 || fg18 == 1 || fg19 == 1){
			puts("すでに覚えています。");
		}
		else{
			puts("お金が足りません。");
			printf("\n\n");
		}
		BookStore();
		sk = 0;
		stk3 = 0;
	}

	if (sk == 1){
		printf("\n\n");
	}
}

int main(void)
{
	int loop, loop2 = 1;	//	繰り返し用変数(最初のループ、バトルモードのループ)
	int sentaku3 = 0, sentaku4 = 0, sentaku5 = 0;	// バトルモードで使用、トーナメントモードで店に行くかどうか選択、TMで店を選択
	int turn = 0, Kcount = -1;	//	ターン数計算、行動順決定(０ならPlayerが先攻で、１ならCPUが先攻)
	int flag = 0, flag2 = 0;	//	Playerが先攻の場合のフラグ、CPUが先攻の場合のフラグ２
	int flag3 = 0, flag4 = 0, flag5 = 0;				//	乱数初期化フラグ、バトルフラグ(P、C)
	char ch2[5];
	//	トーナメントモードで使う変数
	int loop3 = 1, loop4 = 1, loop5 = 1;		//	トーナメントモードの最初の繰り返し、TMのバトルフェーズの繰り返し用変数、TMの買い物フェーズのループ
	int win = 0, c = 0;							//	何回戦まで進んだかの変数、買い物カウント

	loop = 1;
	while (loop == 1){				//	最初の繰り返し
		sentaku = 0;
		sentaku3 = 0;
		sentaku4 = 0;
		sentaku5 = 0;
		turn = 0;
		c = 0;
		shozikin = 30000;

		Init();

		if (flag000 == 0){
			srand((unsigned int)time(NULL));
			flag000 = 1;
		}

		printf("メインメニュー\n1:バトルモード 2:トーナメントモード 3:説明 4:モンスターデータ \n5:スコア(バトル) 6:スコア(トーナメント) 7:終了\n");
		scanf_s("%d", &sentaku);

		int r13 = 0, r14 = 0, r15 = 0, r16 = 0, r17 = 0, r18 = 0, r19 = 0;	//	(CPU専用関数)CSAcommandで技を選択するときに使用(r10～)
		int r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0;
		int r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0, r32 = 0, r33 = 0;
		int r34 = 0, r35 = 0, r36 = 0, r37 = 0, r38 = 0, r39 = 0, r40 = 0;
		int r41 = 0, r42 = 0, r43 = 0, r44 = 0, r45 = 0, r46 = 0, r47 = 0;
		int r48 = 0, r49 = 0, r50 = 0, r51 = 0, r52 = 0, r53 = 0, r54 = 0;
		int r55 = 0, r56 = 0, r57 = 0, r58 = 0, r59 = 0, r60 = 0, r61 = 0;
		int r62 = 0, r63 = 0, r64 = 0;
		int cflag = 0;

		if (sentaku == 1){								//	バトルモード～
			do{
				puts("1=ニューゲーム: 2=ロードゲーム");
				scanf_s("%d", &sentaku3);

				if (sentaku3 == 1 || sentaku3 == 2){
					break;
				}
				else{
					puts("１か２を入力してください。");
				}
			} while (sentaku3 != 1 || sentaku3 != 2);

			PMST();				//	プレイヤーモンスター決定フェーズ
			CMST();				//	CPUモンスター決定フェーズ

			loop2 = 1;
			while (loop2 == 1){
				turn++;

				Kcount = Act(Kcount);

				//	バトルフェーズ
				printf("----------------turn%d----------------\n", turn);

				//	--------Playerが先攻の場合の処理----------
				if (Kcount == 0){
					PAC();
					Kcount++;
				}
				if (Kcount == 1 && HP2 >= 1){
					CAC();
					Kcount++;
				}

				//	----------CPUが先攻の場合の処理-------------
				if (Kcount == 5){
					CAC();
					Kcount++;
				}
				if (Kcount == 6 && HP >= 1){
					PAC();
				}

				puts("適当なキーを入力してください。");
				scanf_s("%s", ch2, 5);
				printf("\n");

				if (HP <= 0){
					HP = 0;
					flag4 = 1;
				}
				if (HP2 <= 0){
					HP2 = 0;
					flag5 = 1;
				}

				if (turn == 30){
					if (sentaku3 == 1){						//	ニューゲームを選択した場合の処理
						error = fopen_s(&fp, "score.txt", "w");
					}
					else{									//	ロードゲームを選択した場合の処理
						error = fopen_s(&fp, "score.txt", "a");
					}
					if (error == NULL){
						puts("File Open Error");
					}
					puts("タイムオーバー！！");
					if (HP > HP2){					//	CPUよりもPlayerのHPが多い場合
						GameScore(name, HP, TP, atk, def, spd, name2, HP2, TP2, atk2, def2, spd2);
						puts("CPUの負け。");
						fprintf(fp, "CPUの負け。\n");
						fclose(fp);
						loop2 = 0;
						loop = GameEnd(loop);
					}
					else if (HP < HP2){				//	PlayerよりもCPUのHPが多い場合
						GameScore(name, HP, TP, atk, def, spd, name2, HP2, TP2, atk2, def2, spd2);
						puts("Playerの負け。");
						fprintf(fp, "Playerの負け。\n");
						fclose(fp);
						loop2 = 0;
						loop = GameEnd(loop);
					}
					else{
						puts("PlayerとCPUのHPが同じなので引き分けです。");
						GameScore(name, HP, TP, atk, def, spd, name2, HP2, TP2, atk2, def2, spd2);
						fprintf(fp, "引き分け。\n");
						fclose(fp);
						loop2 = 0;
						loop = GameEnd(loop);
					}
				}

				if (HP == 0 && flag4 == 1){				//	Playerの負けの場合
					if (sentaku3 == 1){						//	ニューゲームを選択した場合の処理
						error = fopen_s(&fp, "score.txt", "w");
					}
					else{									//	ロードゲームを選択した場合の処理
						error = fopen_s(&fp, "score.txt", "a");
					}
					if (error == NULL){
						puts("File Open Error");
					}
					puts("PlayerのHPが0になったので、Playerの負けです。");
					GameScore(name, HP, TP, atk, def, spd, name2, HP2, TP2, atk2, def2, spd2);
					puts("Playerの負け。");
					fprintf(fp, "Playerの負け。\n");

					fclose(fp);

					loop2 = 0;

					loop = GameEnd(loop);
					break;
				}

				if (HP2 == 0 && flag5 == 1){				//	CPUが負けの場合
					if (sentaku3 == 1){						//	ニューゲームを選択した場合の処理
						error = fopen_s(&fp, "score.txt", "w");
					}
					else{									//	ロードゲームを選択した場合の処理
						error = fopen_s(&fp, "score.txt", "a");
					}
					if (error == NULL){
						puts("File Open Error");
					}
					puts("CPUのHPが0になったので、CPUの負けです。");
					GameScore(name, HP, TP, atk, def, spd, name2, HP2, TP2, atk2, def2, spd2);
					puts("CPUの負け。");
					fprintf(fp, "CPUの負け。\n");

					fclose(fp);

					loop2 = 0;

					loop = GameEnd(loop);
					break;
				}
			}
		}
		else if (sentaku == 2){			//	トーナメントモード
			win = 0;

			do{
				puts("1=ニューゲーム: 2=ロードゲーム");
				scanf_s("%d", &sentaku3);

				if (sentaku3 == 1 || sentaku3 == 2){
					break;
				}
				else{
					puts("１か２を入力してください。");
				}
			} while (sentaku3 != 1 || sentaku3 != 2);

			PMST();

			printf("所持金=%d\n", shozikin);

			puts("ショップを利用しますか？(1=Yes: 2=No)");
			scanf_s("%d", &sentaku4);

			if (sentaku4 == 1){
				ShopEvent();		//	最初の買い物
			}

			loop3 = 1;
			while (loop3 == 1){
				turn = 0;
				win++;
				if (win == 1){		//	1回戦の相手モンスター決定フェーズ
					TM1();
					HP2 += 100;
					TP2 += 3;
					atk2 += 10;
					def2 += 10;
					spd2 += 10;
				}
				else if (win == 2){
					TM2();
					HP2 += 500;
					TP2 += 5;
					atk2 += 50;
					def2 += 50;
					spd2 += 50;
				}
				else if (win == 3){
					TM3();
					HP2 += 1000;
					TP2 += 10;
					atk2 += 100;
					def2 += 100;
					spd2 += 100;
				}
				else if (win == 4){
				}

				loop4 = 1;
				while (loop4 == 1){		//	バトルフェーズ
					turn++;

					Kcount = Act(Kcount);

					printf("----------------turn%d----------------\n", turn);

					//	--------Playerが先攻の場合の処理----------
					if (Kcount == 0){
						PAC();
						Kcount++;
					}
					if (Kcount == 1 && HP2 >= 1){
						CAC();
						Kcount++;
					}

					//	----------CPUが先攻の場合の処理-------------
					if (Kcount == 5){
						CAC();
						Kcount++;
					}
					if (Kcount == 6 && HP >= 1){
						PAC();
					}

					puts("適当なキーを入力してください。");
					scanf_s("%s", ch2, 5);
					printf("\n");

					if (HP <= 0){
						HP = 0;
						flag4 = 1;
					}
					if (HP2 <= 0){
						HP2 = 0;
						flag5 = 1;
					}

					if (HP == 0 && flag4 == 1){				//	Playerの負けの場合
						if (sentaku3 == 1){						//	ニューゲームを選択した場合の処理
							error = fopen_s(&fp, "tournament.txt", "w");
						}
						else{									//	ロードゲームを選択した場合の処理
							error = fopen_s(&fp, "tournament.txt", "a");
						}
						if (error == NULL){
							puts("File Open Error");
						}
						puts("PlayerのHPが0になったので、Playerの負けです。");
						GameScore(name, HP, TP, atk, def, spd, name2, HP2, TP2, atk2, def2, spd2);
						puts("Playerの負け。");
						if (win == 1){
							fprintf(fp, "1回戦敗退。\n");
						}
						else if (win == 2){
							fprintf(fp, "2回戦敗退。\n");
							MP[st2 - 1].HP -= 500;
							MP[st2 - 1].TP -= 5;
							MP[st2 - 1].atk -= 50;
							MP[st2 - 1].def -= 50;
							MP[st2 - 1].spd -= 50;
						}
						else if (win == 3){
							fprintf(fp, "3回戦敗退。\n");
							MP[st2 - 1].HP -= 1000;
							MP[st2 - 1].TP -= 10;
							MP[st2 - 1].atk -= 100;
							MP[st2 - 1].def -= 100;
							MP[st2 - 1].spd -= 100;
						}
						else if (win == 4){
							fprintf(fp, "4回戦敗退。\n");
							MP[st2 - 1].HP -= 1500;
							MP[st2 - 1].TP -= 15;
							MP[st2 - 1].atk -= 150;
							MP[st2 - 1].def -= 150;
							MP[st2 - 1].spd -= 150;
						}
						else if (win == 5){
							fprintf(fp, "5回戦敗退。\n");
							MP[st2 - 1].HP -= 2000;
							MP[st2 - 1].TP -= 20;
							MP[st2 - 1].atk -= 200;
							MP[st2 - 1].def -= 200;
							MP[st2 - 1].spd -= 200;
						}

						//	HPシードを買った場合
						if (puc == 1){
							MP[st2 - 1].HP -= 500;
						}
						else if (puc == 2){
							MP[st2 - 1].HP -= 1000;
						}
						else if (puc == 3){
							MP[st2 - 1].HP -= 1500;
						}
						else if (puc == 4){
							MP[st2 - 1].HP -= 2000;
						}
						else if (puc == 5){
							MP[st2 - 1].HP -= 2500;
						}

						//	HPシード改を買った場合
						if (puc2 == 1){
							MP[st2 - 1].HP -= 1000;
						}
						else if (puc2 == 2){
							MP[st2 - 1].HP -= 2000;
						}
						else if (puc2 == 3){
							MP[st2 - 1].HP -= 3000;
						}
						else if (puc2 == 4){
							MP[st2 - 1].HP -= 4000;
						}
						else if (puc2 == 5){
							MP[st2 - 1].HP -= 5000;
						}

						//	HPシード真を買った場合
						if (puc3 == 1){
							MP[st2 - 1].HP -= 2000;
						}
						else if (puc3 == 2){
							MP[st2 - 1].HP -= 3000;
						}

						//	TPシードを買った場合
						if (puc4 == 1){
							MP[st2 - 1].TP -= 10;
						}
						else if (puc4 == 2){
							MP[st2 - 1].TP -= 20;
						}
						else if (puc4 == 3){
							MP[st2 - 1].TP -= 30;
						}
						else if (puc4 == 4){
							MP[st2 - 1].TP -= 40;
						}
						else if (puc5 == 5){
							MP[st2 - 1].TP -= 50;
						}

						//	TPシード改を買った場合
						if (puc5 == 1){
							MP[st2 - 1].TP -= 20;
						}
						else if (puc5 == 2){
							MP[st2 - 1].TP -= 40;
						}
						else if (puc5 == 3){
							MP[st2 - 1].TP -= 60;
						}
						else if (puc5 == 4){
							MP[st2 - 1].TP -= 80;
						}
						else if (puc5 == 5){
							MP[st2 - 1].TP -= 100;
						}

						//	TPシード真を買った場合
						if (puc6 == 1){
							MP[st2 - 1].TP -= 40;
						}
						else if (puc6 == 2){
							MP[st2 - 1].TP -= 80;
						}

						//	atkシードを買った場合
						if (puc15 == 1){
							MP[st2 - 1].atk -= 50;
						}
						else if (puc15 == 2){
							MP[st2 - 1].atk -= 100;
						}
						else if (puc15 == 3){
							MP[st2 - 1].atk -= 150;
						}
						else if (puc15 == 4){
							MP[st2 - 1].atk -= 200;
						}
						else if (puc15 == 5){
							MP[st2 - 1].atk -= 250;
						}

						//	atkシード改を買った場合
						if (puc16 == 1){
							MP[st2 - 1].atk -= 100;
						}
						else if (puc16 == 2){
							MP[st2 - 1].atk -= 200;
						}
						else if (puc16 == 3){
							MP[st2 - 1].atk -= 300;
						}
						else if (puc16 == 4){
							MP[st2 - 1].atk -= 400;
						}
						else if (puc16 == 5){
							MP[st2 - 1].atk -= 500;
						}

						//	atkシード真を買った場合
						if (puc17 == 1){
							MP[st2 - 1].atk -= 200;
						}
						else if (puc17 == 2){
							MP[st2 - 1].atk -= 400;
						}

						//	defシードを買った場合
						if (puc7 == 1){
							MP[st2 - 1].def -= 50;
						}
						else if (puc7 == 2){
							MP[st2 - 1].def -= 100;
						}
						else if (puc7 == 3){
							MP[st2 - 1].def -= 150;
						}
						else if (puc7 == 4){
							MP[st2 - 1].def -= 200;
						}
						else if (puc7 == 5){
							MP[st2 - 1].def -= 250;
						}

						//	defシード改を買った場合
						if (puc8 == 1){
							MP[st2 - 1].def -= 100;
						}
						else if (puc8 == 2){
							MP[st2 - 1].def -= 200;
						}
						else if (puc8 == 3){
							MP[st2 - 1].def -= 300;
						}
						else if (puc8 == 4){
							MP[st2 - 1].def -= 400;
						}
						else if (puc8 == 5){
							MP[st2 - 1].def -= 500;
						}

						//	defシード真を買った場合
						if (puc9 == 1){
							MP[st2 - 1].def -= 200;
						}
						else if (puc9 == 2){
							MP[st2 - 1].def -= 400;
						}

						//	spdシードを買った場合
						if (puc10 == 1){
							MP[st2 - 1].spd -= 50;
						}
						else if (puc10 == 2){
							MP[st2 - 1].spd -= 100;
						}
						else if (puc10 == 3){
							MP[st2 - 1].spd -= 150;
						}
						else if (puc10 == 4){
							MP[st2 - 1].spd -= 200;
						}
						else if (puc10 == 5){
							MP[st2 - 1].spd -= 250;
						}

						//	spdシード改を買った場合
						if (puc11 == 1){
							MP[st2 - 1].spd -= 100;
						}
						else if (puc11 == 2){
							MP[st2 - 1].spd -= 200;
						}
						else if (puc11 == 3){
							MP[st2 - 1].spd -= 300;
						}
						else if (puc11 == 4){
							MP[st2 - 1].spd -= 400;
						}
						else if (puc11 == 5){
							MP[st2 - 1].spd -= 500;
						}

						//	spdシード真を買った場合
						if (puc12 == 1){
							MP[st2 - 1].spd -= 200;
						}
						else if (puc12 == 2){
							MP[st2 - 1].spd -= 400;
						}

						//	デラックスシードを買った場合
						if (puc13 == 1){
							MP[st2 - 1].HP -= 750;
							MP[st2 - 1].TP -= 20;
							MP[st2 - 1].atk -= 75;
							MP[st2 - 1].def -= 75;
							MP[st2 - 1].spd -= 75;
						}
						else if (puc14 == 2){
							MP[st2 - 1].HP -= 1500;
							MP[st2 - 1].TP -= 40;
							MP[st2 - 1].atk -= 150;
							MP[st2 - 1].def -= 150;
							MP[st2 - 1].spd -= 150;
						}

						//	デラックスシード真を買った場合
						if (puc14 == 1){
							MP[st2 - 1].HP -= 1500;
							MP[st2 - 1].TP -= 40;
							MP[st2 - 1].atk -= 150;
							MP[st2 - 1].def -= 150;
							MP[st2 - 1].spd -= 150;
						}

						fclose(fp);

						loop3 = 0;
						loop4 = 0;

						loop = GameEnd(loop);
						break;
					}

					if (HP2 == 0 && flag5 == 1){			//	CPUが負けの場合
						if (win == 1){					//	1回戦勝利のとき
							printf("CPUのHPが0になったので第２回戦に進出です。\n");
							printf("第1回戦の賞金は3000Gです。\n");
							shozikin += 3000;

							MP[st2 - 1].HP += 500;
							MP[st2 - 1].TP += 5;
						}
						else if (win == 2){				//	2回戦勝利のとき
							printf("CPUのHPが0になったので第３回戦に進出です。\n");
							printf("第2回戦の賞金は8000Gです。\n");
							shozikin += 8000;
							MP[st2 - 1].HP += 500;
							MP[st2 - 1].TP += 5;
						}
						else if (win == 3){				//	3回戦勝利のとき
							printf("CPUのHPが0になったので第４回戦に進出です。\n");
							printf("第3回戦の賞金は14000Gです。\n");
							shozikin += 14000;
							MP[st2 - 1].HP += 500;
							MP[st2 - 1].TP += 5;
						}
						else if (win == 4){				//	4回戦勝利のとき
							printf("CPUのHPが0になったので第５回戦に進出です。\n");
							printf("第4回戦の賞金は18000Gです。\n");
							shozikin += 18000;
							MP[st2 - 1].HP += 500;
							MP[st2 - 1].TP += 5;
						}
						else if (win == 5){
							printf("CPUのHPが0になったので決勝戦に進出です。\n");
							printf("第5回戦の賞金は25000Gです。\n");
							shozikin += 25000;
							MP[st2 - 1].HP += 500;
							MP[st2 - 1].TP += 5;
						}

						if (def < MP[st2 - 1].def){
							def = MP[st2 - 1].def;
						}
						if (def > MP[st2 - 1].def){
							def = MP[st2 - 1].def;
						}
						if (spd < MP[st2 - 1].spd){
							spd = MP[st2 - 1].spd;
						}
						if (spd > MP[st2 - 1].spd){
							spd = MP[st2 - 1].spd;
						}

						HP = MP[st2 - 1].HP;
						TP = MP[st2 - 1].TP;
						puts("HPとTPが回復しました!");

						//	レベルアップフェーズ
						MP[st2 - 1].atk += 50;
						MP[st2 - 1].def += 50;
						MP[st2 - 1].spd += 50;
						atk = MP[st2 - 1].atk;
						def = MP[st2 - 1].def;
						spd = MP[st2 - 1].spd;

						printf("\nLevel UP! HP + 500  TP + 5  atk + 50 def + 50 spd + 50\n");
						printf("Name=%s: HP=%d: TP=%d: atk=%d: def=%d: spd=%d\n", name, HP, TP, atk, def, spd);

						printf("現在の所持金は%dです。\n", shozikin);

						puts("ショップを利用しますか？(1=Yes: 2=No)");
						scanf_s("%d", &sentaku4);

						if (sentaku4 == 1){		//	買い物フェーズ(1回だけ可能)
							loop5 = 1;
							while (loop5 == 1){
								puts("1:ショップ１(回復アイテムの店)");
								puts("2:ショップ２(パワーアップ系アイテムの店)");
								puts("3:ブックストア");
								printf("どの店に行きますか？(数字で)--->");
								scanf_s("%d", &sentaku5);
								printf("\n\n\n");

								if (sentaku5 == 1){	//	ショップ１
									ShopEvent2();
									loop5 = 0;
								}
								else if (sentaku5 == 2){	//	ショップ２
									ShopEvent3();
									loop5 = 0;
								}
								else if (sentaku5 == 3){	//	ブックストア
									BookStore();
									loop5 = 0;
								}
								else{
									puts("１～３までの数字を入力してください。");
									printf("\n\n");
									loop5 = 1;
								}
							}
						}
						printf("\n\n\n");
						loop4 = 0;
					}
				}
			}
		}
	}

	return 0;
}