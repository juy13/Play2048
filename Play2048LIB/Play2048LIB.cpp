// Play2048LIB.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "Play2048LIB.h"




void create_rnd(Table2048& table)
{

	if (table.getAmount() >= 9)
	{
		return;     // write an error for full table
	}
	else
	{

	}
}

void moveD(Table2048& table)
{
	for (int k = 0; k < table.getSizeI(); k++)
	{
		for (int i = table.getSizeI() - 1; i > 0; i--)
		{

			for (int j = 0; j < table.getSizeJ(); j++)
			{
				if (table.at(i, j).getNum() == 0)
				{
					table.at(i, j) += table.at(i - 1, j);
				}
			}
		}
	}

	for (int i = table.getSizeI() - 1; i > 0; i--)
	{

		for (int j = 0; j < table.getSizeJ(); j++)
		{
			if (table.at(i, j) == table.at(i - 1, j) || (table.at(i, j).getNum() == 0))
			{
				table.at(i, j) += table.at(i - 1, j);
			}
		}
	}

	table.changeState();


}

void moveU(Table2048& table)
{

	for (int k = 0; k < table.getSizeI(); k++)
	{
		for (int i = 1; i < table.getSizeI(); i++)
		{
			for (int j = 0; j < table.getSizeJ(); j++)
			{
				if (table.at(i - 1, j).getNum() == 0)
				{
					table.at(i - 1, j) += table.at(i, j);
				}
			}
		}
	}


	for (int i = 1; i < table.getSizeI(); i++)
	{

		for (int j = 0; j < table.getSizeJ(); j++)
		{
			if (table.at(i - 1, j) ==  table.at(i, j) || table.at(i - 1, j).getNum() == 0)
			{
				table.at(i - 1, j) += table.at(i, j);
			}
		}
	}

	table.changeState();


}

void moveL(Table2048& table)
{
	for (int k = 0; k < table.getSizeI(); k++)
	{
		for (int j = table.getSizeI() - 1; j > 0; j--)
		{

			for (int i = 0; i < table.getSizeJ(); i++)
			{
				if (table.at(i, j).getNum() == 0)
				{
					table.at(i, j) += table.at(i, j - 1);
				}
			}
		}
	}

	for (int j = table.getSizeI() - 1; j > 0; j--)
	{
		for (int i = 0; i < table.getSizeJ(); i++)
		{
			if (table.at(i, j) == table.at(i, j - 1) || (table.at(i, j).getNum() == 0))
			{
				table.at(i, j) += table.at(i, j - 1);
			}
		}
	}

	table.changeState();
}

void moveR(Table2048& table)
{
	for (int k = 0; k < table.getSizeJ(); k++)
	{
		for (int j = 1; j < table.getSizeJ(); j++)
		{
			for (int i = 0; i < table.getSizeI(); i++)
			{
				if (table.at(i, j - 1).getNum() == 0)
				{
					table.at(i, j - 1) += table.at(i, j);
				}
			}
		}
	}

	for (int j = 1; j < table.getSizeJ(); j++)
	{

		for (int i = 0; i < table.getSizeI(); i++)
		{
			if (table.at(i, j - 1) == table.at(i, j) || table.at(i, j - 1).getNum() == 0)
			{
				table.at(i, j - 1) += table.at(i, j);
			}
		}
	}

	table.changeState();
}


void print_table(Table2048 table)
{
	
}

// TODO: This is an example of a library function
void fnPlay2048LIB()
{

}

std::ostream& operator << (std::ostream& os, Table2048& p)
{
	for (int i = 0; i < p.getSizeI(); i++)
	{
		for (int j = 0; j < p.getSizeJ(); j++)
		{
			os << p.at(i, j).getNum() << " ";
		}
		os << std::endl;
	}
	return os;
}

bool operator==(const Cell c1, const Cell c2)
{
	return (c1.getNum() == c2.getNum());
}