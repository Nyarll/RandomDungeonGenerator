//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  ゲーム関連のソースファイル
//!
//! @date   日付
//!
//! @author 制作者名
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma warning (disable:4244)

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "Dungeons.h"
#include <direct.h>
#include <string>


// 定数の定義 ==============================================================




// 構造体の定義 ============================================================




// グローバル変数の定義 ====================================================
DungeonMap dungeon;
MapData map[MAPX_RLk][MAPY_RLk];

int time;

FILE* fp;




// プロトタイプ宣言 ========================================================

void InitializeGame(void);  // ゲームの初期化処理
void UpdateGame(void);      // ゲームの更新処理
void RenderGame(void);      // ゲームの描画処理
void FinalizeGame(void);    // ゲームの終了処理

static bool CheckExistenceOfFolder(const std::string folder_name);	// その名前のフォルダが存在するかどうか / 存在したならFALSEを返す


// 関数の定義 ==============================================================

// ゲームの初期化処理
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

// ゲームの更新処理
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
		if (CheckExistenceOfFolder("DungeonMap"))	// DungeonMap というフォルダがあるか確認
		{
			_mkdir("DungeonMap");	// 無ければ作る
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

// ゲームの描画処理
void RenderGame(void)
{
	static bool flag = false;

	DrawBox(0, 0, SCREEN_RIGHT, SCREEN_BOTTOM, COLOR_WHITE, TRUE);
	for (int i = 0; i < MAPX_RLk; i++) {
		for (int j = 0; j < MAPY_RLk; j++) {
			if (!map[i][j].mapData) DrawBox(i * 8, j * 8, (i + 1) * 8, (j + 1) * 8, COLOR_RED, TRUE);
		}
	}

	DrawFormatString(SCREEN_LEFT, SCREEN_TOP, COLOR_RED, "作り直す -> [F1] key  終了 -> [ESC] key");
	ScreenFlip();          // 裏画面の内容を表画面に反映
	ClearDrawScreen();     // 裏画面の消去

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

// ゲームの終了処理
void FinalizeGame(void)
{

}


// 以下オリジナル関数 --------------------------------------------------
