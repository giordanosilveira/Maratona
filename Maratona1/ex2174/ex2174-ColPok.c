#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 64
#define POKE 151

char ** allcteMem (int n) {

	char **matrix;
	int i;

	matrix = (char **)malloc(sizeof(char *)*MAX);

	for (i = 0; i < n; i++) {
 		matrix[i] = (char *)malloc(sizeof(char)*MAX);
	} 

	return matrix;
} 
int searchPok (char *poke, char **allpok, int j) {

	int i;
	if (j == -1)
		return 0;

	for (i = 0; i <= j; i++) {
		if (strcmp (poke, allpok[i]) == 0)
			return 1;
	}
	
	return 0;

}
void insrtPok  (char *poke, char **allpok, int* k) {

	allpok[*k] = poke;

}
void cmpPok (char **plist, int n, int i, char **allpok, int *k, int *count) {

	int j;
	j = i + 1;

	while (j < n){
	
		if (strcmp (plist[i], plist[j]) == 0) {
			*k = *k + 1;
			*count = *count + 1;
			insrtPok (plist[i], allpok, k);
			j = n;
		}
		j++;
	}
}   
int main () {

	int n, i, j, count;
	char **plist, **allpok;

	scanf ("%d", &n);
	plist = allcteMem (n);
	allpok = allcteMem (POKE);
	
	for (i = 0; i < n; i++){		//load the pokemons in memory
		scanf ("%s", plist[i]); 
	}

	i = 0; j = -1; count = 0;
	while (i < n) {
		
		if (! searchPok	(plist[i], allpok, j))
			cmpPok (plist, n, i, allpok, &j, &count);

		i++;

	}
	
	printf ("Falta(m) %d pomekon(s).\n" , POKE-(n-count)+1);
	return 0;
}
