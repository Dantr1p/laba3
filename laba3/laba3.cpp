
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <malloc.h>

using namespace std;
#define N 30
class Laptop
{
private:
	string model;	//модель ноутбука
	int RAM_size;// объем оперативной памяти
	int CPU_frequency; //частота процессора
	double price;// цена ноутбука
	int year;// Год производства
public:
	Laptop()
	{
		model = "";
		RAM_size = 0;
		CPU_frequency = 0;
		price = 0;
		year = 0;
	}
	Laptop(string model, int ram, int cpu, double price, int year)
	{
		this->model = model;
		RAM_size = ram;
		CPU_frequency = cpu;
		this->price = price;
		this->year = year;
	}
	~Laptop()
	{

	};
	void set_laptop(string model, int ram, int cpu, double price, int year)
	{
		this->model = model;
		RAM_size = ram;
		CPU_frequency = cpu;
		this->price = price;
		this->year = year;
	};
	void print_laptop()
	{
		cout << "Модель ноутбука: " << model << endl;
		cout << "Объем оперативной памяти: " << RAM_size << endl;
		cout << "Частота процессора: " << CPU_frequency << endl;
		cout << "Цена ноутбука: " << price << endl;
		cout << "Год производства: " << year << endl;
	};
	string getmodel()
	{
		return model;
	};
	int getram()
	{
		return RAM_size;
	};
	int getcpu()
	{
		return CPU_frequency;
	};
	int getyear()
	{
		return year;
	};
	double getprice()
	{
		return price;
	};
};



class Shop
{
	//Поля объекта
private:
	string name;
	int n;
	double cash = 0;
	Laptop laptop[N];
	//Методы объекта
public:
	Shop()
	{
		name = "Обычный магазин";
		n = 0;
		cash = 0;
	};	
	
	Shop(string name, int n,int cash, Laptop laptop[N])
	{	
		this->name = name;
		this->n = n;
		this->cash = cash;
		for (int i = 0; i < n; i++)
		{
			this->laptop[i] = laptop[i];
		}		
	};

	Shop(string name, int n, int cash, Laptop laptop)
	{
		int i = 0;
		this->name = name;
		this->n = n;
		this->cash = cash;		
		this->laptop[i] = laptop;		
	};
	Laptop getlaptop(int n)
	{
		return laptop[n];
	}
	double getprice(int i)
	{
		return laptop[i].getprice();		
	}
	int getcpu(int i)
	{
		return laptop[i].getcpu();
	}
	int getram(int i)
	{
		return laptop[i].getram();
	}
	int getyear(int i)
	{
		return laptop[i].getyear();
	}
	string getmodel(int i)
	{
		return laptop[i].getmodel();
	}
	~Shop()
	{	
	};

	void set_Shop(string name, int n, int cash, Laptop laptop[])
	{
		this->name = name;
		this->n = n;
		this->cash = cash;
		for (int i = 0; i < N; i++)
		{
			this->laptop[i] = laptop[i];
		}
	};

	void print_shop(int n)
	{
		cout << "Название магазина: " << name << endl;
		cout << "Количество моделей ноутбуков: " << n << endl;
		cout << "Средства: " << cash << endl;
		cout << "Модели: " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ": " << laptop[i].getmodel() <<" Цена: "<<laptop[i].getprice() << endl;
		}
		cout << endl;
	}

	int purchase()
	{
		cout << "\tПокупаем ноутбук" << endl;
		Laptop a;
		string model;
		int ram, cpu, year;
		double price;
		cout << "Введите характеристики нового ноутбука" << endl;
		cout << "Модель: ";
		cin >> model;
		cout << "Объем оперативной памяти: ";
		cin >> ram;
		cout << "Частота процессора: ";
		cin >> cpu;
		cout << "Цена ноутбука: ";
		cin >> price;
		cout << "Год производства: ";
		cin >> year;
		a.set_laptop(model, ram, cpu, price*1.1, year);
		this->laptop[n]=a;
		n = n + 1;
		cash = cash - price;
		cout << endl;
		return n;
		
	};
	int sale(int n)
	{
		cout << "\tПродаем" << endl;
		for (int i = 0; i <= n; i++)
		{
			cash += this->getprice(i);
			n -= 1;
			cout << this->getmodel(i) <<" продан!" << endl;
		}
		n = 0;
		cout << endl;
		return n;
	}
};


void add_price(Shop* a, int n)
{
	double sumprice = 0;
	for (int i = 0; i < n; i++)
	{
		sumprice = sumprice + a->getprice(i);
	}
	cout << "Суммарная цена=" << sumprice<< endl;	
}
void add_price(Laptop a1, Laptop a2)
{
	cout << "Суммарная цена=" << a1.getprice() + a2.getprice() << endl;
}
void compare(Shop* a, int  n)
{
    
	cout << "*******************************"<<endl;
	for (int i = 0; i < n; i++)
	{
		
		cout << "Модель ноутбука: " << a->getmodel(i) << endl;
	}
	cout << "*******************************";
	double maxprice = a->getprice(0);
	double minprice = a->getprice(0);

	int maxcpu = a->getcpu(0);
	int mincpu = a->getcpu(0);

	int maxram = a->getram(0);
	int minram = a->getram(0);

	int maxyear = a->getyear(0);
	int minyear = a->getyear(0);
	
	for (int i = 0; i < n; i++)
	{
		if (a->getprice(i) > maxprice)
			maxprice = a->getprice(i);
		
		if (a->getprice(i) < minprice)
			minprice = a->getprice(i);
	}

	for (int i = 0; i < n; i++)
	{
		if (a->getcpu(i) > maxcpu)
			maxcpu = a->getcpu(i);

		if (a->getcpu(i) < mincpu)
			mincpu = a->getcpu(i);
	}

	for (int i = 0; i < n; i++)
	{
		if (a->getram(i) > maxram)
			maxram = a->getram(i);

		if (a->getram(i) < minram)
			minram = a->getram(i);
	}

	for (int i = 0; i < n; i++)
	{
		if (a->getyear(i) > maxyear)
			maxyear = a->getyear(i);

		if (a->getyear(i) < minyear)
			minyear = a->getyear(i);
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

void compare(Laptop a1, Laptop a)
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

/*void init(Laptop a)
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
}*/


int main()
{
	system("color f0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 1;
	double cash = 0;
	cout << "\tРабота со статическим объектом" << endl;
	Laptop lap1("Acer", 4, 2500, 35000, 2015);
	cash = lap1.getprice() + cash;
	Shop store("DND", 1, 0, lap1);
	store.print_shop(n);
	n=store.purchase();	
	store.print_shop(n);
	add_price(store.getlaptop(0), store.getlaptop(1));
	compare(store.getlaptop(0), store.getlaptop(1));
	n=store.sale(n);
	store.print_shop(n);

	
	cout  <<endl << "\n\tРабота с динамическими объектами!" << endl;
	n = 1;
	Laptop* lap2 = new Laptop("Samsung",8,3500, 80000, 2019);
		Shop* store1 = new Shop("Svideo", 1, 0, lap2);
	store1->print_shop(n);
	n=store1->purchase();
	store1->print_shop(n);
	add_price(store1->getlaptop(0), store1->getlaptop(1));
	compare(store1->getlaptop(0), store1->getlaptop(1));
	n=store1->sale(n);
	store1->print_shop(n);
	delete lap2;
	delete store1;
	
	cout << endl << "\n\tРабота с массивом статических объектов!" << endl;
	Laptop lap3[N];
	cout<<"Введите количество ноутбуков: "<< endl;
	cin >> n;
	for (int i = 0; i < n; i++)
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
	lap3[i].set_laptop(model, ram, cpu, price, year);
	}	
	Shop* store2= new Shop("DNM", n, 0, lap3);
	store2->print_shop(n);
	n=store2->purchase(); //
	store2->print_shop(n);
	add_price(store2, n);
	compare(store2, n);
	n=store2->sale(n+2);
	store2->print_shop(n);	
	delete store2;

	cout << endl << "\n\tРабота с массивом динамических объектов!" << endl;
	cout << "Введите количество ноутбуков: " << endl;
	cin >> n;
	Laptop* lap4 = new Laptop[n];
	for (int i = 0; i < n; i++)
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
		lap4[i].set_laptop(model, ram, cpu, price, year);
	}	
	Shop store3("RG22", n, 20000, lap4);
	store3.print_shop(n);
	n=store3.purchase();
	store3.print_shop(n);
	add_price(&store3, n);
	compare(&store3, n);
	n=store3.sale(n+2);
	store3.print_shop(n);
	delete[] lap4;	
	_getch();
}

