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

  	self->data[0].positionY = 1;
  	self->data[0].positionX = 'A';

  	self->data[1].positionY = 1;
  	self->data[1].positionX = 'A';

  	self->data[2].positionY = 1;
  	self->data[2].positionX = 'A';

  	self->data[3].positionY = 1;
  	self->data[3].positionX = 'A';

  	self->data[4].positionY = 1;
  	self->data[4].positionX = 'A';

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


int main(){
  	struct Equipe NotreEquipe;
  	struct Mine NosMine;

  	setbuf(stdout, NULL);
  	char buffer[BUFSIZE];

  	//Initialisation de la position des Mines et des Bateaux
  	positionMine(&NosMine);
  	positionInitialiser(&NotreEquipe);

  	printf("C2\n");//Ne pas oublier de faire la lecture de nos mines et pas de celle ci
  	printf("H2\n");
  	printf("C7\n");
  	printf("H7\n");
  	printf("E5\n");

	

  	//affichage des coordonnées des bateaux
  	for(size_t i = 0; i < NotreEquipe.size ; i+=1){
    		printf("%c%d%c%d\n",NotreEquipe.data[i].positionTop.positionX,NotreEquipe.data[i].positionTop.positionY,NotreEquipe.data[i].positionBottom.positionX,NotreEquipe.data[i].positionBottom.positionY );
    
    		fgets(buffer, BUFSIZE, stdin);
		assert(strcmp(buffer, "OK\n") == 0);
  	}

	/*for (;;) {
    		printf("SHOOT\n"); // or POOL or MOVE
    		printf("D2\n");
    		fgets(buffer, BUFSIZE, stdin);
    		fgets(buffer, BUFSIZE, stdin); // NOTHING or ATTACK
  	}*/
	
	

  	return EXIT_SUCCESS;
}
