#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define DADO 6

int main () {

	float ev1, ev2, at, d;
	float prob, prob1, prob2;

	scanf ("%f %f %f %f", &ev1, &ev2, &at, &d);

	while (ev1 != 0 && ev2 != 0 && at != 0 && d != 0) {

		prob1 = at/DADO; // probability of the vampire 1 winning on the dice;
		prob2 = (DADO - at)/DADO; // probability of the vampire 2 winning on the dice;
		ev1 = ev1/d;
		ev1 = ceil(ev1);			
		ev2 = ev2/d;
		ev2 = ceil(ev2);

		if (at == 3)
			prob = (ev1/(ev1 + ev2));

		else {
			prob = (1 - pow((prob2/prob1), ev1))/(1 - pow((prob2/prob1), ev1 + ev2));
		
		}

		printf ("%.1f\n", (100 * prob)); 
		scanf ("%f %f %f %f", &ev1, &ev2, &at, &d);

	}
	
	printf ("\n");

	return 0;
}
