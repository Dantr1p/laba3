
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
	string getmodel();
	int getram();
	int getcpu();
	int getyear();
	double getprice();
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

string laptop::getmodel()
{
	return string();
}

int laptop::getram()
{
	return RAM_size;
}

int laptop::getcpu()
{
	return CPU_frequency;
}

int laptop::getyear()
{
	return year;
}

double laptop::getprice()
{
	return price;
}

void add_price(laptop a[],int n)
{
	double sumprice = 0;
	for (int i = 0; i < n; i++)
	{
		sumprice =  sumprice +a[i].getprice();
	}
	cout << "Суммарная цена=" << sumprice<< endl;	
}

void compare_laptop(laptop a[],int  n)
{
    int ram, cpu, year;
    double price;
	for (int i = 0; i < n; i++)
	{
		cout << "*******************************";
		cout << "Сравниваем ноутбуки " << a[i].getmodel() << endl;
	}
	cout << "*******************************";
    
}

void compare2(laptop a1, laptop a)
{
	if (a1.getram() > a.getram())
	{
		ram = a1.getram() - a.getram();
		cout << "Оперативная память ноутбука " << a1.getmodel() << " больше оперативной памяти ноутбука " << a.getmodel() << " на " << ram << " гб." << endl;
	}
	if (a1.getram() < a.getram())
	{
		ram = a.getram() - a1.getram();
		cout << "Оперативная память ноутбука " << a.getmodel() << " больше оперативной памяти ноутбука " << a1.getmodel() << " на " << ram << " гб." << endl;
	}
	if (a1.getram() == a.getram())
	{

		cout << "Оперативная память ноутбуков совпадает и = " << a.getram() << " гб." << endl;
	}
	// сравниваем по частоте
	if (a1.getcpu() > a.getcpu())
	{
		cpu = a1.getcpu() - a.getcpu();
		cout << "Частота процессора ноутбука " << a1.getmodel() << " больше частоты процессора ноутбука " << a.getmodel() << " на " << cpu << " гц." << endl;
	}
	if (a1.getcpu() < a.getcpu())
	{
		cpu = a.getcpu() - a1.getcpu();
		cout << "Частота процессора ноутбука " << a.getmodel() << " больше частоты процессора ноутбука " << a1.getmodel() << " на " << cpu << " гц." << endl;
	}
	if (a1.getram() == a.getram())
	{

		cout << "Частоты процессоров ноутбуков совпадают и = " << a1.getram() << " гц." << endl;
	}
	// сравниваем по цене
	if (a1.getprice() > a.getprice())
	{
		price = a1.price - a.getprice();
		cout << "Цена ноутбука " << a1.getmodel() << " больше цены ноутбука " << a.getmodel() << " на " << price << " р." << endl;
	}
	if (a1.getprice() < a.getprice())
	{
		price = a.getprice() - a1.getprice();
		cout << "Цена ноутбука " << a.getmodel() << " больше цены ноутбука " << a1.getmodel() << " на " << price << " р." << endl;
	}
	if (a1.getprice() == a.getprice())
	{

		cout << "Цены ноутбуков совпадают и = " << a1.getprice() << " р." << endl;
	}
	// сравниваем по году выпуска
	if (a1.getyear() > a.getyear())
	{
		year = a1.getyear() - a.getyear();
		cout << "Год выпуска ноутбука " << a1.getmodel() << " позже года выпуска ноутбука " << a.getmodel() << " на " << year << " г." << endl;
	}
	if (a1.getyear() < a.getyear())
	{
		year = a.getyear() - a1.getyear();
		cout << "Год выпуска ноутбука " << a.getmodel() << " позже года выпуска ноутбука " << a1.getmodel() << " на " << year << " г." << endl;
	}
	if (a1.getyear() == a.getyear())
	{

		cout << "Годы выпуска ноутбуков совпадают и = " << a1.getyear() << " г." << endl;
	}
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

	laptop* buffer1 = (laptop*)malloc(10 * sizeof(laptop)),      // выделяем память под 10 элементов массива типа int, с предварительной инициализацией   
		* buffer2 = (laptop*)calloc(10, sizeof(laptop)),        // выделяем память под 10 элементов массива типа int, без инициализации
		* buffer3 = (laptop*)realloc(buffer2, 50 * sizeof(laptop));// перераспределить память в блоке buffer2, новый размер блока - 50 элементов

	free(buffer1);                                              // высвобождаем блок памяти buffer1
	free(buffer3);

	string model;
	int ram, cpu, year, n;
	double price;
	do {
		system("cls");
		cout << "MENU" << endl;
		cout << "1. Заполнить данные о ноутбуках" << endl;
		cout << "2. Вывести данные" << endl;
		cout << "3. Подсчитать стоимость ноутбуков" << endl;
		cout << "4. Сравнить ноутбуки" << endl;
		cout << "5. " << endl;
		cout << "6. " << endl;
		cout << "7. Выход" << endl;
		cout << "В какой пункт хотите перейти?" << endl;
		switch (_getch())
		{
		case 49:
			system("cls");	
			cout << "Введите количество ноутбуков" << n << endl;
			laptop* lap = new laptop[n];
			for (int i = 0; i < n; i++)
			{
				cout << "Введите модель: " << model << endl;
				cout << "Введите объем оперативной памяти: " << model << endl;
				cout << "Введите частоту процессора: " << model << endl;
				cout << "Введите цену: " << model << endl;
				cout << "Введите год производства: " << model << endl;
				lap[i].set_laptop(model, ram, cpu, price, year);
			}
			break;
		case 50:
			system("cls");
			for (int i = 0; i < n; i++)
			{
				lap[i].print_laptop();
			}
			break;
		case 51:
			system("cls");
			
			break;
		case 52:
			system("cls");
			
			break;
		case 53:
			system("cls");
			
			break;
		case 54:
			system("cls");
			
			break;
		case 55:
			goto exit;
		default:
			system("cls");
			cout << "Вы выбрали несуществующий вариант" << endl;
			cout << "Если хотите выйти, то нажмите ESC. В противном случае перейдёте в MENU" << endl;
			break;
		}
	} while (_getch() != 27);
exit:


	return 0;

}

