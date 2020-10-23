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

	for (i = 0; i <= j; i++) {			//it compares if there are repeated pokemons on the list of repeated pokemons;
		if (strcmp (poke, allpok[i]) == 0)      // if there is, then return 1 for main function so that it doesn't do the next operation;
			return 1;
	}
	
	return 0;					// if there are no repeated pokemons, then return 0;  

}
void insrtPok  (char *poke, char **allpok, int* k) {   // inserts a new repeated pokemons on the list of repeated pokemons;

	allpok[*k] = poke;

}
void cmpPok (char **plist, int n, int i, char **allpok, int *k, int *count) {

	int j;
	j = i + 1;

	while (j < n){
	
		if (strcmp (plist[i], plist[j]) == 0) {	// search for a repeated pokemons on the general list of pokemons 
			*k = *k + 1;			// if there is and doesn't existe a such pokemon on the list of repeated pokemons
			*count = *count + 1;		// insert it on the list of repeated pokemons the new pokemon
			insrtPok (plist[i], allpok, k);	// and the counter adds up to 1;
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
		
		if (! searchPok	(plist[i], allpok, j))            //if it isn't on the list of repeated pokemons,
			cmpPok (plist, n, i, allpok, &j, &count); // checks if there are repeated pokemons on the plist
		i++;

	}
	
	printf ("Falta(m) %d pomekon(s).\n" , POKE-(n-count)+1);
	return 0;
}
