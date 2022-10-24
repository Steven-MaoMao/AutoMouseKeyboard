#pragma once

#include <Windows.h>
#include <WinUser.h>

using namespace std;

class KEYBOARD
{
public:
	void PressKey(BYTE bVk);
	void KeyDown(BYTE bVk);
	void KeyUp(BYTE bVk);
};

// 按键（虚拟键值）
void KEYBOARD::PressKey(BYTE bVk)
{
	::keybd_event(bVk, 0, 0, 0);
	::keybd_event(bVk, 0, KEYEVENTF_KEYUP, 0);
}

// 按下（虚拟键值）
void KEYBOARD::KeyDown(BYTE bVk)
{
	::keybd_event(bVk, 0, 0, 0);
}

// 抬起（虚拟键值）
void KEYBOARD::KeyUp(BYTE bVk)
{
	::keybd_event(bVk, 0, KEYEVENTF_KEYUP, 0);
}