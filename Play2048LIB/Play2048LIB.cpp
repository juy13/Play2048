// Play2048LIB.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "Play2048LIB.h"




void create_rnd(Table2048& table)
{

	if (table.amount >= 9)
	{
		return;     // write an error for full table
	}
	else
	{

	}
}

void moveD(Table2048& table)
{
	for (int i = 0; i < 3; i++)
	{
		if (table.y[i] == table.z[i])
		{
			table.z[i] = 0 - table.y[i] * 2;
			table.y[i] = table.x[i];
			table.x[i] = 0;
		}
		if (table.z[i] == 0)
		{
			table.z[i] = table.y[i];
			table.y[i] = 0;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (table.x[i] == table.y[i])
		{
			table.y[i] = 0 - table.x[i] * 2;
			table.x[i] = 0;
		}
		if (table.y[i] == 0)
		{
			table.y[i] = table.x[i];
			table.x[i] = 0;
		}
	}
	
	for (auto& el : table.x)
	{
		el = abs(el);
	}
	for (auto& el : table.y)
	{
		el = abs(el);
	}
	for (auto& el : table.z)
	{
		el = abs(el);
	}
}

void moveU(Table2048& table)
{
	for (int i = 0; i < 3; i++)
	{
		if (table.x[i] == table.y[i])
		{
			table.x[i] = 0 - table.y[i] * 2;
			table.y[i] = table.z[i];
			table.z[i] = 0;
		}
		if (table.x[i] == 0)
		{
			table.x[i] = table.y[i];
			table.y[i] = 0;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (table.y[i] == table.z[i])
		{
			table.y[i] = 0 - table.z[i] * 2;
			table.z[i] = 0;
		}
		if (table.y[i] == 0)
		{
			table.y[i] = table.z[i];
			table.z[i] = 0;
		}
	}

	for (auto& el : table.x)
	{
		el = abs(el);
	}
	for (auto& el : table.y)
	{
		el = abs(el);
	}
	for (auto& el : table.z)
	{
		el = abs(el);
	}
}

void moveL(Table2048& table)
{

}

void moveR(Table2048& table)
{

}


void print_table(Table2048 table)
{
	std::cout << "Table:" << std::endl;
	for (auto el : table.x)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;
	for (auto el : table.y)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;
	for (auto el : table.z)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

// TODO: This is an example of a library function
void fnPlay2048LIB()
{
}
