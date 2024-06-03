#include "DxLib.h"//Dxライブラリーをインクルード　（読み込み）

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windowsのメインで動かす
{

   //基本設計
    ChangeWindowMode(TRUE);//Windowsの画面をアクティブにする
    DxLib_Init();//DxLibの初期化
    SetDrawScreen(DX_SCREEN_BACK);//画面の背景は黒
    SetGraphMode(800, 600, 32);//画面の大きさ
    
   //DxLibの初期化処理
    if (DxLib_Init() == -1)
    {
        //エラーが起きたら直ちに終了
        return -1;
    }
    //円の初期位置
    int circleX = 320;
    int circleY = 240;
    //文字の初期位置
    int stringX = 15;
    int strinhY = 10;
    int stringX1 = 20;
    int stringY1 = 37;
    //マウスの初期位置
    int mouseX = 0;
    int mouseY = 0;
    //円の色指定
    int circleColor = GetColor(0, 0, 255);
    //文字の色指定
    int StringColor = GetColor(255, 255, 255);
    int StringColor2 = GetColor(255, 255, 0);

    //ゲームループ
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //画面の初期化
        ClearDrawScreen();
        //文字の大きさの指定
        SetFontSize(32);
        //画面に文字表示
        //DrawString(10, 15, "HelloWourd", StringColor);  
        DrawFormatString(stringX,strinhY, StringColor, "X:%d Y:%d", mouseX, mouseY);
        //画面に円を描画させる
        DrawCircle(circleX, circleY, 30, circleColor, TRUE);
        //画面に点を描画させてね　（X座標、Y座標、点の色指定）
        DrawPixel(320, 240, GetColor(255, 0, 0));
        //マウスの座標を取得
        GetMousePoint(&mouseX, &mouseY);
        //マウスがクリックされたら
        if (GetMouseInput() & MOUSE_INPUT_LEFT)
        {
            SetFontSize(30);
            DrawString(stringX1, stringY1, "HIT!", StringColor2);
        }
        if (CheckHitKey(KEY_INPUT_UP)) //上を押したら上に動く
        {
            if (circleY <= 40)
            {
                circleY += 3;
            }
            else
            {
                circleY -= 3;
            }
            
        }
        if (CheckHitKey(KEY_INPUT_DOWN)) //下を押したら下に動く
        {
            if (circleY >= 560)
            {
                circleY -= 3;
            }
            else
            {
                circleY += 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_LEFT)) //左を押したら左に動く
        {
            if (circleX <= 40)
            {
                circleX += 3;
            }
            else
            {
                circleX -= 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_RIGHT)) //右を押したら右に動く
        {
            if (circleX >= 760)
            {
                circleX -= 3;
            }
            else
            {
                circleX += 3;
            }
        }
        //円のX座標に動きをつける
        //circleX += 2;
        //裏画面の内容を表画面に反映させる
        ScreenFlip();

    }
    //画面に点を描画させてね　（X座標、Y座標、天の色指定）
    //DrawPixel(320, 240, GetColor(255, 0, 0));
    //Dxlib使用の処理終了
    DxLib_End();
    //ソースの終了
    return 0;
}