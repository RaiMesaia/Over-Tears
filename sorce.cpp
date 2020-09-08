#include "DxLib.h"

#pragma warning(disable : 4996)

#define GAME_WIDTH	800
#define GAME_HEIGHT	600
#define GAME_COLOR	32

#define GAME_WINDOW_NAME	"Over Tears"
#define GAME_WINDOW_MODECHANGE	TRUE

#define SET_WINDOW_ST_MODE_DEFAULT			0
#define SET_WINDOW_ST_MODE_TITLE_NONE		1
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE	2
#define SET_WINDOW_ST_MODE_FLAME_NONE		3

#define GAME_FPS_SPEED					   60

#define GAME_MAP_YOKO_SIZE		32
#define GAME_MAP_TATE_SIZE		32

#define GAME_MAP_BUN_YOKO_CNT	32
#define GAME_MAP_BUN_TATE_CNT	41

#define GAME_MAP_YOKO			40
#define GAME_MAP_TATE			40
#define GAME_MAP_OK_KIND		100
#define GAME_MAP_NG_KIND		100
#define GAME_MAP_BT_KIND		5

#define GAME_MAP_1_PATH			"MAP\\mapchip1.png"

#define GAME_MAP_CSV_1_SITA		"MAP\\mapchip1_map_sita.csv"
#define GAME_MAP_CSV_1_NAKA		"MAP\\mapchip1_map_naka.csv"
#define GAME_MAP_CSV_1_UE		"MAP\\mapchip1_map_ue.csv"

#define GAME_MAP_NAME_1_UE		"MAPDATA_1_UE"
#define GAME_MAP_NAME_1_NAKA	"MAPDATA_1_NAKA"
#define GAME_MAP_NAME_1_SITA	"MAPDATA_1_SITA"

#define GAME_CHARA				"CHARAIMAGE\\sisiza3.png"

#define GAME_CHARA				"CHARAIMAGE\\sisiza3.png"
#define GAME_CHARA_BUN_YOKO_CNT	12
#define GAME_CHARA_BUN_TATE_CNT	8
#define GAME_CHARA_YOKO_SIZE	24
#define GAME_CHARA_TATE_SIZE	32
#define GAME_CHARA_MOTION_NUM	12
#define GAME_CHARA_KIND_YOKO	3
#define GAME_CHARA_KIND_TATE	4

#define GAME_CHARA_STARTX		5
#define GAME_CHARA_STARTY		10
#define GAME_CHARA_SPEED		2

#define GAME_PLAYER_LV_FIRST	1
#define GAME_PLAYER_HP_FIRST	10
#define GAME_PLAYER_ATK_FIRST	4
#define GAME_PLAYER_DEF_FIRST	6

#define GAME_PLAYER_NAME		"獅子座の勇者"

#define GAME_TITLE_IMAGE		"BACKIMAGE\\title.png"

enum GAME_SCENE {
	GAME_SCENE_TITLE,
	GAME_SCENE_PLAY,
	GAME_SCENE_BATTLE,
	GAME_SCENE_END
};

enum CHARA_IMAGE {
	CHARA_KIND_1 = 0,
	CHARA_KIND_2 = 3,
	CHARA_KIND_3 = 6,
	CHARA_KIND_4 = 9,
	CHARA_KIND_5 = 48,
	CHARA_KIND_6 = 51,
	CHARA_KIND_7 = 54,
	CHARA_KIND_8 = 57,
	CHARA_KIND_END = 95
};

struct STRUCT_IMAGE
{
	char FilePath[128];
	int Handle[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];
	int X[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];
	int Y[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];
	int Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];
	int Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];
	int C_Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];
	int C_Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];

};

struct STRUCT_MAPDATA
{
	char name[64];
	int data[GAME_MAP_TATE][GAME_MAP_YOKO];
	int mapdata_Init[GAME_MAP_TATE][GAME_MAP_YOKO];

	int Handle[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];
	int X[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];
	int Y[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];
	int Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];
	int Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];
	int C_Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];
	int C_Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];

	int mapNGKind[GAME_MAP_NG_KIND];
	int mapOKKind[GAME_MAP_OK_KIND];
	int mapBTKind[GAME_MAP_BT_KIND];

	RECT rect_NG[GAME_MAP_TATE][GAME_MAP_YOKO];
	RECT rect_NG_First[GAME_MAP_TATE][GAME_MAP_YOKO];

	RECT rect_OK[GAME_MAP_TATE][GAME_MAP_YOKO];
	RECT rect_OK_First[GAME_MAP_TATE][GAME_MAP_YOKO];

	RECT rect_BT[GAME_MAP_TATE][GAME_MAP_YOKO];
	RECT rect_BT_First[GAME_MAP_TATE][GAME_MAP_YOKO];

};

struct STRUCT_CHARAIMAGE
{
	char FilePath[128];
	int Handle[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];
	int X[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];
	int Y[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];
	int Width[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];
	int Height[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];
	int C_Width[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];
	int C_Height[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];
};

struct STRUCT_CHARADATA
{
	STRUCT_CHARAIMAGE charaimage;
	int Handle[GAME_CHARA_MOTION_NUM];
	int X;
	int Y;
	int Width;
	int Height;
	int C_Width;
	int C_Height;
	int NowHandleNum;
	int NowHandleCnt;
	int NowHandleCntMAX;

	int Speed;
	int MoveDistX;
	int MoveDistY;

	BOOL CanMoveUp;
	BOOL CanMoveDown;
	BOOL CanMoveLeft;
	BOOL CanMoveRight;

	BOOL ScrollOK_X;
	BOOL ScrollOK_Y;

	int atariX;
	int atariY;
	int atariWidth;
	int atariHeight;
	RECT atariRect;

	char name[255];
	
	RECT rect_st;

};

typedef STRUCT_IMAGE IMAGE;
typedef STRUCT_MAPDATA MAPDATA;
typedef STRUCT_CHARAIMAGE CHARAIMAGE;
typedef STRUCT_CHARADATA CHARADATA;

BOOL IsWM_CREATE = FALSE;

int StartTimeFps;
int CountFps;
float CalcFps;
int SampleNumFps = GAME_FPS_SPEED;

char AllKeyState[256];

int GameSceneNow = (int)GAME_SCENE_TITLE;

IMAGE Image_map;
MAPDATA mapData_sita;
MAPDATA mapData_naka;
MAPDATA mapData_ue;

IMAGE image_grass;
IMAGE image_river;
IMAGE image_maou;
IMAGE image_boss;

IMAGE image_title;
IMAGE image_clear;

int ScrollCntYoko = 0;
int ScrollCntTate = 0;

CHARAIMAGE CharaImage;
CHARADATA	Myplayer;

int PlayerImageNum[GAME_CHARA_MOTION_NUM];

int FontDefault;
int FontBig;
int FontFutsu;

VOID MY_FPS_UPDATE(VOID);
VOID MY_FPS_DRAW(VOID);
VOID MY_FPS_WAIT(VOID);

VOID MY_ALL_KEYDOWN_UPDATE(VOID);

VOID MY_GAME_TITLE(VOID);
VOID MY_GAME_TITLE_DRAW(VOID);
VOID MY_GAME_PLAY(VOID);
VOID MY_GAME_PLAY_DRAW(VOID);

BOOL MY_PLAY_INIT(VOID);

BOOL MY_MAP_READ_CSV_UE_KIND_SET(MAPDATA*);
BOOL MY_MAP_READ_CSV_NAKA_KIND_SET(MAPDATA*);
BOOL MY_MAP_READ_CSV_SITA_KIND_SET(MAPDATA*);
BOOL MY_MAP_READ_CSV_NUM(MAPDATA*, const char*, const char*);

int MY_LOAD_BACKGROUND(IMAGE*, const char*);

BOOL MY_MAP_LOAD_BUNKATSU(MAPDATA*, int, int, int, int, int, const char*);

VOID MY_PLAY_MAP_DRAW(MAPDATA);
VOID MY_PLAY_MAP_DRAW_ATARI(MAPDATA*, MAPDATA*, MAPDATA*);

BOOL MY_CHARA_LOAD_BUNKATSU(CHARAIMAGE*, int, int, int, int, int, const char*);

BOOL MY_PLAYER_INIT(CHARADATA*, CHARAIMAGE, int*, int, int, int);
//
VOID MY_PLAY_PLAYER_DRAW(CHARADATA);

VOID MY_SET_PLAYER_ATARI(CHARADATA*);

BOOL MY_CHECK_RECT_ATARI(RECT, RECT);
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT, RECT map[GAME_MAP_TATE][GAME_MAP_YOKO], int*, int*);

BOOL MY_GAME_NOWLOADING(VOID);
BOOL MY_GAME_IN_MUGENLOOP(VOID);
VOID MY_GAME_DELETE(VOID);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int IsLoad = FALSE;

	ChangeWindowMode(GAME_WINDOW_MODECHANGE);
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));

	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	MY_MAP_READ_CSV_UE_KIND_SET(&mapData_ue);
	MY_MAP_READ_CSV_NAKA_KIND_SET(&mapData_naka);
	MY_MAP_READ_CSV_SITA_KIND_SET(&mapData_sita);

	MY_MAP_READ_CSV_NUM(&mapData_ue, GAME_MAP_CSV_1_UE, GAME_MAP_NAME_1_UE);
	MY_MAP_READ_CSV_NUM(&mapData_naka, GAME_MAP_CSV_1_NAKA, GAME_MAP_NAME_1_NAKA);
	MY_MAP_READ_CSV_NUM(&mapData_sita, GAME_MAP_CSV_1_SITA, GAME_MAP_NAME_1_SITA);

	if (MY_MAP_LOAD_BUNKATSU(&mapData_ue, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }
	if (MY_MAP_LOAD_BUNKATSU(&mapData_naka, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }
	if (MY_MAP_LOAD_BUNKATSU(&mapData_sita, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }

	if (MY_CHARA_LOAD_BUNKATSU(&CharaImage, GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_BUN_YOKO_CNT, GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_YOKO_SIZE, GAME_CHARA_TATE_SIZE, GAME_CHARA) == FALSE) { MessageBox(NULL, GAME_CHARA, "NotFound", MB_OK); return -1; }

	IsLoad = MY_GAME_NOWLOADING();

	if (IsLoad == FALSE) { return -1; }

	int IsInLoop = FALSE;

	while (TRUE)
	{
		IsInLoop = MY_GAME_IN_MUGENLOOP();

		if (IsInLoop == FALSE) { break; }
	}

	MY_GAME_DELETE();

	DxLib_End();

	return 0;
}

BOOL MY_GAME_NOWLOADING(VOID)
{
	if (MY_LOAD_BACKGROUND(&image_title, GAME_TITLE_IMAGE) == FALSE) { MessageBox(NULL, GAME_TITLE_IMAGE, "NotFound", MB_OK); return FALSE; }
}

VOID MY_GAME_DELETE(VOID)
{
	for (int mapCnt = 0; mapCnt < GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT; mapCnt++)
	{
		DeleteGraph(mapData_ue.Handle[mapCnt]);
		DeleteGraph(mapData_sita.Handle[mapCnt]);
	}

	DeleteGraph(image_title.Handle[0]);
	DeleteGraph(image_clear.Handle[0]);
	DeleteGraph(image_grass.Handle[0]);
	DeleteGraph(image_river.Handle[0]);
	DeleteGraph(image_maou.Handle[0]);
	DeleteGraph(image_boss.Handle[0]);

	DeleteFontToHandle(FontDefault);
	DeleteFontToHandle(FontBig);
	DeleteFontToHandle(FontFutsu);

	return;
}

BOOL MY_GAME_IN_MUGENLOOP(VOID)
{
	if (ProcessMessage() != 0) { return FALSE; }

	if (ClearDrawScreen() != 0) { return FALSE; }

	MY_ALL_KEYDOWN_UPDATE();

	switch (GameSceneNow)
	{
	case (int)GAME_SCENE_TITLE:

		MY_GAME_TITLE();

		break;

	case (int)GAME_SCENE_PLAY:

		MY_GAME_PLAY();

		break;

	default:

		break;

	}

	MY_FPS_UPDATE();

	MY_FPS_DRAW();

	ScreenFlip();

	MY_FPS_WAIT();

	return TRUE;
}

VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0)
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps)
	{
		int now = GetNowCount();
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

VOID MY_FPS_DRAW(VOID)
{
	DrawFormatStringToHandle(0, GAME_HEIGHT - 20, GetColor(255, 255, 255), FontDefault, "FPS:%.1f", CalcFps);
	return;
}

VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;
	int waitTime = CountFps * 1000 / GAME_FPS_SPEED - resultTime;

	if (waitTime > 0)
	{
		Sleep(waitTime);
	}
	return;
}

VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];

	GetHitKeyStateAll(TempKey);

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)
		{
			AllKeyState[i]++;
		}
		else
		{
			AllKeyState[i] = 0;
		}
	}
	return;
}

VOID MY_GAME_TITLE(VOID)
{
	if (AllKeyState[KEY_INPUT_RETURN] != 0)
	{
		if (MY_PLAY_INIT() == TRUE)
		{
			GameSceneNow = (int)GAME_SCENE_PLAY;
		}
	}

	MY_GAME_TITLE_DRAW();

	return;
}

VOID MY_GAME_TITLE_DRAW(VOID)
{
	DrawGraph(0, 0, image_title.Handle[0], TRUE);

	char title[64] = { "Over Tears" };

	int height = GetFontSizeToHandle(FontBig);
	int Width = GetDrawStringWidthToHandle(title, strlen(title), FontBig);

	DrawStringToHandle(GAME_WIDTH / 2 - Width / 2 + 4, GAME_HEIGHT / 2 - height / 2 + 4, title, GetColor(0, 0, 0), FontBig);
	DrawStringToHandle(GAME_WIDTH / 2 - Width / 2, GAME_HEIGHT / 2 - height / 2, title, GetColor(30, 144, 255), FontBig);


	char enter[64] = { "PUSH ENTER KEY->START" };

	int height2 = GetFontSizeToHandle(FontFutsu);
	int Width2 = GetDrawStringWidthToHandle(enter, strlen(enter), FontFutsu);

	DrawStringToHandle(GAME_WIDTH / 2 - Width2 / 2 + 4, GAME_HEIGHT / 2 - height2 / 2 + height + 4, enter, GetColor(0, 0, 0), FontFutsu);
	DrawStringToHandle(GAME_WIDTH / 2 - Width2 / 2, GAME_HEIGHT / 2 - height2 / 2 + height, enter, GetColor(255, 255, 255), FontFutsu);

	DrawStringToHandle(0, 0, "タイトル画面", GetColor(255, 255, 255), FontDefault);

	return;
}

BOOL MY_PLAY_INIT(VOID)
{
	ScrollCntYoko = 0;
	ScrollCntTate = 0;

	int StartNum = (int)CHARA_KIND_7;
	int soeji = 0;
	PlayerImageNum[soeji++] = StartNum + 0;
	PlayerImageNum[soeji++] = StartNum + 1;
	PlayerImageNum[soeji++] = StartNum + 2;
	PlayerImageNum[soeji++] = StartNum + 12;
	PlayerImageNum[soeji++] = StartNum + 13;
	PlayerImageNum[soeji++] = StartNum + 14;
	PlayerImageNum[soeji++] = StartNum + 24;
	PlayerImageNum[soeji++] = StartNum + 25;
	PlayerImageNum[soeji++] = StartNum + 26;
	PlayerImageNum[soeji++] = StartNum + 36;
	PlayerImageNum[soeji++] = StartNum + 37;
	PlayerImageNum[soeji++] = StartNum + 38;

	if (MY_PLAYER_INIT(&Myplayer, CharaImage, &PlayerImageNum[0], GAME_MAP_YOKO_SIZE * GAME_CHARA_STARTX, GAME_MAP_TATE_SIZE * GAME_CHARA_STARTY, GAME_CHARA_SPEED) == FALSE) { MessageBox(NULL, "CHARA_INIT", "NotFound", MB_OK); return FALSE; }

	return TRUE;
}

VOID MY_GAME_PLAY(VOID)
{
	DrawStringToHandle(0, 0, "プレイ画面(スペースキーを押してください)", GetColor(255, 255, 255), FontDefault);

	MY_GAME_PLAY_DRAW();

	return;
}

VOID MY_GAME_PLAY_DRAW(VOID)
{
	MY_PLAY_MAP_DRAW(mapData_sita);

	MY_PLAY_MAP_DRAW(mapData_naka);

	MY_PLAY_PLAYER_DRAW(Myplayer);

	MY_PLAY_MAP_DRAW(mapData_ue);

	MY_PLAY_MAP_DRAW_ATARI(&mapData_ue, &mapData_naka, &mapData_sita);

	DrawStringToHandle(0, 0, "プレイ画面", GetColor(255, 255, 255), FontDefault);

	return;
}

BOOL MY_PLAYER_INIT(CHARADATA* charadata, CHARAIMAGE charaimage, int* num, int x, int y, int speed)
{

	for (int mot = 0; mot < GAME_CHARA_MOTION_NUM; mot++)
	{
		charadata->Handle[mot] = charaimage.Handle[*(num + mot)];
	}

	charadata->X = x;
	charadata->Y = y;
	charadata->Width = charaimage.Width[*(num + 0)];
	charadata->Height = charaimage.Height[*(num + 0)];
	charadata->C_Width = charaimage.C_Width[*(num + 0)];
	charadata->C_Height = charaimage.C_Height[*(num + 0)];

	charadata->Width = GAME_MAP_YOKO_SIZE;
	charadata->Height = GAME_MAP_TATE_SIZE;
	charadata->C_Width = GAME_MAP_YOKO_SIZE / 2;
	charadata->C_Height = GAME_MAP_TATE_SIZE / 2;

	charadata->NowHandleNum = 6;
	charadata->NowHandleCnt = 0;

	charadata->NowHandleCntMAX = 6;

	charadata->Speed = speed;

	charadata->MoveDistX = x;
	charadata->MoveDistY = y;

	charadata->CanMoveUp = TRUE;
	charadata->CanMoveDown = TRUE;
	charadata->CanMoveLeft = TRUE;
	charadata->CanMoveRight = TRUE;

	charadata->ScrollOK_X = FALSE;
	charadata->ScrollOK_Y = FALSE;

	charadata->atariX = 4;
	charadata->atariY = 10;
	charadata->atariWidth = 18;
	charadata->atariHeight = 24;

	wsprintf(charadata->name, GAME_PLAYER_NAME);

	MY_SET_PLAYER_ATARI(charadata);

	return TRUE;
}

int MY_RANGE_RAND(int min, int max)
{
	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT chara, RECT map[GAME_MAP_TATE][GAME_MAP_YOKO], int* atariX, int* atariY)
{
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if (MY_CHECK_RECT_ATARI(chara, map[tate][yoko]) == TRUE)
			{
				*atariY = tate;
				*atariX = yoko;

				return TRUE;
			}
		}
	}

	return FALSE;
}

BOOL MY_CHECK_RECT_ATARI(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;
	}

	return FALSE;
}

VOID MY_SET_PLAYER_ATARI(CHARADATA* charadata)
{
	charadata->atariRect.left = charadata->X + charadata->atariX + 2;
	charadata->atariRect.top = charadata->Y + charadata->atariY + 2;
	charadata->atariRect.right = charadata->X + charadata->atariX + charadata->atariWidth - 2;
	charadata->atariRect.bottom = charadata->Y + charadata->atariY + charadata->atariHeight - 2;

	return;
}

VOID MY_PLAY_PLAYER_DRAW(CHARADATA player)
{
	DrawGraph(
		player.X,
		player.Y,
		player.Handle[player.NowHandleNum], TRUE);

	if (AllKeyState[KEY_INPUT_LEFT] != 0)
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 9 && Myplayer.NowHandleNum < 11)
			{
				Myplayer.NowHandleNum++;
			}
			else
			{
				Myplayer.NowHandleNum = 9;
			}
		}

		//IsKeyDown = TRUE;

		Myplayer.CanMoveLeft = TRUE;

		MY_SET_PLAYER_ATARI(&Myplayer);
		Myplayer.atariRect.left -= 4;
		Myplayer.atariRect.right -= 4;

		/*if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)
		{
			Myplayer.CanMoveLeft = FALSE;
		}*/

		if (Myplayer.CanMoveLeft == TRUE)
		{
			if (Myplayer.ScrollOK_X == FALSE)
			{
				if (Myplayer.X > 0)
				{
					Myplayer.X -= Myplayer.Speed;
				}
			}
			else
			{
				if (ScrollCntYoko > 0)
				{
					ScrollCntYoko -= Myplayer.Speed;
				}
			}

			if (Myplayer.MoveDistX > 0)
			{
				Myplayer.MoveDistX -= Myplayer.Speed;
			}
		}
	}
	else if (AllKeyState[KEY_INPUT_RIGHT] != 0)
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 3 && Myplayer.NowHandleNum < 5)
			{
				Myplayer.NowHandleNum++;
			}
			else
			{
				Myplayer.NowHandleNum = 3;
			}
		}

		//IsKeyDown = TRUE;

		Myplayer.CanMoveRight = TRUE;

		MY_SET_PLAYER_ATARI(&Myplayer);
		Myplayer.atariRect.left += 4;
		Myplayer.atariRect.right += 4;

		/*if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)
		{
			Myplayer.CanMoveRight = FALSE;
		}*/

		if (Myplayer.CanMoveRight == TRUE)
		{
			if (Myplayer.ScrollOK_X == FALSE)
			{
				if (Myplayer.X + Myplayer.Width < GAME_WIDTH)
				{
					Myplayer.X += Myplayer.Speed;
				}
			}
			else
			{
				if (ScrollCntYoko < GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)
				{
					ScrollCntYoko += Myplayer.Speed;
				}
			}

			if (Myplayer.MoveDistX < GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)
			{
				Myplayer.MoveDistX += Myplayer.Speed;
			}
		}
	}
	else if (AllKeyState[KEY_INPUT_UP] != 0)
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 0 && Myplayer.NowHandleNum < 2)
			{
				Myplayer.NowHandleNum++;
			}
			else
			{
				Myplayer.NowHandleNum = 0;
			}
		}

		//IsKeyDown = TRUE;

		Myplayer.CanMoveUp = TRUE;

		MY_SET_PLAYER_ATARI(&Myplayer);
		Myplayer.atariRect.top -= 4;
		Myplayer.atariRect.bottom -= 4;

		/*if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)
		{
			Myplayer.CanMoveUp = FALSE;
		}*/

		if (Myplayer.CanMoveUp == TRUE)
		{
			if (Myplayer.ScrollOK_Y == FALSE)
			{
				if (Myplayer.Y > 0)
				{
					Myplayer.Y -= Myplayer.Speed;
				}
			}
			else
			{
				if (ScrollCntTate > 0)
				{
					ScrollCntTate -= Myplayer.Speed;
				}
			}

			if (Myplayer.MoveDistY > 0)
			{
				Myplayer.MoveDistY -= Myplayer.Speed;
			}
		}
	}
	else if (AllKeyState[KEY_INPUT_DOWN] != 0)
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 6 && Myplayer.NowHandleNum < 8)
			{
				Myplayer.NowHandleNum++;
			}
			else
			{
				Myplayer.NowHandleNum = 6;
			}
		}

		//IsKeyDown = TRUE;

		Myplayer.CanMoveDown = TRUE;

		MY_SET_PLAYER_ATARI(&Myplayer);
		Myplayer.atariRect.top += 4;
		Myplayer.atariRect.bottom += 4;

		/*if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)
		{
			Myplayer.CanMoveDown = FALSE;
		}*/

		if (Myplayer.CanMoveDown == TRUE)
		{
			if (Myplayer.ScrollOK_Y == FALSE)
			{
				if (Myplayer.Y + Myplayer.Width < GAME_HEIGHT)
				{
					Myplayer.Y += Myplayer.Speed;
				}
			}
			else
			{
				if (ScrollCntTate < GAME_MAP_TATE_SIZE * GAME_MAP_TATE)
				{
					ScrollCntTate += Myplayer.Speed;
				}
			}

			if (Myplayer.MoveDistY < GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 1))
			{
				Myplayer.MoveDistY += Myplayer.Speed;
			}
		}

		if (Myplayer.MoveDistX > 0 &&
			Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * 10)
		{
			Myplayer.ScrollOK_X = FALSE;
		}

		if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE * 10 &&
			Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * (GAME_MAP_YOKO - 15))
		{
			Myplayer.ScrollOK_X = TRUE;
		}

		if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE * (GAME_MAP_YOKO - 15) &&
			Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)
		{
			Myplayer.ScrollOK_X = FALSE;
		}

		if (Myplayer.MoveDistY > 0 &&
			Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * 10)
		{
			Myplayer.ScrollOK_Y = FALSE;
		}

		if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE * 10 &&
			Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 9))
		{
			Myplayer.ScrollOK_Y = TRUE;
		}

		if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 9) &&
			Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * GAME_MAP_TATE)
		{
			Myplayer.ScrollOK_Y = FALSE;
		}
	}
	return;
}

VOID MY_PLAY_MAP_DRAW(MAPDATA mapdata)
{
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&
				(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
				(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
				)
			{
				DrawGraph(
					yoko * GAME_MAP_YOKO_SIZE - ScrollCntYoko,
					tate * GAME_MAP_TATE_SIZE - ScrollCntTate,
					mapdata.Handle[mapdata.data[tate][yoko]], TRUE);
			}

		}
	}

}

VOID MY_PLAY_MAP_DRAW_ATARI(MAPDATA* map_ue, MAPDATA* map_naka, MAPDATA* map_sita)
{
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&
				(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
				(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
				)

			map_naka->rect_OK[tate][yoko].left = map_naka->rect_OK_First[tate][yoko].left - ScrollCntYoko;
			map_naka->rect_OK[tate][yoko].right = map_naka->rect_OK_First[tate][yoko].right - ScrollCntYoko;
			map_naka->rect_OK[tate][yoko].top = map_naka->rect_OK_First[tate][yoko].top - ScrollCntTate;
			map_naka->rect_OK[tate][yoko].bottom = map_naka->rect_OK_First[tate][yoko].bottom - ScrollCntTate;

			map_naka->rect_NG[tate][yoko].left = map_naka->rect_NG_First[tate][yoko].left - ScrollCntYoko;
			map_naka->rect_NG[tate][yoko].right = map_naka->rect_NG_First[tate][yoko].right - ScrollCntYoko;
			map_naka->rect_NG[tate][yoko].top = map_naka->rect_NG_First[tate][yoko].top - ScrollCntTate;
			map_naka->rect_NG[tate][yoko].bottom = map_naka->rect_NG_First[tate][yoko].bottom - ScrollCntTate;

			map_sita->rect_BT[tate][yoko].left = map_sita->rect_BT_First[tate][yoko].left - ScrollCntYoko;
			map_sita->rect_BT[tate][yoko].right = map_sita->rect_BT_First[tate][yoko].right - ScrollCntYoko;
			map_sita->rect_BT[tate][yoko].top = map_sita->rect_BT_First[tate][yoko].top - ScrollCntTate;
			map_sita->rect_BT[tate][yoko].bottom = map_sita->rect_BT_First[tate][yoko].bottom - ScrollCntTate;


		}
	}
}

BOOL MY_MAP_READ_CSV_NUM(MAPDATA* mapdata, const char* path, const char* mapname)
{
	FILE* fp;

	if ((fp = fopen(path, "r")) == NULL)
	{
		return FALSE;
	}

	int result = 0;
	int LoopCnt = 0;
	while (result != EOF)
	{
		result = fscanf(fp, "%d,", &mapdata->data[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO]);
		mapdata->mapdata_Init[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO]
			= mapdata->data[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO];

		LoopCnt++;
	}
	fclose(fp);

	wsprintf(mapdata->name, mapname);

	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			mapdata->rect_NG[tate][yoko].left = 0;
			mapdata->rect_NG[tate][yoko].top = 0;
			mapdata->rect_NG[tate][yoko].right = 0;
			mapdata->rect_NG[tate][yoko].bottom = 0;

			mapdata->rect_NG_First[tate][yoko] = mapdata->rect_NG[tate][yoko];

			mapdata->rect_OK[tate][yoko].left = 0;
			mapdata->rect_OK[tate][yoko].top = 0;
			mapdata->rect_OK[tate][yoko].right = 0;
			mapdata->rect_OK[tate][yoko].bottom = 0;

			mapdata->rect_OK_First[tate][yoko] = mapdata->rect_OK[tate][yoko];

			mapdata->rect_BT[tate][yoko].left = 0;
			mapdata->rect_BT[tate][yoko].top = 0;
			mapdata->rect_BT[tate][yoko].right = 0;
			mapdata->rect_BT[tate][yoko].bottom = 0;

			mapdata->rect_BT_First[tate][yoko] = mapdata->rect_BT[tate][yoko];

		}
	}

	int cnt;
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			for (cnt = 0; cnt < GAME_MAP_NG_KIND; cnt++)
			{
				if (mapdata->data[tate][yoko] == mapdata->mapNGKind[cnt])
				{
					mapdata->rect_NG[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_NG[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_NG[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_NG[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_NG_First[tate][yoko] = mapdata->rect_NG[tate][yoko];
				}
			}

			for (cnt = 0; cnt < GAME_MAP_OK_KIND; cnt++)
			{
				if (mapdata->data[tate][yoko] == mapdata->mapOKKind[cnt])
				{
					mapdata->rect_OK[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_OK[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_OK[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_OK[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_OK_First[tate][yoko] = mapdata->rect_OK[tate][yoko];
				}
			}

			for (cnt = 0; cnt < GAME_MAP_BT_KIND; cnt++)
			{
				if (mapdata->data[tate][yoko] == mapdata->mapBTKind[cnt])
				{
					mapdata->rect_BT[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_BT[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_BT[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_BT[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_BT_First[tate][yoko] = mapdata->rect_BT[tate][yoko];
				}
			}
		}
	}

	return TRUE;
}

int MY_LOAD_BACKGROUND(IMAGE* image, const char* path)
{
	image->Handle[0] = LoadGraph(path);

	GetGraphSize(
		image->Handle[0],
		&image->Width[0],
		&image->Height[0]);		

	image->C_Width[0] = image->Width[0] / 2;
	image->C_Height[0] = image->Height[0] / 2;

	return image->Handle[0];
}

BOOL MY_MAP_LOAD_BUNKATSU(MAPDATA* mapdata, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char* path)
{
	int ret = 0;

	ret = LoadDivGraph(path, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, mapdata->Handle);

	if (ret == -1) { return FALSE; }

	for (int cnt = 0; cnt < GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT; cnt++)
	{
		GetGraphSize(
			mapdata->Handle[cnt],
			&mapdata->Width[cnt],
			&mapdata->Height[cnt]);			

		mapdata->C_Width[cnt] = mapdata->Width[cnt] / 2;
		mapdata->C_Height[cnt] = mapdata->Height[cnt] / 2;
	}

	return TRUE;
}

BOOL MY_CHARA_LOAD_BUNKATSU(CHARAIMAGE* c, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char* path)
{
	int retLoad;

	wsprintf(c->FilePath, path);

	retLoad = LoadDivGraph(c->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, c->Handle);

	if (retLoad == -1) { return FALSE; }

	for (int cnt = 0; cnt < GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT; cnt++)
	{
		GetGraphSize(
			c->Handle[cnt],
			&c->Width[cnt],
			&c->Height[cnt]);			

		c->C_Width[cnt] = c->Width[cnt] / 2;
		c->C_Height[cnt] = c->Height[cnt] / 2;
	}

	return TRUE;
}

BOOL MY_MAP_READ_CSV_UE_KIND_SET(MAPDATA* mapdata)
{
	int Soeji;

	return TRUE;
}

BOOL MY_MAP_READ_CSV_NAKA_KIND_SET(MAPDATA* mapdata)
{
	int Soeji;

	//通行できるマップ
	Soeji = 0;
	mapdata->mapOKKind[Soeji++] = -1;
	mapdata->mapOKKind[Soeji++] = 817;
	mapdata->mapNGKind[Soeji++] = 849;
	mapdata->mapOKKind[Soeji++] = 851;
	mapdata->mapOKKind[Soeji++] = 1177;

	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++) { mapdata->mapOKKind[cnt] = -1; }

	//通行できないマップ
	Soeji = 0;
	mapdata->mapNGKind[Soeji++] = 1104;
	mapdata->mapNGKind[Soeji++] = 1105;
	mapdata->mapNGKind[Soeji++] = 1106;
	mapdata->mapNGKind[Soeji++] = 1136;
	mapdata->mapNGKind[Soeji++] = 1168;
	mapdata->mapNGKind[Soeji++] = 1201;
	mapdata->mapNGKind[Soeji++] = 1202;
	mapdata->mapNGKind[Soeji++] = 1234;
	mapdata->mapNGKind[Soeji++] = 1168;

	mapdata->mapNGKind[Soeji++] = 1256;
	mapdata->mapNGKind[Soeji++] = 1258;
	mapdata->mapNGKind[Soeji++] = 1259;
	mapdata->mapNGKind[Soeji++] = 1288;
	mapdata->mapNGKind[Soeji++] = 1290;
	mapdata->mapNGKind[Soeji++] = 1291;

	mapdata->mapNGKind[Soeji++] = 1109;
	mapdata->mapNGKind[Soeji++] = 1110;
	mapdata->mapNGKind[Soeji++] = 1141;
	mapdata->mapNGKind[Soeji++] = 1142;

	mapdata->mapNGKind[Soeji++] = 1173;
	mapdata->mapNGKind[Soeji++] = 1205;

	mapdata->mapNGKind[Soeji++] = 34;
	mapdata->mapNGKind[Soeji++] = 35;
	mapdata->mapNGKind[Soeji++] = 66;
	mapdata->mapNGKind[Soeji++] = 67;
	mapdata->mapNGKind[Soeji++] = 343;
	
	mapdata->mapNGKind[Soeji++] = 1089;

	mapdata->mapNGKind[Soeji++] = 164;
	mapdata->mapNGKind[Soeji++] = 165;
	mapdata->mapNGKind[Soeji++] = 166;
	mapdata->mapNGKind[Soeji++] = 167;
	mapdata->mapNGKind[Soeji++] = 196;
	mapdata->mapNGKind[Soeji++] = 197;
	mapdata->mapNGKind[Soeji++] = 198;
	mapdata->mapNGKind[Soeji++] = 199;
	mapdata->mapNGKind[Soeji++] = 228;
	mapdata->mapNGKind[Soeji++] = 229;
	mapdata->mapNGKind[Soeji++] = 230;
	mapdata->mapNGKind[Soeji++] = 231;
	mapdata->mapNGKind[Soeji++] = 260;
	mapdata->mapNGKind[Soeji++] = 261;
	mapdata->mapNGKind[Soeji++] = 262;
	mapdata->mapNGKind[Soeji++] = 263;



	
	mapdata->mapNGKind[Soeji++] = 1040;	//山
	mapdata->mapNGKind[Soeji++] = 1041;	//山
	mapdata->mapNGKind[Soeji++] = 1042;	//山
	mapdata->mapNGKind[Soeji++] = 1043;	//山
	mapdata->mapNGKind[Soeji++] = 1072;	//山
	mapdata->mapNGKind[Soeji++] = 1073;	//山
	mapdata->mapNGKind[Soeji++] = 1074;	//山
	mapdata->mapNGKind[Soeji++] = 1075;	//山
	
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++) { mapdata->mapNGKind[cnt] = -1; }

	return TRUE;
}

BOOL MY_MAP_READ_CSV_SITA_KIND_SET(MAPDATA* mapdata)
{
	int Soeji;

	//通行できるマップ
	Soeji = 0;
	mapdata->mapOKKind[Soeji++] = -1;
	mapdata->mapNGKind[Soeji++] = 1;
	mapdata->mapOKKind[Soeji++] = 2;
	mapdata->mapOKKind[Soeji++] = 3;
	mapdata->mapOKKind[Soeji++] = 4;
	mapdata->mapOKKind[Soeji++] = 5;
	mapdata->mapOKKind[Soeji++] = 6;
	mapdata->mapOKKind[Soeji++] = 7;
	mapdata->mapOKKind[Soeji++] = 315;
	mapdata->mapOKKind[Soeji++] = 664;

	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++) { mapdata->mapOKKind[cnt] = -1; }

	//通行できないマップ
	Soeji = 0;
	mapdata->mapNGKind[Soeji++] = 616;
	mapdata->mapNGKind[Soeji++] = 1080;
	mapdata->mapNGKind[Soeji++] = 1112;
	mapdata->mapNGKind[Soeji++] = 1144;

	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++) { mapdata->mapNGKind[cnt] = -1; }

	return TRUE;
}