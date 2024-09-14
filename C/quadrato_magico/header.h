 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000

void acquisisci(void);//permette di acquisire 1000 numeri generati dalla funzione, dispone nella matrice i numeri da destra verso sinistra e dall'alto verso il basso

int verifica(void);//verifica per ogni matrice se la somma di righe, colonne e diagonali sono uguali

int mat[MAX][MAX];//matrice composta da massimo 1000 colonne e massimo 1000 righe
int r;
int x;
