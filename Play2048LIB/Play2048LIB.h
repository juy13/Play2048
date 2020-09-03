#pragma once

#include <iostream>
#include <string>
#include <vector>

enum StateTable
{
	PLAY = 0,
	LOSE,
	WIN
};

typedef struct Table2048
{
	std::vector<int> x;
	std::vector<int> y;
	std::vector<int> z;
	Table2048* prev;
	Table2048* nextD;
	Table2048* nextU;
	Table2048* nextL;
	Table2048* nextR;
	StateTable state;
	int amount = 0;

	Table2048()
	{
		x.insert(x.begin(), 3, 0);
		y.insert(y.begin(), 3, 0);
		z.insert(z.begin(), 3, 0);
		prev = NULL;
		nextD = NULL;
		nextU = NULL;
		nextL = NULL;
		nextR = NULL;
		state = PLAY;
	}

}Table2048;

void create_rnd(Table2048& table);
void moveD(Table2048& table);
void moveU(Table2048& table);
void moveL(Table2048& table);
void moveR(Table2048& table);
void print_table(Table2048 table);