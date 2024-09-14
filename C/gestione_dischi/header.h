#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <assert.h>
#define MAX 50
#define LEN 10
#define PEX 20
#define BIG	30
//DEFINIZIONI DELLE STRUCT

typedef struct{ //STRUCT DEI DISCHI JAZZ
	int codice;
	char titolo[MAX];  //PER OGNI CATEGORIA I TITOLI E GLI AUTORI SONO COMPOSTI DA MAX 50 CARATTERI
	char autore[MAX];
	int prezzo;
}jazz;

typedef struct //STRUCT DEI DISCHI ROCK
{
	int codice;
	char titolo[MAX];
	char autore[MAX];
	int prezzo;	
}rock;

typedef struct //STRUCT DEI DISCHI PUNK
{
	int codice;
	char titolo[MAX];
	char autore[MAX];
	int prezzo;
}punk;

typedef struct //STRUCT DI ARRAY JAZZ
{
	jazz elementij[LEN];
	int num_jazz;	
}lista_jazz;

typedef struct //STRUCT DI ARRAY ROCK
{
	rock elementir[PEX];
	int num_rock;
}lista_rock;

typedef struct //STRUCT DI ARRAY ROCK 
{
	punk elementip[BIG];
	int num_punk;
}lista_punk;
/* CON LE STRUCT DI ARRAY HO POTUTO GESTIRE MEGLIO SIA IL NUMERO DI ELEMENTI SIA GLI ELEMENTI STESSI*/


jazz JAZZ; //CREO LA VARIABILE DI TIPO JAZZ
rock ROCK; //CREO LA VARIABILE DI TIPO ROCK
punk PUNK; //CREO LA VARIABILE DI TIPO PUNK

lista_jazz discoJ; //CREO LA VARIABILE DI TIPO LISTA_JAZZ
lista_rock discoR; //CREO LA VARIABILE DI TIPO LISTA_ROCK
lista_punk discoP; //CREO LA VARIABILE DI TIPO LISTA_PUNK

//PROTOTIPI DI FUNZIONE
int menu(); 		   //CON QUESTA FUNCTION VISUALIZZIAMO IL MENU DI SCELTA
void inserimento();    //CON QUESTA FUNCTION SI INSERISCE UN NUOVO DISCO
void eliminadisco();   //CON QUESTA FUNCTION SI ELIMINA UN DISCO
void tuttidischi();    //HO INSERITO QUESTA FUNCTION PER MONITORARE E GESTIRE AL MEGLIO I DISCHI 
void prezzominore();   //CON QUESTA FUNZIONE SI VISUALIZZA IL DISCO CON PREZZO MINORE PER OGNI CATEGORIA

int prezzominorejazz();     	//CON QUESTA FUNCTION VISUALIZZIAMO IL DISCO COL PREZZO MINORE JAZZ
int ricercabinariajazz(a,s,l);	//FUNZIONE DIVIDI ET IMPERA RICORSIVO
int prezzominorerock();			//CON QUESTA FUNCTION VISUALIZZIAMO IL DISCO COL PREZZO MINORE ROCK
int ricercabinariarock(a,s,l);	//FUNZIONE DIVIDI ET IMPERA RICORSIVO
int prezzominorepunk();			//CON QUESTA FUNCTION VISUALIZZIAMO IL DISCO COL PREZZO MINORE PUNK
int ricercabinariarock(a,s,l);	//FUNZIONE DIVIDI ET IMPERA RICORSIVO

int i,j,k;		//QUESTE VARIABILI GLOBALI CONTANO GLI ELEMENTI DELLE CATEGORIE
