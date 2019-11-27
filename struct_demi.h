#ifndef STRUCT_H
#define STRUCT_H

#include <time.h>
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>


struct Case{
  int Etat;
  int Nb_Bombes;
  int Nature;
};

//Etat = 1 veut dire vu, Etat=0 veut dire non découvert
//Nature = 1 veut dire bombe

typedef struct Case Case;

void Remplir(Case Matrice[][26],int lignes, int colonnes);

int Nb_Bombes_Case(Case Matrice[][26], int lignes, int colonnes, int x, int y);

void Nb_Bombes_Matrice(Case Matrice[][26], int lignes, int colonnes);

void Afficher_Demi_Test(Case Matrice[][26],int lignes, int colonnes);

char Chiffre_to_Lettre(int i);

int Lettre_to_Chiffre(char c);

void Afficher_Demi(Case Matrice[][26],int lignes, int colonnes);

void Demander_Coord(int * Coord);

void Realisation_Choix(Case Matrice[][26],int lignes, int colonnes, int x, int y);

void Demineur();

#endif