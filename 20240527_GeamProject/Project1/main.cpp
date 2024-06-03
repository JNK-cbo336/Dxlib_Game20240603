#include "DxLib.h"//Dx���C�u�����[���C���N���[�h�@�i�ǂݍ��݁j

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windows�̃��C���œ�����
{

   //��{�݌v
    ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();//DxLib�̏�����
    SetDrawScreen(DX_SCREEN_BACK);//��ʂ̔w�i�͍�
    SetGraphMode(800, 600, 32);//��ʂ̑傫��
    
   //DxLib�̏���������
    if (DxLib_Init() == -1)
    {
        //�G���[���N�����璼���ɏI��
        return -1;
    }
    //�~�̏����ʒu
    int circleX = 320;
    int circleY = 240;
    //�����̏����ʒu
    int stringX = 15;
    int strinhY = 10;
    int stringX1 = 20;
    int stringY1 = 37;
    //�}�E�X�̏����ʒu
    int mouseX = 0;
    int mouseY = 0;
    //�~�̐F�w��
    int circleColor = GetColor(0, 0, 255);
    //�����̐F�w��
    int StringColor = GetColor(255, 255, 255);
    int StringColor2 = GetColor(255, 255, 0);

    //�Q�[�����[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //��ʂ̏�����
        ClearDrawScreen();
        //�����̑傫���̎w��
        SetFontSize(32);
        //��ʂɕ����\��
        //DrawString(10, 15, "HelloWourd", StringColor);  
        DrawFormatString(stringX,strinhY, StringColor, "X:%d Y:%d", mouseX, mouseY);
        //��ʂɉ~��`�悳����
        DrawCircle(circleX, circleY, 30, circleColor, TRUE);
        //��ʂɓ_��`�悳���Ăˁ@�iX���W�AY���W�A�_�̐F�w��j
        DrawPixel(320, 240, GetColor(255, 0, 0));
        //�}�E�X�̍��W���擾
        GetMousePoint(&mouseX, &mouseY);
        //�}�E�X���N���b�N���ꂽ��
        if (GetMouseInput() & MOUSE_INPUT_LEFT)
        {
            SetFontSize(30);
            DrawString(stringX1, stringY1, "HIT!", StringColor2);
        }
        if (CheckHitKey(KEY_INPUT_UP)) //������������ɓ���
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
        if (CheckHitKey(KEY_INPUT_DOWN)) //�����������牺�ɓ���
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
        if (CheckHitKey(KEY_INPUT_LEFT)) //�����������獶�ɓ���
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
        if (CheckHitKey(KEY_INPUT_RIGHT)) //�E����������E�ɓ���
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
        //�~��X���W�ɓ���������
        //circleX += 2;
        //����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip();

    }
    //��ʂɓ_��`�悳���Ăˁ@�iX���W�AY���W�A�V�̐F�w��j
    //DrawPixel(320, 240, GetColor(255, 0, 0));
    //Dxlib�g�p�̏����I��
    DxLib_End();
    //�\�[�X�̏I��
    return 0;
}