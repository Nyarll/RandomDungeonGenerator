#pragma once

/*�}�b�v�n�f�[�^*/
#define MAPX_RLk (64) //�}�b�v�c�T�C�Y
#define MAPY_RLk (32)   //�}�b�v���T�C�Y
#define RL_COUNT_X (0)
#define RL_COUNT_Y (1)

typedef struct DungeonMap_s
{

	//��������镔���̐� (���m�Ɍ����Ɛ����������̐�)
	unsigned char divCountMin = 3; //�}�b�v�̋敪���ŏ���
	unsigned char divCountRand = 4; //�}�b�v�̋敪�������Z

									//��������镔���̃T�C�Y
	unsigned char roomLengthMinX = 5; //������X���W�̍ŏ��T�C�Y
	unsigned char roomLengthMinY = 5; //������Y���W�̍ŏ��T�C�Y
	unsigned char roomLengthRandX = 2; //������X���W�̃T�C�Y���Z
	unsigned char roomLengthRandY = 2; //������Y���W�̃T�C�Y���Z

	unsigned char mapDivCount; //�}�b�v�̋敪���� (�����̌�) 0~n�܂ł̕���ID
	unsigned char mapDiv[8][4] = { 0 }; //�}�b�v�̋�� [����ID][X�I�_ , Y�I�_ , X�n�_ , Y�n�_]
	unsigned char mapRoom[8][4] = { 0 }; //�}�b�v�̕��� [����ID][X�I�_ , Y�I�_ , X�n�_ , Y�n�_]
	unsigned char mapRoad[8][4] = { 0 }; //�}�b�v�̓� [����ID(�O)][�q�����̕���ID(��) , (0.X���W , 1.Y���W) , (�O)���̒ʘH�̈ʒu , (��)���̒ʘH�̈ʒu]
	unsigned char mapRoomPlayer[8] = { 0 };

}DungeonMap;

typedef struct MapData_s
{
	unsigned short mapData = 1; //�}�b�v
}MapData;

int CreateDungeon(DungeonMap* dng, MapData map[][MAPY_RLk]);