#include <iostream>
#include <Windows.h>
#include <ctime>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iterator>

using namespace std;

struct MyStruct
{
	string FIO;
	string E_mail;
	int number_purchases;
	int purchase_amount;
};

void my_sort(vector<MyStruct>& f)
{
	for (int i = 0; i < f.size() - 1; i++)
	{
		for (int j = i; j < f.size(); j++)
		{
			if (f[i].number_purchases < f[j].number_purchases)
				swap(f[i], f[j]);
		}
	}
}

string my_find(vector<MyStruct>& f, int find_int)
{
	for (int i = 0; i < f.size(); i++)
	{
		if (f[i].number_purchases == find_int)
		{
			return f[i].FIO;
		}
	}
}

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int n = 1000;
	MyStruct new_str;
	vector<MyStruct> f(n);
	vector<MyStruct> s(n);
	for (int i = 0; i < n; i++)
	{
		f[i].FIO = "";
		f[i].FIO += (char)(65 + rand() % 25);
		f[i].FIO += (char)(65 + rand() % 25);
		f[i].FIO += (char)(65 + rand() % 25);
		s[i].FIO = f[i].FIO;
		s[i].number_purchases = f[i].number_purchases = rand() % 1000;
		s[i].purchase_amount = f[i].purchase_amount = rand() % 100;
	}

	/*for (int i = 0; i < f.size(); i++)
	{
		cout << endl << f[i].FIO << endl;
		cout<< f[i].number_purchases << endl;
		cout << f[i].purchase_amount << endl;
	}*/


	//Стандартная сортировка
	auto start = chrono::high_resolution_clock::now();
	auto comp = [](MyStruct& f, MyStruct& s) {
		return f.number_purchases > s.number_purchases;
	};
	sort(f.begin(), f.end(), comp);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "Стандартная сортировка: " << duration.count() << endl;

	//Моя сортировка
	start = chrono::high_resolution_clock::now();
	my_sort(s);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Моя сортировка: " << duration.count() << endl;

	cout << endl << endl;
	int cm = rand() % 1000;


	//Стандартный поиск
	start = chrono::high_resolution_clock::now();
	vector<MyStruct>::iterator it;
	it = find_if(f.begin(), f.end(),
		[&cm](const MyStruct& m) -> bool
		{ return cm == m.number_purchases; }
	);
	cout << "Элемент найден: " << it._Ptr->FIO << endl;
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Стандартный поиск: " << duration.count() << endl;

	//Мой поиск
	start = chrono::high_resolution_clock::now();
	cout << "Элемент найден: " << my_find(f, cm) << endl;
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Мой поиск: " << duration.count() << endl;
	/*for (int i = 0; i < f.size(); i++)
	{
		cout << f[i].FIO << " " << s[i].FIO << endl;
		cout << f[i].number_purchases << " " << s[i].number_purchases << endl;
	}*/
	/*for (int i = 0; i < f.size(); i++)
	{
		cout << endl << f[i].FIO << endl;
		cout << f[i].number_purchases << endl;
		cout << f[i].purchase_amount << endl;
	}*/

}