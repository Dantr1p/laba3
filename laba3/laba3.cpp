
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
	void add_price(laptop a);
	void compare_laptop(laptop a);
};

laptop::laptop()
{
	model = "";
	RAM_size = 0;
	CPU_frequency = 0;
	price = 0;
	year = 0;
}

laptop::laptop(string model, int ram, int cpu, double price, int year)
{
	this->model = model;
	RAM_size = ram;
	CPU_frequency = cpu;
	this->price = price;
	this->year = year;
}

laptop::~laptop()
{
	printf("Ноутбук разрушен");
}

void laptop::set_laptop(string model, int ram, int cpu, double price, int year)
{
	this->model = model;
	RAM_size = ram;
	CPU_frequency = cpu;
	this->price = price;
	this->year = year;
}

void laptop::print_laptop()
{
	cout << "Модель ноутбука: " << model << endl;
	cout << "Объем оперативной памяти: " << RAM_size << endl;
	cout << "Частота процессора: " << CPU_frequency << endl;
	cout << "Цена ноутбука: " << price << endl;
	cout << "Год производства: " << year << endl;

}

void laptop::add_price(laptop a)
{
	double sumprice = 0;
	sumprice = this->price + a.price;
	cout << "Суммарная цена=" << sumprice;	
}

void laptop::compare_laptop(laptop a)
{
    int ram, cpu, year;
    double price;
    cout <<"Сравниваем ноутбуки "<<this->model<<" и "<<a.model);

    // сравниваем по ram
    if (this->RAM_size > a.RAM_size)
    {
        ram = this->RAM_size - a.RAM_size;
        cout<<"Оперативная память ноутбука "<< this->model<<" больше оперативной памяти ноутбука "<<a.model<<" на "<< ram<<" гб."
    }
    if (this->RAM_size < a.RAM_size)
    {
        ram = a.RAM_size- this->RAM_size;
        cout << "Оперативная память ноутбука " << a.model << " больше оперативной памяти ноутбука " << this->model << " на " << ram << " гб."
    }
    if (this->RAM_size == a.RAM_size)
    {
       
        cout << "Оперативная память ноутбуков совпадает и = " << this->RAM_size<< " гб.";
    }
    // сравниваем по частоте
    if (this->CPU_frequency > a.CPU_frequency)
    {
        cpu = this->CPU_frequency - a.CPU_frequency;
        cout << "Частота процессора ноутбука " << this->model << " больше частоты процессора ноутбука " << a.model << " на " << cpu << " гц."
    }
    if (this->CPU_frequency < a.CPU_frequency)
    {
        cpu = a.CPU_frequency - this->CPU_frequency;
        cout << "Частота процессора ноутбука " << a.model << " больше частоты процессора ноутбука " << this->model << " на " << cpu << " гц."
    }
    if (this->RAM_size == a.RAM_size)
    {

        cout << "Частоты процессоров ноутбуков совпадают и = " << this->CPU_frequency<< " гц.";
    }
    // сравниваем по цене
    if (this->price > a.price)
    {
        price = this->price - a.price;
        cout << "Цена ноутбука " << this->model << " больше цены ноутбука " << a.model << " на " << price << " р."
    }
    if (this->price < a.price)
    {
        price = a.price - this->price;
        cout << "Цена ноутбука " << a.model << " больше цены ноутбука " << this->model << " на " << price << " р."
    }
    if (this->price == a.price)
    {

        cout << "Цены ноутбуков совпадают и = " << this->price<<" р.";
    }
    // сравниваем по году выпуска
    if (this->year > a.year)
    {
        year = this->year - a.year;
        cout << "Год выпуска ноутбука " << this->model << " позже года выпуска ноутбука " << a.model << " на " << year << " г."
    }
    if (this->year < a.year)
    {
        year = a.year - this->year;
        cout << "Год выпуска ноутбука " << a.model << " позже года выпуска ноутбука " << this->model << " на " << year << " г."
    }
    if (this->year == a.year)
    {

        cout << "Годы выпуска ноутбуков совпадают и = " << this->year <<" г.";
    }
}


int main()
{
	system("color f0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

