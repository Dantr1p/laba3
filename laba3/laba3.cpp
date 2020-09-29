
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>

using namespace std;

class laptop
{
	string model];	//модель ноутбука
	int RAM_size;// объем оперативной памяти
	int CPU_frequency; //частота процессора
	double price;// цена ноутбука
	int year;// Год производства
//public:
	laptop();
	laptop(string model, int ram, int cpu, double price, int year);
	~laptop();
	void set_laptop(string model, int ram, int cpu, double price, int year);
	void print_laptop();
};



int main()
{
	system("color f0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

