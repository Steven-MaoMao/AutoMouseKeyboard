#pragma once

#include <Windows.h>
#include <WinUser.h>

using namespace std;

class MOUSE
{
private:
	// �������
	POINT point;
	// ��Ļ����
	int screen_width = 1920;
	int screen_height = 1080;
public:
	// �ƶ��ຯ��
	void Move(int x, int y);
	void RelativeMove(int dx, int dy);
	void SavePos();
	void RestorePos();
	// ����������
	void Lock();
	void Unlock();
	// ������
	void LBClick();
	void LBDbClick();
	void LBDown();
	void LBUp();
	void RBClick();
	void RBDbClick();
	void RBDown();
	void RBUp();
	void MBClick();
	void MBDbClick();
	void MBDown();
	void MBUp();
	void MBRoll(int ch);
};

// �ƶ���굽����λ�ã�X���꣬Y���꣩
void MOUSE::Move(int x, int y)
{
	this->point.x = x;
	this->point.y = y;
	::SetCursorPos(x, y);
	mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, x * 65536 / this->screen_width, y * 65536 / this->screen_height, 0, 0);
}

// �ƶ���굽���λ�ã�Xλ�ƣ�Yλ�ƣ�
void MOUSE::RelativeMove(int dx, int dy)
{
	::GetCursorPos(&this->point);
	this->point.x += dx;
	this->point.y += dy;
	::SetCursorPos(this->point.x, this->point.y);
	mouse_event(MOUSEEVENTF_MOVE, dx, dy, 0, 0);
}

// ���浱ǰλ�ã���
void MOUSE::SavePos()
{
	::GetCursorPos(&this->point);
}

// �ָ����λ�ã���
void MOUSE::RestorePos()
{
	::SetCursorPos(this->point.x, this->point.y);
	mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, this->point.x * 65536 / this->screen_width, this->point.y * 65536 / this->screen_height, 0, 0);
}

// ������꣨��
void MOUSE::Lock()
{
	POINT pt;
	RECT rt;

	::GetCursorPos(&pt);
	rt.left = rt.right = pt.x;
	rt.top = rt.bottom = pt.y;
	rt.right++;
	rt.bottom++;
	::ClipCursor(&rt);
}

// ������꣨��
void MOUSE::Unlock()
{
	::ClipCursor(NULL);
}

// �����������
void MOUSE::LBClick()
{
	this->SavePos();
	::mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, this->point.x, this->point.y, 0, 0);
}

// ���˫������
void MOUSE::LBDbClick()
{
	this->SavePos();
	::mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, this->point.x, this->point.y, 0, 0);
	::mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, this->point.x, this->point.y, 0, 0);
}

// ������£���
void MOUSE::LBDown()
{
	this->SavePos();
	::mouse_event(MOUSEEVENTF_LEFTDOWN, this->point.x, this->point.y, 0, 0);
}

// ���̧�𣨣�
void MOUSE::LBUp()
{
	this->SavePos();
	::mouse_event(MOUSEEVENTF_LEFTUP, this->point.x, this->point.y, 0, 0);
}

// �Ҽ���������
void MOUSE::RBClick()
{
	this->SavePos();
	::mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, this->point.x, this->point.y, 0, 0);
}

// �Ҽ�˫������
void MOUSE::RBDbClick()
{
	this->SavePos();
	::mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, this->point.x, this->point.y, 0, 0);
	::mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, this->point.x, this->point.y, 0, 0);
}

// �Ҽ����£���
void MOUSE::RBDown()
{
	this->SavePos();
	::mouse_event(MOUSEEVENTF_RIGHTDOWN, this->point.x, this->point.y, 0, 0);
}

// �Ҽ�̧�𣨣�
void MOUSE::RBUp()
{
	this->SavePos();
	::mouse_event(MOUSEEVENTF_RIGHTUP, this->point.x, this->point.y, 0, 0);
}

// �м���������
void MOUSE::MBClick()
{
	this->SavePos();
	::mouse_event(MOUSEEVENTF_MIDDLEDOWN | MOUSEEVENTF_MIDDLEUP, this->point.x, this->point.y, 0, 0);
}

// �м�˫������
void MOUSE::MBDbClick()
{
	this->SavePos();
	::mouse_event(MOUSEEVENTF_MIDDLEDOWN | MOUSEEVENTF_MIDDLEUP, this->point.x, this->point.y, 0, 0);
	::mouse_event(MOUSEEVENTF_MIDDLEDOWN | MOUSEEVENTF_MIDDLEUP, this->point.x, this->point.y, 0, 0);
}

// �м����£���
void MOUSE::MBDown()
{
	this->SavePos();
	::mouse_event(MOUSEEVENTF_MIDDLEDOWN, this->point.x, this->point.y, 0, 0);
}

// �м�̧�𣨣�
void MOUSE::MBUp()
{
	this->SavePos();
	::mouse_event(MOUSEEVENTF_MIDDLEUP, this->point.x, this->point.y, 0, 0);
}

// �м�����������λ�ƣ�
void MOUSE::MBRoll(int ch)
{
	this->SavePos();
	::mouse_event(MOUSEEVENTF_WHEEL, this->point.x, this->point.y, ch, 0);
}