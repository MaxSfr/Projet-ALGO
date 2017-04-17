	#include <stdio.h>
	#include <stdlib.h>

	//Taille des bateaux
	#define PA 5
	#define Cr 4
	#define CT 3
	#define SM 3
	#define Tr 2

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
	  self->data = malloc (5*sizeof(size_t));

	  self->data[0].positionY = 1;
	  self->data[0].positionX = 'A';

	  self->data[1].positionY = 2;
	  self->data[1].positionX = 'B';

	  self->data[2].positionY = 3;
	  self->data[2].positionX = 'C';

	  self->data[3].positionY = 4;
	  self->data[3].positionX = 'D';

	  self->data[4].positionY = 5;
	  self->data[4].positionX = 'E';

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
	  self->data = malloc(sizeof(size_t));

	  //on défini la postion du porte avions ainsi que ca taille
	  self->data[0].tailleBateau = PA;
	  self->data[0].positionTop.positionY = 2;
	  self->data[0].positionTop.positionX = 'B';
	  self->data[0].positionBottom.positionY = 2;
	  self->data[0].positionBottom.positionX = 'B';

	  //on défini la postion du croiseur ainsi que ca taille
	  self->data[1].tailleBateau = Cr;
	  self->data[1].positionTop.positionY = 1;
	  self->data[1].positionTop.positionX = 'A';
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
	  self->data[4].positionBottom.positionY = 7;
	  self->data[4].positionBottom.positionX = 'A';

	  self->size = 5;
	  self->capacity = 5;
	};


	int main(){

	  struct Equipe NotreEquipe;
	  struct Mine NosMine;


	  //Initialisation de la position des Mines et des Bateaux
		
	  positionMine(&NosMine);
	  positionInitialiser(&NotreEquipe);
	
	  //affichage des coordonnées des bateaux;
	  for(size_t i = 0; i < NotreEquipe.size ; i+=1){
	    printf(" %d %c %d %c\n",NotreEquipe.data[i].positionTop.positionY,NotreEquipe.data[i].positionTop.positionX,NotreEquipe.data[i].positionBottom.positionY,NotreEquipe.data[i].positionBottom.positionX );
	  }

	  return 0;
	}
