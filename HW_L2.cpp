#include <windows.h>
#include <iostream>
#include <fstream>

#include "MyLib.h"
#include "RunTimer.h"


#include "Task1.h"
#include "Task2.h"
#include "Task3.h"


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
	const size_t size = 25;
	std::vector<int32_t*> myArray;
	myArray.reserve(size);
	for (size_t i = 0; i < size; i++)
	{
		int32_t* element = new int32_t(std::rand() % 100 );
		myArray.push_back(element);
	}
	
	auto printArr = [&myArray]()
	{
		for (const auto i : myArray)
		{
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	};

	printArr();
	SortPointers<int>(myArray);
	printArr();

	for (auto i : myArray)
	{
		delete i;
	}
}


void Task3()
{	
	std::ifstream file("../Input.txt");
	file.seekg(0, std::ios::end);
	size_t size = file.tellg();
	file.seekg(0);
	string s(size, ' ');
	file.read(&s[0], size);
	
	std::string vowels = "АОИЕЁЭЫУЮЯаоиеёэыуюя";

	uint16_t count;
	RunTimer timer;
	timer.start("Count_if_find");
	count = Count_if_find(s, vowels);
	timer.print();
	std::cout << count << " Гласных" << std::endl;

	timer.start("Count_if_for");
	count = Count_if_for(s, vowels);
	timer.print();
	std::cout << count << " Гласных" << std::endl;

	timer.start("For_find");
	count = For_find(s, vowels);
	timer.print();
	std::cout << count << " Гласных" << std::endl;

	timer.start("For_For");
	count = For_For(s, vowels);
	timer.print();
	std::cout << count << " Гласных" << std::endl;

}


int main()
{
	setlocale(LC_ALL, "RU");

	std::srand(std::time(0));

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