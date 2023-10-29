#include <iostream>
#include <string>
#include <cstring>
#include <clocale>
#include <Windows.h>
using namespace std;

enum Kind {Human  = 0 , Cattle = 1, Bird = 2};

struct alive
{	
	string name;
	Kind kind;
	string color;
	double speed;
	union
	{
		double sfly;
		int hooves;
		int iq;
	};
};

alive list[1000];
int power = 0;

void printAlive(int n)
{
	cout << "\n";
	if (n < 0 || n >= power)
	{
		cout << "Такой сущности нет" << "\n";
		return;
	}
	cout << "Номер строки: " << n << "\n";
	cout << "Имя: " << list[n].name << "\n";
	cout << "Вид: ";
	if (list[n].kind == Kind::Human)
	{
		cout << "Человек" << "\n";
		cout << "IQ: " << list[n].iq << "\n";
	}
	if (list[n].kind == Kind::Cattle)
	{
		cout << "Скот" << "\n";
		cout << "Копыт: " << list[n].hooves << "\n";
	}
	if (list[n].kind == Kind::Bird)
	{
		cout << "Птица" << "\n";
		cout << "Скорость полета: " << list[n].sfly << "\n";
	}
	cout << "Цвет: " << list[n].color << "\n";
	cout << "Скорость: " << list[n].speed << "\n";
	cout << "\n";

}

string tolowerstr(string p)
{
	string res = "";
	for (int i = 0; i < p.length(); i++)
	{
		res = res + (char)tolower(p[i]);
	}
	return res;
}

void findByKind(int kind)
{
	for (int i = 0; i < power; i++)
	{
		if (kind == list[i].kind)
		{
			printAlive(i);
		}
	}
}

void findByColor(string color)
{
	for (int i = 0; i < power; i++)
	{
		if (tolowerstr(color) == tolowerstr(list[i].color))
		{
			printAlive(i);
		}
	}
}


void findBySpeed(double speed)
{
	for (int i = 0; i < power; i++)
	{
		if (speed == list[i].speed)
		{
			printAlive(i);
		}
	}
}
void findByFly(double sfly)
{
	for (int i = 0; i < power; i++)
	{
		if  (sfly == list[i].sfly && list[i].kind == Bird)
		{
			printAlive(i);
		}
	}
}

void findByHooves(int hooves)
{
	for (int i = 0; i < power; i++)
	{
		if (hooves == list[i].hooves && list[i].kind == Cattle)
		{
			printAlive(i);
		}
	}
}

void findByIq(int iq)
{
	for (int i = 0; i < power; i++)
	{
		if (iq == list[i].iq && list[i].kind == Human)
		{
			printAlive(i);
		}
	}
}

void setAlive(int item, Kind kind, string name, string color, double speed, double sfly, int hooves, int iq)
{

	list[item].kind = kind;
	list[item].name = name;
	list[item].color = color;
	list[item].speed = speed;
	if (kind == Human)
	{
		list[item].iq = iq;
	}
	if (kind == Cattle)
	{
		list[item].hooves = hooves;
	}
	if (kind == Bird)
	{
		list[item].sfly = sfly;
	}
}

void addAlive(Kind kind, string name, string color, double speed, double sfly, int hooves, int iq)
{
	setAlive(power, kind, name, color,  speed, sfly, hooves, iq);
	power = power + 1;
}



alive inputAlive()
{
	alive a;
	int k;
	cout << "Вид (0 - Человек, 1 - Cкот, 2 - Птица): ";
	cin >> k;
	a.kind = static_cast<Kind>(k);
	cout << "Имя: ";
	cin >>  a.name;
	cout << "Цвет: ";
	cin >> a.color;
	cout << "Скорость: ";
	cin >> a.speed;
	switch (a.kind)
	{
	case Human:
		cout << "IQ: ";
		cin >> a.iq;
		break;
	case Bird:
		cout << "Скорость полета: ";
		cin >> a.sfly;
		break;
	case Cattle:
		cout << "Копыт: ";
		cin >> a.hooves;
		break;
	}
	
	return a;
}

void printAll()
{
	for (int i = 0; i < power; i++)
	{
			printAlive(i);
	}
}



int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	addAlive(Kind::Human, "Джон", "Белый", 6, 0, 2, 100);
	addAlive(Kind::Human, "Билл", "Черный", 6, 0, 2, 100);
	addAlive(Kind::Cattle, "Cвинья", "Розовая", 10, 0, 4, 0);
	addAlive(Kind::Cattle, "Корова", "Бурая", 11, 0, 4, 0);
	addAlive(Kind::Bird, "Орел", "Черный", 7, 50, 2, 30);
	addAlive(Kind::Human, "Вика", "Белый", 7, 0, 2, 90);
	addAlive(Kind::Human, "Аня", "Черный", 7, 0, 2, 120);
	addAlive(Kind::Cattle, "Коза", "Серый", 10, 0, 4, 0);
	addAlive(Kind::Bird, "Курица", "Рыжий", 11, 0, 2, 0);
	addAlive(Kind::Bird, "Воробей", "Серый", 7, 20, 2, 0);

	int pos;
	string req;
	double r;
	int n;
	do
	{
		cout << "Поиск: '1' - Скорость полета, '2' - по копытам, '3' - по iq, '4' - печатать все, '5' добавить новый, '6' - редактирывать, '7' - выйти\n";
		cout << "Ваш выбор: ";
		cin >> pos;
		if (pos == 1)
		{
			cout << "Введите скорость полета: ";
			cin >> r;
			findByFly(r);
		}
		if (pos == 2)
		{
			cout << "Введите количество копыт: ";
			cin >> n;
			findByHooves(n);
		}
		if (pos == 3)
		{
			cout << "Введите количество IQ: ";
			cin >> n;
			findByIq(n);
		}
		if (pos == 4)
		{
			printAll();
		}
		if (pos == 5)
		{

			alive a = inputAlive();
			addAlive(a.kind, a.name, a.color, a.speed, a.sfly, a.hooves, a.iq);
		}
		if (pos == 6)
		{
			int item;
			cout << "Введите номер: ";
			cin >> item;
			alive a = inputAlive();
			setAlive(item, a.kind, a.name, a.color, a.speed, a.sfly, a.hooves, a.iq);
		}		
	} while (pos != 7);
}
