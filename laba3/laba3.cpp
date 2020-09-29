
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <malloc.h>

using namespace std;

class laptop
{
private:
	string model;	//модель ноутбука
	int RAM_size;// объем оперативной памяти
	int CPU_frequency; //частота процессора
	double price;// цена ноутбука
	int year;// Год производства
public:
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
	cout << "Суммарная цена=" << sumprice<< endl;	
}

void laptop::compare_laptop(laptop a)
{
    int ram, cpu, year;
    double price;
    cout <<"Сравниваем ноутбуки "<<this->model<<" и "<<a.model << endl;

    // сравниваем по ram
    if (this->RAM_size > a.RAM_size)
    {
        ram = this->RAM_size - a.RAM_size;
		cout << "Оперативная память ноутбука " << this->model << " больше оперативной памяти ноутбука " << a.model << " на " << ram << " гб." << endl;
    }
    if (this->RAM_size < a.RAM_size)
    {
        ram = a.RAM_size- this->RAM_size;
		cout << "Оперативная память ноутбука " << a.model << " больше оперативной памяти ноутбука " << this->model << " на " << ram << " гб." << endl;
    }
    if (this->RAM_size == a.RAM_size)
    {
       
        cout << "Оперативная память ноутбуков совпадает и = " << this->RAM_size<< " гб." << endl;
    }
    // сравниваем по частоте
    if (this->CPU_frequency > a.CPU_frequency)
    {
        cpu = this->CPU_frequency - a.CPU_frequency;
		cout << "Частота процессора ноутбука " << this->model << " больше частоты процессора ноутбука " << a.model << " на " << cpu << " гц." << endl;
    }
    if (this->CPU_frequency < a.CPU_frequency)
    {
        cpu = a.CPU_frequency - this->CPU_frequency;
		cout << "Частота процессора ноутбука " << a.model << " больше частоты процессора ноутбука " << this->model << " на " << cpu << " гц." << endl;
    }
    if (this->RAM_size == a.RAM_size)
    {

        cout << "Частоты процессоров ноутбуков совпадают и = " << this->CPU_frequency<< " гц." << endl;
    }
    // сравниваем по цене
    if (this->price > a.price)
    {
        price = this->price - a.price;
		cout << "Цена ноутбука " << this->model << " больше цены ноутбука " << a.model << " на " << price << " р." << endl;
    }
    if (this->price < a.price)
    {
        price = a.price - this->price;
		cout << "Цена ноутбука " << a.model << " больше цены ноутбука " << this->model << " на " << price << " р." << endl;
    }
    if (this->price == a.price)
    {

        cout << "Цены ноутбуков совпадают и = " << this->price<<" р." << endl;
    }
    // сравниваем по году выпуска
    if (this->year > a.year)
    {
        year = this->year - a.year;
		cout << "Год выпуска ноутбука " << this->model << " позже года выпуска ноутбука " << a.model << " на " << year << " г." << endl;
    }
    if (this->year < a.year)
    {
        year = a.year - this->year;
		cout << "Год выпуска ноутбука " << a.model << " позже года выпуска ноутбука " << this->model << " на " << year << " г." << endl;
    }
    if (this->year == a.year)
    {

        cout << "Годы выпуска ноутбуков совпадают и = " << this->year <<" г." << endl;
    }
}

void init(laptop a)
{
	string model = "";
	int cpu = 0, ram = 0, year = 0;
	double price = 0;
	cout << "Введите модель ноутбука: " << endl;
	cin >> model;
	cout << "Объем оперативной памяти(гб): " << endl;
	cin >> ram;
	cout << "Введите частоту процессора: " << endl;
	cin >> cpu;
	cout << "Введите стоимость ноутбука: " << endl;
	cin >> price;
	cout << "Введите год производства ноутбука: " << endl;
	cin >> year;
	a.set_laptop(model, ram, cpu, price, year);
}


int main()
{
	system("color f0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	
	laptop obj1;
	laptop obj2("Asus NITRO 5", 8, 3500, 75000, 2020);		
	obj1.set_laptop("Asus Zenbook", 4, 2500, 42000, 2017);

	
	obj1.print_laptop();		
	obj2.print_laptop();
	obj1.add_price(obj2);
	obj1.compare_laptop(obj2);	
	laptop* obj3 = new laptop;
	obj3->set_laptop("Asus NITRO 6", 16, 4500, 100000, 2023);
	obj3->print_laptop();
	delete obj3;
	cout << "Введите количество ноутбуков"<<endl;
	int n;
	cin >> n;
	laptop* newpart = new laptop[n];
	for (int i = 0; i < n; i++)
	{
		cout <<"Адрес ноутбука № "<<i+1<<" "<< &newpart[i]<<endl;
	}
	delete[] newpart;

	
	return 0;

}

