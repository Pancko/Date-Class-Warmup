#include "Date_Class.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int day = 0;
	int month = 0;
	int year = 0;
	int switcher = 1;
	Date date;

	while (switcher != 0)
	{
		cout << "Выберете действие:" << endl << "1. Ввод даты (формат: dd mm yyyy)" << endl << "2. Сложение" << endl << "3. Вычитание" << endl << "4. Вычитание с результатом в днях" << endl << "5. Выйти" << endl;
		cin >> switcher;
		switch (switcher)
		{
		case 1:
			// Ввод даты
		{
			cout << endl << "1. Ввод даты" << endl << "Введите дату: ";
			cin >> day >> month >> year;
			date.set(day, month, year);
			break;
		}
		case 2:
			//Бинарное сложение
		{
			int days = 0;
			cout << endl << "2. Сложение" << endl << "Введите дни: ";
			cin >> days;
			date + days;
			break;
		}
		case 3:
			//Бинарное вычитание
		{
			int days = 0;
			cout << endl << "3. Вычитание" << endl << "Введите дни: ";
			cin >> days;
			date - days;
			break;
		}
		case 4:
		{
			//Вычитание с результатом в днях
			cout << endl << "4. Вычитание с результатом в днях" << endl << "Введите дату (формат: dd mm yyyy): ";
			cin >> day >> month >> year;
			Date NewDate(day, month, year);
			int result = date - NewDate;
			cout << "Разница дней = " << result << endl;
			break;
		}
		case 5:
		{
			cout << endl << "5. Выйти" << endl;
			switcher = 0;
			break;
		}
		}
		cout << endl << "Ваша дата: " << date.GetDay() << "." << date.GetMonth() << "." << date.GetYear() << endl << endl;
	}
	return 0;
}