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

enum StateCell
{
	EMPTY = 0,
	FULL,
	REPLACED
};


class Cell
{
	int number = 0;
	StateCell state = EMPTY;

public:
	Cell()
	{

	}

	Cell& operator+=(Cell &c2)
	{
		number += c2.getNum();	
		c2.changeState();
		return *this;
	}

	friend bool operator==(const Cell c1, const Cell c2);

	int getNum() const
	{
		return number;
	}


	void setNum(int num)
	{
		number = num;
	}

	void changeStates()
	{
		state = FULL;
	}

private:
	void changeState()
	{
		state = REPLACED;
		number = 0;
	}

	

};



class Table2048
{
	std::vector<int> x;
	std::vector<int> y;
	std::vector<int> z;

	Cell table[3][3];

	Table2048* prev;
	Table2048* nextD;
	Table2048* nextU;
	Table2048* nextL;
	Table2048* nextR;
	StateTable state;
	int amount = 0;
	int sizeI = 0;
	int sizeJ = 0;

public:
	Table2048()
	{
		for (int i = 0; i < 3; i++)
		{
			Cell cell;
			for (int j = 0; j < 3; j++)
			{
				table[i][j] = cell;
			}
		}
		prev = NULL;
		nextD = NULL;
		nextU = NULL;
		nextL = NULL;
		nextR = NULL;
		state = PLAY;

		sizeI = 3;
		sizeJ = 3;
	}

	Table2048(int k, int m)
	{
		for (int i = 0; i < k; i++)
		{
			Cell cell;
			for (int j = 0; j < m; j++)
			{
				table[i][j] = cell;
			}
		}
		prev = NULL;
		nextD = NULL;
		nextU = NULL;
		nextL = NULL;
		nextR = NULL;
		state = PLAY;
	}

	int getAmount() const
	{
		return amount;
	}

	int getaState() const
	{
		return state;
	}

	Cell& at(int i, int j)
	{
		return table[i][j];
	}

	int getSizeI() const
	{
		return sizeI;
	}

	int getSizeJ() const
	{
		return sizeJ;
	}

	friend std::ostream& operator << (std::ostream& os, Table2048& p);

	void changeState()
	{
		for (int i = 0; i < sizeI; i++)
		{
			for (int j = 0; j < sizeJ; j++)
			{
				table[i][j].changeStates();
			}
		}
	}

};





void create_rnd(Table2048& table);
void moveD(Table2048& table);
void moveU(Table2048& table);
void moveL(Table2048& table);
void moveR(Table2048& table);
void print_table(Table2048 table);