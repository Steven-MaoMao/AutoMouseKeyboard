#pragma once

#include <Windows.h>

using namespace std;

class CONSOLE_CURSOR
{
public:
    void Move(int x, int y);
    void RelativeMove(int dx, int dy);
    COORD GetPosition();
};

void CONSOLE_CURSOR::Move(int x, int y)
{
    COORD  coord;
    coord.X = x;
    coord.Y = y;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, coord);
}

void CONSOLE_CURSOR::RelativeMove(int dx, int dy)
{
    COORD coord = GetPosition();
    coord.X += dx;
    coord.Y += dy;
    Move(coord.X, coord.Y);
}

COORD CONSOLE_CURSOR::GetPosition()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(handle, &csbi);
    COORD  coord;
    coord.X = csbi.dwCursorPosition.X;
    coord.Y = csbi.dwCursorPosition.Y;
    return coord;
}