//il programma deve generare 1000 quadrati magici e ne verifica la percentuale di successi
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000

void acquisisci(void);//permette di acquisire 1000 numeri generati dalla funzione, dispone nella matrice i numeri da destra verso sinistra e dall'alto verso il basso
int verifica(void);//verifica per ogni matrice se la somma di righe, colonne e diagonali sono uguali

int mat[MAX][MAX];//matrice composta da massimo 1000 colonne e massimo 1000 righe
int r;
int x;

void main(){
	srand(time(NULL)+500);	//imposta il tempo +500 come seme in modo da prevenire la generazione degli stessi numeri
	int a=0;
	int b,p;
	float percent;
	
	printf("--------------Benvenuti nel gioco del quadrato magico!!-------------- \n\n");
	printf("Un quadrato e' definito magico se la somma di ogni riga, ogni colonna e ogni diagonale e' uguale (costante magica). \n\n");
	printf("Verranno generati 1000 quadrati magici con numeri pseudocasuali. \nAlla fine verra' riportata la percentuale di successi\n\n");
	
	do{
    printf("Inserire la dimensione del quadrato (il valore e' sia per le colonne sia per le righe) :    ");
    scanf("%d",&r);
	}while(r<1 || r>=MAX);
	
	for(p=0;p<1000;p++){
	acquisisci();
	
    if(verifica()){
        printf("\n\nla matrice e` un quadrato magico\n\n");
    	b=b+1;
    	printf("-----------------------------------------\n\n\n");
    }else{
        printf("\n\nla matrice non e` un quadrato magico\n\n");
        printf("-----------------------------------------\n\n\n");   
		 }
  } 
  percent=((b/1000.0)*100.0);
  printf("I quadrati magici riusciti sono: %d \n\n",b);
  printf("la percentuale di successo e': %f %%",percent);
}

 void acquisisci(){
    
    int i=0,j=0;   
	
	    for(i=0;i<r;i++)
	    for(j=0;j<r;j++){
        printf("inserire il valore alla riga %d ed alla colonna %d : ",i+1,j+1);
		x=r*r;
		mat[i][j]=rand()%x+1;
        printf("%d\n",mat[i][j]);
        }
    
    for(i=0;i<r;++i){
    	printf(" \n\n ");
        for (j = 0; j < r; ++j)
        printf(" | %d | ",mat[i][j]);           
        }  
}

int verifica(){
   //dichiarazioni
    int i,j,sommap=0,sommas=0,sommar[MAX],sommac[MAX];

    //inizializzaizoni

    //inizializzaizone vettore somma righe
    for(i=0;i<r;i++)
        sommar[i] = 0;

    //inizializzaizone vettore somma colonne
    for(i=0;i<r;i++)
        sommac[i] = 0;

    //somme

    //somma diagonale princiaple
    for(i=0;i<r;i++)
        sommap += mat[i][i];

    //somma diagonale secondaria
    for(i=0,j=r-1;i<r;i++,j--)
        sommas += mat[i][j];

    //somma righe
    for(i=0;i<r;i++)
        for(j=0;j<r;j++)
            sommar[i] += mat[i][j];

    //somma colonne
    for(j=0;j<r;j++)
        for(i=0;i<r;i++)
            sommac[j] += mat[i][j];

    //verifica
    if(sommap == sommas){
        //verifica somma righe
        for(i=0;i<r;i++)
            if(sommap != sommar[i])
                return 0;

        //verifica somma colonne
        for(i=0;i<r;i++)
            if(sommap != sommac[i])
                return 0;
        return 1;
    }else
        return 0;
}

