#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

int  Menu();
string writeWords();
double writeNumbers();

class Programmirovanie {
protected:
	string education;
	string special;
public:
	Programmirovanie()
	{};
	Programmirovanie(string e, string s) {
		education = e;
		special = s;
	}
	void printInf()
	{
		cout << "Образование: " << education << endl;
		cout << "Спецификация программироания: " << special << endl;
	}
	void Name()
	{
		cout << "\nПрограммирование:\n" << endl;
	}
	~Programmirovanie();
};

class Courses :virtual public Programmirovanie {
protected:
	string language;
	int amount_of_hours;
	double rating;

public:
	Courses(string e, string s, int ho, double rt, string l) :Programmirovanie(e, s)
	{

		amount_of_hours = ho;
		language = l;
		rating = rt;
	}
	Courses()
	{
		amount_of_hours = 0;
		rating = 0;
	};
	void printInf()
	{
		cout << "Количество пройденных на курсах часов : " << amount_of_hours << endl;
		cout << "Языки программирования: " << language << endl;
		cout << "Общий средний рейтинг со всех курсов: " << rating << endl;
	}
	void Name()
	{
		cout << "\nКурсы программирования:\n" << endl;
	}
	~Courses();
};

class Man:virtual public Programmirovanie {
protected:
	string name;
	string surname;
	int age;

public:
	Man()
	{
		age = 0;
	};
	Man(string e, string s, string nm, string sm, int ag) :Programmirovanie(e, s)
	{
		name = nm;
		surname = sm;
		age = ag;
	}
	void printInf()
	{
		cout << "Имя : " << name << endl;
		cout << "Фамилия: " << surname << endl;
		cout << "Возраст: " << age << endl;
	}
	void Name()
	{
		cout << "\nДанные человека:\n" << endl;
	}
	~Man();
};

class Work :public Courses, public Man {
private:
	string name_of_company;
	int projects;


public:
	Work()
	{
		projects = 0;
	};
	Work(string e, string s, int ho, double rt, string l, string nm, string sm, int ag, string co, int pr) :Courses(e, s, ho, rt, l), Man(e, s, nm, sm, ag)
	{
		name_of_company = co;
		projects = pr;
	}
	void printWorkInf()
	{
		Programmirovanie::printInf();
		Courses::printInf();
		Man::printInf();
		cout << "Название компании: " << name_of_company << endl;
		cout << "Количество текущих и планируемых проектов: " << projects << endl;
	}
	void Name()
	{
		cout << "\nДанные работника:\n" << endl;
	}
	~Work();
};
Programmirovanie::~Programmirovanie()
{

}
Courses::~Courses()
{

}
Man::~Man()
{

}
Work::~Work()
{

}

int Menu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {

		choose_menu = (choose_menu + 3) % 3;

		if (choose_menu == 0) { cout << " -> Ввод данных" << endl; }
		else { cout << " Ввод данных" << endl; }

		if (choose_menu == 1) { cout << " -> Просмотр данных" << endl; }
		else { cout << " Просмотр данных" << endl; }

		if (choose_menu == 2) { cout << " -> Выход" << endl; }
		else { cout << " Выход" << endl; }

		

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int main() {
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string e, s, l, nm, sm, co;
	int ho, ag, pr,n=0;
	double rt;
	Work* mas = new Work[n];
	while (true) {
		int choose = Menu();
		if (choose == 0)
		{
			cout << "Имя: ";
			nm = writeWords();
			cout << endl;
			cout << "Фамилия: ";
			sm = writeWords();
			cout << endl;
			cout << "Возраст: ";
			ag = writeNumbers();
			cout << endl;
			cout << "Название компании: ";
			co = writeWords();
			cout << endl;
			cout << "Образование: ";
			e = writeWords();
			cout << endl;
			cout << "Спецификация программирования: ";
			s = writeWords();
			cout << endl;
			cout << "Количество пройденных на курсах часов: ";
			ho = writeNumbers();
			cout << endl;
			cout << "Пройденные языки программирования: ";
			l = writeWords();
			cout << endl;
			cout << "Общий средний реётинг по всем курсам: ";
			rt = writeNumbers();
			cout << endl;
			cout << "Количество планируемых и текущих проектов: ";
			pr = writeNumbers();
			Work worker(e, s, ho, rt, l, nm, sm, ag, co, pr);
			Work* mas1 = new Work[n + 1];
			copy(mas, mas + n, mas1);
			mas1[n] = worker;
			n++;
			delete[]mas;
			mas = mas1;
		}
		else
			if (choose == 1)
			{
				if (n == 0) 
				{
				 cout << "Отсутствуют данные" << endl;
				}
				else {
					for (int i = 0; i < n; i++) {
						mas[i].Name();
						mas[i].printWorkInf();
					}


				}

			}
			else break;
	}
	delete[]mas;
	return 0;
}

string writeWords()
{
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z') || (sumbol >= 'а' && sumbol <= 'я') || (sumbol >= 'А' && sumbol <= 'Я') || sumbol == ' ' || sumbol == '+') {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

double writeNumbers() {
	string numbers;
	while (true) {
		double key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9' || key == ',') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stod(numbers);
}