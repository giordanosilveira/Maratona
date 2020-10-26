#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200
int strgCmpr (char * str1, char *str2) {

	int count, i, size1, size2;

	size1 = strlen (str1);
	size2 = strlen (str2);
	
	count = 0;
	if (size1 >= size2) {
		for (i = 0; (i < size2) && (str1[i] == str2[i]); i++) {
			count++;
		}
		
	}
	else {
		for (i = 0; (i < size1) && (str1[i] == str2[i]); i++) {
			count++;
		}
	
	}
	return count;

}

char * allctMem () {

	char *array;
	
	array = (char *)malloc(sizeof(char )*MAX);

	return array;

}
int main () {

	int n, i, back, count;
	char c, *atual, *proximo;
	
	count = 0;
	atual = allctMem ();
	proximo = allctMem ();

	//while (scanf ("%d", &n)) {
		scanf ("%d", &n);
		n = (int)c;
		i = 1;
		scanf ("%s", atual);
		while (i < n) {

			scanf ("%s", proximo);
			
			back = strgCmpr (atual,proximo);
			count = count + back;

			atual = proximo;
			i++;
		}
		printf ("%d\n", count);	
	//}
	
	return 0;
}
