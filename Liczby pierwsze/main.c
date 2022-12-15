#include <stdio.h>
#include <math.h>

#define size 1000


//Czy podzielna przez pewne liczby
int ifDevide(int a) {
	/*if (a % 7 == 0 || a % 11 == 0)
		return 1;
	else*/
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
	FILE* F = fopen("Liczby.txt","w+");
	fprintf(F, "Czy_pierwsza;x;y\n");//nagłówek
	int x=size/2;
	int y=x;
	void (*function[])(int*,int*)={right,down,left,up};
	fprintf(F,"%d;%d;%d\n",0,x,y);
	x++;
	int number = 1; //Obecna liczba
	int way=0; //przebyta droga od ostatniego zakrętu
	short direction=1; //Który kierunek
	float max_way=1; //Ile może przebyć, przed zmianą kierunku
	long iteration=size*size+1; //z ilu wyników ma się składać próba
	long i=1;
	while(i<iteration){
		number++;
		if(ifDevide(number))
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