#include<stdio.h>
#include<stdlib.h>

int main () {	

	int num1, num2, count, carry, lnum1, lnum2;

	scanf ("%d %d", &num1, &num2);

	while (num1 != 0 || num2 != 0) {
		
		count = 0; carry = 0;
		while (num1 > 0 || num2 > 0) {
		
			lnum1 = num1 % 10;
			num1 = num1/10;

			lnum2 = num2 % 10;
			num2 = num2/10;

			if ((lnum1 + lnum2 + carry) >= 10) {
				count++;
				carry = 1; 
			}
			else
				carry = 0;

 
		}

		if (count > 1)
			printf ("%d carry operations.\n", count);
		else if (count == 1)	
			printf ("%d carry operation.\n", count);
		else 	
			printf ("No carry operation.\n");
		
		scanf ("%d %d", &num1, &num2);
	}
	

	return 0;
}

