//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  �Q�[���֘A�̃\�[�X�t�@�C��
//!
//! @date   ���t
//!
//! @author ����Җ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma warning (disable:4244)

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "Dungeons.h"
#include <direct.h>
#include <string>


// �萔�̒�` ==============================================================




// �\���̂̒�` ============================================================




// �O���[�o���ϐ��̒�` ====================================================
DungeonMap dungeon;
MapData map[MAPX_RLk][MAPY_RLk];

int time;

FILE* fp;




// �v���g�^�C�v�錾 ========================================================

void InitializeGame(void);  // �Q�[���̏���������
void UpdateGame(void);      // �Q�[���̍X�V����
void RenderGame(void);      // �Q�[���̕`�揈��
void FinalizeGame(void);    // �Q�[���̏I������

static bool CheckExistenceOfFolder(const std::string folder_name);	// ���̖��O�̃t�H���_�����݂��邩�ǂ��� / ���݂����Ȃ�FALSE��Ԃ�


// �֐��̒�` ==============================================================

// �Q�[���̏���������
void InitializeGame(void)
{
	time = 30;
}

static bool CheckExistenceOfFolder(const std::string folder_name)
{
	if (_mkdir(folder_name.c_str()) == 0) {
		return true;
	}
	else {
		return false;
	}
}

// �Q�[���̍X�V����
void UpdateGame(void)
{
	/**
	if (time == 60)
	{
		if (CreateDungeon(&dungeon, map))ExitGame();
		time = 0;


	}
	time++;
	/**/
	if (0 == CreateDungeon(&dungeon, map))
	{
		if (CheckExistenceOfFolder("DungeonMap"))	// DungeonMap �Ƃ����t�H���_�����邩�m�F
		{
			_mkdir("DungeonMap");	// ������΍��
		}
		fopen_s(&fp, "DungeonMap/DungeonMapData.dat", "w");

		fprintf_s(fp, "# 1 -> Wall, 0 -> Walkable floor \n");

		for (int i = 0; i < MAPX_RLk; i++)
		{
			for (int j = 0; j < MAPY_RLk; j++)
			{
				fprintf_s(fp, "%d,", map[i][j].mapData);
			}
			fprintf_s(fp, "\n");
		}
		fclose(fp);
	}
}

// �Q�[���̕`�揈��
void RenderGame(void)
{
	static bool flag = false;

	DrawBox(0, 0, SCREEN_RIGHT, SCREEN_BOTTOM, COLOR_WHITE, TRUE);
	for (int i = 0; i < MAPX_RLk; i++) {
		for (int j = 0; j < MAPY_RLk; j++) {
			if (!map[i][j].mapData) DrawBox(i * 8, j * 8, (i + 1) * 8, (j + 1) * 8, COLOR_RED, TRUE);
		}
	}

	DrawFormatString(SCREEN_LEFT, SCREEN_TOP, COLOR_RED, "��蒼�� -> [F1] key  �I�� -> [ESC] key");
	ScreenFlip();          // ����ʂ̓��e��\��ʂɔ��f
	ClearDrawScreen();     // ����ʂ̏���

	back:
	switch (WaitKey())
	{
	case KEY_INPUT_ESCAPE:
		ExitGame();
		break;

	case KEY_INPUT_F1:
		break;

	default:
		goto back;
		break;
	}
}

// �Q�[���̏I������
void FinalizeGame(void)
{

}


// �ȉ��I���W�i���֐� --------------------------------------------------
