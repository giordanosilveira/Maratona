#include<stdio.h>
#include<stdlib.h>
#define DYEARS 365
#define DMONTH 30

int main () {

	int days, remainder;

//	printf ("Enter number of days\n");
	scanf ("%d", &days); 

	remainder = days % DYEARS; // The days remaining of a full year(s) 
	printf ("%d ano(s)\n", (days/DYEARS)); // whole number of year(s)
	printf ("%d mes(es)\n", (remainder/DMONTH)); // whole number of month(s)
	printf ("%d dia(s)\n", (remainder % DMONTH)); // the days remaining of a full month

	return 0;
}
