// TestPlay2048.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Play2048LIB.h"
#include <gtest/gtest.h>

int main(int argc, wchar_t* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "Hello World!\n";
    return RUN_ALL_TESTS();
}

TEST(TestMove, TestDown1)
{
    Table2048 table;
    table.x.at(2) = 4;
    table.x.at(1) = 4;
    table.y.at(0) = 4;
    table.y.at(1) = 2;
    table.z.at(1) = 2;
    print_table(table);

    moveD(table);
    print_table(table);
    ASSERT_EQ(table.z.at(1), 4);
}

TEST(TestMove, TestDown2)
{
    Table2048 table;
    table.x.at(1) = 4;
    table.y.at(2) = 2;
    table.z.at(1) = 2;
    table.z.at(0) = 2;
    print_table(table);

    moveD(table);
    print_table(table);
    ASSERT_EQ(table.z.at(1), 2);
}

TEST(TestMove, TestDown3)
{
    Table2048 table;
    table.x.at(1) = 2;
    table.x.at(2) = 4;
    table.y.at(0) = 2;
    table.z.at(1) = 2;
    table.z.at(0) = 2;
    print_table(table);

    moveD(table);
    print_table(table);
    ASSERT_EQ(table.z.at(1), 4);
}

TEST(TestMove, TestUp1)
{
    Table2048 table;
    table.x.at(1) = 2;
    table.y.at(2) = 4;
    table.y.at(1) = 2;
    table.z.at(1) = 4;
    print_table(table);

    moveU(table);
    print_table(table);
    ASSERT_EQ(table.z.at(1), 0);
}

TEST(TestMove, TestUp2)
{
    Table2048 table;
    table.x.at(1) = 2;
    table.x.at(2) = 4;
    table.y.at(0) = 2;
    table.z.at(1) = 2;
    table.z.at(0) = 2;
    print_table(table);

    moveU(table);
    print_table(table);
    ASSERT_EQ(table.z.at(1), 0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file