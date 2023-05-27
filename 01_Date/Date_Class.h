#pragma once
class Date
{

	int day;
	int month;
	int year;

public:

	Date();
	Date(int _day, int _month, int _year);

	void set(int _day, int _month, int _year);

	void next_year();
	void next_month();

	void prev_year();
	void prev_month();

	int prev_month_days();

	Date operator=(const Date& _date);

	int GetDay();
	int GetMonth();
	int GetYear();

	Date operator+(int _days);
	Date operator-(int _days);

	int operator-(const Date& _date);
};

