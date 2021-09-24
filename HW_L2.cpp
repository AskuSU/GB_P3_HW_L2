﻿#include <windows.h>
#include <iostream>
#include "MyLib.h"

#include "Task1.h"
//#include "Task2.h"
//#include "Task3.h"


void Task1()
{
	std::cout << "Работа с Функцией Swap:" << std::endl << std::endl;
	int16_t a = 10, b = 20;
	int16_t* a_ptr = &a, * b_ptr = &b;

	std::cout << "a = " << *a_ptr << " b = " << *b_ptr << std::endl;
	Swap<int16_t>(a_ptr, b_ptr);
	std::cout << "a = " << *a_ptr << " b = " << *b_ptr << std::endl;

	std::string a_s = "abc", b_s = "def";
	std::string* a_s_ptr = &a_s, * b_s_ptr = &b_s;
 	
	std::cout << "a = " << *a_s_ptr << " b = " << *b_s_ptr << std::endl;
	Swap<std::string>(a_s_ptr, b_s_ptr);
	std::cout << "a = " << *a_s_ptr << " b = " << *b_s_ptr << std::endl;
}

void Task2()
{
}

void Task3()
{
}


int main()
{
	setlocale(LC_ALL, "RU");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	unsigned short taskNumber = 0;
	while (true)
	{
		taskNumber = myLib::getUserSelectedTask(3);
		switch (taskNumber)
		{
		case 1: Task1();
			break;
		case 2: Task2();
			break;
		case 3: Task3();
			break;
		}
		cout << endl;
	}

    return 0;
}