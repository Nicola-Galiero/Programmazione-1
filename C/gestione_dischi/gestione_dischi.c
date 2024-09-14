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

int main(){ //NEL MAIN VIENE RICHIAMATO IL MENU E SONO PRESENTI LE FUNZIONI PRINCIPALI
	int scelta;
	while(scelta=menu()){
		switch(scelta){
			case 1: system("CLS");					
					inserimento();										
					system("PAUSE");
					break;
			case 2: system("CLS");	
					eliminadisco();									
					system("PAUSE");
					break;
			case 3: system("CLS");
					prezzominore();					
					system("PAUSE");
					break;
			case 4: system("CLS");
					tuttidischi();					
					system("PAUSE");
					break;
			case 5: system("CLS");
					printf("\nIl programma di gestione dischi augura buon proseguimento!\n");
					return 0;					
					}
		}
	
}

int menu(){
	int scelta;	
	printf("\n***Benvenuto nel programma gestione dischi!***\n\n");
	printf("[1] inserisci disco\n");
	printf("[2] elimina disco\n");
	printf("[3] disco con prezzo minore\n");
	printf("[4] stampa dischi\n");
	printf("[5] esci dal programma\n");
	printf("\nInserisci la tua scelta:  ");
	scanf("%d",&scelta);
	while(scelta<1||scelta>5){
		printf("\n---scelta non valida---\n");
		printf("\nInserisci la tua scelta: ");
		scanf("%d",&scelta);
		return scelta;
	}
	return scelta;	
	system("PAUSE");
}

int i,j,k;		//QUESTE VARIABILI GLOBALI CONTANO GLI ELEMENTI DELLE CATEGORIE

void inserimento(){
	
	int x;

	printf("\nInserisci il genere del disco che si vuole inserire: \n");
	printf("[1]-disco JAZZ   \n[2]-disco ROCK   \n[3]-disco PUNK\n\n");
	printf("\ndigita: ");
	scanf("%d",&x);	
		
		switch(x){
			case 1: 		if(i<3||discoJ.num_jazz<3){
							printf("Hai scelto di inserire un disco jazz\n");	//INSERIMENTO DISCO JAZZ
							printf("!Si prega di inserire i dischi col prezzo in ordine crescente.!\n\n");
							printf("Titolo: ");
							scanf("%s",&discoJ.elementij[i].titolo);		
							printf("Autore: ");
							scanf("%s",&discoJ.elementij[i].autore);
							printf("Prezzo: ");
							scanf("%d",&discoJ.elementij[i].prezzo);											
							i++;
							discoJ.num_jazz++;
							printf("\nDisco jazz inserito!\n\n");
							}else printf("--non si possono inserire piu' dischi jazz.--\n");
							break;
							
			case 2: 		if(j<3||discoR.num_rock<3){
							printf("Hai scelto di inserire un disco rock\n");	//INSERIMENTO DISCO ROCK
							printf("!Si prega di inserire i dischi col prezzo in ordine crescente.!\n\n");
							printf("Titolo: ");
							scanf("%s",&discoR.elementir[j].titolo);
							printf("Autore: ");
							scanf("%s",&discoR.elementir[j].autore);
							printf("Prezzo: ");
							scanf("%d",&discoR.elementir[j].prezzo);							
							j++;
							discoR.num_rock++;
							printf("\nDisco rock inserito!\n\n");
							}else printf("--non si possono inserire piu' dischi rock.--\n");
							break;
							
			case 3: 		if(k<3||discoP.num_punk<3){
							printf("Hai scelto di inserire un disco punk\n");	//INSERIMENTO DISCO PUNK
							printf("!Si prega di inserire i dischi col prezzo in ordine crescente.!\n\n");
							printf("Titolo: ");
							scanf("%s",&discoP.elementip[k].titolo);
							printf("Autore: ");
							scanf("%s",&discoP.elementip[k].autore);
							printf("Prezzo: ");
							scanf("%d",&discoP.elementip[k].prezzo);						 	
							k++;
							discoP.num_punk++;
							printf("\nDisco punk inserito!\n\n");
							}else printf("--non si possono inserire piu' dischi punk.--\n");
							break;
	}
	
}

void tuttidischi(){
	int a,b,c;	

	printf("Ora visualizzerai tutti i dischi.\n");
	
	for(a=0;a<discoJ.num_jazz;a++){	// CON QUESTO CICLO VEDIAMO TUTTI I DISCHI DELLE 3 CATEGORIE
	printf("\nI dischi del genere jazz");
	printf("\ntitolo: ** %s ** ",discoJ.elementij[a].titolo);
	printf("\nautore: ** %s ** ",discoJ.elementij[a].autore);
	printf("\nprezzo: ** %d ** ",discoJ.elementij[a].prezzo);
	printf("\ncodice: ** 00000111 ** \n");
}
	for(b=0;b<discoR.num_rock;b++){
	printf("\nI dischi del genere rock");
	printf("\ntitolo: ** %s ** ",discoR.elementir[b].titolo);
	printf("\nautore: ** %s ** ",discoR.elementir[b].autore);
	printf("\nprezzo: ** %d ** ",discoR.elementir[b].prezzo);
	printf("\ncodice: ** 00000222 ** \n");
}
	for(c=0;c<discoP.num_punk;c++){
	printf("\nI dischi del genere punk");
	printf("\ntitolo: ** %s ** ",discoP.elementip[c].titolo);
	printf("\nautore: ** %s ** ",discoP.elementip[c].autore);
	printf("\nprezzo: ** %d ** ",discoP.elementip[c].prezzo);
	printf("\ncodice: ** 00000333 ** \n");
}

}
	
void eliminadisco(){
	int a;
								/*AD OGNI DISCO ELIMINATO ASSOCIAMO DEI CARATTERI NULLI*/
	char canc[MAX];
	printf("Hai scelto di eliminare un disco.\n\n");
	printf("Inserisci il titolo del disco che vuoi cancellare:  ");
	scanf("%s",canc);
	
	for(a=0;a<10;a++)
    {
        	if(strcmp(discoJ.elementij[a].titolo,canc)==0){
            strcpy(discoJ.elementij[a].titolo,"---");
            strcpy(discoJ.elementij[a].autore,"---");
            discoJ.elementij[a].prezzo=0;
			printf("\n--DISCO JAZZ ELIMINATO--\n");}
			else if(strcmp(discoR.elementir[a].titolo,canc)==0){
            strcpy(discoR.elementir[a].titolo,"---");
            strcpy(discoR.elementir[a].autore,"---");
            discoR.elementir[a].prezzo=0;
			printf("\n--DISCO ROCK ELIMINATO--\n");}
			else if(strcmp(discoP.elementip[a].titolo,canc)==0){
            strcpy(discoP.elementip[a].titolo,"---");
            strcpy(discoP.elementip[a].autore,"---");
            discoP.elementip[a].prezzo=0;
			printf("\n--DISCO PUNK ELIMINATO--\n");}
	}
}

void prezzominore(){  		//FUNCTION DELLA VISUALIZZAZIONE DEL PREZZO MINORE DI OGNI CATEGORIA
	int x;					//SOLO COSI' HO SAPUTO GESTIRE AL MEGLIO LA COSA
	printf("Inserisci la categoria per la quale vuoi ricercare il disco con prezzo minore: \n");
	printf("[1]-disco JAZZ   \n[2]-disco ROCK   \n[3]-disco PUNK\n\n");
	printf("\ndigita: ");
	scanf("%d",&x);
	switch(x){
		case 1: prezzominorejazz();
			break;
		case 2: prezzominorerock();
			break;
		case 3: prezzominorepunk();
			break;					
	}
}
	
int prezzominorejazz(){ 		//IN QUESTA FUNZIONE VENGONO GESTITE LE VARIALBILI PER LA VISUALIZZAZIONE DEL PREZZO MINORE JAZZ,COSI' PER TUTTE LE CATEGORIE
	
	int s=0,a,r;
	int l= 3;
	a=discoJ.elementij[0].prezzo;
	r=ricercabinariajazz(a,s,l);
	if(r==1)
		printf("non ci sono ancora dischi inseriti");
	else
		printf("il prezzo minore di questa categoria e' [ %d ] del  titolo [ %s].\n\n",r,discoJ.elementij[0].titolo);
	
	
return 1;	
}

int ricercabinariajazz(a,s,l){  //RICERCA BINARIA CON DIVIDE ET IMPERA RICORSIVO
	
	int k=(l+s)/2;
	int r=-1;
	
	if(l>=s){
		if(discoJ.elementij[k].prezzo == a)
			return k;
		else if(discoJ.elementij[k].prezzo > a)	
			r=ricercabinariajazz(a,s,k-1);
		else if(discoJ.elementij[k].prezzo < a)
			r=ricercabinariajazz(a,k+1,l);
	}
	return a;	
}

int prezzominorerock(){
	
	int s=0,a,r;
	int l= 3;
	a=discoR.elementir[0].prezzo;
	r=ricercabinariarock(a,s,l);
	if(r==1)
		printf("non ci sono ancora dischi inseriti");
	else
		printf("il prezzo minore di questa categoria e' [ %d ] del  titolo [ %s].\n\n",r,discoR.elementir[0].titolo);
	
	
return 1;	
}

int ricercabinariarock(a,s,l){
	
	int k=(l+s)/2;
	int r=-1;
	
	if(l>=s){
		if(discoR.elementir[k].prezzo == a)
			return k;
		else if(discoR.elementir[k].prezzo > a)	
			r=ricercabinariajazz(a,s,k-1);
		else if(discoR.elementir[k].prezzo < a)
			r=ricercabinariajazz(a,k+1,l);
	}
	return a;	
}

int prezzominorepunk(){
	
	int s=0,a,r;
	int l= 3;
	a=discoP.elementip[0].prezzo;
	r=ricercabinariapunk(a,s,l);
	if(r==1)
		printf("non ci sono ancora dischi inseriti");
	else
		printf("il prezzo minore di questa categoria e' [ %d ] del  titolo [ %s ].\n\n",r,discoP.elementip[0].titolo);
	
	
return 1;	
}

int ricercabinariapunk(a,s,l){
	
	int k=(l+s)/2;
	int r=-1;
	
	if(l>=s){
		if(discoP.elementip[k].prezzo == a)
			return k;
		else if(discoP.elementip[k].prezzo > a)	
			r=ricercabinariajazz(a,s,k-1);
		else if(discoP.elementip[k].prezzo < a)
			r=ricercabinariajazz(a,k+1,l);
	}
	return a;	
}
