//	�o�g���Q�[���Q
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MONUM 60		//	�ʏ탂���X�^�[�̑���
#define INUM 5	//	�A�C�e����������(�g�[�i�����g���[�h�̂�)
#define _CRT_SECURE_NO_WARNINGS

//	(�\����)Player
typedef struct MonsterP{
	char name[30];
	int HP;
	int TP;
	int atk;
	int def;
	int spd;
}MstP;

//	(�\����)CPU
typedef struct MonsterC{
	char name[30];
	int HP;
	int TP;
	int atk;
	int def;
	int spd;
}MstC;

//	(�\����)LB
typedef struct LBoss{
	char name[20];
	int HP;
	int TP;
	int atk;
	int def;
	int spd;
} LB;

//	���ϐ��̐錾
MstP MP[MONUM] = {
	{ "�u���[�X���C��", 3000, 8, 680, 240, 370 },
	{ "�A�C�A���X���C��", 1500, 25, 600, 500, 400 },
	{ "���b�h�X���C��", 3200, 7, 750, 150, 320 },
	{ "����", 3400, 12, 670, 280, 330 },
	{ "�C�O��", 2500, 18, 760, 350, 200 },
	{ "�C��", 2950, 15, 670, 200, 390 },
	{ "���@�g��", 2700, 40, 650, 320, 270 },
	{ "�R�J�g���X", 3050, 19, 710, 200, 300 },
	{ "�n�[�r�[", 2800, 23, 700, 260, 330 },
	{ "�g�����g", 3900, 26, 640, 380, 180 },
	{ "�S�u����", 3500, 6, 720, 270, 210 },
	{ "�X�P���g��", 3300, 13, 740, 260, 220 },
	{ "���b��l", 3150, 10, 690, 210, 260 },
	{ "�|�S���l", 2500, 9, 610, 450, 170 },
	{ "�R�{���g", 3700, 17, 700, 310, 320 },
	{ "�]���r", 5000, 0, 770, 100, 80 },
	{ "�I�[�K", 4500, 0, 800, 70, 120 },
	{ "�O���t�H��", 3250, 20, 730, 290, 270 },
	{ "�R�h��", 2700, 10, 760, 340, 160 },
	{ "�S�C��", 3450, 13, 700, 260, 300 },
	{ "�㖂���m", 3300, 70, 660, 330, 300 },
	{ "���R�m", 4000, 30, 740, 300, 340 },
	{ "�O���[�^�[�f�[����", 4200, 28, 780, 270, 180 },
	{ "�剤�C�J", 4000, 12, 800, 220, 200 },
	{ "�h���S���t���C", 3450, 13, 730, 260, 290 },
	{ "�t�@�C�A�G�������^��", 4300, 20, 650, 250, 200 },
	{ "�R�[���h�G�������^��", 4200, 35, 600, 380, 260 },
	{ "�t���C���W���C�A���g", 3050, 15, 710, 320, 230 },
	{ "�t���X�g�W���C�A���g", 3300, 24, 670, 320, 260 },
	{ "�P���x���X", 3650, 11, 780, 190, 280 },
	{ "���@���p�C�A�o�b�g", 3550, 22, 695, 220, 310 },
	{ "�~�C���j", 3800, 0, 720, 340, 150 },
	{ "�K�[�S�C��", 3700, 27, 730, 270, 290 },
	{ "�o�V���X�N", 2950, 24, 700, 300, 270 },
	{ "�|�C�Y���X�l�C�N", 3100, 31, 740, 280, 290 },
	{ "�_�[�N�S�u����", 2750, 6, 800, 120, 350 },
	{ "�����\���W���[", 3250, 33, 680, 310, 300 },
	{ "���C�o�[��", 3500, 10, 690, 360, 210 },
	{ "�l�򂢃V���[�N", 3900, 23, 750, 250, 310 },
	{ "�R���a", 2900, 37, 700, 320, 130 },
	{ "�W���C�A���g���b�g", 4100, 9, 765, 350, 10 },
	{ "�S�[�X�g", 3600, 40, 710, 230, 150 },
	{ "�O��������", 2800, 43, 745, 220, 360 },
	{ "�L���O�R�u��", 3900, 14, 770, 210, 330 },
	{ "�����E��A", 3600, 12, 760, 330, 250 },
	{ "�����E��B", 3200, 36, 680, 270, 380 },
	{ "�S�[�X�g�i�C�g", 2700, 28, 670, 340, 320 },
	{ "����", 4300, 11, 760, 300, 220 },
	{ "�d�p�m", 3500, 60, 730, 270, 260 },
	{ "���U�[�h�}��", 3300, 15, 790, 250, 220 },
	{ "�O���[���X���C��", 3400, 18, 720, 290, 310 },
	{ "�}�b�h�}��", 2600, 9, 700, 400, 50 },
	{ "�l�򂢐A��", 3450, 17, 690, 290, 340 },
	{ "�W���C�A���g", 4700, 6, 790, 160, 180 },
	{ "�L�}�C��", 3850, 23, 785, 310, 210 }
};

MstC MC[MONUM] = {
	{ "�u���[�X���C��", 3000, 8, 680, 240, 370 },
	{ "�A�C�A���X���C��", 1500, 25, 600, 500, 400 },
	{ "���b�h�X���C��", 3200, 7, 750, 150, 320 },
	{ "����", 3400, 12, 670, 280, 330 },
	{ "�C�O��", 2500, 18, 760, 350, 200 },
	{ "�C��", 2950, 15, 670, 200, 390 },
	{ "���@�g��", 2700, 40, 650, 320, 270 },
	{ "�R�J�g���X", 3050, 19, 710, 200, 300 },
	{ "�n�[�r�[", 2800, 23, 700, 260, 330 },
	{ "�g�����g", 3900, 26, 640, 380, 180 },
	{ "�S�u����", 3500, 6, 720, 270, 210 },
	{ "�X�P���g��", 3300, 13, 740, 260, 220 },
	{ "���b��l", 3150, 10, 690, 210, 260 },
	{ "�|�S���l", 2500, 9, 610, 450, 170 },
	{ "�R�{���g", 3700, 17, 700, 310, 320 },
	{ "�]���r", 5000, 0, 770, 100, 80 },
	{ "�I�[�K", 4500, 0, 800, 70, 120 },
	{ "�O���t�H��", 3250, 20, 730, 290, 270 },
	{ "�R�h��", 2700, 10, 760, 340, 160 },
	{ "�S�C��", 3450, 13, 700, 260, 300 },
	{ "�㖂���m", 3300, 70, 660, 330, 300 },
	{ "���R�m", 4000, 30, 740, 300, 340 },
	{ "�O���[�^�[�f�[����", 4200, 28, 780, 270, 180 },
	{ "�剤�C�J", 4000, 12, 800, 220, 200 },
	{ "�h���S���t���C", 3450, 13, 730, 260, 290 },
	{ "�t�@�C�A�G�������^��", 4300, 20, 650, 250, 200 },
	{ "�R�[���h�G�������^��", 4200, 35, 600, 380, 260 },
	{ "�t���C���W���C�A���g", 3050, 15, 710, 320, 230 },
	{ "�t���X�g�W���C�A���g", 3300, 24, 670, 320, 260 },
	{ "�P���x���X", 3650, 11, 780, 190, 280 },
	{ "���@���p�C�A�o�b�g", 3550, 22, 695, 220, 310 },
	{ "�~�C���j", 3800, 0, 720, 340, 150 },
	{ "�K�[�S�C��", 3700, 27, 730, 270, 290 },
	{ "�o�V���X�N", 2950, 24, 700, 300, 270 },
	{ "�|�C�Y���X�l�C�N", 3100, 31, 740, 280, 290 },
	{ "�_�[�N�S�u����", 2750, 6, 800, 120, 350 },
	{ "�����\���W���[", 3250, 33, 680, 310, 300 },
	{ "���C�o�[��", 3500, 10, 690, 360, 210 },
	{ "�l�򂢃V���[�N", 3900, 23, 750, 250, 310 },
	{ "�R���a", 2900, 37, 700, 320, 130 },
	{ "�W���C�A���g���b�g", 4100, 9, 765, 350, 10 },
	{ "�S�[�X�g", 3600, 40, 710, 230, 150 },
	{ "�O��������", 2800, 43, 745, 220, 360 },
	{ "�L���O�R�u��", 3900, 14, 770, 210, 330 },
	{ "�����E��A", 3600, 12, 760, 330, 250 },
	{ "�����E��B", 3200, 36, 680, 270, 380 },
	{ "�S�[�X�g�i�C�g", 2700, 28, 670, 340, 320 },
	{ "����", 4300, 11, 760, 300, 220 },
	{ "�d�p�m", 3500, 60, 730, 270, 260 },
	{ "���U�[�h�}��", 3300, 15, 790, 250, 220 },
	{ "�O���[���X���C��", 3400, 18, 720, 290, 310 },
	{ "�}�b�h�}��", 2600, 9, 700, 400, 50 },
	{ "�l�򂢐A��", 3450, 17, 690, 290, 340 },
	{ "�W���C�A���g", 4700, 6, 790, 160, 180 },
	{ "�L�}�C��", 3850, 23, 785, 310, 210 }
};

//	���ϐ�
FILE* fp;
errno_t error;										//	�t�@�C���p�ϐ�
int sentaku = 0;									//	���C�����j���[�I��
int HP = 0, TP = 0, atk = 0, def = 0, spd = 0;		//	�v���C���[�p�ϐ�
int HP2 = 0, TP2 = 0, atk2 = 0, def2 = 0, spd2 = 0;	//	CPU�p�ϐ�
char name[30], name2[30];							//	�����X�^�[���i�[�ϐ�
int stk1 = 0, st2 = 0, r = 0;						//	PAC��Player���R�}���h��I������Ƃ��Ɏg���ϐ��APMST�Ń����X�^�[��I������Ƃ��Ɏg���ϐ��ACMST�Ń����X�^�[�𗐐��Ō��肷��Ƃ��Ɏg���ϐ�
int flag000 = 0;
int flag10 = 0, flag11 = 0, flag12 = 0, flag13 = 0, flag14 = 0;
int flag15 = 0, flag16 = 0, flag17 = 0, flag18 = 0, flag19 = 0;		//	����Z���g�p���ꂽ���ǂ����̃t���O(Player)
int flag025 = 0, flag026 = 0, flag027 = 0, flag028 = 0;
int flag20 = 0, flag21 = 0, flag22 = 0, flag23 = 0, flag24 = 0;		//	�⏕����Z���g�p���ꂽ���ǂ����̃t���O(�t���O20�`24)(Player)

int flag30 = 0, flag31 = 0, flag32 = 0, flag33 = 0, flag34 = 0;
int flag35 = 0, flag36 = 0, flag37 = 0, flag38 = 0, flag39 = 0;		//	����Z���g�p���ꂽ���ǂ����̃t���O(CPU)
int flag40 = 0, flag41 = 0, flag42 = 0, flag43 = 0;
int flag25 = 0, flag26 = 0, flag27 = 0, flag28 = 0, flag29 = 0;		//	�⏕����Z���g�p���ꂽ���ǂ����̃t���O(�t���O25�`29)(CPU)
int r7 = 0;											//	CAC�ōs�������߂�Ƃ��Ɏg�p����ϐ�

int st3 = 0, st4 = 0, st5 = 0, st6 = 0, st7 = 0;	//	SAcommand�ŋZ��I������Ƃ��Ɏg�p(st3�`)(Player)
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
int flag = 0;										//	SAcommand�Ŏg�p����t���O�p�ϐ�

int r13 = 0, r14 = 0, r15 = 0, r16 = 0, r17 = 0, r18 = 0, r19 = 0;	//	(CPU��p�֐�)CSAcommand�ŋZ��I������Ƃ��Ɏg�p(r10�`)
int r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0;
int r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0, r32 = 0, r33 = 0;
int r34 = 0, r35 = 0, r36 = 0, r37 = 0, r38 = 0, r39 = 0, r40 = 0;
int r41 = 0, r42 = 0, r43 = 0, r44 = 0, r45 = 0, r46 = 0, r47 = 0;
int r48 = 0, r49 = 0, r50 = 0, r51 = 0, r52 = 0, r53 = 0, r54 = 0;
int r55 = 0, r56 = 0, r57 = 0, r58 = 0, r59 = 0, r60 = 0, r61 = 0;
int r62 = 0, r63 = 0, r64 = 0, r65 = 0;
int cflag = 0, tflg = 0;

//	�A�C�e���֘A�ϐ�(�o�g�����[�h�̂�)
int ist = 0;			//	�ǂ̃A�C�e����I���������̕ϐ�
int c1, c2, c3, c4, c5;	//	�A�C�e��������g�p�������̃t���O(�n�[�u)
int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10;	//	�n�[�u(��)&�t���O
int e1, e2, e3, e4, e5, e6, e7, e8, e9, e10;	//	�n�[�u(����)&�t���O
int g1, g2, g3, g4, g5, g6, g7, g8, g9, g10;	//	�o�W��&�t���O
int h1, h2, h3, h4, h5, h6, h7, h8, h9, h10;	//	�o�W��(��)���t���O
int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;	//	�o�W��(����)���t���O
int j1, j2, j3, j4, j5, j6, j7, j8, j9, j10;	//	�o�W��(��)���t���O
int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;	//	�x���B���t���O
int l1, l2, l3, l4, l5, l6, l7, l8, l9, l10;	//	�x���B(��)���t���O
int m1, m2, m3, m4, m5, m6, m7, m8, m9, m10;	//	�x���B(����)���t���O
int n1, n2, n3, n4, n5, n6;						//	//	���̃n�[�u���t���O
char herb_t[][10] = { "�n�[�u", "�n�[�u", "�n�[�u", "�n�[�u", "�n�[�u" };
char uherb_t[][15] = { "�n�[�u(��)", "�n�[�u(��)", "�n�[�u(��)", "�n�[�u(��)", "�n�[�u(��)" };
char suherb_t[][20] = { "�n�[�u(����)", "�n�[�u(����)", "�n�[�u(����)", "�n�[�u(����)", "�n�[�u(����)" };
char baziru_t[][10] = { "�o�W��", "�o�W��", "�o�W��", "�o�W��", "�o�W��" };
char ubaziru_t[][15] = { "�o�W��(��)", "�o�W��(��)", "�o�W��(��)", "�o�W��(��)", "�o�W��(��)" };
char subaziru_t[][20] = { "�o�W��(����)", "�o�W��(����)", "�o�W��(����)", "�o�W��(����)", "�o�W��(����)" };
char ulbaziru_t[][15] = { "�o�W��(��)", "�o�W��(��)", "�o�W��(��)", "�o�W��(��)", "�o�W��(��)" };
char very_t[][10] = { "�x���B", "�x���B", "�x���B", "�x���B", "�x���B" };
char uvery_t[][15] = { "�x���B(��)", "�x���B(��)", "�x���B(��)", "�x���B(��)", "�x���B(��)" };
char ulvery_t[][15] = { "�x���B(��)", "�x���B(��)", "�x���B(��)", "�x���B(��)", "�x���B(��)" };
char pherb_t[][15] = { "���̃n�[�u", "���̃n�[�u", "���̃n�[�u" };
int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0;			//	�n�[�u���g�p���ꂽ���ǂ����̃t���O

//	�V���b�v�֘A�ϐ�(�g�[�i�����g���[�h�̂�)
int count = 0, puc = 0, puc2 = 0, puc3 = 0, puc4 = 0, puc5 = 0;	//	�z��Y�����p�ϐ��AHP�V�[�h�p�J�E���g
int puc6 = 0, puc7 = 0, puc8 = 0, puc9 = 0, puc10 = 0, puc11 = 0;		//	�p���[�A�b�v�n�A�C�e���p�J�E���g
int puc12 = 0, puc13 = 0, puc14 = 0, puc15 = 0, puc16 = 0, puc17 = 0;
int ifg = 0, ifg2 = 0, ifg3 = 0, ifg4 = 0, ifg5 = 0, ifg6 = 0, ifg7 = 0;		//	�p���[�A�b�v�n�A�C�e�����g�p���ꂽ���Ɏg�p����t���O
int ifg8 = 0, ifg9 = 0, ifg10 = 0, ifg11 = 0, ifg12 = 0, ifg13 = 0, ifg14 = 0, ifg15 = 0, ifg16 = 0, ifg17 = 0;

//	�񕜌n�A�C�e��
int hf = 0;						//	�n�[�u
int zhf = 0;					//	�n�[�u(��)
int thf = 0;					//	�n�[�u(����)
int bz = 0;						//	�o�W��
int ubz = 0;					//	�o�W��(��)
int tbz = 0;					//	�o�W��(����)
int gbz = 0;					//	�o�W��(��)
int br = 0;						//	�x���B
int ubr = 0;					//	�x���B(��)
int gbr = 0;					//	�x���B(��)
int mhb = 0;					//	���̃n�[�u

//	����Z���K������̂Ɏg�p����t���O
int fg1 = 0, fg2 = 0, fg3 = 0, fg4 = 0, fg5 = 0, fg6 = 0, fg7 = 0, fg8 = 0, fg9 = 0, fg10 = 0;
int fg11 = 0, fg12 = 0, fg13 = 0, fg14 = 0, fg15 = 0, fg16 = 0, fg17 = 0, fg18 = 0, fg19 = 0, fg20 = 0;
int fg21 = 0, fg22 = 0, fg23 = 0;
int sac = 0;	//	�֐�BookStore�Ŗ{������w���������̃J�E���g

//	�g�[�i�����g���[�h�Ŏg�p����ϐ�
int shozikin = 10000, bp = 0;					//	�����̏������A�o�g���|�C���g
char TMI[50][50];

//	BScommand�Ŏg���ϐ�
int wk = 2, wk2 = 4, wk3 = 2, wk4 = 1, wk5 = 3, wk6 = 2, wk7 = 8, wk8 = 4, wk9 = 4, wk10 = 4;
int wk11 = 2, wk12 = 4, wk13 = 2, wk14 = 1, wk15 = 4, wk16 = 0, wk17 = 0, wk18 = 5, wk19 = 3;
int wk20 = 2, wk21 = 10, wk22 = 4, wk23 = 3, wk24 = 2, wk25 = 3, wk26 = 2, wk27 = 3, wk28 = 1;
int wk29 = 3, wk30 = 2, wk31 = 3, wk32 = 0, wk33 = 4, wk34 = 2, wk35 = 2, wk36 = 1, wk37 = 6;
int wk38 = 3, wk39 = 3, wk40 = 3, wk41 = 1, wk42 = 6, wk43 = 4, wk44 = 2, wk45 = 2, wk46 = 3;
int wk47 = 4, wk48 = 2, wk49 = 5, wk50 = 4, wk51 = 2, wk52 = 2, wk53 = 2, wk54 = 1, wk55 = 2;
//	�e�����X�^�[�̋Z�̌����i�[�����ϐ�
int work = 0;	//	�����X�^�[�̋Z�̌����i�[����ϐ�

/*	�Q�[������	*/
void GameExplanation(){
	puts("");
}

//	�v���C���[�̍U���_���[�W�v�Z
int PDamage()
{
	int r = 0;							//	�����l�擾�ϐ�
	int r2 = 0, r3 = 0;					//	���Z�����Z�������肷�闐���A�㉺�_���[�W��
	int gensan3 = 0, flag = 0;

	srand((unsigned int)time(NULL));

	r = (rand() % 16 + 1);	//	��U���̊m���ŃN���e�B�J���q�b�g���o��

	srand((unsigned int)time(NULL));

	r2 = (rand() % 2 + 1);	//	���̒l�����̒l��

	if (r2 = 1){						//	r2�̒l��1�Ȃ��
		r3 = (rand() % 20 + 1);		//	���̒l�𓾂�
	}
	else{							//	r2�̒l��1�ȊO�Ȃ��
		r3 = (rand() % -20 - 20);	//	���̒l�𓾂�
	}

	if (atk < def2){
		printf("�~�X�ICPU�ɂ͍U����������Ȃ��I\n");
		flag = 1;
	}

	if (flag == 0){
		switch (r){
		case 1:					//	�N���e�B�J���q�b�g�̃_���[�W�v�Z
			gensan3 = ((atk - def2) + r3) * 2;
			HP2 = HP2 - gensan3;
			printf("�N���e�B�J���q�b�g�ICPU��%d�̃_���[�W�I\n", gensan3);
			break;
		case 2:					//	r�̒l��2�`16�Ȃ�Βʏ�̃_���[�W
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
			printf("Player�̍U���ICPU��%d�̃_���[�W�I\n", gensan3);
			break;
		}
	}
	return HP2;
}

//	CPU�_���[�W�v�Z
int CDamage()
{
	int r4 = 0;							//	�����l�擾�ϐ�
	int r5 = 0, r6 = 0;					//	���Z�����Z�������肷�闐���A�㉺�_���[�W��
	int gensan4 = 0, flag2 = 0;

	srand((unsigned int)time(NULL));

	r4 = (rand() % 16 + 1);	//	��U���̊m���ŃN���e�B�J���q�b�g���o��

	srand((unsigned int)time(NULL));

	r5 = (rand() % 2 + 1);	//	���̒l�����̒l��

	if (r5 = 1){						//	r5�̒l��1�Ȃ��
		r6 = (rand() % 20 + 1);		//	���̒l�𓾂�
	}
	else{							//	r5�̒l��1�ȊO�Ȃ��
		r6 = (rand() % -20 - 1);	//	���̒l�𓾂�
	}

	if (atk2 < def){
		printf("�~�X�IPlayer�ɂ͍U����������Ȃ��I\n");
		flag2 = 1;
	}

	if (flag2 == 0){
		switch (r4){
		case 1:					//	�N���e�B�J���q�b�g�̃_���[�W�v�Z
			if (stk1 == 2){
				gensan4 = (double)(((atk2 - def) + r6) * 2) * 0.25;
			}
			else{
				gensan4 = ((atk2 - def) + r6) * 2;
			}
			HP = HP - gensan4;
			printf("�N���e�B�J���q�b�g�IPlayer��%d�̃_���[�W�I\n", gensan4);
			break;
		case 2:					//	r4�̒l��2�`16�Ȃ�Βʏ�̃_���[�W
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
			if (stk1 == 2){		//	���肪�h�䂵���Ƃ�
				gensan4 = ((atk2 - def) + r6) * 0.25;
			}
			else{		//	�ʏ펞
				gensan4 = (atk2 - def) + r6;
			}
			HP = HP - gensan4;
			printf("CPU�̍U���IPlayer��%d�̃_���[�W�I\n", gensan4);
			break;
		}
	}

	return HP;
}

//	Player�����X�^�[����֐�
void PMST(){
	int kloop = 1, kloop2 = 1, st3 = 0, flg0 = 0;			//	�֐����ϐ�

	puts("----Player----");

	kloop = 1;
	while (kloop == 1){
		puts("�����X�^�[�����߂Ă��������B");
		puts("1:�u���[�X���C�� 2:�A�C�A���X���C�� 3:���b�h�X���C�� 4:���� 5:�C�O�� 6:�C��");
		puts("7:���@�g�� 8:�R�J�g���X 9:�n�[�r�[ 10:�g�����g 11:�S�u����\n12:�X�P���g�� 13:���b��l 14:�|�S���l 15:�R�{���g 16:�]���r 17:�I�[�K");
		puts("18:�O���t�H�� 19:�R�h�� 20:�S�C�� 21:�㖂���m 22:���R�m 23:�O���[�^�[�f�[����");
		puts("24:�剤�C�J 25:�h���S���t���C 26:�t�@�C�A�G�������^�� 27:�R�[���h�G�������^��");
		puts("28:�t���C���W���C�A���g 29:�t���X�g�W���C�A���g 30:�P���x���X 31:���@���p�C�A�o�b�g");
		puts("32:�~�C���j 33:�K�[�S�C�� 34:�o�V���X�N 35:�|�C�Y���X�l�C�N 36:�_�[�N�S�u����");
		puts("37:�����\���W���[ 38:���C�o�[�� 39:�l�򂢃V���[�N 40:�R���a 41:�W���C�A���g���b�g");
		puts("42:�S�[�X�g 43:�O�������� 44:�L���O�R�u�� 45:�����E��A 46:�����E��B");
		puts("47:�S�[�X�g�i�C�g 48:���� 49:�d�p�m 50:���U�[�h�}�� 51:�O���[���X���C��");
		puts("52:�}�b�h�}�� 53:�l�򂢐A�� 54:�W���C�A���g 55:�L�}�C��");
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


		if (st2 == 1){		//	1��I�������ꍇ�̏���
			work = wk;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 2){		//	2��I�������ꍇ�̏���
			work = wk2;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 3){		//	3��I�������ꍇ�̏���
			work = wk3;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 4){		//	4��I�������ꍇ�̏���
			work = wk4;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 5){		//	5��I�������ꍇ�̏���
			work = wk5;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 6){		//	6��I�������ꍇ�̏���
			work = wk6;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 7){		//	7��I�������ꍇ�̏���
			work = wk7;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 8){		//	8��I�������ꍇ�̏���
			work = wk8;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 9){		//	9��I�������ꍇ�̏���
			work = wk9;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 10){		//	10��I�������ꍇ�̏���
			work = wk10;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 11){		//	11��I�������ꍇ�̏���
			work = wk11;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 12){		//	12��I�������ꍇ�̏���
			work = wk12;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 13){		//	13��I�������ꍇ�̏���
			work = wk13;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 14){		//	14��I�������ꍇ�̏���
			work = wk14;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 15){		//	15��I�������ꍇ�̏���
			work = wk15;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 16){		//	16��I�������ꍇ�̏���
			work = wk16;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 17){		//	17��I�������ꍇ�̏���
			work = wk17;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 18){		//	18��I�������ꍇ�̏���
			work = wk18;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 19){		//	19��I�������ꍇ�̏���
			work = wk19;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 20){		//	20��I�������ꍇ�̏���
			work = wk20;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 21){		//	21��I�������ꍇ�̏���
			work = wk21;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 22){		//	22��I�������ꍇ�̏���
			work = wk22;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 23){		//	23��I�������ꍇ�̏���
			work = wk23;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 24){		//	24��I�������ꍇ�̏���
			work = wk24;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 25){		//	25��I�������ꍇ�̏���
			work = wk25;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 26){		//	26��I�������ꍇ�̏���
			work = wk26;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 27){		//	27��I�������ꍇ�̏���
			work = wk27;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 28){		//	28��I�������ꍇ�̏���
			work = wk28;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 29){		//	29��I�������ꍇ�̏���
			work = wk29;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 30){		//	30��I�������ꍇ�̏���
			work = wk30;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 31){		//	31��I�������ꍇ�̏���
			work = wk31;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 32){		//	32��I�������ꍇ�̏���
			work = wk32;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 33){		//	33��I�������ꍇ�̏���
			work = wk33;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 34){		//	34��I�������ꍇ�̏���
			work = wk34;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 35){		//	35��I�������ꍇ�̏���
			work = wk35;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 36){		//	36��I�������ꍇ�̏���
			work = wk36;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 37){		//	37��I�������ꍇ�̏���
			work = wk37;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 38){		//	38��I�������ꍇ�̏���
			work = wk38;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 39){		//	39��I�������ꍇ�̏���
			work = wk39;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 40){		//	40��I�������ꍇ�̏���
			work = wk40;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 41){		//	41��I�������ꍇ�̏���
			work = wk41;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 42){		//	42��I�������ꍇ�̏���
			work = wk42;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 43){		//	43��I�������ꍇ�̏���
			work = wk43;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 44){		//	44��I�������ꍇ�̏���
			work = wk44;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 45){		//	45��I�������ꍇ�̏���
			work = wk45;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 46){		//	46��I�������ꍇ�̏���
			work = wk46;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 47){		//	47��I�������ꍇ�̏���
			work = wk47;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 48){		//	48��I�������ꍇ�̏���
			work = wk48;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 49){		//	49��I�������ꍇ�̏���
			work = wk49;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 50){		//	50��I�������ꍇ�̏���
			work = wk50;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 51){		//	51��I�������ꍇ�̏���
			work = wk51;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 52){		//	52��I�������ꍇ�̏���
			work = wk52;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 53){		//	53��I�������ꍇ�̏���
			work = wk53;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 54){		//	54��I�������ꍇ�̏���
			work = wk54;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else if (st2 == 55){		//	55��I�������ꍇ�̏���
			work = wk55;			//	���ϐ�work�Ɋe�����X�^�[�̋Z�̌�����
		}
		else{
			puts("�G���[�I�I������x���͂��Ă��������B");
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
			puts("�I�����������X�^�[�ł����ł����H(1=YES:2=NO)");
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
				puts("�P���Q����͂��Ă��������B");
				kloop2 = 1;
			}
		}
	}
}

//	CPU�����X�^�[����֐�6
void CMST(){
	int flag = 0;
	char ch[5];

	if (flag == 0){
		srand((unsigned int)time(NULL));
		flag = 1;
	}

	r = (rand() % 55 + 1);

	puts("----CPU----");

	puts("�����X�^�[�����߂Ă��������B");
	puts("1:�u���[�X���C�� 2:�A�C�A���X���C�� 3:���b�h�X���C�� 4:���� 5:�C�O�� 6:�C��");
	puts("7:���@�g�� 8:�R�J�g���X 9:�n�[�r�[ 10:�g�����g 11:�S�u����\n12:�X�P���g�� 13:���b��l 14:�|�S���l 15:�R�{���g 16:�]���r 17:�I�[�K");
	puts("18:�O���t�H�� 19:�R�h�� 20:�S�C�� 21:�㖂���m 22:���R�m 23:�O���[�^�[�f�[����");
	puts("24:�剤�C�J 25:�h���S���t���C 26:�t�@�C�A�G�������^�� 27:�R�[���h�G�������^��");
	puts("28:�t���C���W���C�A���g 29:�t���X�g�W���C�A���g 30:�P���x���X 31:���@���p�C�A�o�b�g");
	puts("32:�~�C���j 33:�K�[�S�C�� 34:�o�V���X�N 35:�|�C�Y���X�l�C�N 36:�_�[�N�S�u����");
	puts("37:�����\���W���[ 38:���C�o�[�� 39:�l�򂢃V���[�N 40:�R���a 41:�W���C�A���g���b�g");
	puts("42:�S�[�X�g 43:�O�������� 44:�L���O�R�u�� 45:�����E��A 46:�����E��B");
	puts("47:�S�[�X�g�i�C�g 48:���� 49:�d�p�m 50:���U�[�h�}�� 51:�O���[���X���C��");
	puts("52:�}�b�h�}�� 53:�l�򂢐A�� 54:�W���C�A���g 55:�L�}�C��");

	strcpy_s(name2, MC[r - 1].name);
	HP2 = MC[r - 1].HP;
	TP2 = MC[r - 1].TP;
	atk2 = MC[r - 1].atk;
	def2 = MC[r - 1].def;
	spd2 = MC[r - 1].spd;

	printf("name=%s: HP=%d: TP=%d: atk=%d: def=%d: spd=%d\n", name2, HP2, TP2, atk2, def2, spd2);

	puts("�K���ȃL�[����͂��Ă��������B");
	scanf_s("%s", ch, 5);
	
}

//	�s�������������֐�
int Act(int Kcount){
	int ar = 0;
	int gensan = 0, gensan2 = 0;
	Kcount = -1;
	int flag = 0;					//	Kcount�̒l���擾�����瑼�̏������ł��Ȃ�����t���O

	gensan = spd - spd2;			//	Player
	gensan2 = spd2 - spd;			//	CPU

	srand((unsigned int)time(NULL));

	ar = rand() % 10 + 1;

	if (gensan >= 100){
		Kcount = 0;					//	Player����U
		flag = 1;
	}
	if (gensan2 >= 100){
		Kcount = 5;					//	CPU����U
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
			Kcount = 0;			//	Player����U
			break;
		case 10:
			Kcount = 5;			//	CPU����U
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
			Kcount = 5;			//	CPU����U
			break;
		case 10:
			Kcount = 0;			//	Player����U
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
			Kcount = 0;			//	Player����U
			break;
		case 9:
		case 10:
			Kcount = 5;			//	CPU����U
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
			Kcount = 5;			//	CPU����U
			break;
		case 9:
		case 10:
			Kcount = 0;			//	Player����U
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
			Kcount = 0;			//	Player����U
			break;
		case 8:
		case 9:
		case 10:
			Kcount = 5;			//	CPU����U
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
			Kcount = 5;			//	CPU����U
			break;
		case 8:
		case 9:
		case 10:
			Kcount = 0;			//	Player����U
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
			Kcount = 0;			//	Player����U
			break;
		case 7:
		case 8:
		case 9:
		case 10:
			Kcount = 5;			//	CPU����U
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
			Kcount = 5;			//	CPU����U
			break;
		case 7:
		case 8:
		case 9:
		case 10:
			Kcount = 0;			//	Player����U
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
			Kcount = 0;			//	Player����U
			break;
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
			Kcount = 5;			//	CPU����U
			break;
		}
	}

	return Kcount;
}

//	����U���p�̃_���[�W�v�Z�֐�(Player)
int PSAD(){
	int r8 = 0, r9 = 0;			//	�����𓾂�ϐ�(�������ǂ����A�_���[�W�������ɂȂ邩�ǂ���)
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

	if (r8 == 1){		//	r8���P�̏ꍇ
		r9 = (rand() % 20 + 1);
	}
	else{				//	r8���Q�̏ꍇ
		r9 = (rand() % -20 - 1);
	}

	//	Fire,Blizzard,thunder���g�p���ꂽ�ꍇ�̏���
	if (flag10 == 1){
		gensan5 = ((atk - def2) + r9) * (double)1.3;
		HP2 = HP2 - gensan5;
		printf("CPU��%d�̃_���[�W!\n", gensan5);
	}
	//	FireSword,BlizzardSword, ThunderSword���g�p���ꂽ�ꍇ�̏���
	if (flag11 == 1){
		gensan5 = ((atk - def2) + r9) * (double)1.2;
		HP2 = HP2 - gensan5;
		printf("CPU��%d�̃_���[�W!\n", gensan5);
	}
	//	�ɍ��̈ꌂ���g�p���ꂽ�ꍇ�̏���
	if (flag12 == 1){
		gensan5 = ((atk - def2) + r9) * (double)1.5;
		HP2 = HP2 - gensan5;
		printf("�ɍ��̈ꌂ�ICPU��%d�̃_���[�W!\n", gensan5);
	}
	//	�W�����v�U�����g�p���ꂽ�ꍇ�̏���
	if (flag13 == 1){
		gensan5 = ((atk - def2) + r9) * (double)1.25;
		HP2 = HP2 - gensan5;
		printf("CPU��%d�̃_���[�W!\n", gensan5);
	}
	//	���e�I���g�p���ꂽ�ꍇ�̏���
	if (flag14 == 1){
		gensan5 = ((atk - def2) + r9) * (double)3;
		HP2 = HP2 - gensan5;
		printf("CPU��%d�̃_���[�W!\n", gensan5);
	}
	//	�ːi���g�p���ꂽ�ꍇ�̏���
	if (flag15 == 1){
		gensan5 = ((atk - def2) + r9) * (double)1.1;
		HP2 = HP2 - gensan5;
		printf("CPU��%d�̃_���[�W!\n", gensan5);
	}
	//	�t�@�C�A�u���X�A�R�[���h�u���X�A�T���_�[�u���X���g�p���ꂽ�ꍇ�̏���
	if (flag16 == 1){
		gensan5 = ((atk - def2) + r9) * (double)1.25;
		HP2 = HP2 - gensan5;
		printf("CPU��%d�̃_���[�W!\n", gensan5);
	}
	//	�w���t�@�C�A�A�_�C�������h�_�X�g���g�p���ꂽ�ꍇ�̏���
	if (flag025 == 1){
		gensan5 = ((atk - def2) + r9) * (double)1.4;
		HP2 = HP2 - gensan5;
		printf("CPU��%d�̃_���[�W!\n", gensan5);
	}

	return HP2;
}

//	����U���p�̃_���[�W�v�Z�֐�(CPU)
int CSAD(){
	int r10 = 0, r11 = 0;			//	�����𓾂�ϐ�(�������ǂ����A�_���[�W�������ɂȂ邩�ǂ���)
	int gensan6 = 0;

	srand((unsigned int)time(NULL));

	r10 = (rand() % 2 + 1);

	srand((unsigned int)time(NULL));

	if (r10 == 1){		//	r8���P�̏ꍇ
		r11 = (rand() % 20 + 1);
	}
	else{				//	r8���Q�̏ꍇ
		r11 = (rand() % -20 - 1);
	}

	//	Fire,Blizzard,thunder���g�p���ꂽ�ꍇ�̏���
	if (flag30 == 1){
		gensan6 = ((atk2 - def) + r11) * 1.3;
		HP = HP - gensan6;
		printf("Player��%d�̃_���[�W�I\n", gensan6);
	}
	//	FireSword,BlizzardSword, ThunderSword���g�p���ꂽ�ꍇ�̏���
	if (flag31 == 1){
		gensan6 = ((atk2 - def) + r11) * 1.2;
		HP = HP - gensan6;
		printf("Player��%d�̃_���[�W�I\n", gensan6);
	}
	//	�ɍ��̈ꌂ���g�p���ꂽ�ꍇ�̏���
	if (flag32 == 1){
		gensan6 = ((atk2 - def) + r11) * 1.5;
		HP = HP - gensan6;
		printf("�ɍ��̈ꌂ�IPlayer��%d�̃_���[�W�I\n", gensan6);
	}
	//	�W�����v�U�����g�p���ꂽ�ꍇ�̏���
	if (flag33 == 1){
		gensan6 = ((atk2 - def) + r11) * 1.25;
		HP = HP - gensan6;
		printf("Player��%d�̃_���[�W�I\n", gensan6);
	}
	//	���e�I���g�p���ꂽ�ꍇ�̏���
	if (flag34 == 1){
		gensan6 = ((atk2 - def) + r11) * 3;
		HP = HP - gensan6;
		printf("Player��%d�̃_���[�W�I\n", gensan6);
	}
	//	�ːi���g�p���ꂽ�ꍇ�̏���
	if (flag35 == 1){
		gensan6 = ((atk2 - def) + r11) * 1.1;
		HP = HP - gensan6;
		printf("Player��%d�̃_���[�W�I\n", gensan6);
	}
	//	�t�@�C�A�u���X�A�R�[���h�u���X�A�T���_�[�u���X���g�p���ꂽ�ꍇ�̏���
	if (flag36 == 1){
		gensan6 = ((atk2 - def) + r11) * 1.25;
		HP = HP - gensan6;
		printf("Player��%d�̃_���[�W�I\n", gensan6);
	}
	//	�w���t�@�C�A�A�_�C�������h�_�X�g���g�p���ꂽ�ꍇ�̏���
	if (flag40 == 1){
		gensan6 = ((atk2 - def) + r11) * (double)1.4;
		HP = HP - gensan6;
		printf("Player��%d�̃_���[�W!\n", gensan6);
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

	//	�V�[���h���g�p���ꂽ�ꍇ�̏���
	if (flag20 == 1){
		def = def * 1.10;
		printf("Player�͖h��͂��オ�����I\n");
	}
	//	�V�[���h�_�E�����g�p���ꂽ�ꍇ�̏���
	if (flag21 == 1){
		def2 = def2 * 0.8;
		printf("CPU�͖h��͂����������I\n");
	}
	//	�X�s�[�h�A�b�v���g�p���ꂽ�ꍇ�̏���
	if (flag22 == 1){
		spd = spd * 1.15;
		printf("Player�͑f�������オ�����I\n");
	}
	//	�X�s�[�h�_�E�����g�p���ꂽ�ꍇ�̏���
	if (flag23 == 1){
		spd2 = spd2 * 0.8;
		printf("CPU�͑f���������������I\n");
	}
	//	�S�ǂ��g�p���ꂽ�ꍇ�̏���
	if (flag24 == 1){
		def = def * 1.2;
		printf("Player�͖h��͂��オ�����I\n");
	}
}

void CSAas(){		//	CPU
	//	�V�[���h���g�p���ꂽ�ꍇ�̏���
	if (flag25 == 1){
		def2 = def2 * 1.10;
		printf("CPU�͖h��͂��オ�����I\n");
	}
	//	�V�[���h�_�E�����g�p���ꂽ�ꍇ�̏���
	if (flag26 == 1){
		def = def * 0.8;
		printf("Player�͖h��͂����������I\n");
	}
	//	�X�s�[�h�A�b�v���g�p���ꂽ�ꍇ�̏���
	if (flag27 == 1){
		spd2 = spd2 * 1.15;
		printf("CPU�͑f�������オ�����I\n");
	}
	//	�X�s�[�h�_�E�����g�p���ꂽ�ꍇ�̏���
	if (flag28 == 1){
		spd = spd * 0.8;
		printf("Player�͑f���������������I\n");
	}
	//	�S�ǂ��g�p���ꂽ�ꍇ�̏���
	if (flag29 == 1){
		def2 = def2 * 1.2;
		printf("CPU�͖h��͂��オ�����I\n");
	}

	flag30 = 0, flag31 = 0, flag32 = 0, flag33 = 0, flag34 = 0;
	flag35 = 0, flag36 = 0, flag37 = 0, flag38 = 0, flag39 = 0;
	flag40 = 0, flag41 = 0, flag42 = 0, flag43 = 0;
	flag25 = 0, flag26 = 0, flag27 = 0, flag28 = 0, flag29 = 0;
}

//	-----------Player��p�֐��`-------------------
void FireSword(){
	if (TP < 3){
		puts("TP������܂���B");
	}
	else{
		puts("�t�@�C�A�\�[�h���J��o�����I");
		HP2 = PSAD();
		TP -= 3;
	}
}

void BlizzardSword(){
	if (TP < 3){
		puts("TP������܂���B");
	}
	else{
		puts("�u���U�[�h�\�[�h���J��o�����I");
		HP2 = PSAD();
		TP -= 3;
	}
}

void ThunderSword(){
	if (TP < 3){
		puts("TP������܂���B");
	}
	else{
		puts("�T���_�[�\�[�h���J��o�����I");
		HP2 = PSAD();
		TP -= 3;
	}
}

void Fire(){
	if (TP < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�t�@�C�A���������I");
		HP2 = PSAD();
		TP -= 5;
	}
}

void Blizzard(){
	if (TP < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�u���U�[�h���������I");
		HP2 = PSAD();
		TP -= 5;
	}
}

void Thunder(){
	if (TP < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�T���_�[���������I");
		HP2 = PSAD();
		TP -= 5;
	}
}

void WindSlash(){
	if (TP < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�E�B���h�X���b�V�����������I");
		HP2 = PSAD();
		TP -= 5;
	}
}

void Shield(){
	if (TP < 7){
		puts("TP������܂���B");
	}
	else{
		puts("�V�[���h���������I");
		PSAas();
		TP -= 7;
	}
}

void ShieldDown(){
	if (TP < 7){
		puts("TP������܂���B");
	}
	else{
		puts("�V�[���h�_�E�����������I");
		PSAas();
		TP -= 7;
	}
}

void Meteo(){
	if (TP < 35){
		puts("TP������܂���B");
	}
	else{
		puts("���e�I���������I");
		HP2 = PSAD();
		TP -= 35;
	}
}

void SpeedUp(){
	if (TP < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�X�s�[�h�A�b�v���������I");
		PSAas();
		TP -= 5;
	}
}

void SpeedDown(){
	if (TP < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�X�s�[�h�_�E�����������I");
		PSAas();
		TP -= 5;
	}
}

//	�ɍ��̈ꌂ
void Regret(){
	if (TP < 6){
		puts("TP������܂���B");
	}
	else{
		HP2 = PSAD();
		TP -= 6;
	}
}

void JumpAttack(){
	if (TP < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�W�����v�A�^�b�N���J��o�����I");
		HP2 = PSAD();
		TP -= 5;
	}
}

void IronWall(){
	if (TP < 20){
		puts("TP������܂���B");
	}
	else{
		puts("�S�ǂōX�ɖh����ł߂��I");
		PSAas();
		TP -= 20;
	}
}

//	�ːi
void Rush(){
	if (TP < 3){
		puts("TP������܂���B");
	}
	else{
		puts("�ːi���J��o�����I");
		HP2 = PSAD();
		TP -= 3;
	}
}

void FireBreath(){
	if (TP < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�t�@�C�A�u���X��f�����I");
		HP2 = PSAD();
		TP -= 5;
	}
}

void ColdBreath(){
	if (TP < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�R�[���h�u���X��f�����I");
		HP2 = PSAD();
		TP -= 5;
	}
}

void ThunderBreath(){
	if (TP < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�T���_�[�u���X��f�����I");
		HP2 = PSAD();
		TP -= 5;
	}
}

void ElementalSword(){
	if (TP < 6 || TP2 < 6){
		puts("TP������܂���B");
	}
	else{
	}
}

void HellFire(){
	if (TP < 8){
		puts("TP������܂���B");
	}
	else{
		puts("�w���t�@�C�A���������I");
		HP2 = PSAD();
		TP -= 8;
	}
}

void DiamondDust(){
	if (TP < 8){
		puts("TP������܂���B");
	}
	else{
		puts("�_�C�������h�_�X�g���������I");
		HP2 = PSAD();
		TP -= 8;
	}
}

void ThunderBlast(){
	if (TP < 10 || TP2 < 10){
		puts("TP������܂���B");
	}
	else{
	}
}

//	-----------CPU��p�̊֐��`-----------------
void CFireSword(){
	if (TP2 < 3){
		puts("TP������܂���B");
	}
	else{
		puts("�t�@�C�A�\�[�h���J��o�����I");
		HP = CSAD();
		TP2 -= 3;
	}
}

void CBlizzardSword(){
	if (TP2 < 3){
		puts("TP������܂���B");
	}
	else{
		puts("�u���U�[�h�\�[�h���J��o�����I");
		HP = CSAD();
		TP2 -= 3;
	}
}

void CThunderSword(){
	if (TP2 < 3){
		puts("TP������܂���B");
	}
	else{
		puts("�T���_�[�\�[�h���J��o�����I");
		HP = CSAD();
		TP2 -= 3;
	}
}

void CFire(){
	if (TP2 < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�t�@�C�A���������I");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CBlizzard(){
	if (TP2 < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�u���U�[�h���������I");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CThunder(){
	if (TP2 < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�T���_�[���������I");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CWindSlash(){
	if (TP2 < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�E�B���h�X���b�V�����������I");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CShield(){
	if (TP2 < 7){
		puts("TP������܂���B");
	}
	else{
		puts("�V�[���h���������I");
		CSAas();
		TP2 -= 7;
	}
}

void CShieldDown(){
	if (TP2 < 7){
		puts("TP������܂���B");
	}
	else{
		puts("�V�[���h�_�E�����������I");
		CSAas();
		TP2 -= 7;
	}
}

void CMeteo(){
	if (TP2 < 35){
		puts("TP������܂���B");
	}
	else{
		puts("���e�I���������I");
		HP = CSAD();
		TP2 -= 35;
	}
}

void CSpeedUp(){
	if (TP2 < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�X�s�[�h�A�b�v���������I");
		CSAas();
		TP2 -= 5;
	}
}

void CSpeedDown(){
	if (TP2 < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�X�s�[�h�_�E�����������I");
		CSAas();
		TP2 -= 5;
	}
}

//	�ɍ��̈ꌂ
void CRegret(){
	if (TP2 < 6){
		puts("TP������܂���B");
	}
	else{
		HP = CSAD();
		TP2 -= 6;
	}
}

void CJumpAttack(){
	if (TP2 < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�W�����v�A�^�b�N���J��o�����I");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CIronWall(){
	if (TP2 < 20){
		puts("TP������܂���B");
	}
	else{
		puts("�S�ǂōX�ɖh����ł߂��I");
		CSAas();
		TP2 -= 20;
	}
}

//	�ːi
void CRush(){
	if (TP2 < 3){
		puts("TP������܂���B");
	}
	else{
		puts("�ːi���J��o�����I");
		HP = CSAD();
		TP2 -= 3;
	}
}

void CFireBreath(){
	if (TP2 < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�t�@�C�A�u���X��f�����I");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CColdBreath(){
	if (TP2 < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�R�[���h�u���X��f�����I");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CThunderBreath(){
	if (TP2 < 5){
		puts("TP������܂���B");
	}
	else{
		puts("�T���_�[�u���X��f�����I");
		HP = CSAD();
		TP2 -= 5;
	}
}

void CElementalSword(){
	if (TP2 < 6){
		puts("TP������܂���B");
	}
	else{
	}
}

void CHellFire(){
	if (TP2 < 8){
		puts("TP������܂���B");
	}
	else{
		puts("�w���t�@�C�A���������I");
		HP = CSAD();
		TP2 -= 8;
	}
}

void CDiamondDust(){
	if (TP2 < 8){
		puts("TP������܂���B");
	}
	else{
		puts("�_�C�������h�_�X�g���������I");
		HP = CSAD();
		TP2 -= 8;
	}
}

void CThunderBlast(){
	if (TP2 < 10){
		puts("TP������܂���B");
	}
	else{
	}
}

//	����Z(Player��p)
void SpecialAttack(){
	flag10 = 0, flag11 = 0, flag12 = 0, flag13 = 0, flag14 = 0, flag15 = 0;
	flag15 = 0, flag16 = 0, flag20 = 0, flag21 = 0, flag22 = 0, flag23 = 0, flag24 = 0;
	flag025 = 0;

	//	����U���t�@�C�A�̏���
	if (st3 == 1 || st4 == 1 || st9 == 1 || st11 == 1 || st18 == 1 || st21 == 1 || st26 == 1 || st42 == 1 || st43 == 1){
		flag10 = 1;
		Fire();
	}
	//	����U���u���U�[�h�̏���
	if (st6 == 1 || st9 == 2 || st11 == 2 || st12 == 1 || st21 == 2 || st24 == 1 || st27 == 1 || st42 == 2 || st43 == 2 || st51 == 1){
		flag10 = 1;
		Blizzard();
	}
	//	����U���T���_�[�̏���
	if (st4 == 2 || st9 == 3 || st10 == 1 || st11 == 3 || st12 == 2 || st18 == 2 || st21 == 3 || st37 == 4 || st42 == 3){
		flag10 = 1;
		Thunder();
	}
	//	����U���E�B���h�X���b�V���̏���
	if (st9 == 4 || st10 == 2 || st17 == 4 || st22 == 3 || st23 == 2 || st31 == 3 || st33 == 3 || st42 == 4 || st46 == 1){
		flag10 = 1;
		WindSlash();
	}
	//	����U���t�@�C�A�\�[�h�̏���
	if (st14 == 1 || st22 == 2 || st33 == 1 || st37 == 1 || st47 == 1){
		flag11 = 1;
		FireSword();
	}
	//	����U���u���U�[�h�\�[�h�̏���
	if (st14 == 2 || st37 == 2 || st47 == 2 || st50 == 2){
		flag11 = 1;
		BlizzardSword();
	}
	//	����U���T���_�[�\�[�h�̏���
	if (st14 == 3 || st17 == 2 || st33 == 2 || st37 == 3 || st47 == 3 || st50 == 3){
		flag11 = 1;
		ThunderSword();
	}
	//	����U��,�ɍ��̈ꌂ�̏���
	if (st11 == 4 || st13 == 1 || st25 == 3 || st29 == 3 || st30 == 2 || st40 == 2 || st44 == 2 || st50 == 4 || st52 == 2 || st53 == 2 || st54 == 1){
		flag12 = 1;
		Regret();
	}
	//	����U���A�W�����v�U���̏���
	if (st13 == 2 || st14 == 4 || st17 == 1 || st36 == 1 || st37 == 5 || st45 == 2 || st46 == 2 || st50 == 1){
		flag13 = 1;
		JumpAttack();
	}
	//	����U���A���e�I�̏���
	if (st9 == 5 || st21 == 4 || st49 == 1){
		flag14 = 1;
		Meteo();
	}
	//	����U���A�ːi�̏���
	if (st5 == 1 || st20 == 1 || st25 == 2 || st30 == 1 || st35 == 1 || st39 == 2 || st41 == 1 || st48 == 2 || st52 == 1){
		flag15 = 1;
		Rush();
	}
	//	����U���A�t�@�C�A�u���X�̏���
	if (st5 == 2 || st19 == 1 || st21 == 9 || st22 == 1 || st25 == 1 || st26 == 2 || st28 == 1 || st38 == 1 || st48 == 1){
		flag16 = 1;
		FireBreath();
	}
	//	����U���A�R�[���h�u���X�̏���
	if (st18 == 5 || st19 == 2 || st20 == 2 || st24 == 2 || st29 == 1 || st31 == 1 || st38 == 2 || st39 == 1 || st47 == 4 || st55 == 2){
		flag16 = 1;
		ColdBreath();
	}
	//	����U���A�T���_�[�u���X�̏���
	if (st19 == 3 || st23 == 3 || st34 == 1 || st38 == 3 || st53 == 1){
		flag16 = 1;
		ThunderBreath();
	}
	//	�⏕����Z�A�V�[���h�̏���
	if (st4 == 3 || st7 == 1 || st8 == 1 || st9 == 6 || st10 == 3 || st12 == 3 || st21 == 5 || st27 == 2 || st40 == 3 || st43 == 3 || st49 == 2){
		flag20 = 1;
		Shield();
	}
	//	�⏕����Z�A�V�[���h�_�E���̏���
	if (st3 == 2 || st8 == 2 || st12 == 4 || st15 == 1 || st17 == 3 || st18 == 3 || st21 == 6 || st33 == 4 || st35 == 2 || st37 == 6 || st44 == 1 || st46 == 3 || st49 == 3){
		flag21 = 1;
		ShieldDown();
	}
	//	�⏕����Z�A�X�s�[�h�A�b�v�̏���
	if (st7 == 2 || st9 == 7 || st10 == 4 || st18 == 4 || st21 == 7 || st29 == 2 || st31 == 2 || st39 == 3 || st42 == 6 || st43 == 4 || st45 == 1 || st49 == 4){
		flag22 = 1;
		SpeedUp();
	}
	//	�⏕����Z�A�X�s�[�h�_�E���̏���
	if (st7 == 3 || st9 == 8 || st15 == 2 || st16 == 1 || st21 == 8 || st22 == 4 || st27 == 3 || st34 == 2 || st49 == 5 || st51 == 2){
		flag23 = 1;
		SpeedDown();
	}
	//	�⏕����Z�A�S�ǂ̏���
	if (st4 == 4 || st40 == 1){
		flag24 = 1;
		IronWall();
	}
	//	����U���A�w���t�@�C�A�̏���
	if (st21 == 10 || st23 == 1){
		flag025 = 1;
		HellFire();
	}
	//	����U���A�_�C�������h�_�X�g�̏���
	if (st42 == 5 || st55 == 1){
		flag025 = 1;
		DiamondDust();
	}
}

//	����Z(CPU��p)
void CSpecialAttack(){
	flag25 = 0, flag26 = 0, flag27 = 0, flag28 = 0, flag29 = 0, flag30 = 0;
	flag31 = 0, flag32 = 0, flag33 = 0, flag34 = 0, flag35 = 0, flag36 = 0;

	//	����U���t�@�C�A�̏���
	if (r13 == 1 || r14 == 1 || r19 == 1 || r21 == 1 || r28 == 1 || r31 == 1 || r36 == 1 || r52 == 1 || r53 == 1){
		flag30 = 1;
		CFire();
	}
	//	����U���u���U�[�h�̏���
	if (r16 == 1 || r19 == 2 || r21 == 2 || r22 == 1 || r31 == 2 || r34 == 1 || r37 == 1 || r52 == 2 || r53 == 2 || r61 == 1){
		flag30 = 1;
		CBlizzard();
	}
	//	����U���T���_�[�̏���
	if (r14 == 2 || r19 == 3 || r20 == 1 || r21 == 3 || r22 == 2 || r28 == 2 || r31 == 3 || r47 == 4 || r52 == 3){
		flag30 = 1;
		CThunder();
	}
	//	����U���E�B���h�X���b�V���̏���
	if (r19 == 4 || r20 == 2 || r27 == 4 || r32 == 3 || r33 == 2 || r41 == 3 || r43 == 3 || r52 == 4 || r56 == 1){
		flag30 = 1;
		CWindSlash();
	}
	//	����U���t�@�C�A�\�[�h�̏���
	if (r24 == 1 || r32 == 2 || r43 == 1 || r47 == 1 || r57 == 1){
		flag31 = 1;
		CFireSword();
	}
	//	����U���u���U�[�h�\�[�h�̏���
	if (r24 == 2 || r47 == 2 || r57 == 2 || r60 == 2){
		flag31 = 1;
		CBlizzardSword();
	}
	//	����U���T���_�[�\�[�h�̏���
	if (r24 == 3 || r27 == 2 || r43 == 2 || r47 == 3 || r57 == 3 || r60 == 3){
		flag31 = 1;
		CThunderSword();
	}
	//	����U��,�ɍ��̈ꌂ�̏���
	if (r21 == 4 || r23 == 1 || r35 == 3 || r39 == 3 || r40 == 2 || r50 == 2 || r54 == 2 || r60 == 4 || r62 == 2 || r63 == 2 || r64 == 1){
		flag32 = 1;
		CRegret();
	}
	//	����U���A�W�����v�U���̏���
	if (r23 == 2 || r24 == 4 || r27 == 1 || r46 == 1 || r47 == 5 || r55 == 2 || r56 == 2 || r60 == 1){
		flag33 = 1;
		CJumpAttack();
	}
	//	����U���A���e�I�̏���
	if (r19 == 5 || r31 == 4 || r59 == 1){
		flag34 = 1;
		CMeteo();
	}
	//	����U���A�ːi�̏���
	if (r15 == 1 || r30 == 1 || r35 == 2 || r40 == 1 || r45 == 1 || r49 == 2 || r51 == 1 || r58 == 2 || r62 == 1){
		flag35 = 1;
		CRush();
	}
	//	����U���A�t�@�C�A�u���X�̏���
	if (r29 == 1 || r15 == 2 || r31 == 9 || r32 == 1 || r35 == 1 || r36 == 2 || r38 == 1 || r48 == 1 || r58 == 1){
		flag36 = 1;
		CFireBreath();
	}
	//	����U���A�R�[���h�u���X�̏���
	if (r28 == 5 || r29 == 2 || r30 == 2 || r34 == 2 || r39 == 1 || r41 == 1 || r48 == 2 || r49 == 1 || r57 == 4 || r65 == 2){
		flag36 = 1;
		CColdBreath();
	}
	//	����U���A�T���_�[�u���X�̏���
	if (r29 == 3 || r33 == 3 || r44 == 1 || r48 == 3 || r63 == 1){
		flag36 = 1;
		CThunderBreath();
	}
	//	�⏕����Z�A�V�[���h�̏���
	if (r14 == 3 || r17 == 1 || r18 == 1 || r19 == 6 || r20 == 3 || r22 == 3 || r31 == 5 || r37 == 2 || r50 == 3 || r53 == 3 || r59 == 2){
		flag25 = 1;
		CShield();
	}
	//	�⏕����Z�A�V�[���h�_�E���̏���
	if (r13 == 2 || r18 == 2 || r22 == 4 || r25 == 1 || r27 == 3 || r28 == 3 || r31 == 6 || r43 == 4 || r45 == 2 || r47 == 6 || r54 == 1 || r56 == 3 || r59 == 3){
		flag26 = 1;
		CShieldDown();
	}
	//	�⏕����Z�A�X�s�[�h�A�b�v�̏���
	if (r17 == 2 || r19 == 7 || r20 == 4 || r28 == 4 || r31 == 7 || r39 == 2 || r41 == 2 || r49 == 3 || r52 == 6 || r53 == 4 || r55 == 1 || r59 == 4){
		flag27 = 1;
		CSpeedUp();
	}
	//	�⏕����Z�A�X�s�[�h�_�E���̏���
	if (r17 == 3 || r19 == 8 || r25 == 2 || r26 == 1 || r31 == 8 || r32 == 4 || r37 == 3 || r44 == 2 || r59 == 5 || r61 == 2){
		flag28 = 1;
		CSpeedDown();
	}
	//	�⏕����Z�A�S�ǂ̏���
	if (r14 == 4 || r50 == 1){
		flag29 = 1;
		CIronWall();
	}
	//	����U���A�w���t�@�C�A�̏���
	if (r31 == 10 || r33 == 1){
		flag40 = 1;
		CHellFire();
	}
	//	����U���A�_�C�������h�_�X�g�̏���
	if (r52 == 5 || r65 == 1){
		flag40 = 1;
		CDiamondDust();
	}
}

//	�֐�BookStore�ōw�������Z��\��
void BScommand(){
	if (fg1 == 1 && sac == 1){		//	�t���O���P�ōw���񐔂�1��ڂȂ��
		printf("%d:�t�@�C�A�\�[�h", work);
	}
	else if (fg1 == 1 && sac == 2){							//	�w���񐔂�2��ڂȂ��
		printf("%d:�t�@�C�A�\�[�h", work);
	}

	if (fg2 == 1 && sac == 1){
		printf("%d:�u���U�[�h�\�[�h", work);
	}
	else if (fg2 == 1 && sac == 2){
		printf("%d:�u���U�[�h�\�[�h", work);
	}

	if (fg3 == 1 && sac == 1){
		printf("%d:�T���_�[�\�[�h", work);
	}
	else if (fg3 == 1 && sac == 2){
		printf("%d:�T���_�[�\�[�h", work);
	}

	if (fg4 == 1 && sac == 1){
		printf("%d:�ɍ��̈ꌂ", work);
	}
	else if (fg4 == 1 && sac == 2){
		printf("%d:�ɍ��̈ꌂ", work);
	}

	if (fg5 == 1 && sac == 1){
		printf("%d:�W�����v�U��", work);
	}
	else if (fg5 == 1 && sac == 2){
		printf("%d:�W�����v�U��", work);
	}

	if (fg6 == 1 && sac == 1){
		printf("%d:�ːi\n", work);
	}
	else if (fg6 == 1 && sac == 2){
		printf("%d:�ːi\n", work);
	}

	if (fg7 == 1 && sac == 1){
		printf("%d:�t�@�C�A�u���X", work);
	}
	else if (fg7 == 1 && sac == 2){
		printf("%d:�t�@�C�A�u���X", work);
	}
	if (fg8 == 1 && sac == 1){
		printf("%d:�R�[���h�u���X", work);
	}

	else if (fg8 == 1 && sac == 2){
		printf("%d:�R�[���h�u���X", work);
	}
	if (fg9 == 1 && sac == 1){
		printf("%d:�T���_�[�u���X", work);
	}
	else if (fg9 == 1 && sac == 2){
		printf("%d:�T���_�[�u���X", work);
	}

	if (fg10 == 1 && sac == 1){				//	�g���郂���X�^�[�͂Ȃ�
		printf("%d:�G�������^���\�[�h", work);
	}
	else if (fg10 == 1 && sac == 2){
		printf("%d:�G�������^���\�[�h", work);
	}

	if (fg11 == 1 && sac == 1){
		printf("%d:�S��", work);
	}
	else if (fg11 == 1 && sac == 2){
		printf("%d:�S��", work);
	}

	if (fg12 == 1 && sac == 1){
		printf("%d:�t�@�C�A", work);
	}
	else if (fg12 == 1 && sac == 2){
		printf("%d:�t�@�C�A", work);
	}

	if (fg13 == 1 && sac == 1){
		printf("%d:�u���U�[�h", work);
	}
	else if (fg13 == 1 && sac == 2){
		printf("%d:�u���U�[�h", work);
	}

	if (fg14 == 1 && sac == 1){
		printf("%d:�T���_�[", work);
	}
	else if (fg14 == 1 && sac == 2){
		printf("%d:�T���_�[", work);
	}

	if (fg15 == 1 && sac == 1){
		printf("%d:�E�B���h�X���b�V��", work);
	}
	else if (fg15 == 1 && sac == 2){
		printf("%d:�E�B���h�X���b�V��", work);
	}

	if (fg16 == 1 && sac == 1){
		printf("%d;�V�[���h", work);
	}
	else if (fg16 == 1 && sac == 2){
		printf("%d;�V�[���h", work);
	}

	if (fg17 == 1 && sac == 1){
		printf("%d;�V�[���h�_�E��", work);
	}
	else if (fg17 == 1 && sac == 2){
		printf("%d;�V�[���h�_�E��", work);
	}

	if (fg18 == 1 && sac == 1){
		printf("%d:�X�s�[�h�A�b�v", work);
	}
	else if (fg18 == 1 && sac == 2){
		printf("%d:�X�s�[�h�A�b�v", work);
	}

	if (fg19 == 1 && sac == 1){
		printf("%d:�X�s�[�h�_�E��", work);
	}
	if (fg19 == 1 && sac == 2){
		printf("%d:�X�s�[�h�_�E��", work);
	}
	printf("\n");
}

//	Player��p
void SAcommand(){
	st3 = 0, st4 = 0, st5 = 0, st6 = 0, st7 = 0;	//	SAcommand�ŋZ��I������Ƃ��Ɏg�p(st3�`)(Player)
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
	flag = 0;										//	SAcommand�Ŏg�p����t���O

	puts("3=����Z");

	//	�u���[�X���C���̓���Z�R�}���h
	if (st2 == 1){
		puts("1:�t�@�C�A");
		puts("2:�V�[���h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st3);

		if ((st3 == 3 || st3 == 4) && TP <= 6){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
		}

		//	�ē��̓t�F�[�Y
		if (st3 != 1 && st3 != 2 && sac == 0){	//	�Z���w�����Ă��Ȃ��ꍇ
			printf("�P���Q����͂��Ă��������B\n");
			printf("\n");
			SAcommand();
		}
		if (sac == 1){
			if (st3 != 1 && st3 != 2 && st3 != 3){	//	�P�Z���w�������ꍇ
				printf("�P�`�R�܂ł̐�������͂��Ă��������B\n");
				printf("\n");
				SAcommand();
			}
		}
		else if (sac == 2){
			if (st3 != 1 && st3 != 2 && st3 != 3 && st3 != 4){	//	�Q�Z���w�������ꍇ
				printf("�P�`�S�܂ł̐�������͂��Ă��������B\n");
				printf("\n");
				SAcommand();
			}
		}
	}
	//	�A�C�A���X���C���̓���Z�R�}���h
	if (st2 == 2){
		st4 = 0;

		puts("1:�t�@�C�A");
		puts("2:�T���_�[");
		puts("3:�V�[���h");
		puts("4:�S��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st4);

		if ((st4 == 3 || st4 == 4) && TP <= 6){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
		}
		if (st4 == 1 || st4 == 2 || st4 == 3 || st4 == 4){
			flag = 1;
		}
		else if ((st4 == 0 || st4 >= 5) && flag == 0){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
		}
	}
	//	���b�h�X���C��
	if (st2 == 3){
		puts("1:�ːi");
		puts("2:�t�@�C�A�u���X");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st5);

		if (st5 != 1 && st5 != 2){
			printf("�P���Q����͂��Ă��������B\n");
			printf("\n");
			SAcommand();
		}
	}
	//	����
	if (st2 == 4){
		puts("1:�u���U�[�h");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st6);

		if (st6 != 1){
			printf("�P����͂��Ă��������B\n");
			printf("\n");
			SAcommand();
		}
	}
	//	�C�O��
	if (st2 == 5){
		puts("1:�V�[���h");
		puts("2:�X�s�[�h�A�b�v");
		puts("3:�X�s�[�h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st7);

		if (st7 == 1 && TP <= 6){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
		}
		if (st7 == 1 || st7 == 2 || st7 == 3){
			flag = 1;
		}
		else if ((st7 == 0 || st7 >= 4) && flag == 0){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
		}
	}
	//	�C��
	if (st2 == 6){
		puts("1:�V�[���h");
		puts("2:�V�[���h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st8);

		if (st8 != 1 && st8 != 2){
			printf("�P���Q����͂��Ă��������B\n");
			printf("\n");
			SAcommand();
		}
	}
	//	���@�g��
	if (st2 == 7){
		puts("1:�t�@�C�A");
		puts("2:�u���U�[�h");
		puts("3:�T���_�[");
		puts("4:�E�B���h�X���b�V��");
		puts("5:���e�I");
		puts("6:�V�[���h");
		puts("7:�X�s�[�h�A�b�v");
		puts("8:�X�s�[�h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st9);

		if ((st9 == 5 || st9 == 6) && TP <= 6){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
		}
		if (st9 == 5 && TP < 35){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
		}
		if (st9 == 1 || st9 == 2 || st9 == 3 || st9 == 4 || st9 == 5 || st9 == 6 || st9 == 7 || st9 == 8){
			flag = 1;
		}
		else if ((st9 == 0 || st9 >= 9) && flag == 0){
			puts("�P�`�W�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
		}
	}
	//	�R�J�g���X
	if (st2 == 8){
		puts("1:�T���_�[");
		puts("2:�E�B���h�X���b�V��");
		puts("3:�V�[���h");
		puts("4:�X�s�[�h�A�b�v");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st10);

		if (st10 != 1 && st10 != 2 && st10 != 3 && st10 != 4){
			printf("�P�`�S�܂ł̐�������͂��Ă��������B\n");
			printf("\n");
			SAcommand();
		}
	}
	//	�n�[�r�[
	if (st2 == 9){
		puts("1:�t�@�C�A");
		puts("2:�u���U�[�h");
		puts("3:�T���_�[");
		puts("4:�ɍ��̈ꌂ");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st11);

		if (st11 == 4 && TP <= 5){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
		}
		if (st11 == 1 || st11 == 2 || st11 == 3 || st11 == 4){
			flag = 1;
		}
		else if ((st11 == 0 || st11 >= 5) && flag == 0){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
		}
	}
	//	�g�����g
	if (st2 == 10){
		puts("1:�u���U�[�h");
		puts("2:�T���_�[");
		puts("3:�V�[���h");
		puts("4:�V�[���h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st12);

		if ((st12 == 3 || st12 == 4) && TP <= 6){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
		}
		if (st12 == 1 || st12 == 2 || st12 == 3 || st12 == 4){
			flag = 1;
		}
		else if ((st12 == 0 || st12 >= 5) && flag == 0){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
		}
	}
	//	�S�u����
	if (st2 == 11){
		puts("1:�ɍ��̈ꌂ");
		puts("2:�W�����v�U��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st13);

		if (st13 != 1 && st13 != 2){
			printf("�P���Q����͂��Ă��������B\n");
			printf("\n");
			SAcommand();
		}
	}
	//	�X�P���g��
	if (st2 == 12){
		puts("1:�t�@�C�A�\�[�h");
		puts("2:�u���U�[�h�\�[�h");
		puts("3:�T���_�[�\�[�h");
		puts("4:�W�����v�U��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st14);

		if (st14 == 4 && TP <= 4){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
		}
		if (st14 == 1 || st14 == 2 || st14 == 3 || st14 == 4){
			flag = 1;
		}
		else if ((st14 == 0 || st14 >= 5) && flag == 0){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
		}
	}
	//	���b��l
	if (st2 == 13){
		puts("1:�V�[���h�_�E��");
		puts("2:�X�s�[�h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st15);

		if (st15 != 1 && st15 != 2){
			printf("�P���Q����͂��Ă��������B\n");
			printf("\n");
			SAcommand();
		}
	}
	//	�|�S���l
	if (st2 == 14){
		puts("1:�X�s�[�h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st16);

		if (st16 != 1){
			printf("�P����͂��Ă��������B\n");
			printf("\n");
			SAcommand();
		}
	}
	//	�R�{���g
	if (st2 == 15){
		puts("1:�W�����v�U��");
		puts("2:�T���_�[�\�[�h");
		puts("3:�V�[���h�_�E��");
		puts("4:�E�B���h�X���b�V��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st17);

		if ((st17 == 1 || st17 == 3 || st17 == 4) && TP <= 4){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
		}
		if (st17 == 3 && TP <= 6){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
		}
		if (st17 == 1 || st17 == 2 || st17 == 3 || st17 == 4){
			flag = 1;
		}
		else if ((st17 == 0 || st17 >= 5) && flag == 0){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
		}
	}
	//	�O���t�H��
	if (st2 == 18){
		puts("1:�t�@�C�A");
		puts("2:�T���_�[");
		puts("3:�V�[���h�_�E��");
		puts("4:�X�s�[�h�A�b�v");
		puts("5:�R�[���h�u���X");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st18);

		if (st18 == 3 && TP <= 6){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
		}
		if (st18 == 1 || st18 == 2 || st18 == 3 || st18 == 4 || st18 == 5){
			flag = 1;
		}
		else if ((st18 == 0 || st18 >= 6) && flag == 0){
			puts("�P�`�T�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
		}
	}
	//	�R�h��
	if (st2 == 19){
		puts("1:�t�@�C�A�u���X");
		puts("2:�R�[���h�u���X");
		puts("3:�T���_�[�u���X");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st19);

		if (st19 != 1 && st19 != 2 && st19 != 3){
			printf("�P�`�R�̐�������͂��Ă��������B\n");
			printf("\n");
			SAcommand();
		}
	}
	//	�S�C��
	if (st2 == 20){
		puts("1:�ːi");
		puts("2:�R�[���h�u���X");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st20);

		if (st20 == 2 && TP <= 4){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
		}
		if (st20 == 1 || st20 == 2){
			flag = 1;
		}
		else if ((st20 == 0 || st20 >= 3) && flag == 0){
			puts("�P�`�Q�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
		}
	}
	//	�㖂���m
	if (st2 == 21){
		puts("1:�t�@�C�A");
		puts("2:�u���U�[�h");
		puts("3:�T���_�[");
		puts("4:���e�I");
		puts("5:�V�[���h");
		puts("6:�V�[���h�_�E��");
		puts("7:�X�s�[�h�A�b�v");
		puts("8:�X�s�[�h�_�E��");
		puts("9:�t�@�C�A�u���X");
		puts("10:�w���t�@�C�A");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st21);

		if (st21 != 1 && st21 != 2 && st21 != 3 && st21 != 4 && st21 != 5 && st21 != 6 && st21 != 7 && st21 != 8 && st21 != 9 && st21 != 10){
			puts("�P�`�P�O�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st21 = 0;
		}

		if (st21 == 4 && TP < 35){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st21 = 0;
		}
		if (st21 == 10 && TP < 8){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st21 = 0;
		}
		if ((st21 == 5 || st21 == 6) && TP < 7){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st21 = 0;
		}
	}

	//	���R�m
	if (st2 == 22){
		puts("1:�t�@�C�A�u���X");
		puts("2:�t�@�C�A�\�[�h");
		puts("3:�E�B���h�X���b�V��");
		puts("4:�X�s�[�h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st22);

		if (st22 != 1 && st22 != 2 && st22 != 3 && st22 != 4){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st22 = 0;
		}

		if (st22 == 4 && TP < 7){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st22 = 0;
		}
		if ((st22 == 1 || st22 == 3) && TP < 5){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st22 = 0;
		}
	}
	//	�O���[�^�[�f�[����
	if (st2 == 23){
		puts("1:�w���t�@�C�A");
		puts("2:�E�B���h�X���b�V��");
		puts("3:�T���_�[�u���X");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st23);

		if (st23 != 1 && st23 != 2 && st23 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st23 = 0;
		}

		if (st23 == 1 && TP < 8){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st23 = 0;
		}
	}
	//	�剤�C�J
	if (st2 == 24){
		puts("1:�u���U�[�h");
		puts("2:�R�[���h�u���X");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st24);

		if (st24 != 1 && st24 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st24 = 0;
		}
	}
	//	�h���S���t���C
	if (st2 == 25){
		puts("1:�t�@�C�A�u���X");
		puts("2:�ːi");
		puts("3:�ɍ��̈ꌂ");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st25);

		if (st25 != 1 && st25 != 2 && st25 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st25 = 0;
		}
		if (st25 == 1 && TP < 5){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st25 = 0;
		}
		if (st25 == 3 && TP < 6){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st25 = 0;
		}
	}
	//	�t�@�C�A�G�������^��
	if (st2 == 26){
		puts("1:�t�@�C�A");
		puts("2:�t�@�C�A�u���X");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st26);

		if (st26 != 1 && st26 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st26 = 0;
		}

		if ((st26 == 1 || st26 == 2) && TP < 5){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st26 = 0;
		}
	}
	//	�R�[���h�G�������^��
	if (st2 == 27){
		puts("1:�u���U�[�h");
		puts("2:�V�[���h");
		puts("3:�X�s�[�h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st27);

		if (st27 != 1 && st27 != 2 && st27 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st27 = 0;
		}

		if (st27 == 2 && TP < 7){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st27 = 0;
		}
	}
	//	�t���C���W���C�A���g
	if (st2 == 28){
		puts("1:�t�@�C�A�u���X");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st28);

		if (st28 != 1){
			puts("�P����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st28 = 0;
		}
	}
	//	�t���X�g�W���C�A���g
	if (st2 == 29){
		puts("1:�R�[���h�u���X");
		puts("2:�X�s�[�h�A�b�v");
		puts("3:�ɍ��̈ꌂ");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st29);

		if (st29 != 1 && st29 != 2 && st29 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st29 = 0;
		}

		if (st29 == 3 && TP < 6){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st29 = 0;
		}
	}
	//	�P���x���X
	if (st2 == 30){
		puts("1:�ːi");
		puts("2:�ɍ��̈ꌂ");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st30);

		if (st30 != 1 && st30 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st30 = 0;
		}

		if (st30 == 2 && TP < 6){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st30 = 0;
		}
	}
	//	���@���p�C�A�o�b�g
	if (st2 == 31){
		puts("1:�R�[���h�u���X");
		puts("2:�X�s�[�h�A�b�v");
		puts("3:�E�B���h�X���b�V��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st31);

		if (st31 != 1 && st31 != 2 && st31 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st31 = 0;
		}
	}
	//	�K�[�S�C��
	if (st2 == 33){
		puts("1:�t�@�C�A�\�[�h");
		puts("2:�T���_�[�\�[�h");
		puts("3:�E�B���h�X���b�V��");
		puts("4:�V�[���h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st33);

		if (st33 != 1 && st33 != 2 && st33 != 3 && st33 != 4){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st33 = 0;
		}

		if (st33 == 4 && TP < 7){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st33 = 0;
		}
		if (st33 == 3 && TP < 5){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st33 = 0;
		}
	}
	//	�o�V���X�N
	if (st2 == 34){
		puts("1:�T���_�[�u���X");
		puts("2:�X�s�[�h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st34);

		if (st34 != 1 && st34 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st34 = 0;
		}

		if ((st34 == 1 || st34 == 2) && TP < 5){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st34 = 0;
		}
	}
	//	�|�C�Y���X�l�C�N
	if (st2 == 35){
		puts("1:�ːi");
		puts("2:�V�[���h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st35);

		if (st35 != 1 && st35 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st35 = 0;
		}

		if (st35 == 2 && TP < 6){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st35 = 0;
		}
	}
	//	�_�[�N�S�u����
	if (st2 == 36){
		puts("1:�W�����v�U��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st36);

		if (st36 != 1){
			puts("�P����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st36 = 0;
		}
	}
	//	�����\���W���[
	if (st2 == 37){
		puts("1:�t�@�C�A�\�[�h");
		puts("2:�u���U�[�h�\�[�h");
		puts("3:�T���_�[�\�[�h");
		puts("4:�T���_�[");
		puts("5:�W�����v�U��");
		puts("6:�V�[���h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st37);

		if (st37 != 1 && st37 != 2 && st37 != 3 && st37 != 4 && st37 != 5 && st37 != 6){
			puts("�P�`�U�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st37 = 0;
		}

		if ((st37 == 4 || st37 == 5) && TP < 5){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st37 = 0;
		}
		if (st37 == 6 && TP < 7){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st37 = 0;
		}
	}
	//	���C�o�[��
	if (st2 == 38){
		puts("1:�t�@�C�A�u���X");
		puts("2:�R�[���h�u���X");
		puts("3:�T���_�[�u���X");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st38);

		if (st38 != 1 && st38 != 2 && st38 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st38 = 0;
		}
	}
	//	�l�H���V���[�N
	if (st2 == 39){
		puts("1:�R�[���h�u���X");
		puts("2:�ːi");
		puts("3:�X�s�[�h�A�b�v");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st39);

		if (st39 != 1 && st39 != 2 && st39 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st39 = 0;
		}
	}
	//	�R���a
	if (st2 == 40){
		puts("1:�S��");
		puts("2:�ɍ��̈ꌂ");
		puts("3:�V�[���h");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st40);

		if (st40 != 1 && st40 != 2 && st40 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st40 = 0;
		}
		if (st40 == 2 && TP < 6){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st40 = 0;
		}
	}
	//	�W���C�A���g���b�g
	if (st2 == 41){
		puts("1:�ːi");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st41);

		if (st41 != 1){
			puts("�P����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st41 = 0;
		}
	}
	//	�S�[�X�g
	if (st2 == 42){
		puts("1:�t�@�C�A");
		puts("2:�u���U�[�h");
		puts("3:�T���_�[");
		puts("4:�E�B���h�X���b�V��");
		puts("5:�_�C�������h�_�X�g");
		puts("6:�X�s�[�h�A�b�v");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st42);

		if (st42 != 1 && st42 != 2 && st42 != 3 && st42 != 4 && st42 != 5 && st42 != 6){
			puts("�P�`�U�ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st42 = 0;
		}
		if (st42 == 5 && TP < 8){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st42 = 0;
		}
	}
	//	�O��������
	if (st2 == 43){
		puts("1:�t�@�C�A");
		puts("2:�u���U�[�h");
		puts("3:�V�[���h");
		puts("4:�X�s�[�h�A�b�v");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st43);

		if (st43 != 1 && st43 != 2 && st43 != 3 && st43 != 4){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st43 = 0;
		}
		if (st43 == 3 && TP < 7){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st43 = 0;
		}
	}
	//	�L���O�R�u��
	if (st2 == 44){
		puts("1:�V�[���h�_�E��");
		puts("2:�ɍ��̈ꌂ");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st44);

		if (st44 != 1 && st44 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st44 = 0;
		}
		if (st44 == 1 && TP < 7){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st44 = 0;
		}
	}
	//	�����E��A
	if (st2 == 45){
		puts("1:�X�s�[�h�A�b�v");
		puts("2:�W�����v�U��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st45);

		if (st45 != 1 && st45 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st45 = 0;
		}
	}
	//	�����E��B
	if (st2 == 46){
		puts("1:�E�B���h�X���b�V��");
		puts("2:�W�����v�U��");
		puts("3:�V�[���h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st46);

		if (st46 != 1 && st46 != 2 && st46 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st46 = 0;
		}
		if (st46 == 3 && TP < 7){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st46 = 0;
		}
	}
	//	�S�[�X�g�i�C�g
	if (st2 == 47){
		puts("1:�t�@�C�A�\�[�h");
		puts("2:�u���U�[�h�\�[�h");
		puts("3:�T���_�[�\�[�h");
		puts("4:�R�[���h�u���X");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st47);

		if (st47 != 1 && st47 != 2 && st47 != 3 && st47 != 4){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st47 = 0;
		}
		if (st47 == 4 && TP < 5){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st47 = 0;
		}
	}
	//	����
	if (st2 == 48){
		puts("1:�t�@�C�A�u���X");
		puts("2:�ːi");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st48);

		if (st48 != 1 && st48 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st48 = 0;
		}
		if (st48 == 1 && TP < 5){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st48 = 0;
		}
	}
	//	�d�p�t
	if (st2 == 49){
		puts("1:���e�I");
		puts("2:�V�[���h");
		puts("3:�V�[���h�_�E��");
		puts("4:�X�s�[�h�A�b�v");
		puts("5:�X�s�[�h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st49);

		if (st49 != 1 && st49 != 2 && st49 != 3 && st49 != 4 && st49 != 5){
			puts("�P�`�T�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st49 = 0;
		}
		if (st49 == 1 && TP < 35){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st49 = 0;
		}
		if ((st49 == 2 || st49 == 3) && TP < 7){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st49 = 0;
		}
	}
	//	���U�[�h�}��
	if (st2 == 50){
		puts("1:�W�����v�U��");
		puts("2:�u���U�[�h�\�[�h");
		puts("3:�T���_�[�\�[�h");
		puts("4:�ɍ��̈ꌂ");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st50);

		if (st50 != 1 && st50 != 2 && st50 != 3 && st50 != 4){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			SAcommand();
			st50 = 0;
		}
		if (st50 == 1 && TP < 5){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st50 = 0;
		}
		if (st50 == 4 && TP < 6){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st50 = 0;
		}
	}
	//	�O���[���X���C��
	if (st2 == 51){
		puts("1:�u���U�[�h");
		puts("2:�X�s�[�h�_�E��");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st51);

		if (st51 != 1 && st51 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st51 = 0;
		}
	}
	//	�}�b�h�}��
	if (st2 == 52){
		puts("1:�ːi");
		puts("2:�ɍ��̈ꌂ");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st52);

		if (st52 != 1 && st52 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st52 = 0;
		}
	}
	//	�l�򂢐A��
	if (st2 == 53){
		puts("1:�T���_�[�u���X");
		puts("2:�ɍ��̈ꌂ");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st53);

		if (st53 != 1 && st53 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st53 = 0;
		}
		if (st53 == 2 && TP < 6){
			puts("TP������܂���B");
			printf("\n");
			SAcommand();
			st53 = 0;
		}
	}
	//	�W���C�A���g
	if (st2 == 54){
		puts("1:�ɍ��̈ꌂ");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st54);

		if (st54 != 1){
			puts("�P����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st54 = 0;
		}
	}
	//	�L�}�C��
	if (st2 == 55){
		puts("1:�_�C�������h�_�X�g");
		puts("2:�R�[���h�u���X");

		if (sac >= 1){
			BScommand();
		}

		printf("����̐�������͂��Ă��������B--->");
		scanf_s("%d", &st55);

		if (st55 != 1 && st55 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			SAcommand();
			st55 = 0;
		}
		if (st55 == 1 && TP < 8){
			puts("TP������܂���B");
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

	//	�u���[�X���C���̓���Z�R�}���h
	if (r == 1){
		puts("1:�t�@�C�A");
		puts("2:�V�[���h�_�E��");
		r13 = (rand() % 2 + 1);

		if ((r13 == 1 && TP2 < 5) || (r13 == 2 && TP2 < 7)){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
		}
	}
	//	�A�C�A���X���C���̓���Z�R�}���h
	if (r == 2){
		puts("1:�t�@�C�A");
		puts("2:�T���_�[");
		puts("3:�V�[���h");
		puts("4:�S��");
		r14 = (rand() % 4 + 1);

		if ((r14 == 3 || r14 == 4) && TP2 <= 6){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
		}
		if (r14 == 1 || r14 == 2 || r14 == 3 || r14 == 4){
			cflag = 1;
		}
		else if ((r14 == 0 || r14 >= 5) && cflag == 0){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
		}
	}
	//	���b�h�X���C��
	if (r == 3){
		puts("1:�ːi");
		puts("2:�t�@�C�A�u���X");
		r15 = (rand() % 2 + 1);
	}
	//	����
	if (r == 4){
		puts("1:�u���U�[�h");
		r16 = (rand() % 1 + 1);
	}
	//	�C�O��
	if (r == 5){
		puts("1:�V�[���h");
		puts("2:�X�s�[�h�A�b�v");
		puts("3:�X�s�[�h�_�E��");
		r17 = (rand() % 3 + 1);

		if (r17 == 1 && TP2 <= 6){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
		}
		if (r17 == 1 || r17 == 2 || r17 == 3){
			cflag = 1;
		}
		else if ((r17 == 0 || r17 >= 4) && cflag == 0){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
		}
	}
	//	�C��
	if (r == 6){
		puts("1:�V�[���h");
		puts("2:�V�[���h�_�E��");
		r18 = (rand() % 2 + 1);
	}
	//	���@�g��
	if (r == 7){
		puts("1:�t�@�C�A");
		puts("2:�u���U�[�h");
		puts("3:�T���_�[");
		puts("4:�E�B���h�X���b�V��");
		puts("5:���e�I");
		puts("6:�V�[���h");
		puts("7:�X�s�[�h�A�b�v");
		puts("8:�X�s�[�h�_�E��");
		r19 = (rand() % 8 + 1);

		if ((r19 == 5 || r19 == 6) && TP2 <= 6){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
		}
		if (r19 == 5 && TP2 < 35){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
		}
		if (r19 == 1 || r19 == 2 || r19 == 3 || r19 == 4 || r19 == 5 || r19 == 6 || r19 == 7 || r19 == 8){
			cflag = 1;
		}
		else if ((r19 == 0 || r19 >= 9) && cflag == 0){
			puts("�P�`�W�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
		}
	}
	//	�R�J�g���X
	if (r == 8){
		puts("1:�T���_�[");
		puts("2:�E�B���h�X���b�V��");
		puts("3:�V�[���h");
		puts("4:�X�s�[�h�A�b�v");
		r20 = (rand() % 4 + 1);
	}
	//	�n�[�r�[
	if (r == 9){
		puts("1:�t�@�C�A");
		puts("2:�u���U�[�h");
		puts("3:�T���_�[");
		puts("4:�ɍ��̈ꌂ");
		r21 = (rand() % 4 + 1);

		if (r21 == 4 && TP2 <= 5){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
		}
		if (r21 == 1 || r21 == 2 || r21 == 3 || r21 == 4){
			cflag = 1;
		}
		else if ((r21 == 0 || r21 >= 5) && cflag == 0){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
		}
	}
	//	�g�����g
	if (r == 10){
		puts("1:�u���U�[�h");
		puts("2:�T���_�[");
		puts("3:�V�[���h");
		puts("4:�V�[���h�_�E��");
		r22 = (rand() % 4 + 1);

		if ((r22 == 3 || r22 == 4) && TP2 <= 6){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
		}
		if (r22 == 1 || r22 == 2 || r22 == 3 || r22 == 4){
			cflag = 1;
		}
		else if ((r22 == 0 || r22 >= 5) && cflag == 0){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
		}
	}
	//	�S�u����
	if (r == 11){
		puts("1:�ɍ��̈ꌂ");
		puts("2:�W�����v�U��");
		r23 = (rand() % 2 + 1);
	}
	//	�X�P���g��
	if (r == 12){
		puts("1:�t�@�C�A�\�[�h");
		puts("2:�u���U�[�h�\�[�h");
		puts("3:�T���_�[�\�[�h");
		puts("4:�W�����v�U��");
		r24 = (rand() % 4 + 1);

		if (r24 == 4 && TP2 <= 4){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
		}
		if (r24 == 1 || r24 == 2 || r24 == 3 || r24 == 4){
			cflag = 1;
		}
		else if ((r24 == 0 || r24 >= 5) && cflag == 0){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
		}
	}
	//	���b��l
	if (r == 13){
		puts("1:�V�[���h�_�E��");
		puts("2:�X�s�[�h�_�E��");
		r25 = (rand() % 2 + 1);
	}
	//	�|�S���l
	if (r == 14){
		puts("1:�X�s�[�h�_�E��");
		r26 = (rand() % 1 + 1);
	}
	//	�R�{���g
	if (r == 15){
		puts("1:�W�����v�U��");
		puts("2:�T���_�[�\�[�h");
		puts("3:�V�[���h�_�E��");
		puts("4:�E�B���h�X���b�V��");
		r27 = (rand() % 4 + 1);

		if ((r27 == 1 || r27 == 3 || r27 == 4) && TP2 <= 4){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
		}
		if (r27 == 3 && TP2 <= 6){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
		}
		if (r27 == 1 || r27 == 2 || r27 == 3 || r27 == 4){
			cflag = 1;
		}
		else if ((r27 == 0 || r27 >= 5) && cflag == 0){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
		}
	}
	//	�O���t�H��
	if (r == 18){
		puts("1:�t�@�C�A");
		puts("2:�T���_�[");
		puts("3:�V�[���h�_�E��");
		puts("4:�X�s�[�h�A�b�v");
		puts("5:�R�[���h�u���X");
		r28 = (rand() % 5 + 1);

		if (r28 == 3 && TP2 <= 6){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
		}
		if (r28 == 1 || r28 == 2 || r28 == 3 || r28 == 4 || r28 == 5){
			cflag = 1;
		}
		else if ((r28 == 0 || r28 >= 6) && cflag == 0){
			puts("�P�`�T�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
		}
	}
	//	�R�h��
	if (r == 19){
		puts("1:�t�@�C�A�u���X");
		puts("2:�R�[���h�u���X");
		puts("3:�T���_�[�u���X");
		r29 = (rand() % 3 + 1);
	}
	//	�S�C��
	if (r == 20){
		puts("1:�ːi");
		puts("2:�R�[���h�u���X");
		r30 = (rand() % 2 + 1);

		if (r30 == 2 && TP2 <= 4){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
		}
		if (r30 == 1 || r30 == 2){
			cflag = 1;
		}
		else if ((r30 == 0 || r30 >= 3) && cflag == 0){
			puts("�P�`�Q�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
		}
	}
	//	�㖂���m
	if (r == 21){
		r31 = 0;
		puts("1:�t�@�C�A");
		puts("2:�u���U�[�h");
		puts("3:�T���_�[");
		puts("4:���e�I");
		puts("5:�V�[���h");
		puts("6:�V�[���h�_�E��");
		puts("7:�X�s�[�h�A�b�v");
		puts("8:�X�s�[�h�_�E��");
		puts("9:�t�@�C�A�u���X");
		puts("10:�w���t�@�C�A");
		r31 = (rand() % 10 + 1);

		if (r31 != 1 && r31 != 2 && r31 != 3 && r31 != 4 && r31 != 5 && r31 != 6 && r31 != 7 && r31 != 8 && r31 != 9 && r31 != 10){
			puts("�P�`�P�O�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r31 = 0;
		}

		if (r31 == 4 && TP2 < 35){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r31 = 0;
		}
		if (r31 == 10 && TP2 < 8){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r31 = 0;
		}
		if ((r31 == 5 || r31 == 6) && TP2 < 7){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r31 = 0;
		}
	}
	//	���R�m
	if (r == 22){
		puts("1:�t�@�C�A�u���X");
		puts("2:�t�@�C�A�\�[�h");
		puts("3:�E�B���h�X���b�V��");
		puts("4:�X�s�[�h�_�E��");
		r32 = (rand() % 4 + 1);

		if (r32 != 1 && r32 != 2 && r32 != 3 && r32 != 4){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r32 = 0;
		}

		if (r32 == 4 && TP2 < 7){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r32 = 0;
		}
		if ((r32 == 1 || r32 == 3) && TP2 < 5){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r32 = 0;
		}
	}
	//	�O���[�^�[�f�[����
	if (r == 23){
		puts("1:�w���t�@�C�A");
		puts("2:�E�B���h�X���b�V��");
		puts("3:�T���_�[�u���X");
		r33 = (rand() % 3 + 1);

		if (r33 != 1 && r33 != 2 && r33 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r33 = 0;
		}

		if (r33 == 1 && TP2 < 8){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r33 = 0;
		}
	}
	//	�剤�C�J
	if (r == 24){
		puts("1:�u���U�[�h");
		puts("2:�R�[���h�u���X");
		r34 = (rand() % 2 + 1);

		if (r34 != 1 && r34 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r34 = 0;
		}
	}
	//	�h���S���t���C
	if (r == 25){
		puts("1:�t�@�C�A�u���X");
		puts("2:�ːi");
		puts("3:�ɍ��̈ꌂ");
		r35 = (rand() % 3 + 1);

		if (r35 != 1 && r35 != 2 && r35 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r35 = 0;
		}
		if (r35 == 1 && TP2 < 5){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r35 = 0;
		}
		if (r35 == 3 && TP2 < 6){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r35 = 0;
		}
	}
	//	�t�@�C�A�G�������^��
	if (r == 26){
		puts("1:�t�@�C�A");
		puts("2:�t�@�C�A�u���X");
		r36 = (rand() % 2 + 1);

		if (r36 != 1 && r36 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r36 = 0;
		}

		if ((r36 == 1 || r36 == 2) && TP2 < 5){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r36 = 0;
		}
	}
	//	�R�[���h�G�������^��
	if (r == 27){
		puts("1:�u���U�[�h");
		puts("2:�V�[���h");
		puts("3:�X�s�[�h�_�E��");
		r37 = (rand() % 3 + 1);

		if (r37 != 1 && r37 != 2 && r37 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r37 = 0;
		}

		if (r37 == 2 && TP2 < 7){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r37 = 0;
		}
	}
	//	�t���C���W���C�A���g
	if (r == 28){
		puts("1:�t�@�C�A�u���X");
		r38 = 1;

		if (r38 != 1){
			puts("�P����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r38 = 0;
		}
	}
	//	�t���X�g�W���C�A���g
	if (r == 29){
		puts("1:�R�[���h�u���X");
		puts("2:�X�s�[�h�A�b�v");
		puts("3:�ɍ��̈ꌂ");
		r39 = (rand() % 3 + 1);

		if (r39 != 1 && r39 != 2 && r39 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r39 = 0;
		}

		if (r39 == 3 && TP2 < 6){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r39 = 0;
		}
	}
	//	�P���x���X
	if (r == 30){
		puts("1:�ːi");
		puts("2:�ɍ��̈ꌂ");
		r40 = (rand() % 2 + 1);

		if (r40 != 1 && r40 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r40 = 0;
		}

		if (r40 == 2 && TP2 < 6){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r40 = 0;
		}
	}
	//	���@���p�C�A�o�b�g
	if (r == 31){
		puts("1:�R�[���h�u���X");
		puts("2:�X�s�[�h�A�b�v");
		puts("3:�E�B���h�X���b�V��");
		r41 = (rand() % 3 + 1);

		if (r41 != 1 && r41 != 2 && r41 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r41 = 0;
		}
	}
	//	�K�[�S�C��
	if (r == 33){
		puts("1:�t�@�C�A�\�[�h");
		puts("2:�T���_�[�\�[�h");
		puts("3:�E�B���h�X���b�V��");
		puts("4:�V�[���h�_�E��");
		r43 = (rand() % 4 + 1);

		if (r43 != 1 && r43 != 2 && r43 != 3 && r43 != 4){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r43 = 0;
		}

		if (r43 == 4 && TP2 < 7){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r43 = 0;
		}
		if (r43 == 3 && TP2 < 5){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r43 = 0;
		}
	}
	//	�o�V���X�N
	if (r == 34){
		puts("1:�T���_�[�u���X");
		puts("2:�X�s�[�h�_�E��");
		r44 = (rand() % 2 + 1);

		if (r44 != 1 && r44 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r44 = 0;
		}

		if ((r44 == 1 || r44 == 2) && TP2 < 5){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r44 = 0;
		}
	}
	//	�|�C�Y���X�l�C�N
	if (r == 35){
		puts("1:�ːi");
		puts("2:�V�[���h�_�E��");
		r45 = (rand() % 2 + 1);

		if (r45 != 1 && r45 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r45 = 0;
		}

		if (r45 == 2 && TP2 < 6){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r45 = 0;
		}
	}
	//	�_�[�N�S�u����
	if (r == 36){
		puts("1:�W�����v�U��");
		r46 = 1;

		if (r46 != 1){
			puts("�P����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r46 = 0;
		}
	}
	//	�����\���W���[
	if (r == 37){
		puts("1:�t�@�C�A�\�[�h");
		puts("2:�u���U�[�h�\�[�h");
		puts("3:�T���_�[�\�[�h");
		puts("4:�T���_�[");
		puts("5:�W�����v�U��");
		puts("6:�V�[���h�_�E��");
		r47 = (rand() % 6 + 1);

		if (r47 != 1 && r47 != 2 && r47 != 3 && r47 != 4 && r47 != 5 && r47 != 6){
			puts("�P�`�U�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r47 = 0;
		}

		if ((r47 == 4 || r47 == 5) && TP2 < 5){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r47 = 0;
		}
		if (r47 == 6 && TP2 < 7){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r47 = 0;
		}
	}
	//	���C�o�[��
	if (r == 38){
		puts("1:�t�@�C�A�u���X");
		puts("2:�R�[���h�u���X");
		puts("3:�T���_�[�u���X");
		r48 = (rand() % 3 + 1);

		if (r48 != 1 && r48 != 2 && r48 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r48 = 0;
		}
	}
	//	�l�H���V���[�N
	if (r == 39){
		puts("1:�R�[���h�u���X");
		puts("2:�ːi");
		puts("3:�X�s�[�h�A�b�v");
		r49 = (rand() % 3 + 1);

		if (r49 != 1 && r49 != 2 && r49 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r49 = 0;
		}
	}
	//	�R���a
	if (r == 40){
		puts("1:�S��");
		puts("2:�ɍ��̈ꌂ");
		puts("3:�V�[���h");
		r50 = (rand() % 3 + 1);

		if (r50 != 1 && r50 != 2 && r50 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r50 = 0;
		}
		if (r50 == 2 && TP2 < 6){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r50 = 0;
		}
		if (r50 == 1 && TP2 < 20){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r50 = 0;
		}
	}
	//	�W���C�A���g���b�g
	if (r == 41){
		puts("1:�ːi");
		r51 = 1;

		if (r51 != 1){
			puts("�P����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r51 = 0;
		}
	}
	//	�S�[�X�g
	if (r == 42){
		puts("1:�t�@�C�A");
		puts("2:�u���U�[�h");
		puts("3:�T���_�[");
		puts("4:�E�B���h�X���b�V��");
		puts("5:�_�C�������h�_�X�g");
		puts("6:�X�s�[�h�A�b�v");
		r52 = (rand() % 6 + 1);

		if (r52 != 1 && r52 != 2 && r52 != 3 && r52 != 4 && r52 != 5 && r52 != 6){
			puts("�P�`�U�ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r52 = 0;
		}
		if (r52 == 5 && TP2 < 8){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r52 = 0;
		}
	}
	//	�O��������
	if (r == 43){
		puts("1:�t�@�C�A");
		puts("2:�u���U�[�h");
		puts("3:�V�[���h");
		puts("4:�X�s�[�h�A�b�v");
		r53 = (rand() % 4 + 1);

		if (r53 != 1 && r53 != 2 && r53 != 3 && r53 != 4){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r53 = 0;
		}
		if (r53 == 3 && TP2 < 7){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r53 = 0;
		}
	}
	//	�L���O�R�u��
	if (r == 44){
		puts("1:�V�[���h�_�E��");
		puts("2:�ɍ��̈ꌂ");
		r54 = (rand() % 2 + 1);

		if (r54 != 1 && r54 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r54 = 0;
		}

		if (r54 == 1 && TP < 7){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r54 = 0;
		}
	}
	//	�����E��A
	if (r == 45){
		puts("1:�X�s�[�h�A�b�v");
		puts("2:�W�����v�U��");
		r55 = (rand() % 2 + 1);

		if (r55 != 1 && r55 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r55 = 0;
		}
	}
	//	�����E��B
	if (r == 46){
		puts("1:�E�B���h�X���b�V��");
		puts("2:�W�����v�U��");
		puts("3:�V�[���h�_�E��");
		r56 = (rand() % 3 + 1);

		if (r56 != 1 && r56 != 2 && r56 != 3){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r56 = 0;
		}
		if (r56 == 3 && TP2 < 7){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r56 = 0;
		}
	}
	//	�S�[�X�g�i�C�g
	if (r == 47){
		puts("1:�t�@�C�A�\�[�h");
		puts("2:�u���U�[�h�\�[�h");
		puts("3:�T���_�[�\�[�h");
		puts("4:�R�[���h�u���X");
		r57 = (rand() % 4 + 1);

		if (r57 != 1 && r57 != 2 && r57 != 3 && r57 != 4){
			puts("�P�`�R�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r57 = 0;
		}
		if (r57 == 4 && TP2 < 5){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r57 = 0;
		}
	}
	//	����
	if (r == 48){
		puts("1:�t�@�C�A�u���X");
		puts("2:�ːi");
		r58 = (rand() % 2 + 1);

		if (r58 != 1 && r58 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r58 = 0;
		}
		if (r58 == 1 && TP < 5){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r58 = 0;
		}
	}
	//	�d�p�t
	if (r == 49){
		puts("1:���e�I");
		puts("2:�V�[���h");
		puts("3:�V�[���h�_�E��");
		puts("4:�X�s�[�h�A�b�v");
		puts("5:�X�s�[�h�_�E��");
		r59 = (rand() % 5 + 1);

		if (r59 != 1 && r59 != 2 && r59 != 3 && r59 != 4 && r59 != 5){
			puts("�P�`�T�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r59 = 0;
		}
		if (r59 == 1 && TP2 < 35){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r59 = 0;
		}
		if ((r59 == 2 || r59 == 3) && TP2 < 7){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r59 = 0;
		}
	}
	//	���U�[�h�}��
	if (r == 50){
		puts("1:�W�����v�U��");
		puts("2:�u���U�[�h�\�[�h");
		puts("3:�T���_�[�\�[�h");
		puts("4:�ɍ��̈ꌂ");
		r60 = (rand() % 4 + 1);

		if (r60 != 1 && r60 != 2 && r60 != 3 && r60 != 4){
			puts("�P�`�S�܂ł̐�������͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r60 = 0;
		}
		if (r60 == 1 && TP2 < 5){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r60 = 0;
		}
		if (r60 == 4 && TP2 < 6){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r60 = 0;
		}
	}
	//	�O���[���X���C��
	if (r == 51){
		puts("1:�u���U�[�h");
		puts("2:�X�s�[�h�_�E��");
		r61 = (rand() % 2 + 1);

		if (r61 != 1 && r61 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r61 = 0;
		}
	}
	//	�}�b�h�}��
	if (r == 52){
		puts("1:�ːi");
		puts("2:�ɍ��̈ꌂ");
		r62 = (rand() % 2 + 1);

		if (r62 != 1 && r62 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r62 = 0;
		}
		if (r62 == 2 && TP2 < 6){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r62 = 0;
		}
	}
	//	�l�򂢐A��
	if (r == 53){
		puts("1:�T���_�[�u���X");
		puts("2:�ɍ��̈ꌂ");
		r63 = (rand() % 2 + 1);

		if (r63 != 1 && r63 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r63 = 0;
		}
		if (r63 == 2 && TP2 < 6){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r63 = 0;
		}
	}
	//	�W���C�A���g
	if (r == 54){
		puts("1:�ɍ��̈ꌂ");
		r64 = 1;

		if (r64 != 1){
			puts("�P����͂��Ă��������B");
			printf("\n");
			SAcommand();
			r64 = 0;
		}
	}
	//	�L�}�C��
	if (r == 55){
		puts("1:�_�C�������h�_�X�g");
		puts("2:�R�[���h�u���X");
		r65 = (rand() % 2 + 1);

		if (r65 != 1 && r65 != 2){
			puts("�P���Q����͂��Ă��������B");
			printf("\n");
			CSAcommand();
			r65 = 0;
		}
		if (r65 == 1 && TP2 < 8){
			puts("TP������܂���B");
			printf("\n");
			CSAcommand();
			r65 = 0;
		}
	}

	CSpecialAttack();
}

//	�o�g�����[�h��p�̗\��`
void herb(){			//	�n�[�u
	puts("�n�[�u���g�����IHP���V�O�O�񕜂����I");
	HP += 700;
}

void uherb(){			//	�n�[�u�i��j
	puts("�n�[�u(��)���g�����IHP���P�T�O�O�񕜂����I");
	HP += 1500;
}

void suherb(){			//	�n�[�u(����)
	puts("�n�[�u(����)���g�����IHP���R�O�O�O�񕜂����I");
	HP += 3000;
}

void baziru(){			//	�o�W��
	puts("�o�W�����g�����ITP���T�񕜂����I");
	TP += 5;
}

void ubaziru(){			//	�o�W���i��j
	puts("�o�W��(��)���g�����ITP���P�O�񕜂����I");
	TP += 10;
}

void subaziru(){		//	�o�W���i����j
	puts("�o�W��(����)���g�����ITP���Q�O�񕜂����I");
	TP += 20;
}

void ulbaziru(){		//	�o�W���i�Ɂj
	puts("�o�W��(��)���g�����ITP���T�O�񕜂����I");
	TP += 50;
}

void very(){			//	�x���B
	puts("�x���B���g�����IHP���P�O�O�O�ATP���P�T�񕜂����I");
	HP += 1000;
	TP += 15;
}

void uvery(){			//	�x���B�i��j
	puts("�x���B(��)���g�����IHP���Q�O�O�O�ATP���R�O�񕜂����I");
	HP += 2000;
	TP += 30;
}

void ulvery(){			//	�x���B�i�Ɂj
	puts("�x���B(��)���g�����IHP���S�O�O�O�ATP���U�O�񕜂����I");
	HP += 4000;
	TP += 60;
}

void pherb(){			//	���̃n�[�u
	puts("���̃n�[�u���g�����ITP�������ɂȂ����I");
	TP += 9999;			//	�����ɂ��邱�Ƃ��ł��Ȃ����A�l��9999�ɂ��邱�Ƃ�TP���s���邱�Ƃ��Ȃ�
}

void ITEM(){			//	����
	int i, j;			//	�J��Ԃ��p�ϐ�
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
		printf("�ǂ���g���܂����H--->");
		scanf_s("%d", &ist);

		if (ist == 1){					//	ist���P�A����f1���O�Ȃ�A�C�e���g�p����
			if (f1 == 0){
				herb();
				c1 = 1;
				lp = 0;
				f1 = 1;				//	�g�p�ς݂ł���Ƃ�������
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}
		else if (ist == 2){
			if (f2 == 0){
				herb();
				c2 = 1;
				lp = 0;
				f2 = 1;				//	�g�p�ς݂ł���Ƃ�������
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}
		else if (ist == 3){
			if (f3 == 0){
				herb();
				c3 = 1;
				lp = 0;
				f3 = 1;				//	�g�p�ς݂ł���Ƃ�������
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}
		else if (ist == 4){
			if (f4 == 0){
				herb();
				c4 = 1;
				lp = 0;
				f4 = 1;				//	�g�p�ς݂ł���Ƃ�������
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}
		else if (ist == 5){
			if (f5 == 0){
				herb();
				c5 = 1;
				lp = 0;
				f5 = 1;				//	�g�p�ς݂ł���Ƃ�������
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}						//	���̉����n�[�u(��)
		else if (ist == 6){
			if (d6 == 0){
				uherb();
				d1 = 1;
				lp = 0;
				d6 = 1;
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}							//	���̉����n�[�u(����)
		else if (ist == 11){
			if (e6 == 0){
				suherb();
				e1 = 1;
				lp = 0;
				e6 = 1;
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}						//	���̉����o�W��
		else if (ist == 16){
			if (g6 == 0){
				baziru();
				g1 = 1;
				lp = 0;
				g6 = 1;
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}						//	���̉����o�W��(��)
		else if (ist == 21){
			if (h6 == 0){
				ubaziru();
				h1 = 1;
				lp = 0;
				h6 = 1;
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}						//	���̉����o�W��(����)
		else if (ist == 26){
			if (i6 == 0){
				subaziru();
				i1 = 1;
				lp = 0;
				i6 = 1;
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}						//	���̉����o�W��(��)
		else if (ist == 31){
			if (j6 == 0){
				ulbaziru();
				j1 = 1;
				lp = 0;
				j6 = 1;
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}				//	���̉����x���B
		else if (ist == 36){
			if (k6 == 0){
				very();
				k1 = 1;
				lp = 0;
				k6 = 1;
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}						//	���̉����x���B(��)
		else if (ist == 41){
			if (l6 == 0){
				uvery();
				l1 = 1;
				lp = 0;
				l6 = 1;
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}					//	���̉����x���B(��)
		else if (ist == 46){
			if (m6 == 0){
				ulvery();
				m1 = 1;
				lp = 0;
				m6 = 1;
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}					//	���̉���茶�̃n�[�u
		else if (ist == 51){
			if (n4 == 0){
				pherb();
				n1 = 1;
				lp = 0;
				n4 = 1;
			}
			else{
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
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
				puts("���łɎg�p���Ă��܂��B");
				lp = 1;
			}
		}
		else{
			puts("�P�`�T�R�܂ł̐�������͂��Ă��������B");
			lp = 1;
		}

		printf("\n");
	}
}

//	�g�[�i�����g���[�h��p�̃A�C�e���֐�
void Titem(){
	int i, j;
	int tst = 0;		//	�g�p����A�C�e����I�����邽�߂Ɏg�p
	int tlp = 1;

	tflg = 0;
	//	���ݏ������Ă���A�C�e���̕\��
	for (i = 0; i<INUM; i++){
		printf("%d:%s\n", i + 1, TMI[i]);
	}
	for (j = 0; j<INUM; j++){
		if (strcmp(TMI[j], "") == 0){
			tflg = 1;
			puts("�A�C�e��������܂���B");
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
			if (hf >= 1){					//	�A�C�e�����̈�ԏオ�n�[�u�Ȃ�
				herb();						//	�n�[�u���g�p����
				strcpy_s(TMI[tst - 1], "");		//	�g�p������A�C�e�����̈�ԏ���󔒂ɂ���
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
			if (hf >= 1){					//	�A�C�e�����̈�ԏオ�n�[�u�Ȃ�
				herb();						//	�n�[�u���g�p����
				strcpy_s(TMI[tst - 1], "");		//	�g�p������A�C�e�����̈�ԏ���󔒂ɂ���
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
			if (hf >= 1){					//	�A�C�e�����̈�ԏオ�n�[�u�Ȃ�
				herb();						//	�n�[�u���g�p����
				strcpy_s(TMI[tst - 1], "");		//	�g�p������A�C�e�����̈�ԏ���󔒂ɂ���
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
			if (hf >= 1){					//	�A�C�e�����̈�ԏオ�n�[�u�Ȃ�
				herb();						//	�n�[�u���g�p����
				strcpy_s(TMI[tst - 1], "");		//	�g�p������A�C�e�����̈�ԏ���󔒂ɂ���
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
			if (hf >= 1){					//	�A�C�e�����̈�ԏオ�n�[�u�Ȃ�
				herb();						//	�n�[�u���g�p����
				strcpy_s(TMI[tst - 1], "");		//	�g�p������A�C�e�����̈�ԏ���󔒂ɂ���
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

//	�v���C���[�s���֐�
void PAC(){
	int plo = 0;
	char ch[5];

	puts("----Player----");
	printf("name:%s HP=%d: TP=%d: atk:%d def:%d spd:%d\n", name, HP, TP, atk, def, spd);

	plo = 1;
	while (plo == 1){
		if (st2 == 16 || st2 == 17 || st2 == 32){					//	�I�����������X�^�[���]���r�A�~�C���j�A���̓I�[�K�̏ꍇ
			puts("�R�}���h�H");
			printf("1=�U��: 2=�h�� 3=�A�C�e��\n");
			scanf_s("%d", &stk1);

			if (stk1 == 1){			//	�U��
				HP2 = PDamage();
				plo = 0;
			}
			else if (stk1 == 2){		//	�h��
				puts("�g������Ă���B");
				plo = 0;
			}
			else if (stk1 == 3){		//	�A�C�e��
				if (sentaku == 1){
					ITEM();					//	�o�g�����[�h
				}
				else if (sentaku == 2){
					Titem();				//	�g�[�i�����g���[�h
				}
				plo = 0;
			}
			else{
				puts("�P�`�R�܂ł̐�������͂��Ă��������B");
				plo = 1;
			}
		}
		else{										//	�]���r�A�I�[�K�ȊO�̃����X�^�[
			puts("�R�}���h�H");
			printf("1=�U��: 2=�h��: 3=����Z: 4=�A�C�e��\n");
			scanf_s("%d", &stk1);

			if (stk1 == 1){			//	�U��
				HP2 = PDamage();
				plo = 0;
			}
			else if (stk1 == 2){		//	�h��
				puts("�g������Ă���B");
				plo = 0;
			}
			else if (stk1 == 3){		//	����Z
				if (st2 == 3 || st2 == 12 || st2 == 15 || st2 == 20 || st2 == 22 || st2 == 25 || st2 == 30 || st2 == 33 || st2 == 35 || st2 == 37 || st2 == 39 || st2 == 41 || st2 == 47 || st2 == 48 || st2 == 50 || st2 == 52){
					if (TP >= 3){		//	3�ȏ�
						SAcommand();
						plo = 0;
					}
					else{
						puts("TP������܂���B");
						printf("\n");
						plo = 1;
					}
				}
				else if (st2 == 1 || st2 == 2 || st2 == 4 || st2 == 5 || st2 == 7 || st2 == 8 || st2 == 9 || st2 == 10 || st2 == 11 || st2 == 13 || st2 == 14 || st2 == 18 || st2 == 19 || st2 == 21 || st2 == 23 || st2 == 24 || st2 == 26 || st2 == 27 || st2 == 28 || st2 == 29 || st2 == 31 || st2 == 34 || st2 == 36 || st2 == 38 || st2 == 42 || st2 == 43 || st2 == 45 || st2 == 46 || st2 == 49 || st2 == 51 || st2 == 53 || st2 == 55){
					if (TP >= 5){		//	5�ȏ�
						SAcommand();
						plo = 0;
					}
					else{
						puts("TP������܂���B");
						printf("\n");
						plo = 1;
					}
				}
				else if (st2 == 40 || st2 == 44 || st2 == 54){
					if (TP >= 6){			//	6�ȏ�
						SAcommand();
						plo = 0;
					}
					else{
						puts("TP������܂���B");
						printf("\n");
						plo = 1;
					}
				}
				else if (st2 == 6){
					if (TP >= 7){			//	7�ȏ�
						SAcommand();
						plo = 0;
					}
					else{
						puts("TP������܂���B");
						printf("\n");
						plo = 1;
					}
				}
			}
			else if (stk1 == 4){		//	�A�C�e��
				if (sentaku == 1){
					ITEM();				//	�o�g�����[�h
					plo = 0;
				}
				else if (sentaku == 2){
					Titem();			//	�g�[�i�����g���[�h
					if (tflg == 1){
						plo = 1;
					}
					else{
						plo = 0;
					}
				}
			}
			else{
				puts("�P�`�S�܂ł̐�������͂��Ă��������B");
				plo = 1;
			}
		}
	}
	printf("\n");
	puts("�K���ȃL�[����͂��Ă��������B");
	scanf_s("%s", ch, 5);
	printf("\n");
}

//	CPU�s���֐�
void CAC(){
	int clo = 0;
	r7 = 0;

	srand((unsigned int)time(NULL));

	r7 = (rand() % 2 + 1);

	puts("----CPU----");
	printf("name:%s HP=%d: TP=%d: atk:%d def:%d spd:%d\n", name2, HP2, TP2, atk2, def2, spd2);

	clo = 1;
	while (clo == 1){
		if (r == 16 || r == 17 || r == 32){				//	CPU���I�����������X�^�[���]���r�A���̓I�[�K�̏ꍇ
			puts("�R�}���h�H");
			printf("1=�U��\n");
			//	�U��
			HP = CDamage();
			clo = 0;
		}
		else{								//	�]���r�A�I�[�K�ȊO�̃����X�^�[
			puts("�R�}���h�H");
			printf("1=�U��: 2=����Z\n");

			if (r7 == 1){			//	�U��
				HP = CDamage();
				clo = 0;
			}
			else if (r7 == 2){		//	����Z
				if (r == 3 || r == 12 || r == 15 || r == 20 || r == 22 || r == 25 || r == 30 || r == 33 || r == 35 || r == 37 || r == 39 || r == 41 || r == 47 || r == 48 || r == 50 || r == 52){
					if (TP2 >= 3){
						CSAcommand();
						clo = 0;
					}
					else{
						puts("TP������܂���B");
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
						puts("TP������܂���B");
						printf("\n");
						r7 = 0;
						r7 = (rand() % 2 + 1);
						clo = 1;
					}
				}
				else if (r == 40 || r == 44 || r == 54){
					if (TP2 >= 6){			//	6�ȏ�
						CSAcommand();
						clo = 0;
					}
					else{
						puts("TP������܂���B");
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
						puts("TP������܂���B");
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
		puts("�Q�[�����I����Ă������ł����H(Yes=1: NO=2)");
		scanf_s("%d", &ges);

		if (ges == 1){
			puts("�I�����܂��E�E�E");
			exit(1);
		}
		else if (ges == 2){
			puts("���C�����j���[�֖߂�܂��B");
			loop2 = 0;
			loop = 1;
		}
		else{
			puts("�P���Q����͂��Ă��������B");
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

//	�A�C�e���ϐ��������֐�
void Init(){
	c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;												//	�A�C�e��������g�p�������̃t���O(�n�[�u)
	d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0, d8 = 0, d9 = 0, d10 = 0;	//	�n�[�u(��)&�t���O
	e1 = 0, e2 = 0, e3 = 0, e4 = 0, e5 = 0, e6 = 0, e7 = 0, e8 = 0, e9 = 0, e10 = 0;	//	�n�[�u(����)&�t���O
	g1 = 0, g2 = 0, g3 = 0, g4 = 0, g5 = 0, g6 = 0, g7 = 0, g8 = 0, g9 = 0, g10 = 0;	//	�o�W��&�t���O
	h1 = 0, h2 = 0, h3 = 0, h4 = 0, h5 = 0, h6 = 0, h7 = 0, h8 = 0, h9 = 0, h10 = 0;	//	�o�W��(��)���t���O
	i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0, i9 = 0, i10 = 0;	//	�o�W��(����)���t���O
	j1 = 0, j2 = 0, j3 = 0, j4 = 0, j5 = 0, j6 = 0, j7 = 0, j8 = 0, j9 = 0, j10 = 0;	//	�o�W��(��)���t���O
	k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0, k6 = 0, k7 = 0, k8 = 0, k9 = 0, k10 = 0;	//	�x���B���t���O
	l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0, l6 = 0, l7 = 0, l8 = 0, l9 = 0, l10 = 0;	//	�x���B(��)���t���O
	m1 = 0, m2 = 0, m3 = 0, m4 = 0, m5 = 0, m6 = 0, m7 = 0, m8 = 0, m9 = 0, m10 = 0;	//	�x���B(����)���t���O
	n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0;										//	���̃n�[�u���t���O
	f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0;			//	�n�[�u���g�p���ꂽ���ǂ����̃t���O

	strcpy_s(herb_t[0], "�n�[�u");

	strcpy_s(herb_t[1], "�n�[�u");

	strcpy_s(herb_t[2], "�n�[�u");

	strcpy_s(herb_t[3], "�n�[�u");

	strcpy_s(herb_t[4], "�n�[�u");

	strcpy_s(uherb_t[0], "�n�[�u(��)");

	strcpy_s(uherb_t[1], "�n�[�u(��)");

	strcpy_s(uherb_t[2], "�n�[�u(��)");

	strcpy_s(uherb_t[3], "�n�[�u(��)");

	strcpy_s(uherb_t[4], "�n�[�u(��)");

	strcpy_s(suherb_t[0], "�n�[�u(����)");

	strcpy_s(suherb_t[1], "�n�[�u(����)");

	strcpy_s(suherb_t[2], "�n�[�u(����)");

	strcpy_s(suherb_t[3], "�n�[�u(����)");

	strcpy_s(suherb_t[4], "�n�[�u(����)");

	strcpy_s(baziru_t[0], "�o�W��");

	strcpy_s(baziru_t[1], "�o�W��");

	strcpy_s(baziru_t[2], "�o�W��");

	strcpy_s(baziru_t[3], "�o�W��");

	strcpy_s(baziru_t[4], "�o�W��");

	strcpy_s(ubaziru_t[0], "�o�W��(��)");

	strcpy_s(ubaziru_t[1], "�o�W��(��)");

	strcpy_s(ubaziru_t[2], "�o�W��(��)");

	strcpy_s(ubaziru_t[3], "�o�W��(��)");

	strcpy_s(ubaziru_t[4], "�o�W��(��)");

	strcpy_s(subaziru_t[0], "�o�W��(����)");

	strcpy_s(subaziru_t[1], "�o�W��(����)");

	strcpy_s(subaziru_t[2], "�o�W��(����)");

	strcpy_s(subaziru_t[3], "�o�W��(����)");

	strcpy_s(subaziru_t[4], "�o�W��(����)");

	strcpy_s(ulbaziru_t[0], "�o�W��(��)");

	strcpy_s(ulbaziru_t[1], "�o�W��(��)");

	strcpy_s(ulbaziru_t[2], "�o�W��(��)");

	strcpy_s(ulbaziru_t[3], "�o�W��(��)");

	strcpy_s(ulbaziru_t[4], "�o�W��(��)");

	strcpy_s(very_t[0], "�x���B");

	strcpy_s(very_t[1], "�x���B");

	strcpy_s(very_t[2], "�x���B");

	strcpy_s(very_t[3], "�x���B");

	strcpy_s(very_t[4], "�x���B");

	strcpy_s(uvery_t[0], "�x���B(��)");

	strcpy_s(uvery_t[1], "�x���B(��)");

	strcpy_s(uvery_t[2], "�x���B(��)");

	strcpy_s(uvery_t[3], "�x���B(��)");

	strcpy_s(uvery_t[4], "�x���B(��)");

	strcpy_s(ulvery_t[0], "�x���B(��)");

	strcpy_s(ulvery_t[1], "�x���B(��)");

	strcpy_s(ulvery_t[2], "�x���B(��)");

	strcpy_s(ulvery_t[3], "�x���B(��)");

	strcpy_s(ulvery_t[4], "�x���B(��)");

	strcpy_s(pherb_t[0], "���̃n�[�u");

	strcpy_s(pherb_t[1], "���̃n�[�u");

	strcpy_s(pherb_t[2], "���̃n�[�u");
}

void TM1(){				//	1���̃����X�^�[�𗐐��ɂ�茈��
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

	puts("��1���̑���́E�E�E");

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

	puts("�K���ȃL�[����͂��Ă��������B");
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

	puts("��2���̑���́E�E�E");

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

	puts("�K���ȃL�[����͂��Ă��������B");
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

	puts("��3���̑���́E�E�E");

	strcpy_s(name2, MC[r - 1].name);
	HP2 = MC[r - 1].HP;
	TP2 = MC[r - 1].TP;
	atk2 = MC[r - 1].atk;
	def2 = MC[r - 1].def;
	spd2 = MC[r - 1].spd;

	printf("name=%s\n", name2);

	puts("�K���ȃL�[����͂��Ă��������B");
	scanf_s("%s", ch, 5);
}

void ShopEvent(){
	int stk0 = 0, sk = 1;		//	�֐����ϐ�(�I��)�A�ċA�����΍�
	int i;

	puts("���V���b�v��");
	puts("���i��			�l�i");
	puts("-------------------------------");
	puts("1:�n�[�u		3000G");
	puts("2:�n�[�u�i��j		7000G");
	puts("3:�o�W��		5000G");
	puts("4:HP�V�[�h		5000G");
	puts("5:TP�V�[�h		5000G");
	puts("6:atk�V�[�h		3000G");
	puts("7:def�V�[�h		3000G");
	puts("8:spd�V�[�h		3000G");
	printf("--->");
	scanf_s("%d", &stk0);

	if (stk0 == 1 && shozikin >= 3000){		//	�n�[�u�𔃂����ꍇ
		shozikin -= 3000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "�n�[�u");
				puts("�n�[�u�𔃂����I");
				count++;
				hf++;
				break;
			}
			else{
				puts("(!)����ȏ�w�����邱�Ƃ��ł��܂���B");
				break;
			}
		}
	}
	else if (stk0 == 2 && shozikin >= 7000){		//	�n�[�u�i��j�𔃂����ꍇ
		shozikin -= 7000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "�n�[�u(��)");
				puts("�n�[�u(��)�𔃂����I");
				count++;
				zhf++;
				break;
			}
			else{
				puts("(!)����ȏ�w�����邱�Ƃ��ł��܂���B");
				break;
			}
		}
	}
	else if (stk0 == 3 && shozikin >= 5000){		//	�o�W���𔃂����ꍇ
		shozikin -= 5000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "�o�W��");
				puts("�o�W���𔃂����I");
				count++;
				bz++;
				break;
			}
			else{
				puts("(!)����ȏ�w�����邱�Ƃ��ł��܂���B");
				break;
			}
		}
	}
	else if (stk0 == 4 && shozikin >= 5000){		//	HP�V�[�h�𔃂����ꍇ
		shozikin -= 5000;
		MP[st2 - 1].HP += 500;
		HP = MP[st2 - 1].HP;
		puts("HP�V�[�h�𔃂����I");
		puts("HP��500�オ�����I");
		puc++;
	}
	else if (stk0 == 5 && shozikin >= 5000){		//	TP�V�[�h�𔃂����ꍇ
		shozikin -= 5000;
		MP[st2 - 1].TP += 10;
		TP = MP[st2 - 1].TP;
		puts("TP�V�[�h�𔃂����I");
		puts("TP��10�オ�����I");
		puc4++;
	}
	else if (stk0 == 6 && shozikin >= 3000){		//	atk�V�[�h���w�������ꍇ
		shozikin -= 3000;
		MP[st2 - 1].atk += 50;
		atk = MP[st2 - 1].atk;
		puts("atk�V�[�h�𔃂����I");
		puts("atk��50�オ�����I");
		puc15++;
	}
	else if (stk0 == 7 && shozikin >= 3000){		//	def�V�[�h���w�������ꍇ
		shozikin -= 3000;
		MP[st2 - 1].def += 50;
		def = MP[st2 - 1].def;
		puts("def�V�[�h�𔃂����I");
		puts("def��50�オ�����I");
		puc7++;
	}
	else if (stk0 == 8 && shozikin >= 3000){		//	spd�V�[�h���w�������ꍇ
		shozikin -= 3000;
		MP[st2 - 1].spd += 50;
		spd = MP[st2 - 1].spd;
		puts("spd�V�[�h�𔃂����I");
		puts("spd��50�オ�����I");
		puc10++;
	}
	else{
		puts("����������܂���B");
		ShopEvent();
		sk = 0;
		stk0 = 0;
	}

	if (stk0 == 4 || stk0 == 5 || stk0 == 6 || stk0 == 7){		//	�p���[�A�b�v�n�A�C�e���𔃂����ꍇ
		printf("Name=%s: HP=%d: TP=%d: atk=%d: def=%d: spd=%d\n", name, HP, TP, atk, def, spd);
	}

	if (sk == 1){
		printf("\n\n\n");
	}
}

void ShopEvent2(){
	int stk1 = 0, i;		//	�A�C�e���I��p�ϐ��A���[�v�p�ϐ�
	int sk = 1;

	puts("���V���b�v��");
	puts("1:�n�[�u				3000G");
	puts("2:�n�[�u�i��j	7000G");
	puts("3:�n�[�u�i����j15000G");
	puts("4:�o�W��				5000G");
	puts("5:�o�W���i��j	10000G");
	puts("6:�o�W���i����j17000G");
	puts("7:�o�W���i�Ɂj	30000G");
	puts("8:�x���B				20000G");
	puts("9:�x���B�i��j	30000G");
	puts("10:�x���B�i�Ɂj	50000G");
	printf("--->");
	scanf_s("%d", &stk1);

	if (stk1 == 1 && shozikin >= 3000){		//	�n�[�u�𔃂����ꍇ
		shozikin -= 3000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "�n�[�u");
				puts("�n�[�u�𔃂����I");
				count++;
				hf++;
				break;
			}
			else{
				puts("(!)����ȏ�w�����邱�Ƃ��ł��܂���B");
				break;
			}
		}
	}
	else if (stk1 == 2 && shozikin >= 7000){		//	�n�[�u(��)
		shozikin -= 7000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "�n�[�u(��)");
				puts("�n�[�u(��)�𔃂����I");
				count++;
				zhf++;
				break;
			}
			else{
				puts("(!)����ȏ�w�����邱�Ƃ��ł��܂���B");
				break;
			}
		}
	}
	else if (stk1 == 3 && shozikin >= 15000){	//	�n�[�u(����)
		shozikin -= 15000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "�n�[�u(����)");
				puts("�n�[�u(����)�𔃂����I");
				count++;
				thf++;
				break;
			}
			else{
				puts("(!)����ȏ�w�����邱�Ƃ��ł��܂���B");
				break;
			}
		}
	}
	else if (stk1 == 4 && shozikin >= 5000){		//	�o�W��
		shozikin -= 5000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "�o�W��");
				puts("�o�W���𔃂����I");
				count++;
				bz++;
				break;
			}
			else{
				puts("(!)����ȏ�w�����邱�Ƃ��ł��܂���B");
				break;
			}
		}
	}
	else if (stk1 == 5 && shozikin >= 10000){	//	�o�W��(��)
		shozikin -= 10000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "�o�W��(��)");
				puts("�o�W��(��)�𔃂����I");
				count++;
				ubz++;
				break;
			}
			else{
				puts("(!)����ȏ�w�����邱�Ƃ��ł��܂���B");
				break;
			}
		}
	}
	else if (stk1 == 6 && shozikin >= 17000){	//	�o�W��(����)
		shozikin -= 17000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "�o�W��(����)");
				puts("�o�W��(����)�𔃂����I");
				count++;
				tbz++;
				break;
			}
			else{
				puts("(!)����ȏ�w�����邱�Ƃ��ł��܂���B");
				break;
			}
		}
	}
	else if (stk1 == 7 && shozikin >= 30000){	//	�o�W��(��)
		shozikin -= 30000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "�o�W��(��)");
				puts("�o�W��(��)�𔃂����I");
				count++;
				gbz++;
				break;
			}
			else{
				puts("(!)����ȏ�w�����邱�Ƃ��ł��܂���B");
				break;
			}
		}
	}
	else if (stk1 == 8 && shozikin >= 20000){	//	�x���B
		shozikin -= 20000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "�x���B");
				puts("�x���B�𔃂����I");
				count++;
				br++;
				break;
			}
			else{
				puts("(!)����ȏ�w�����邱�Ƃ��ł��܂���B");
				break;
			}
		}
	}
	else if (stk1 == 9 && shozikin >= 30000){	//	�x���B(��)
		shozikin -= 30000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "�x���B(��)");
				puts("�x���B(��)�𔃂����I");
				count++;
				ubr++;
				break;
			}
			else{
				puts("(!)����ȏ�w�����邱�Ƃ��ł��܂���B");
				break;
			}
		}
	}
	else if (stk1 == 10 && shozikin >= 50000){	//	�x���B(��)
		shozikin -= 50000;
		for (i = 0; i<INUM; i++){
			if (strcmp(TMI[i], "") == 0) {
				strcpy_s(TMI[i], "�x���B(��)");
				puts("�x���B(��)�𔃂����I");
				count++;
				gbr++;
				break;
			}
			else{
				puts("(!)����ȏ�w�����邱�Ƃ��ł��܂���B");
				break;
			}
		}
	}
	else{
		puts("����������܂���B");
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

	puts("���V���b�v��");
	puts("1:HP�V�[�h			5000G");
	puts("2:HP�V�[�h��			17000G");
	puts("3:HP�V�[�h�^			40000G");
	puts("4:TP�V�[�h			5000G");
	puts("5:TP�V�[�h��			17000G");
	puts("6:TP�V�[�h�^			40000G");
	puts("7:atk�V�[�h			3000G");
	puts("8:atk�V�[�h��			15000G");
	puts("9:atk�V�[�h�^			35000G");
	puts("10:def�V�[�h			3000G");
	puts("11:def�V�[�h��		15000G");
	puts("12:def�V�[�h�^		35000G");
	puts("13:spd�V�[�h			3000G");
	puts("14:spd�V�[�h��		15000G");
	puts("15:spd�V�[�h�^		35000");
	puts("16:�f���b�N�X�V�[�h	30000G");
	puts("17:�f���b�N�X�V�[�h�^	55000G");
	printf("--->");
	scanf_s("%d", &stk2);

	if (stk2 == 1 && shozikin >= 5000){				//	HP�V�[�h
		shozikin -= 5000;
		MP[st2 - 1].HP += 500;
		HP = MP[st2 - 1].HP;
		puts("HP�V�[�h�𔃂����I");
		puc++;
	}
	else if (stk2 == 2 && shozikin >= 17000){		//	HP�V�[�h��
		shozikin -= 17000;
		MP[st2 - 1].HP += 1000;
		HP = MP[st2 - 1].HP;
		puts("HP�V�[�h���𔃂����I");
		puc2++;
	}
	else if (stk2 == 3 && shozikin >= 40000){		//	HP�V�[�h�^
		shozikin -= 40000;
		MP[st2 - 1].HP += 2000;
		HP = MP[st2 - 1].HP;
		puts("HP�V�[�h�^�𔃂����I");
		puc3++;
	}
	else if (stk2 == 4 && shozikin >= 5000){			//	TP�V�[�h
		shozikin -= 5000;
		MP[st2 - 1].TP += 10;
		TP = MP[st2 - 1].TP;
		puts("TP�V�[�h�𔃂����I");
		puc4++;
	}
	else if (stk2 == 5 && shozikin >= 17000){		//	TP�V�[�h��
		shozikin -= 17000;
		MP[st2 - 1].TP += 20;
		TP = MP[st2 - 1].TP;
		puts("TP�V�[�h�𔃂����I");
		puc5++;
	}
	else if (stk2 == 6 && shozikin >= 40000){		//	TP�V�[�h�^
		shozikin -= 40000;
		MP[st2 - 1].TP += 40;
		TP = MP[st2 - 1].TP;
		puts("TP�V�[�h�𔃂����I");
		puc6++;
	}
	else if (stk2 == 7 && shozikin >= 3000){			//	atk�V�[�h
		shozikin -= 3000;
		MP[st2 - 1].atk += 50;
		atk = MP[st2 - 1].atk;
		puts("atk�V�[�h�𔃂����I");
		puc15++;
	}
	else if (stk2 == 8 && shozikin >= 15000){		//	atk�V�[�h��
		shozikin -= 15000;
		MP[st2 - 1].atk += 100;
		atk = MP[st2 - 1].atk;
		puts("atk�V�[�h���𔃂����I");
		puc16++;
	}
	else if (stk2 == 9 && shozikin >= 35000){		//	atk�V�[�h�^
		shozikin -= 35000;
		MP[st2 - 1].atk += 200;
		atk = MP[st2 - 1].atk;
		puts("atk�V�[�h�^�𔃂����I");
		puc17++;
	}
	else if (stk2 == 10 && shozikin >= 3000){		//	def�V�[�h
		shozikin -= 3000;
		MP[st2 - 1].def += 50;
		def = MP[st2 - 1].def;
		puts("def�V�[�h�𔃂����I");
		puc7++;
	}
	else if (stk2 == 11 && shozikin >= 15000){		//	def�V�[�h��
		shozikin -= 15000;
		MP[st2 - 1].def += 100;
		def = MP[st2 - 1].def;
		puts("def�V�[�h���𔃂����I");
		puc8++;
	}
	else if (stk2 == 12 && shozikin >= 35000){		//	def�V�[�h�^
		shozikin -= 35000;
		MP[st2 - 1].def += 200;
		def = MP[st2 - 1].def;
		puts("def�V�[�h�^�𔃂����I");
		puc9++;
	}
	else if (stk2 == 13 && shozikin >= 3000){		//	spd�V�[�h
		shozikin -= 3000;
		MP[st2 - 1].spd += 50;
		spd = MP[st2 - 1].spd;
		puts("spd�V�[�h�𔃂����I");
		puc10++;
	}
	else if (stk2 == 14 && shozikin >= 15000){		//	spd�V�[�h��
		shozikin -= 15000;
		MP[st2 - 1].spd += 100;
		spd = MP[st2 - 1].spd;
		puts("spd�V�[�h���𔃂����I");
		puc11++;
	}
	else if (stk2 == 15 && shozikin >= 35000){		//	spd�V�[�h�^
		shozikin -= 35000;
		MP[st2 - 1].spd += 200;
		spd = MP[st2 - 1].spd;
		puts("spd�V�[�h�^�𔃂����I");
		puc12++;
	}
	else if (stk2 == 16 && shozikin >= 30000){		//	�f���b�N�X�V�[�h
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
		puts("�f���b�N�X�V�[�h�𔃂����I");
		puc13++;
	}
	else if (stk2 == 17 && shozikin >= 55000){		//	�f���b�N�X�V�[�h�^
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
		puts("�f���b�N�X�V�[�h�^�𔃂����I");
		puc14++;
	}
	else{
		puts("����������܂���B");
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
	int stk3 = 0;		//	�Z��I������Ƃ��̕ϐ�
	int sk = 1;

	puts("���V���b�v��");
	puts("1:�t�@�C�A�\�[�h�̖{		30000G");
	puts("2:�u���U�[�h�\�[�h�̖{		30000G");
	puts("3:�T���_�[�\�[�h�̖{		30000G");
	puts("4:�ɍ��̈ꌂ�̖{		60000G");
	puts("5:�W�����v�U���̖{		35000G");
	puts("6:�ːi�̖{			25000G");
	puts("7:�t�@�C�A�u���X�̖{		35000G");
	puts("8:�R�[���h�u���X�̖{		35000G");
	puts("9:�T���_�[�u���X�̖{		35000G");
	puts("10:�S�ǂ̖{			40000G");
	puts("11:�t�@�C�A�̖{			40000G");
	puts("12:�u���U�[�h�̖{		40000G");
	puts("13:�T���_�[�̖{			40000G");
	puts("14:�E�B���h�X���b�V���̖{	40000G");
	puts("15:�V�[���h�̖{			32000G");
	puts("16:�V�[���h�_�E���̖{		37000G");
	puts("17:�X�s�[�h�A�b�v�̖{		32000G");
	puts("18:�X�s�[�h�_�E���̖{		37000G");
	printf("--->");
	scanf_s("%d", &stk3);

	if (stk3 == 1 && shozikin >= 30000 && fg1 == 0 && (st2 != 12 && st2 != 22 && st2 != 33 && st2 != 37 && st2 != 47)){		//	�t�@�C�A�\�[�h
		shozikin -= 30000;
		fg1 = 1;
		sac++;
		work++;
		puts("�t�@�C�A�\�[�h���o�����I");
	}
	else if (stk3 == 2 && shozikin >= 30000 && fg2 == 0 && (st2 != 12 && st2 != 37 && st2 != 47 && st2 != 50)){	//	�u���U�[�h�\�[�h
		shozikin -= 30000;
		fg2 = 1;
		sac++;
		work++;
		puts("�u���U�[�h�\�[�h���o�����I");
	}
	else if (stk3 == 3 && shozikin >= 30000 && fg3 == 0 && (st2 != 12 && st2 != 15 && st2 != 33 && st2 != 37 && st2 != 47 && st2 != 50)){	//	�T���_�[�\�[�h
		shozikin -= 30000;
		fg3 = 1;
		sac++;
		work++;
		puts("�T���_�[�\�[�h���o�����I");
	}
	else if (stk3 == 4 && shozikin >= 60000 && fg4 == 0 && (st2 != 9 && st2 != 11 && st2 != 25 && st2 != 29 && st2 != 30 && st2 != 40 && st2 != 44 && st2 != 50 && st2 != 52 && st2 != 53 && st2 != 54)){	//	�ɍ��̈ꌂ
		shozikin -= 60000;
		fg4 = 1;
		sac++;
		work++;
		puts("�ɍ��̈ꌂ���o�����I");
	}
	else if (stk3 == 5 && shozikin >= 35000 && fg5 == 0 && (st2 != 11 && st2 != 12 && st2 != 15 && st2 != 36 && st2 != 37 && st2 != 45 && st2 != 46 && st2 != 50)){	//	�W�����v�U��
		shozikin -= 35000;
		fg5 = 1;
		sac++;
		work++;
		puts("�W�����v�U�����o�����I");
	}
	else if (stk3 == 6 && shozikin >= 25000 && fg6 == 0 && (st2 != 3 && st2 != 20 && st2 != 25 && st2 != 30 && st2 != 35 && st2 != 39 && st2 != 41 && st2 != 48 && st2 != 52)){	//	�ːi
		shozikin -= 25000;
		fg6 = 1;
		sac++;
		work++;
		puts("�ːi���o�����I");
	}
	else if (stk3 == 7 && shozikin >= 35000 && fg7 == 0 && (st2 != 3 && st2 != 19 && st2 != 21 && st2 != 22 && st2 != 25 && st2 != 26 && st2 != 28 && st2 != 38 && st2 != 48)){	//	�t�@�C�A�u���X
		shozikin -= 35000;
		fg7 = 1;
		sac++;
		work++;
		puts("�t�@�C�A�u���X���o�����I");
	}
	else if (stk3 == 8 && shozikin >= 35000 && fg8 == 0 && (st2 != 18 && st2 != 19 && st2 != 20 && st2 != 24 && st2 != 29 && st2 != 31 && st2 != 38 && st2 != 39 && st2 != 47 && st2 != 55)){	//	�R�[���h�u���X
		shozikin -= 35000;
		fg8 = 1;
		sac++;
		work++;
		puts("�R�[���h�u���X���o�����I");
	}
	else if (stk3 == 9 && shozikin >= 35000 && fg9 == 0 && (st2 != 19 && st2 != 23 && st2 != 34 && st2 != 38 && st2 != 53)){	//	�T���_�[�u���X
		shozikin -= 35000;
		fg9 = 1;
		sac++;
		work++;
		puts("�T���_�[�u���X���o�����I");
	}
	else if (stk3 == 10 && shozikin >= 40000 && fg11 == 0 && (st2 != 2 && st2 != 40)){	//	�S��
		shozikin -= 40000;
		fg11 = 1;
		sac++;
		work++;
		puts("�S�ǂ��o�����I");
	}
	else if (stk3 == 11 && shozikin >= 40000 && fg12 == 0 && st2 != 1 && (st2 != 1 && st2 != 2 && st2 != 7 && st2 != 9 && st2 != 18 && st2 != 21 && st2 != 26 && st2 != 42 && st2 != 43)){	//	�t�@�C�A
		shozikin -= 40000;
		fg12 = 1;
		sac++;
		work++;
		puts("�t�@�C�A���o�����I");
	}
	else if (stk3 == 12 && shozikin >= 40000 && fg13 == 0 && (st2 != 4 && st2 != 7 && st2 != 9 && st2 != 10 && st2 != 21 && st2 != 24 && st2 != 27 && st2 != 42 && st2 != 43 && st2 != 51)){	//	�u���U�[�h
		shozikin -= 40000;
		fg13 = 1;
		sac++;
		work++;
		puts("�u���U�[�h���o�����I");
	}
	else if (stk3 == 13 && shozikin >= 40000 && fg14 == 0 && (st2 != 2 && st2 != 7 && st2 != 8 && st2 != 9 && st2 != 10 && st2 != 18 && st2 != 21 && st2 != 37 && st2 != 42)){	//	�T���_�[
		shozikin -= 40000;
		fg14 = 1;
		sac++;
		work++;
		puts("�T���_�[���o�����I");
	}
	else if (stk3 == 14 && shozikin >= 40000 && fg15 == 0 && (st2 != 7 && st2 != 8 && st2 != 15 && st2 != 22 && st2 != 23 && st2 != 31 && st2 != 33 && st2 != 42 && st2 != 46)){	//	�E�B���h�X���b�V��
		shozikin -= 40000;
		fg15 = 1;
		sac++;
		work++;
		puts("�E�B���h�X���b�V�����o�����I");
	}
	else if (stk3 == 15 && shozikin >= 32000 && fg16 == 0 && (st2 != 2 && st2 != 5 && st2 != 6 && st2 != 7 && st2 != 8 && st2 != 10 && st2 != 21 && st2 != 27 && st2 != 40 && st2 != 43 && st2 != 49)){	//	�V�[���h
		shozikin -= 32000;
		fg16 = 1;
		sac++;
		work++;
		puts("�V�[���h���o�����I");
	}
	else if (stk3 == 16 && shozikin >= 37000 && fg17 == 0 && (st2 != 1 && st2 != 6 && st2 != 10 && st2 != 13 && st2 != 15 && st2 != 18 && st2 != 21 && st2 != 33 && st2 != 35 && st2 != 37 && st2 != 44 && st2 != 46 && st2 != 49)){	//	�V�[���h�_�E��
		shozikin -= 37000;
		fg17 = 1;
		sac++;
		work++;
		puts("�V�[���h�_�E�����o�����I");
	}
	else if (stk3 == 17 && shozikin >= 32000 && fg18 == 0 && (st2 != 5 && st2 != 8 && st2 != 18 && st2 != 29 && st2 != 31 && st2 != 39 && st2 != 42 && st2 != 43 && st2 != 45 && st2 != 49)){	//	�X�s�[�h�A�b�v
		shozikin -= 32000;
		fg18 = 1;
		sac++;
		work++;
		puts("�X�s�[�h�A�b�v���o�����I");
	}
	else if (stk3 == 18 && shozikin >= 37000 && fg19 == 0 && (st2 != 5 && st2 != 13 && st2 != 14 && st2 != 21 && st2 != 22 && st2 != 27 && st2 != 34 && st2 != 37 && st2 != 49 && st2 != 51)){	//	�X�s�[�h�_�E��
		shozikin -= 37000;
		fg19 = 1;
		sac++;
		work++;
		puts("�X�s�[�h�_�E�����o�����I");
	}
	else{
		if (fg1 == 1 || fg2 == 1 || fg3 == 1 || fg4 == 1 || fg5 == 1 || fg6 == 1 || fg7 == 1 || fg8 == 1 || fg9 == 1 || fg10 == 1 || fg11 == 1 || fg12 == 1 || fg13 == 1 || fg14 == 1 || fg15 == 1 || fg16 == 1 || fg17 == 1 || fg18 == 1 || fg19 == 1){
			puts("���łɊo���Ă��܂��B");
		}
		else{
			puts("����������܂���B");
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
	int loop, loop2 = 1;	//	�J��Ԃ��p�ϐ�(�ŏ��̃��[�v�A�o�g�����[�h�̃��[�v)
	int sentaku3 = 0, sentaku4 = 0, sentaku5 = 0;	// �o�g�����[�h�Ŏg�p�A�g�[�i�����g���[�h�œX�ɍs�����ǂ����I���ATM�œX��I��
	int turn = 0, Kcount = -1;	//	�^�[�����v�Z�A�s��������(�O�Ȃ�Player����U�ŁA�P�Ȃ�CPU����U)
	int flag = 0, flag2 = 0;	//	Player����U�̏ꍇ�̃t���O�ACPU����U�̏ꍇ�̃t���O�Q
	int flag3 = 0, flag4 = 0, flag5 = 0;				//	�����������t���O�A�o�g���t���O(P�AC)
	char ch2[5];
	//	�g�[�i�����g���[�h�Ŏg���ϐ�
	int loop3 = 1, loop4 = 1, loop5 = 1;		//	�g�[�i�����g���[�h�̍ŏ��̌J��Ԃ��ATM�̃o�g���t�F�[�Y�̌J��Ԃ��p�ϐ��ATM�̔������t�F�[�Y�̃��[�v
	int win = 0, c = 0;							//	�����܂Ői�񂾂��̕ϐ��A�������J�E���g

	loop = 1;
	while (loop == 1){				//	�ŏ��̌J��Ԃ�
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

		printf("���C�����j���[\n1:�o�g�����[�h 2:�g�[�i�����g���[�h 3:���� 4:�����X�^�[�f�[�^ \n5:�X�R�A(�o�g��) 6:�X�R�A(�g�[�i�����g) 7:�I��\n");
		scanf_s("%d", &sentaku);

		int r13 = 0, r14 = 0, r15 = 0, r16 = 0, r17 = 0, r18 = 0, r19 = 0;	//	(CPU��p�֐�)CSAcommand�ŋZ��I������Ƃ��Ɏg�p(r10�`)
		int r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0;
		int r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0, r32 = 0, r33 = 0;
		int r34 = 0, r35 = 0, r36 = 0, r37 = 0, r38 = 0, r39 = 0, r40 = 0;
		int r41 = 0, r42 = 0, r43 = 0, r44 = 0, r45 = 0, r46 = 0, r47 = 0;
		int r48 = 0, r49 = 0, r50 = 0, r51 = 0, r52 = 0, r53 = 0, r54 = 0;
		int r55 = 0, r56 = 0, r57 = 0, r58 = 0, r59 = 0, r60 = 0, r61 = 0;
		int r62 = 0, r63 = 0, r64 = 0;
		int cflag = 0;

		if (sentaku == 1){								//	�o�g�����[�h�`
			do{
				puts("1=�j���[�Q�[��: 2=���[�h�Q�[��");
				scanf_s("%d", &sentaku3);

				if (sentaku3 == 1 || sentaku3 == 2){
					break;
				}
				else{
					puts("�P���Q����͂��Ă��������B");
				}
			} while (sentaku3 != 1 || sentaku3 != 2);

			PMST();				//	�v���C���[�����X�^�[����t�F�[�Y
			CMST();				//	CPU�����X�^�[����t�F�[�Y

			loop2 = 1;
			while (loop2 == 1){
				turn++;

				Kcount = Act(Kcount);

				//	�o�g���t�F�[�Y
				printf("----------------turn%d----------------\n", turn);

				//	--------Player����U�̏ꍇ�̏���----------
				if (Kcount == 0){
					PAC();
					Kcount++;
				}
				if (Kcount == 1 && HP2 >= 1){
					CAC();
					Kcount++;
				}

				//	----------CPU����U�̏ꍇ�̏���-------------
				if (Kcount == 5){
					CAC();
					Kcount++;
				}
				if (Kcount == 6 && HP >= 1){
					PAC();
				}

				puts("�K���ȃL�[����͂��Ă��������B");
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
					if (sentaku3 == 1){						//	�j���[�Q�[����I�������ꍇ�̏���
						error = fopen_s(&fp, "score.txt", "w");
					}
					else{									//	���[�h�Q�[����I�������ꍇ�̏���
						error = fopen_s(&fp, "score.txt", "a");
					}
					if (error == NULL){
						puts("File Open Error");
					}
					puts("�^�C���I�[�o�[�I�I");
					if (HP > HP2){					//	CPU����Player��HP�������ꍇ
						GameScore(name, HP, TP, atk, def, spd, name2, HP2, TP2, atk2, def2, spd2);
						puts("CPU�̕����B");
						fprintf(fp, "CPU�̕����B\n");
						fclose(fp);
						loop2 = 0;
						loop = GameEnd(loop);
					}
					else if (HP < HP2){				//	Player����CPU��HP�������ꍇ
						GameScore(name, HP, TP, atk, def, spd, name2, HP2, TP2, atk2, def2, spd2);
						puts("Player�̕����B");
						fprintf(fp, "Player�̕����B\n");
						fclose(fp);
						loop2 = 0;
						loop = GameEnd(loop);
					}
					else{
						puts("Player��CPU��HP�������Ȃ̂ň��������ł��B");
						GameScore(name, HP, TP, atk, def, spd, name2, HP2, TP2, atk2, def2, spd2);
						fprintf(fp, "���������B\n");
						fclose(fp);
						loop2 = 0;
						loop = GameEnd(loop);
					}
				}

				if (HP == 0 && flag4 == 1){				//	Player�̕����̏ꍇ
					if (sentaku3 == 1){						//	�j���[�Q�[����I�������ꍇ�̏���
						error = fopen_s(&fp, "score.txt", "w");
					}
					else{									//	���[�h�Q�[����I�������ꍇ�̏���
						error = fopen_s(&fp, "score.txt", "a");
					}
					if (error == NULL){
						puts("File Open Error");
					}
					puts("Player��HP��0�ɂȂ����̂ŁAPlayer�̕����ł��B");
					GameScore(name, HP, TP, atk, def, spd, name2, HP2, TP2, atk2, def2, spd2);
					puts("Player�̕����B");
					fprintf(fp, "Player�̕����B\n");

					fclose(fp);

					loop2 = 0;

					loop = GameEnd(loop);
					break;
				}

				if (HP2 == 0 && flag5 == 1){				//	CPU�������̏ꍇ
					if (sentaku3 == 1){						//	�j���[�Q�[����I�������ꍇ�̏���
						error = fopen_s(&fp, "score.txt", "w");
					}
					else{									//	���[�h�Q�[����I�������ꍇ�̏���
						error = fopen_s(&fp, "score.txt", "a");
					}
					if (error == NULL){
						puts("File Open Error");
					}
					puts("CPU��HP��0�ɂȂ����̂ŁACPU�̕����ł��B");
					GameScore(name, HP, TP, atk, def, spd, name2, HP2, TP2, atk2, def2, spd2);
					puts("CPU�̕����B");
					fprintf(fp, "CPU�̕����B\n");

					fclose(fp);

					loop2 = 0;

					loop = GameEnd(loop);
					break;
				}
			}
		}
		else if (sentaku == 2){			//	�g�[�i�����g���[�h
			win = 0;

			do{
				puts("1=�j���[�Q�[��: 2=���[�h�Q�[��");
				scanf_s("%d", &sentaku3);

				if (sentaku3 == 1 || sentaku3 == 2){
					break;
				}
				else{
					puts("�P���Q����͂��Ă��������B");
				}
			} while (sentaku3 != 1 || sentaku3 != 2);

			PMST();

			printf("������=%d\n", shozikin);

			puts("�V���b�v�𗘗p���܂����H(1=Yes: 2=No)");
			scanf_s("%d", &sentaku4);

			if (sentaku4 == 1){
				ShopEvent();		//	�ŏ��̔�����
			}

			loop3 = 1;
			while (loop3 == 1){
				turn = 0;
				win++;
				if (win == 1){		//	1���̑��胂���X�^�[����t�F�[�Y
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
				while (loop4 == 1){		//	�o�g���t�F�[�Y
					turn++;

					Kcount = Act(Kcount);

					printf("----------------turn%d----------------\n", turn);

					//	--------Player����U�̏ꍇ�̏���----------
					if (Kcount == 0){
						PAC();
						Kcount++;
					}
					if (Kcount == 1 && HP2 >= 1){
						CAC();
						Kcount++;
					}

					//	----------CPU����U�̏ꍇ�̏���-------------
					if (Kcount == 5){
						CAC();
						Kcount++;
					}
					if (Kcount == 6 && HP >= 1){
						PAC();
					}

					puts("�K���ȃL�[����͂��Ă��������B");
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

					if (HP == 0 && flag4 == 1){				//	Player�̕����̏ꍇ
						if (sentaku3 == 1){						//	�j���[�Q�[����I�������ꍇ�̏���
							error = fopen_s(&fp, "tournament.txt", "w");
						}
						else{									//	���[�h�Q�[����I�������ꍇ�̏���
							error = fopen_s(&fp, "tournament.txt", "a");
						}
						if (error == NULL){
							puts("File Open Error");
						}
						puts("Player��HP��0�ɂȂ����̂ŁAPlayer�̕����ł��B");
						GameScore(name, HP, TP, atk, def, spd, name2, HP2, TP2, atk2, def2, spd2);
						puts("Player�̕����B");
						if (win == 1){
							fprintf(fp, "1���s�ށB\n");
						}
						else if (win == 2){
							fprintf(fp, "2���s�ށB\n");
							MP[st2 - 1].HP -= 500;
							MP[st2 - 1].TP -= 5;
							MP[st2 - 1].atk -= 50;
							MP[st2 - 1].def -= 50;
							MP[st2 - 1].spd -= 50;
						}
						else if (win == 3){
							fprintf(fp, "3���s�ށB\n");
							MP[st2 - 1].HP -= 1000;
							MP[st2 - 1].TP -= 10;
							MP[st2 - 1].atk -= 100;
							MP[st2 - 1].def -= 100;
							MP[st2 - 1].spd -= 100;
						}
						else if (win == 4){
							fprintf(fp, "4���s�ށB\n");
							MP[st2 - 1].HP -= 1500;
							MP[st2 - 1].TP -= 15;
							MP[st2 - 1].atk -= 150;
							MP[st2 - 1].def -= 150;
							MP[st2 - 1].spd -= 150;
						}
						else if (win == 5){
							fprintf(fp, "5���s�ށB\n");
							MP[st2 - 1].HP -= 2000;
							MP[st2 - 1].TP -= 20;
							MP[st2 - 1].atk -= 200;
							MP[st2 - 1].def -= 200;
							MP[st2 - 1].spd -= 200;
						}

						//	HP�V�[�h�𔃂����ꍇ
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

						//	HP�V�[�h���𔃂����ꍇ
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

						//	HP�V�[�h�^�𔃂����ꍇ
						if (puc3 == 1){
							MP[st2 - 1].HP -= 2000;
						}
						else if (puc3 == 2){
							MP[st2 - 1].HP -= 3000;
						}

						//	TP�V�[�h�𔃂����ꍇ
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

						//	TP�V�[�h���𔃂����ꍇ
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

						//	TP�V�[�h�^�𔃂����ꍇ
						if (puc6 == 1){
							MP[st2 - 1].TP -= 40;
						}
						else if (puc6 == 2){
							MP[st2 - 1].TP -= 80;
						}

						//	atk�V�[�h�𔃂����ꍇ
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

						//	atk�V�[�h���𔃂����ꍇ
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

						//	atk�V�[�h�^�𔃂����ꍇ
						if (puc17 == 1){
							MP[st2 - 1].atk -= 200;
						}
						else if (puc17 == 2){
							MP[st2 - 1].atk -= 400;
						}

						//	def�V�[�h�𔃂����ꍇ
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

						//	def�V�[�h���𔃂����ꍇ
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

						//	def�V�[�h�^�𔃂����ꍇ
						if (puc9 == 1){
							MP[st2 - 1].def -= 200;
						}
						else if (puc9 == 2){
							MP[st2 - 1].def -= 400;
						}

						//	spd�V�[�h�𔃂����ꍇ
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

						//	spd�V�[�h���𔃂����ꍇ
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

						//	spd�V�[�h�^�𔃂����ꍇ
						if (puc12 == 1){
							MP[st2 - 1].spd -= 200;
						}
						else if (puc12 == 2){
							MP[st2 - 1].spd -= 400;
						}

						//	�f���b�N�X�V�[�h�𔃂����ꍇ
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

						//	�f���b�N�X�V�[�h�^�𔃂����ꍇ
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

					if (HP2 == 0 && flag5 == 1){			//	CPU�������̏ꍇ
						if (win == 1){					//	1��폟���̂Ƃ�
							printf("CPU��HP��0�ɂȂ����̂ő�Q���ɐi�o�ł��B\n");
							printf("��1���̏܋���3000G�ł��B\n");
							shozikin += 3000;

							MP[st2 - 1].HP += 500;
							MP[st2 - 1].TP += 5;
						}
						else if (win == 2){				//	2��폟���̂Ƃ�
							printf("CPU��HP��0�ɂȂ����̂ő�R���ɐi�o�ł��B\n");
							printf("��2���̏܋���8000G�ł��B\n");
							shozikin += 8000;
							MP[st2 - 1].HP += 500;
							MP[st2 - 1].TP += 5;
						}
						else if (win == 3){				//	3��폟���̂Ƃ�
							printf("CPU��HP��0�ɂȂ����̂ő�S���ɐi�o�ł��B\n");
							printf("��3���̏܋���14000G�ł��B\n");
							shozikin += 14000;
							MP[st2 - 1].HP += 500;
							MP[st2 - 1].TP += 5;
						}
						else if (win == 4){				//	4��폟���̂Ƃ�
							printf("CPU��HP��0�ɂȂ����̂ő�T���ɐi�o�ł��B\n");
							printf("��4���̏܋���18000G�ł��B\n");
							shozikin += 18000;
							MP[st2 - 1].HP += 500;
							MP[st2 - 1].TP += 5;
						}
						else if (win == 5){
							printf("CPU��HP��0�ɂȂ����̂Ō�����ɐi�o�ł��B\n");
							printf("��5���̏܋���25000G�ł��B\n");
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
						puts("HP��TP���񕜂��܂���!");

						//	���x���A�b�v�t�F�[�Y
						MP[st2 - 1].atk += 50;
						MP[st2 - 1].def += 50;
						MP[st2 - 1].spd += 50;
						atk = MP[st2 - 1].atk;
						def = MP[st2 - 1].def;
						spd = MP[st2 - 1].spd;

						printf("\nLevel UP! HP + 500  TP + 5  atk + 50 def + 50 spd + 50\n");
						printf("Name=%s: HP=%d: TP=%d: atk=%d: def=%d: spd=%d\n", name, HP, TP, atk, def, spd);

						printf("���݂̏�������%d�ł��B\n", shozikin);

						puts("�V���b�v�𗘗p���܂����H(1=Yes: 2=No)");
						scanf_s("%d", &sentaku4);

						if (sentaku4 == 1){		//	�������t�F�[�Y(1�񂾂��\)
							loop5 = 1;
							while (loop5 == 1){
								puts("1:�V���b�v�P(�񕜃A�C�e���̓X)");
								puts("2:�V���b�v�Q(�p���[�A�b�v�n�A�C�e���̓X)");
								puts("3:�u�b�N�X�g�A");
								printf("�ǂ̓X�ɍs���܂����H(������)--->");
								scanf_s("%d", &sentaku5);
								printf("\n\n\n");

								if (sentaku5 == 1){	//	�V���b�v�P
									ShopEvent2();
									loop5 = 0;
								}
								else if (sentaku5 == 2){	//	�V���b�v�Q
									ShopEvent3();
									loop5 = 0;
								}
								else if (sentaku5 == 3){	//	�u�b�N�X�g�A
									BookStore();
									loop5 = 0;
								}
								else{
									puts("�P�`�R�܂ł̐�������͂��Ă��������B");
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