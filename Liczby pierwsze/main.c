#include <stdio.h>

#define size 500

//Czy podzielna przez pewne liczby
int ifDevide(int a) {
	if (a % 2 == 0)
		return 1;
	else
		return 0;
}

//Czy liczba pierwsza
int ifFirst(int a) {
	int j;
	int max_j = a / 2+1;
	for (j = 2; j < max_j; j++)
		if (a % j == 0)
			return 0;
	return 1;
}

void main(int argc, char** argv) {
	FILE* F = fopen("Liczby.txt","w+");
	int i=2; //Uzyskane liczby
	int number = 2;//Kolejne liczby
	int iteration = size * size + 1;
	fprintf(F, "\n");//Zapisanie jedynki
	while (i < iteration) {
		if(!ifDevide(number)){
			if (ifFirst(number)){
				fprintf(F, ".\n");
			}
			else
				fprintf(F,"\n");
			i++;
		}
		number++;
	}
	fclose(F);
}