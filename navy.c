#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


//Taille des bateaux
#define PA 5
#define Cr 4
#define CT 3
#define SM 3
#define Tr 2

//Définition du BUZSIZE
#define BUFSIZE 256

//Définition des structures
struct position{
  	int positionY;
  	char positionX;
};

struct Mine{
  	size_t size;
  	size_t capacity;
  	struct position *data;
};

void positionMine(struct Mine *self){
  	self->data = malloc (sizeof(struct position)*5);

  	self->data[0].positionY = 8;
  	self->data[0].positionX = 'B';

  	self->data[1].positionY = 7;
  	self->data[1].positionX = 'E';

  	self->data[2].positionY = 8;
  	self->data[2].positionX = 'F';

  	self->data[3].positionY = 7;
  	self->data[3].positionX = 'G';

  	self->data[4].positionY = 8;
  	self->data[4].positionX = 'H';

  	self->size = 5;     //A chauqe fois qu'une mine est détruite alors on enlève 1 à la taille
  	self->capacity = 5; //On ne peut avoir seulement 5 mines, la capacité ne changera jamais


}

struct Bateau{
  	int tailleBateau;
  	struct position positionTop;
  	struct position positionBottom;
};

struct Equipe {
  	size_t size;
  	size_t capacity;
  	struct Bateau *data;
};

void positionInitialiser(struct Equipe *self){
  	self->data = malloc (sizeof(struct Bateau)*5);
  
  //on défini la postion du porte avions ainsi que ca taille
  	self->data[0].tailleBateau = PA;
  	self->data[0].positionTop.positionY = 2;
  	self->data[0].positionTop.positionX = 'B';
  	self->data[0].positionBottom.positionY = 2;
  	self->data[0].positionBottom.positionX = 'F';

  //on défini la postion du croiseur ainsi que ca taille
  	self->data[1].tailleBateau = Cr;
  	self->data[1].positionTop.positionY = 1;
  	self->data[1].positionTop.positionX = 'C';
  	self->data[1].positionBottom.positionY = 1;
  	self->data[1].positionBottom.positionX = 'F';

  //on défini la postion du contre_torpilleur ainsi que ca taille
  	self->data[2].tailleBateau = CT;
  	self->data[2].positionTop.positionY = 7;
  	self->data[2].positionTop.positionX = 'C';
  	self->data[2].positionBottom.positionY = 7;
  	self->data[2].positionBottom.positionX = 'E';

  //on défini la postion du sous_marin ainsi que ca taille
  	self->data[3].tailleBateau = SM;
  	self->data[3].positionTop.positionY = 4;
  	self->data[3].positionTop.positionX = 'D';
  	self->data[3].positionBottom.positionY = 4;
  	self->data[3].positionBottom.positionX = 'F';

  //on défini la postion du torpilleur ainsi que ca taille
  	self->data[4].tailleBateau = Tr;
  	self->data[4].positionTop.positionY = 5;
  	self->data[4].positionTop.positionX = 'F';
  	self->data[4].positionBottom.positionY = 6;
  	self->data[4].positionBottom.positionX = 'F';

  	self->size = 5;
 	self->capacity = 5;
};

void tireAGauche(int position_Y, char position_X,char* buffer){
	
	

	position_X--;
	if(position_X >= 'A'){
		printf("SHOOT\n"); // or POOL or MOVE
	    	printf("%c%d\n",position_X,position_Y);
	   	fgets(buffer, BUFSIZE, stdin);
	    	
		
		
		if(strcmp(buffer,"HIT\n")==0){ 
			tireAGauche(position_Y,position_X,buffer);
		fgets(buffer, BUFSIZE, stdin); // NOTHING or ATTACK
		if(strcmp(buffer,"ATTACK\n")==0){
				fgets(buffer, BUFSIZE, stdin);
		}
		}
		else{
		fgets(buffer, BUFSIZE, stdin); // NOTHING or ATTACK
		if(strcmp(buffer,"ATTACK\n")==0){
			fgets(buffer, BUFSIZE, stdin);
		}
		}
	}
};

void tireADroite(int position_Y, char position_X,char* buffer){
	
	

	position_X++;
	if(position_X <= 'J'){		
		printf("SHOOT\n"); // or POOL or MOVE
	    	printf("%c%d\n",position_X,position_Y);
	   	fgets(buffer, BUFSIZE, stdin);
	    
		
		
		if(strcmp(buffer,"HIT\n")==0){ 
			tireADroite(position_Y,position_X,buffer);
		fgets(buffer, BUFSIZE, stdin); // NOTHING or ATTACK
		if(strcmp(buffer,"ATTACK\n")==0){
				fgets(buffer, BUFSIZE, stdin);
		}
		}
		else{
		fgets(buffer, BUFSIZE, stdin); // NOTHING or ATTACK
		if(strcmp(buffer,"ATTACK\n")==0){
			fgets(buffer, BUFSIZE, stdin);
		}
		}
	
	}
};

void tireEnHaut(int position_Y, char position_X,char* buffer){

	position_Y--;
	if(position_Y >= 0){
		
	printf("SHOOT\n"); // or POOL or MOVE
    	printf("%c%d\n",position_X,position_Y);
   	fgets(buffer, BUFSIZE, stdin);	
		
	if(strcmp(buffer,"HIT\n")==0){ 
		tireEnHaut(position_Y,position_X,buffer);
		fgets(buffer, BUFSIZE, stdin); // NOTHING or ATTACK
		if(strcmp(buffer,"ATTACK\n")==0){
			fgets(buffer, BUFSIZE, stdin);
		}
	}
	else{
		fgets(buffer, BUFSIZE, stdin); // NOTHING or ATTACK
		if(strcmp(buffer,"ATTACK\n")==0){
			fgets(buffer, BUFSIZE, stdin);
		}
	}
	}
};

void tireEnBas(int position_Y, char position_X,char* buffer){
	
	position_Y++;
	if(position_Y <= 9){	
		printf("SHOOT\n"); // or POOL or MOVE
	    	printf("%c%d\n",position_X,position_Y);
	   	fgets(buffer, BUFSIZE, stdin);
	    
		
		
		if(strcmp(buffer,"HIT\n")==0){ 
			tireEnBas(position_Y,position_X,buffer);
			fgets(buffer, BUFSIZE, stdin); // NOTHING or ATTACK
			if(strcmp(buffer,"ATTACK\n")==0){
				fgets(buffer, BUFSIZE, stdin);
			}
		}
		else{
			fgets(buffer, BUFSIZE, stdin); // NOTHING or ATTACK
			if(strcmp(buffer,"ATTACK\n")==0){
				fgets(buffer, BUFSIZE, stdin);
			}
		}
	}
};



void tireAutour(int position_Y, char position_X,char* buffer){	//fonctionne qui généralise tout
	tireAGauche( position_Y, position_X,buffer);	
	tireADroite( position_Y, position_X,buffer);	
	tireEnHaut( position_Y, position_X,buffer);
	tireEnBas( position_Y, position_X,buffer);
};




int main(){
  	struct Equipe NotreEquipe;
  	struct Mine NosMine;
	FILE* fd = NULL;
	fd = fopen("logJoueur.txt","w");

  	setbuf(stdout, NULL);
  	char buffer[BUFSIZE];

  	//Initialisation de la position des Mines et des Bateaux
  	positionMine(&NosMine);
  	positionInitialiser(&NotreEquipe);

	fprintf(fd,"Positions Mines: \n");
	
  	for(size_t y = 0; y < NosMine.size;y+=1){
		printf("%c%d\n",NosMine.data[y].positionX, NosMine.data[y].positionY);
		fprintf(fd,"%c%d\n",NosMine.data[y].positionX, NosMine.data[y].positionY);
	}

	
	fprintf(fd,"\nPositions Bateaux: \n");

  	//affichage des coordonnées des bateaux
  	for(size_t i = 0; i < NotreEquipe.size ; i+=1){
    		printf("%c%d%c%d\n",NotreEquipe.data[i].positionTop.positionX,NotreEquipe.data[i].positionTop.positionY,NotreEquipe.data[i].positionBottom.positionX,NotreEquipe.data[i].positionBottom.positionY );

		fprintf(fd,"%c%d%c%d\n",NotreEquipe.data[i].positionTop.positionX,NotreEquipe.data[i].positionTop.positionY,NotreEquipe.data[i].positionBottom.positionX,NotreEquipe.data[i].positionBottom.positionY );
    
    		fgets(buffer, BUFSIZE, stdin);
		//assert(strcmp(buffer, "OK\n") == 0);
  	}
	
	fclose(fd);

	int count = 0;
	int countLettre = 'A';	

	for (;;) {
		if(count == 10){
			count = 0;
		}
		

    		printf("SHOOT\n"); // or POOL or MOVE
    		printf("%c%d\n",countLettre,count);
    		fgets(buffer, BUFSIZE, stdin);


		if(strcmp(buffer,"HIT\n")==0){ 	//Si on touche alors on fait une autre action
			tireAutour(count,countLettre,buffer);
			fgets(buffer, BUFSIZE, stdin);
 			if(strcmp(buffer,"ATTACK\n")==0){
				fgets(buffer, BUFSIZE, stdin);
			}
		}

							//Sinon on continue de tirer 
		if(countLettre == 'I'){
			countLettre = 'A';
			count++;
			fgets(buffer, BUFSIZE, stdin);
			if(strcmp(buffer,"ATTACK\n")==0){
				fgets(buffer, BUFSIZE, stdin);
			}
		}
		else {
			if( countLettre == 'J'){
				countLettre = 'B';
				count++;
				fgets(buffer, BUFSIZE, stdin);
				if(strcmp(buffer,"ATTACK\n")==0){
					fgets(buffer, BUFSIZE, stdin);
				}
			}
			else {
				countLettre+=2;
				fgets(buffer, BUFSIZE, stdin);
				if(strcmp(buffer,"ATTACK\n")==0){
					fgets(buffer, BUFSIZE, stdin);
				}
			}
		}
		
		
		
  	}	

  	return EXIT_SUCCESS;
}
