/*
*  Polytech Tours, France
* All right reserved to Pengt BAI
*/
#ifndef fonctionsSudoku_H_INCLUDED
#define fonctionsSudoku_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define nbPermutations 700
#define nbRemplies 25


int genererGrilleAleatoirement(int Grille[9][9], int);
void genererGrillePermutations(int Grille[9][9]);
void genererGrille(int Grille[9][9], int);

void permuterLigne(int Grille[9][9],int, int);
void permuterColonne(int Grille[9][9],int, int);

int absentLigne(int Grille[9][9],int,int);
int absentColonne(int Grille[9][9],int,int); 
int absentBloc(int Grille[9][9],int,int,int);
int testerCase(int Grille[9][9],int,int,int);

void initGrille(int Grille[9][9]);
void copierGrille(int de[9][9],int a[9][9]);
void afficherGrille(int Grille[9][9]);
int resoudreGrille(int Grille[9][9],int);

void effacerCases(int Grille[9][9],int );

int solutionUnique(int Grille[9][9]);


#endif 
