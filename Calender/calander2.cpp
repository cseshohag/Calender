#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
using namespace std;
#define TRUE 1
#define FALSE 0
int get_day_code (int year);
int get_leap_year (int year);
void print_calendar (FILE *fout, int year, int day_code, int leap_year);
int get_year (void);
main()
{

   int year, day_code, leap_year;

   FILE *fout;

   fout = fopen ("calendar.txt", "w");

   year = get_year();

   day_code = get_day_code (year);

   leap_year = get_leap_year (year);

   print_calendar(fout, year, day_code, leap_year);

   cout<<"Open up \'calendar.txt\' to see your calendar...\n";

   system("pause");

}

int get_year (void)
{
int year;
cout<<"Enter a year: ";
cin>>year;
return year;
}
int get_day_code (int year)
{
int day_code;
int x1, x2, x3;
	x1 = (year - 1.)/ 4.0;
	x2 = (year - 1.)/ 100.;
	x3 = (year - 1.)/ 400.;
day_code = (year + x1 - x2 + x3) %7;
return day_code;
}
int get_leap_year (int year)
{


if(year% 4==0 && year%100 != 0 || year%400==0)
   return TRUE;
   else return FALSE;

}
void print_calendar (FILE *fout, int year, int day_code, int leap_year)
{
	int  days_in_month,
         day,
         month;
     fprintf (fout,"                   %d", year);
     for ( month = 1; month <= 12; month++ ) {
          switch ( month ) {
          case 1:
               fprintf(fout,"\n\nJanuary" );
               days_in_month = 31;
               break;
          case 2:
               fprintf(fout,"\n\nFebruary" );
               days_in_month = leap_year ? 29 : 28;
               break;
          case 3:
               fprintf(fout, "\n\nMarch" );
               days_in_month = 31;
               break;
          case 4:
               fprintf(fout,"\n\nApril" );
               days_in_month = 30;
               break;
          case 5:
               fprintf(fout,"\n\nMay" );
               days_in_month = 31;
               break;
          case 6:
               fprintf(fout,"\n\nJune" );
               days_in_month = 30;
               break;
          case 7:
               fprintf(fout,"\n\nJuly" );
               days_in_month = 31;
               break;
          case 8:
               fprintf(fout,"\n\nAugust" );
               days_in_month = 31;
               break;
          case 9:
               fprintf(fout,"\n\nSeptember" );
               days_in_month = 30;
               break;
          case 10:
               fprintf(fout,"\n\nOctober" );
               days_in_month = 31;
               break;
          case 11:
               fprintf(fout,"\n\nNovember" );
               days_in_month = 30;
               break;
          case 12:
               fprintf(fout,"\n\nDecember" );
               days_in_month = 31;
               break;
          }
          fprintf(fout,"\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );

          for ( day = 1; day <= 1 + day_code * 5; day++ )
               fprintf(fout," " );

          for ( day = 1; day <= days_in_month; day++ ) {
               fprintf(fout,"%2d", day );
               if ( ( day + day_code ) % 7 > 0 )
                    fprintf(fout,"   " );
               else
                    fprintf(fout, "\n " );
          }

          day_code = ( day_code + days_in_month ) % 7;
     }
}
