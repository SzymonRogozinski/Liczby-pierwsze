#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define size 1000
#pragma warning(disable : 4996)

//Czy podzielna przez pewne liczby
int ifDevide(int a,short *div,int len) {
	for (short i=0; i < len; i++) {
		if (a % div[i]==0) {
			return 1;
		}
	}
	return 0;
}

//Czy liczba pierwsza
int ifFirst(int a) {
	int j;
	int max_j = sqrt(a);
	for (j = 2; j <= max_j; j++)
		if (a % j == 0)
			return 0;
	return 1;
}

//Przesunięcie
void up(int *x,int *y){
	(*y)--;
}

void down(int *x,int *y){
	(*y)++;
}

void left(int *x,int *y){
	(*x)--;
}

void right(int *x,int *y){
	(*x)++;
}

void main(int argc, char** argv) {
	if (argc < 2) {
		fprintf(stderr, "Nie podano pliku wejsciowego!");
		return;
	}
	FILE* F = fopen(argv[1], "w+");
	if (F == NULL) {
		fprintf(stderr, "Nie odnaleziono pliku!");
		return;
	}
	fprintf(F, "Czy_pierwsza;x;y\n");//nagłówek
	//Stworzenie tablicy dzielników
	short n = argc - 2;
	short *divide=malloc(sizeof(short)*n);
	for (int i = 0; i < n; i++) {
		short d = atoi(argv[i + 2]);
		divide[i] = d;
	}
	int x=size/2;
	int y=x;
	void (*function[])(int*,int*)={right,down,left,up};
	fprintf(F,"%d;%d;%d\n",0,x,y); //zapisanie jedynki
	x++;
	int number = 1; //Obecna liczba
	int way=0; //przebyta droga od ostatniego zakrętu
	short direction=1; //Który kierunek
	float max_way=1; //Ile może przebyć, przed zmianą kierunku
	long iteration=size*size+1; //z ilu wyników ma się składać próba
	long i=1;
	while(i<iteration){
		number++;
		if(ifDevide(number,divide,n))
			continue;
		fprintf(F,"%d;%d;%d\n",ifFirst(number),x,y);
		function[direction](&x,&y);
		way++;
		i++;
		//Czy następuję zmiana kierunku
		if(way<max_way)
			continue;
		//Zmiana kierunku
		way=0;
		max_way+=0.5;
		if(direction==3)
			direction=0;
		else
			direction++;
	}
	fclose(F);
}