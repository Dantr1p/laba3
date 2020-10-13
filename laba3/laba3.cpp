
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <malloc.h>

using namespace std;
#define N 20
class Shop
{
	//Поля объекта
private:
	string name;
	int n;
	int cash = 0;
	Laptop laptop;
	//Методы объекта
public:
	Shop()
	{
		name = "Обычный магазин";
		n = 0;
		cash = 0;
	};
	Shop(string name, int n,int cash, Laptop laptop)
	{
		this->name = name;
		this->n = n;
		this->cash = cash;
		this->laptop = laptop;
	};
	~Shop()
	{	
	};


};
class Laptop
{
private:
	string model;	//модель ноутбука
	int RAM_size;// объем оперативной памяти
	int CPU_frequency; //частота процессора
	double price;// цена ноутбука
	int year;// Год производства
public:
	Laptop();
	Laptop(string model, int ram, int cpu, double price, int year);
	~Laptop();
	void set_laptop(string model, int ram, int cpu, double price, int year);
	void print_laptop();	
	string getmodel();
	int getram();
	int getcpu();
	int getyear();
	double getprice();
};

Laptop::Laptop()
{
	model = "";
	RAM_size = 0;
	CPU_frequency = 0;
	price = 0;
	year = 0;
}

Laptop::Laptop(string model, int ram, int cpu, double price, int year)
{
	this->model = model;
	RAM_size = ram;
	CPU_frequency = cpu;
	this->price = price;
	this->year = year;
}

Laptop::~Laptop()
{
	
}

void Laptop::set_laptop(string model, int ram, int cpu, double price, int year)
{
	this->model = model;
	RAM_size = ram;
	CPU_frequency = cpu;
	this->price = price;
	this->year = year;
}

void Laptop::print_laptop()
{
	cout << "Модель ноутбука: " << model << endl;
	cout << "Объем оперативной памяти: " << RAM_size << endl;
	cout << "Частота процессора: " << CPU_frequency << endl;
	cout << "Цена ноутбука: " << price << endl;
	cout << "Год производства: " << year << endl;

}

string Laptop::getmodel()
{
	return model;
}

int Laptop::getram()
{
	return RAM_size;
}

int Laptop::getcpu()
{
	return CPU_frequency;
}

int Laptop::getyear()
{
	return year;
}

double Laptop::getprice()
{
	return price;
}

void add_price(Laptop a[],int n)
{
	double sumprice = 0;
	for (int i = 0; i < n; i++)
	{
		sumprice =  sumprice +a[i].getprice();
	}
	cout << "Суммарная цена=" << sumprice<< endl;	
}

void compare_laptop(Laptop a[],int  n)
{
    
	cout << "*******************************"<<endl;
	for (int i = 0; i < n; i++)
	{
		
		cout << "Модель ноутбука: " << a[i].getmodel() << endl;
	}
	cout << "*******************************";
	double maxprice = a[0].getprice();
	double minprice = a[0].getprice();

	int maxcpu = a[0].getcpu();
	int mincpu = a[0].getcpu();

	int maxram = a[0].getram();
	int minram = a[0].getram();

	int maxyear = a[0].getyear();
	int minyear = a[0].getyear();
	
	for (int i = 0; i < n; i++)
	{
		if (a[i].getprice() > maxprice)		
			maxprice = a[i].getprice();	
		
		if (a[i].getprice() < minprice) 
			minprice = a[i].getprice(); 
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i].getcpu() > maxcpu)
			maxcpu = a[i].getcpu();

		if (a[i].getcpu() < mincpu)
			mincpu = a[i].getcpu();
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i].getram() > maxram)
			maxram = a[i].getram();

		if (a[i].getram() < minram)
			minram = a[i].getram();
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i].getyear() > maxyear)
			maxyear = a[i].getyear();

		if (a[i].getyear() < minyear)
			minyear = a[i].getyear();
	}

	cout << "Самый дорогой ноутбук стоит " <<maxprice<<" р."<<endl;
	cout << "Самый дешевый ноутбук стоит " << minprice << " р." << endl;

	cout << "Самая большая оперативная память среди ноутбуков " << maxram << " гб." << endl;
	cout << "Самая маленькая оперативная память среди ноутбуков " << minram << " гб." << endl;

	cout << "Самая большая частота процессора среди ноутбуков " << maxcpu << " гц." << endl;
	cout << "Самая маленькая частота процессора среди ноутбуков " << mincpu << " гц." << endl;

	cout << "Самый новый ноутбук " << maxyear << " г." << endl;
	cout << "Самый старый ноутбук " << minyear << " г." << endl;
}

void compare2(Laptop a1, Laptop a)
{
	int ram, cpu, year;
	double price;
	
	cout << "Сравниваем ноутбуки " << a1.getmodel() << " и " << a.getmodel() << endl;
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
		price = a1.getprice() - a.getprice();
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

void init(Laptop a)
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

	Laptop lapstart("model", 0, 0, 0, 0);
	
	
	int n = 20;	
	Laptop lap[N];   //статическое
	Laptop* lap2 = new Laptop[n];    //динамическое
	
	
	
	string model;
	int ram=0, cpu=0, year=0;
	double price=0;
	do {
		system("cls");
		cout << "MENU" << endl;
		cout << "1. Заполнить данные о ноутбуках(static)" << endl;
		cout << "2. Вывести данные (static)" << endl;
		cout << "3. Подсчитать стоимость ноутбуков(static)" << endl;
		cout << "4. Сравнить два ноутбука(static)" << endl;
		cout << "5. Сравнить все ноутбуки (max, min)(static)" << endl;
		cout << "6. Ввести данные (dynamic)" << endl;
		cout << "7. Вывести данные(dynamic)" << endl;
		cout << "8. Подсчитать стоимость ноутбуков(dynamic)" << endl;
		cout << "9. Сравнить два ноутбука(dynamic)" << endl;
		cout << "0. Сравнить все ноутбуки (max, min)(dynamic)" << endl;
		cout << "Backspace. Выход" << endl;
		cout << "В какой пункт хотите перейти?" << endl;
		switch (_getch())
		{
		case 49:
		{
			system("cls");
			lapstart.print_laptop();
			cout << "Введите количество ноутбуков" << endl;
			cin >> n;						
			for (int i = 0; i < n; i++)
			{
				cout << "Введите модель: "  << endl;
				cin >> model;
				cout << "Введите объем оперативной памяти: " << endl;
				cin >> ram;
				cout << "Введите частоту процессора: "  << endl;
				cin >> cpu;
				cout << "Введите цену: "  << endl;
				cin >> price;
				cout << "Введите год производства: "  << endl;
				cin >> year;
				lap[i].set_laptop(model, ram, cpu, price, year);
			}
			break;
		}
		case 50:
		{
			system("cls");
			for (int i = 0; i < n; i++)
			{
				lap[i].print_laptop();
			}

			break;
		}
		case 51:
		{
			system("cls");
			add_price(lap, n);
			break;
		}
		case 52:
		{
			int n1, n2;
			system("cls");
			cout << "Укажите номер первого ноутбука:";
			cin >>  n1;
			cout << "Укажите номер второго ноутбука:";
			cin >> n2;
			compare2(lap[n1-1], lap[n2-1]);
			break;
		}
		case 53:
		{
			system("cls");
			compare_laptop(lap, n);
			break;
		}
		case 54:
		{
			system("cls");
			cout << "Введите количество ноутбуков" << endl;
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "Введите модель: " << endl;
				cin >> model;
				cout << "Введите объем оперативной памяти: " << endl;
				cin >> ram;
				cout << "Введите частоту процессора: " << endl;
				cin >> cpu;
				cout << "Введите цену: " << endl;
				cin >> price;
				cout << "Введите год производства: " << endl;
				cin >> year;
				lap2[i].set_laptop(model, ram, cpu, price, year);
			}
			break;
		}
		case 55:
		{
			system("cls");
			for (int i = 0; i < n; i++)
			{
				lap2[i].print_laptop();
			}
		}
		case 56:
		{
			system("cls");
			add_price(lap2, n);
			break;
		}
		case 57:
		{
			int n1, n2;
			system("cls");
			cout << "Укажите номер первого ноутбука:";
			cin >> n1;
			cout << "Укажите номер второго ноутбука:";
			cin >> n2;
			compare2(lap2[n1 - 1], lap2[n2 - 1]);
			break;
		}
		case 48:
		{
			system("cls");
			compare_laptop(lap2, n);
			break;
		}
		case 8:
			goto exit;
		default:
			system("cls");
			cout << "Вы выбрали несуществующий вариант" << endl;
			cout << "Если хотите выйти, то нажмите ESC. В противном случае перейдёте в MENU" << endl;
			break;
		}
	} while (_getch() != 27);
exit:
	
	delete[] lap;
	delete[] lap2;
	Laptop* buffer1 = (Laptop*)malloc(10 * sizeof(Laptop)),      // выделяем память под 10 элементов массива типа int, с предварительной инициализацией   
	* buffer2 = (Laptop*)calloc(10, sizeof(Laptop)),        // выделяем память под 10 элементов массива типа int, без инициализации
	* buffer3 = (Laptop*)realloc(buffer2, 50 * sizeof(Laptop));// перераспределить память в блоке buffer2, новый размер блока - 50 элементов
	free(buffer1);                                              // высвобождаем блок памяти buffer1
	free(buffer3);
	return 0;

}

