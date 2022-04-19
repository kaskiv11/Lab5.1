/*
Сформувати файл даних, компонентами якого є цілі числа.
Записати в інший файл даних максимальну непарну компоненту і мінімальну парну компоненту.
Вивести на екран вміст результуючого файлу.
*/
#include <iostream>
#include <fstream>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(const char* fName)
{
	srand((unsigned)time(NULL));
	ofstream f(fName, ios::binary);
	int x;
	for (int i = 0; i < 10; i++)
	{
		x = -10 + rand() % 21;
		f.write((char*)&x, sizeof(x));
	}
}

void Print(const char* fName)
{
	cout << endl << "\nfile \"" << fName << "\":\n";
	ifstream f(fName, ios::binary);
	int x;
	while (f.read((char*)&x, sizeof(x)))
		cout << x << " ";
	cout << endl;
}

void ProcessBin(const char* fname, const char* gname) {
	ifstream f(fname, ios::binary);
	ofstream g(gname, ios::binary);
	int c;
	f.read((char*)&c, sizeof(c));
	int max = c, min = c;
	while (f.read((char*)&c, sizeof(c))) {
		if ((max % 2 == 0 && c % 2 != 0) || (c % 2 != 0 && c > max)) {
			max = c;
		}
		if ((min % 2 != 0 && c % 2 == 0) || (c % 2 == 0 && c < min)) {
			min = c;
		}
	}
	g.write((char*)&min, sizeof(min));
	g.write((char*)&max, sizeof(max));
	f.close();
	g.close();
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char f[6] = "f.dat";
	char g[6] = "g.dat";
	Create(f);
	Print(f);
	ProcessBin(f, g);
	Print(g);


	cin.get();
	return 0;
}