#include "struct_demi.h"



void Remplir(Case Matrice[][26],int lignes, int colonnes){
  //Fonction qui rempli les cases de la matrice pour savoir si bombe ou vide.
  srand(time(0));
  int i;
  int j;
  float alea;

  for (i=0;i<lignes;i++){
    for (j=0;j<colonnes;j++){
      alea = (float)rand()/RAND_MAX;
      if (alea < 0.22){
	Matrice[i][j].Nature = 1;
      }
      else{
	Matrice[i][j].Nature = 0;
      }
      Matrice[i][j].Etat = 0;
    }
  }
}

int Nb_Bombes_Case(Case Matrice[][26], int lignes, int colonnes, int x, int y){
  //Fonction qui calcule le nb de bombes autour de la case.
  int i;
  if (Matrice[y][x].Nature == 1){
    i= -1;
  }
  else{
    i = 0;
    int droite = x<colonnes-1;
    int gauche = x>0;
    int haut = y>0;
    int bas = y<lignes-1;
    if (droite){
      i = (Matrice[y][x+1].Nature == 1) ? i+1 : i+0;
    }
    if (gauche){
      i = (Matrice[y][x-1].Nature == 1)? i+1 : i+0;
    }
    if (haut){
      i = (Matrice[y-1][x].Nature == 1)? i+1 : i+0;
    }
    if(bas){
      i = (Matrice[y+1][x].Nature == 1)? i+1 : i+0;
    }
    if(droite&&haut){
      i = (Matrice[y-1][x+1].Nature == 1)? i+1 : i+0;
    }
    if(droite&&bas){
      i = (Matrice[y+1][x+1].Nature == 1)? i+1 : i+0;
    }
    if(gauche&&haut){
      i = (Matrice[y-1][x-1].Nature == 1)? i+1 : i+0;
    }
    if(gauche&&bas){
      i = (Matrice[y+1][x-1].Nature == 1)? i+1 : i+0;
    }
  }
  return i;
}

void Nb_Bombes_Matrice(Case Matrice[][26], int lignes, int colonnes){
  int x;
  int y;

  for (x=0;x<colonnes;x++){
    for (y=0;y<lignes;y++){
      Matrice[y][x].Nb_Bombes = Nb_Bombes_Case(Matrice,lignes,colonnes,x,y);
    }
  }
}

void Afficher_Demi_Test(Case Matrice[][26],int lignes, int colonnes){
  int x;
  int y;
  for (y=0;y<lignes;y++){
    for (x=0;x<colonnes;x++){
      switch (Matrice[y][x].Nature){
      case 1 : printf("B "); break;
      case 0 : printf("%d " ,Matrice[y][x].Nb_Bombes); break;
      default : NULL;
      }
    }
  printf("\n");
  }
}

char Chiffre_to_Lettre(int i){
  char res;
  switch (i){
  case 1 : res = 'A'; break;
  case 2 : res = 'B'; break;
  case 3 : res = 'C'; break;
  case 4 : res = 'D'; break;
  case 5 : res = 'E'; break;
  case 6 : res = 'F'; break;
  case 7 : res = 'G'; break;
  case 8 : res = 'H'; break;
  case 9 : res = 'I'; break;
  case 10 : res = 'J'; break;
  case 11: res = 'K'; break;
  case 12 : res = 'L'; break;
  case 13 : res = 'M'; break;
  case 14 : res = 'N'; break;
  case 15 : res = 'O'; break;
  case 16 : res = 'P'; break;
  case 17 : res = 'Q'; break;
  case 18 : res = 'R'; break;
  case 19 : res = 'S'; break;
  case 20: res = 'T'; break;
  case 21 : res = 'U'; break;
  case 22 : res = 'V'; break;
  case 23 : res = 'W'; break;
  case 24 : res = 'X'; break;
  case 25 : res = 'Y'; break;
  case 26 : res = 'Z'; break;
  default : res = 'Z';
  }
  return res;
}

int Lettre_to_Chiffre(char c){
  int res;
    switch (c){
    case 'A' : res = 1; break;
    case 'B' : res = 2; break;
    case 'C' : res = 3; break;
    case 'D' : res = 4; break;
    case 'E' : res = 5; break;
    case 'F' : res = 6; break;
    case 'G' : res = 7; break;
    case 'H' : res = 8; break;
    case 'I' : res = 9; break;
    case 'J' : res = 10; break;
    case 'K' : res = 11; break;
    case 'L' : res = 12; break;
    case 'M' : res = 13; break;
    case 'N' : res = 14; break;
    case 'O' : res = 15; break;
    case 'P' : res = 16; break;
    case 'Q' : res = 17; break;
    case 'R' : res = 18; break;
    case 'S' : res = 19; break;
    case 'T' : res = 20; break;
    case 'U' : res = 21; break;
    case 'V' : res = 22; break;
    case 'W' : res = 23; break;
    case 'X' : res = 24; break;
    case 'Y' : res = 25; break;
    case 'Z' : res = 26; break;
    default : res = 26;
    }
  return res;
}
      
    

void Afficher_Demi(Case Matrice[][26],int lignes, int colonnes){
  int x;
  int y;
  int i = 1;
  for (y=0;y<lignes;y++){
    if (y==0){
      printf("   ");
      for (i=1;i<colonnes+1;i++){
	printf("%c ",Chiffre_to_Lettre(i));
      }
      printf("\n\n");
    }
	
    for (x=0;x<colonnes;x++){
      if (x==0){
	printf("%c  ", Chiffre_to_Lettre(y+1));
      }	
      if (Matrice[y][x].Etat == 1){
	 switch (Matrice[y][x].Nature){
	 case 1 : printf("B "); break;
	 case 0 : printf("%d " ,Matrice[y][x].Nb_Bombes); break;
	 default : NULL;
	 }
      }
      else{
	printf("# ");
      }
    }
    printf("\n");
  }
}

void Demander_Coord(int * Coord){
  //Coord = [y,x]
  printf("\nRentrez la coord verticale de votre prochain choix : ");
  Coord[0] = Lettre_to_Chiffre(getchar())-1;
  __fpurge(stdin);
  printf("Rentrez la coord horizontale de votre prochain choix : ");
  Coord[1] = Lettre_to_Chiffre(getchar()) -1;
  __fpurge(stdin);
}

void Realisation_Choix(Case Matrice[][26],int lignes, int colonnes, int x, int y){
  int haut = y > 0;
  int bas = y < lignes-1;
  int droite = x < colonnes-1;
  int gauche = x > 0;
  int Deja_vu = 1;
  if (Matrice[y][x].Etat == 1){
    Deja_vu = 0;
  }
  Matrice[y][x].Etat = 1;
  if ((Matrice[y][x].Nature == 0)&&(Matrice[y][x].Nb_Bombes == 0)&&(Deja_vu)){

    if (droite){
      Realisation_Choix(Matrice,lignes,colonnes,x+1,y); 
    }
    if (gauche){
      Realisation_Choix(Matrice,lignes,colonnes,x-1,y); 
    }
    if (haut){
      Realisation_Choix(Matrice,lignes,colonnes,x,y-1); 
    }
    if(bas){
      Realisation_Choix(Matrice,lignes,colonnes,x,y+1); 
    }
    if(droite&&haut){
      Realisation_Choix(Matrice,lignes,colonnes,x+1,y-1); 
    }
    if(droite&&bas){
      Realisation_Choix(Matrice,lignes,colonnes,x+1,y+1); 
    }
    if(gauche&&haut){
      Realisation_Choix(Matrice,lignes,colonnes,x-1,y-1); 
    }
    if(gauche&&bas){
      Realisation_Choix(Matrice,lignes,colonnes,x-1,y+1); 
    }
  }
}
    
 	  	   		
void Demineur(){
  int Coord[2];
  Case Matrice[16][26];
  int Pas_Perdu = 1;
  Remplir(Matrice, 16,26);
  Nb_Bombes_Matrice(Matrice,16,26);
  while (Pas_Perdu){
    //Afficher_Demi_Test(Matrice,16,26);
    Afficher_Demi(Matrice,16,26);
    Demander_Coord(Coord);
    if (Matrice[Coord[0]][Coord[1]].Nature == 1){
      Pas_Perdu = 0;
      printf("\nPERDU, C'EST UNE BOMBE ;)\n");
    }
    else{
      Realisation_Choix(Matrice,16,26,Coord[1],Coord[0]);
      system("clear");
    }
  }
}