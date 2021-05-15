#include <iostream>
#include <string>
#include <exception>
#include <math.h>
#include <sstream>

#include <iomanip>


using namespace std;

class Empty
{};

class Error
{
	string message;
public:
	Error(string message)
		: message(message)
	{}
	string What() { return message; }
};

class E : public exception
{
	string message;
public:
	E(string message)
		: message(message)
	{}
	string What() { return message; }
};

class Time
{
private:
	int seconds;
	int hh, mm;
public:

	void convertIntoSeconds(void);
	void displayTime(void);
	int Time1(int hh, int mm);
	int Time2(int hh, int mm);
	int Time3(int hh, int mm);
	int Time4(int hh, int mm);
	int Time5(int hh, int mm);
	int Time6(int hh, int mm);
	void getTime(void);

};


void Time::convertIntoSeconds(void)
{
	seconds = hh * 3600 + mm * 60;
}

int Time::Time1(int hh, int mm) {
	if (hh > 24 && mm > 60) throw 1;
	return  hh * 3600 + mm * 60;
}
int Time::Time2(int hh, int mm)throw() {
	if (hh > 24 && mm > 60) throw 1.0;
	return  hh * 3600 + mm * 60;
}
int Time::Time3(int hh, int mm)throw(char) {
	if (hh > 24 && mm > 60) throw '1';
	return  hh * 3600 + mm * 60;
}
int Time::Time4(int hh, int mm)throw (Empty) {
	if (hh > 24 && mm > 60) throw Empty();
	return  hh * 3600 + mm * 60;
}
int Time::Time5(int hh, int mm)throw(Error) {
	if (hh > 24 && mm > 60) throw Error("Wrong time!");
	return  hh * 3600 + mm * 60;
}
int Time::Time6(int hh, int mm)throw(int) {
	if (hh > 24 && mm > 60) throw E("Wrong time!");
	return  hh * 3600 + mm * 60;
}
void Time::getTime(void)
{
	cout << "Enter time:" << endl;
	cout << "Hours?   ";          cin >> hh;
	cout << "Minutes? ";          cin >> mm;
}
void Time::displayTime(void)
{
	cout << "The time is = " << setw(2) << setfill('0') << hh << ":"
		<< setw(2) << setfill('0') << mm << ":"
		<< endl;
	cout << "Time in total seconds: " << seconds;
}

void unexpected() {
	cout << "unexpected error! - bad_exception" << endl;
	throw;
}
void terminate() {
	cout << "unknown error! - terminate" << endl;
	abort();
}
int main()
{

	Time T;
	int hh, mm;

	T.getTime();
	T.displayTime();

	for (int i = 0; i < 6; i++)
	{
		cout << " Hours = ? "; cin >> hh;
		cout << " Minutes = ? "; cin >> mm;

		try
		{
			if (i == 0)
			{
				cout << T.Time1(hh, mm) << endl;
			}
			else if (i == 1)
			{
				cout << T.Time2(hh, mm) << endl;
			}
			else if (i == 2)
			{
				cout << T.Time3(hh, mm) << endl;
			}
			else if (i == 3)
			{
				cout << T.Time4(hh, mm) << endl;
			}
			else if (i == 4)
			{
				cout << T.Time5(hh, mm) << endl;
			}
			else
			{
				cout << T.Time6(hh, mm) << endl;
			}
		}
		catch (int)
		{
			cout << " catch (int) <= Time1()" << endl;
		}
		catch (double)
		{
			cout << " catch (double) <= Time2()" << endl;
		}
		catch (char)
		{
			cout << " catch (char) <= Time3()" << endl;
		}
		catch (Empty)
		{
			cout << " catch (Empty) <= Time4()" << endl;
		}
		catch (Error e)
		{
			cout << " catch (Error) <= Time5() :" << endl;
			cout << e.What() << endl;
		}
		catch (bad_exception)
		{
			cout << " catch (bad_exception)" << endl;
		}
		catch (exception)
		{
			cout << " catch (exception) <= Time6() :" << endl;
		}
		catch (E e)
		{
			cout << " catch (E) <= Time6() :" << endl;
			cout << e.What() << endl;
		}

	}



	return 0;
}