#include "Date_Class.h"

Date::Date()
{
	day = 1;
	month = 1;
	year = 1970;
}

Date::Date(int _day, int _month, int _year)
{
	if ((_year < 1970) || (_year > 2099))
		year = 1970;
	else
		year = _year;

	if ((_month < 1) || (_month > 12))
		month = 1;
	else
		month = _month;

	switch (month)
	{
	case 12:
	case 10:
	case 8:
	case 7:
	case 5:
	case 3:
	case 1:
	{
		if ((_day < 1) || (_day > 31))
			day = 1;
		else
			day = _day;
		break;
	}
	case 11:
	case 9:
	case 6:
	case 4:
	{
		if ((_day < 1) || (_day > 30))
			day = 1;
		else
			day = _day;
		break;
	}
	case 2:
	{
		if (year % 4 == 0)
		{
			if ((_day < 1) || (_day > 29))
				day = 1;
			else
				day = _day;
			break;
		}
		else
		{
			if ((_day < 1) || (_day > 28))
				day = 1;
			else
				day = _day;
			break;
		}
	}
	}
}

void Date::set(int _day, int _month, int _year)
{
	if ((_year < 1970) || (_year > 2099))
		year = 1970;
	else
		year = _year;

	if ((_month < 1) || (_month > 12))
		month = 1;
	else
		month = _month;

	switch (month)
	{
	case 12:
	case 10:
	case 8:
	case 7:
	case 5:
	case 3:
	case 1:
	{
		if ((_day < 1) || (_day > 31))
			day = 1;
		else
			day = _day;
		break;
	}
	case 11:
	case 9:
	case 6:
	case 4:
	{
		if ((_day < 1) || (_day > 30))
			day = 1;
		else
			day = _day;
		break;
	}
	case 2:
	{
		if (year % 4 == 0)
		{
			if ((_day < 1) || (_day > 29))
				day = 1;
			else
				day = _day;
			break;
		}
		else
		{
			if ((_day < 1) || (_day > 28))
				day = 1;
			else
				day = _day;
			break;
		}
	}
	}
}

void Date::next_year()
{
	year++;
	if (year > 2099)
		year = 1970;
}

void Date::next_month()
{
	day = 1;
	month++;
	if (month > 12)
	{
		month = 1;
		this->next_year();
	}
}

void Date::prev_year()
{
	year--;
	month = 12;
	day = 31;
	if (year < 1970)
	{
		year = 1970;
		month = 1;
		day = 1;
	}
}

void Date::prev_month()
{
	month--;
	if (month == 0)
		this->prev_year();
	else
		switch (month)
		{
		case 12:
		case 10:
		case 8:
		case 7:
		case 5:
		case 3:
		case 1:
		{
			day = 31;
			break;
		}
		case 11:
		case 9:
		case 6:
		case 4:
		{
			day = 30;
			break;
		}
		case 2:
		{
			if (year % 4 == 0)
			{
				day = 29;
				break;
			}
			else
			{
				day = 28;
				break;
			}
		}
		}
}

int Date::prev_month_days()
{
	int _prev_month = month - 1;

	if (_prev_month == 0)
		_prev_month = 12;

	switch (_prev_month)
	{
	case 12:
	case 10:
	case 8:
	case 7:
	case 5:
	case 3:
	case 1:
	{
		return 31;
	}
	case 11:
	case 9:
	case 6:
	case 4:
	{
		return 30;
	}
	case 2:
	{
		if (year % 4 == 0)
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	}
}

Date Date::operator=(const Date& _date)
{
	year = _date.year;
	month = _date.month;
	day = _date.day;
	return *this;
}

int Date::GetDay()
{
	return day;
}
int Date::GetMonth()
{
	return month;
}
int Date::GetYear()
{
	return year;
}

Date Date::operator+(int _days)
{
	int days = _days;
	int Difference = 0;

	while (days > 0)
	{
		switch (month)
		{
		case 12:
		case 10:
		case 8:
		case 7:
		case 5:
		case 3:
		case 1:
		{
			Difference = 31 - day;
			days = days - Difference - 1;
			this->next_month();
			break;
		}
		case 11:
		case 9:
		case 6:
		case 4:
		{
			Difference = 30 - day;
			days = days - Difference - 1;
			this->next_month();
			break;
		}
		case 2:
		{
			if (year % 4 == 0)
			{
				Difference = 29 - day;
				days = days - Difference - 1;
				this->next_month();
				break;
			}
			else
			{
				Difference = 28 - day;
				days = days - Difference - 1;
				this->next_month();
				break;
			}
		}
		}
	}

	if (days < 0)
	{
		this->prev_month();
		days++;
		while (days < 0)
		{
			days++;
			day--;
		}
	}

	return *this;
}

Date Date::operator-(int _days)
{
	int days = _days;
	int Difference = 0;

	days = days - day;
	this->prev_month();

	while (days > 0)
	{
		switch (month)
		{
		case 12:
		case 10:
		case 8:
		case 7:
		case 5:
		case 3:
		case 1:
		{
			days = days - 31;
			this->prev_month();
			break;
		}
		case 11:
		case 9:
		case 6:
		case 4:
		{
			days = days - 30;
			this->prev_month();
			break;
		}
		case 2:
		{
			if (year % 4 == 0)
			{
				days = days - 29;
				this->prev_month();
				break;
			}
			else
			{
				days = days - 28;
				this->prev_month();
				break;
			}
		}
		}
	}

	if (days < 0)
	{
		this->next_month();
		days++;
		while (days < 0)
		{
			days++;
			day++;
		}
	}

	return *this;
}

int Date::operator-(const Date& _date)
{
	int days = 0;
	Date MaxDate = *this;
	Date MinDate = _date;

	if (_date.year > year)
	{
		MaxDate = _date;
		MinDate = *this;
	}

	while (MinDate.day != MaxDate.day)
	{
		days++;
		MinDate + 1;
	}

	while (MinDate.month != MaxDate.month)
	{
		switch (MinDate.month)
		{
		case 12:
		case 10:
		case 8:
		case 7:
		case 5:
		case 3:
		case 1:
		{
			days = days + 31;
			MinDate.next_month();
			break;
		}
		case 11:
		case 9:
		case 6:
		case 4:
		{
			days = days + 30;
			MinDate.next_month();
			break;
		}
		case 2:
		{
			if (year % 4 == 0)
			{
				days = days + 29;
				MinDate.next_month();
				break;
			}
			else
			{
				days = days + 28;
				MinDate.next_month();
				break;
			}
		}
		}
	}

	while (MinDate.year != MaxDate.year)
	{
		if (MinDate.year % 4 == 0)
			days = days + 366;
		else
			days = days + 365;
		MinDate.year++;
	}

	return days;
}