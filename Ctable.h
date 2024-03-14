#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

void gotoxy(int x, int y)
{
	COORD pos; pos.X = x; pos.Y = y; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void horizontal_line(int gx, int gy, int l, char a)
{
	for (int i = 0; i < l; i++)
	{
		gotoxy(gx + i, gy); std::cout << a;
	}
}
void vertical_line(int gx, int gy, int h, char a)
{
	for (int i = 0; i < h; i++)
	{
		gotoxy(gx, gy + i); std::cout << a;
	}
}

#define hl horizontal_line
#define vl vertical_line

void Ctable()
{

	hl(2, 5, 117, 196);
	hl(2, 7, 117, 196);
	hl(2, 9, 117, 196);
	hl(2, 11, 117, 196);
	hl(2, 13, 117, 196);
	hl(2, 15, 117, 196);
	hl(2, 17, 117, 196);
	hl(2, 19, 117, 196);
	hl(2, 21, 117, 196);
	hl(2, 23, 117, 196);

	gotoxy(5, 0); cout << "SCHOOL CURRICULUM";
	gotoxy(113, 0); cout << "help";
	hl(2, 1, 117, 196);
	hl(2, 3, 117, 196);//Search bar
	vl(2, 2, 1, 179);
	vl(118, 2, 1, 179);

	vl(2, 6, 19, 179);
	vl(118, 6, 19, 179);
	vl(6, 6, 19, 179);// NO
	vl(26, 6, 19, 179);// YEAR LEVEL
	vl(41, 6, 19, 179);// SUBJECT CODE
	vl(90, 6, 19, 179);// SUBJECT DESCRIPTIO //SUBJECT UNIT
	vl(97, 6, 19, 179);//PRE REQUIST
	hl(3, 25, 114, 196);
	gotoxy(3, 6); cout << "NO"; gotoxy(10, 6); cout << "YEAR LEVEL"; gotoxy(27, 6); cout << " SUBJECT CODE";
	gotoxy(55, 6); cout << " SUBJECT DESCRIPTION"; gotoxy(92, 6); cout << "UNIT"; gotoxy(103, 6); cout << "PRE-REQ.";


	gotoxy(60, 26); cout << string(15, char(205));	gotoxy(60, 28); cout << string(15, char(205)); gotoxy(60, 27); cout << string(1, char(186)); gotoxy(75, 27); cout << string(1, char(186));
	gotoxy(60, 26); cout << string(1, char(201));	gotoxy(60, 28); cout << string(1, char(200));	gotoxy(75, 26); cout << string(1, char(187));	gotoxy(75, 28); cout << string(1, char(188));

	gotoxy(80, 26); cout << string(15, char(205));	gotoxy(80, 28); cout << string(15, char(205)); gotoxy(80, 27); cout << string(1, char(186)); gotoxy(95, 27); cout << string(1, char(186));
	gotoxy(80, 26); cout << string(1, char(201));	gotoxy(80, 28); cout << string(1, char(200));	gotoxy(95, 26); cout << string(1, char(187));	gotoxy(95, 28); cout << string(1, char(188));

	gotoxy(100, 26); cout << string(15, char(205));	gotoxy(100, 28); cout << string(15, char(205)); gotoxy(100, 27); cout << string(1, char(186)); gotoxy(115, 27); cout << string(1, char(186));
	gotoxy(100, 26); cout << string(1, char(201));	gotoxy(100, 28); cout << string(1, char(200));	gotoxy(115, 26); cout << string(1, char(187));	gotoxy(115, 28); cout << string(1, char(188));

	gotoxy(62, 27); cout << "ADD SUBJECT"; gotoxy(85, 27); cout << "DELETE"; gotoxy(106, 27); cout << "BACK";

	gotoxy(5, 2); cout << "SEARCH YEAR: " << char(179); gotoxy(45, 2); cout << char(179) << "SEARCH SEMESTER:" << char(179);

}

