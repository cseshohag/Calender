#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

bool isLeapYear (int);
int firstDayofnewyearMonth (int );
int numOfDaysInMonth (int, bool);
void printHeader (int);
void printMonth (int, int&);
void skip (int);
void skipToDay (int);
void disaster ();
void event();

int main ()
{
    int year, firstDayInCurrentMonth;
    int currentMonth = 1;
    int numDays;
    bool leap;
    cout << "select a Year: ";
    cin >>year;
    cout<<endl;
    firstDayInCurrentMonth=firstDayofnewyearMonth(year);
    leap = isLeapYear(year);
    skip(9);
    cout << year << endl;
    while (currentMonth <= 12)
    {
    numDays = numOfDaysInMonth(currentMonth, leap);
    printHeader(currentMonth);
    printMonth(numDays, firstDayInCurrentMonth);
    cout << endl << endl << endl;
    currentMonth = currentMonth + 1;
    }

    event();
    cout << endl;
}
bool isLeapYear (int year)
{
    return   ((year%4==0) && (year%100 !=0))||(year%400==0)  ;
}
int  firstDayofnewyearMonth(int year)
{
    int day_start;
    int x1, x2, x3;
    x1 = (year - 1)/ 4;
    x2 = (year - 1)/ 100;
    x3 = (year - 1)/ 400;
    day_start = (year + x1 - x2 + x3) %7;
    return day_start;
}
int numOfDaysInMonth (int m, bool leap)
{
    if (m == 1) return(31);
    else if (m == 2) if (leap) return(29);else return(28);
    else if (m == 3) return(31);
    else if (m == 4) return(30);
    else if (m == 5) return(31);
    else if (m == 6) return(30);
    else if (m == 7) return(31);
    else if (m == 8) return(31);
    else if (m == 9) return(30);
    else if (m == 10) return(31);
    else if (m == 11) return(30);
    else if (m == 12) return(31);
    else disaster();
}
void printHeader (int m)
{
    if (m == 1)
    {
    skip(7);
    cout << "January\n" << endl;
    }
    else if (m == 2) { skip(7); cout << "February\n" << endl; }
    else if (m == 3) { skip(7); cout << "March\n" << endl; }
    else if (m == 4) { skip(7); cout << "April\n" << endl; }
    else if (m == 5) { skip(7); cout << "May\n" << endl; }
    else if (m == 6) { skip(7); cout << "June\n" << endl; }
    else if (m == 7) { skip(7); cout << "July\n" << endl; }
    else if (m == 8) { skip(7); cout << "August\n" << endl; }
    else if (m == 9) { skip(7); cout << "September\n" << endl; }
    else if (m == 10) { skip(7); cout << "October\n" << endl; }
    else if (m == 11) { skip(7); cout << "November\n" << endl; }
    else if (m == 12) { skip(7); cout << "December\n" << endl; }
    else disaster();

    cout << " S  M  T  W  T  F  S" <<endl;
    cout << "____________________" << endl;
}
void skip (int i)
{
    while (i > 0)
    {
    cout << " ";
    i = i - 1;
    }
}
void printMonth (int numDays, int &weekDay)
{
    int day = 1;
    skipToDay(weekDay);
    while (day <= numDays)
    {
    cout << setw(2) << day << " ";
    if (weekDay == 6)
    {
        cout << endl;
        weekDay = 0;
    }
    else weekDay = weekDay + 1;
    day = day + 1;
    }
}
void skipToDay (int d)
{
    return skip(3*d);
}
void disaster ()
{
    cout << "Disaster! Exiting ..." << endl;
    exit ( -1);
}

void event(){
cout<<"Friday and Saturday are off-day";
}
