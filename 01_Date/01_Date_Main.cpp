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
		cout << "�������� ��������:" << endl << "1. ���� ���� (������: dd mm yyyy)" << endl << "2. ��������" << endl << "3. ���������" << endl << "4. ��������� � ����������� � ����" << endl << "5. �����" << endl;
		cin >> switcher;
		switch (switcher)
		{
		case 1:
			// ���� ����
		{
			cout << endl << "1. ���� ����" << endl << "������� ����: ";
			cin >> day >> month >> year;
			date.set(day, month, year);
			break;
		}
		case 2:
			//�������� ��������
		{
			int days = 0;
			cout << endl << "2. ��������" << endl << "������� ���: ";
			cin >> days;
			date + days;
			break;
		}
		case 3:
			//�������� ���������
		{
			int days = 0;
			cout << endl << "3. ���������" << endl << "������� ���: ";
			cin >> days;
			date - days;
			break;
		}
		case 4:
		{
			//��������� � ����������� � ����
			cout << endl << "4. ��������� � ����������� � ����" << endl << "������� ���� (������: dd mm yyyy): ";
			cin >> day >> month >> year;
			Date NewDate(day, month, year);
			int result = date - NewDate;
			cout << "������� ���� = " << result << endl;
			break;
		}
		case 5:
		{
			cout << endl << "5. �����" << endl;
			switcher = 0;
			break;
		}
		}
		cout << endl << "���� ����: " << date.GetDay() << "." << date.GetMonth() << "." << date.GetYear() << endl << endl;
	}
	return 0;
}