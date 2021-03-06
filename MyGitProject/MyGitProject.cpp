#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <conio.h>
#include <time.h>
#include <Windows.h>


struct PixelToEdit
{
	size_t x;
	size_t y;
	char symbol;
};

struct VerticalLine
{
	size_t x_;
	size_t y;
	size_t cnt;
};

struct HorizontalLine
{
	size_t x;
	size_t y_;
	size_t cnt;
};

struct TextToWrite
{
	size_t x;
	size_t y;
	std::string str;
};

struct PixelMap
{
	size_t x;
	size_t y;
	std::vector<std::vector<char>> map;
};

class Screen
{
	void gotoxy(int x, int y) {
		if (x >= 0 && y >= 0) {
			COORD kursor;
			kursor.X = x;
			kursor.Y = y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), kursor);
		}
	}
public:

	void printText(const TextToWrite& txt)
	{
		gotoxy(txt.x, txt.y);
		std::cout << txt.str;
	}

	void MakeBlock(const PixelMap& map) // blocks
	{
		for (size_t i = 0; i < map.map.size(); i++)
		{
			gotoxy(map.x, map.y + i);
			for (auto el : map.map[i])
				std::cout << el;
		}
	}

	void DrawLine(const VerticalLine& line)
	{
		gotoxy(line.x_, line.y);
		for (size_t i = 0; i < line.cnt; i++)
		{
			gotoxy(line.x_, line.y + i);
			std::cout << "|";
		}
	}

	void DrawLine(const HorizontalLine& line)
	{
		gotoxy(line.x, line.y_);
		for (size_t i = 0; i < line.cnt; i++)
		{
			std::cout << "=";
		}
	}

	void SetPixel(const PixelToEdit& cord)
	{
		gotoxy(cord.x, cord.y);
		std::cout << cord.symbol;
	}


	void moveBlock(const PixelMap& map)
	{
		for (size_t i = 0; i < 4; i++)
		{
			gotoxy(map.x, map.y + i );
			for (auto el : map.map[i])
				std::cout << el;
		}

		//оновлення координати
		//x = x2;
		//y = y2;

		// обновлення 
		//for (size_t i = 0; i < 4; i++)
		//{
		//for (size_t j = 0; j < 4; j++)
		//{
		//gotoxy(map.y + i,map.x + j) += map.map[i][j];
		//}
		//}
	}
	void initializeBoard()
	{
		char board[41][30];

		for (int i = 0; i < 41; i++)
		{

			for (int j = 0; j < 30; j++)
			{
				if ((i == 0) || (j == 0) || (i == 41 - 1) || (j == 30 - 1) || (j == -21)) {

					board[i][j] = (char)219;

					gotoxy(i, j);

					std::cout << board[i][j];

				}

				else

					board[i][j] = ' ';

			}

		}

	}


	/*
	void userInput(const PixelMap& map)
	{
		char key;

		key = _getch();

		switch (key)
		{
		case 'd':
		{
			moveBlock(map.x + 1, map.y);
		}
		break;
		case 'a':
		{
			moveBlock(map.x - 1, map.y);
		}
		break;
		case 's':
		{
			moveBlock(map.x, map.y + 1);
		}
		break;
		case ' ':
			//rotateBolck();
		}
	}
	*/

};




int main()
{

	Screen screen;

	//screen.SetPixel(Cordinate{ 21,21,'@' });
	screen.DrawLine(HorizontalLine{ 0,15,11 });
	screen.DrawLine(VerticalLine{ 10,0,16 });
	screen.DrawLine(VerticalLine{ 0,0,16 });
	//screen.MakeBlock(PixelMap{ 5,0, {{'*', '*'},{ '*', '*'}} });
	screen.moveBlock(PixelMap{ 5,0,{ { '*', '*' },{ '*', '*' } } });
	screen.printText(TextToWrite{ 15,1,"Score --- > " });
	screen.printText(TextToWrite{ 15,3,"Timer --- > " });


	system("pause");



}


