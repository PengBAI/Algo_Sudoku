/*
*  Polytech Tours, France
* All right reserved to Pengt BAI
*/
#include "fonctionsSudoku.h"

int nbSol = 0;                      

int source[9][9] = {
	5,3,2,9,7,4,1,6,8,
    7,1,6,3,8,5,9,2,4,
    8,9,4,2,1,6,7,5,3,
    1,2,7,5,3,8,6,4,9,
    4,6,8,1,9,2,5,3,7,
    3,5,9,4,6,7,2,8,1,
    6,8,3,7,5,1,4,9,2,
    2,7,5,8,4,9,3,1,6,
    9,4,1,6,2,3,8,7,5
};

/*
Genere une grille à partir de la grille source en effectuant nbPermutations permutations
@params	Grille	    Grille
*/
void genererGrillePermutations(int Grille[9][9]){

    int Bloc, de, a, nbPermutationsColonne = nbPermutations / 2, nbPermutationsLignes = nbPermutations / 2;
	
	copierGrille(source,Grille);
	
    while(nbPermutationsColonne >0) { 
        Bloc= 3*(rand()%3);
        a = Bloc + rand()%3; 
        de = Bloc + rand()%3;
        
        if(de != a)
            permuterColonne(Grille ,de ,a);

        nbPermutationsColonne--;
    }
    
    while(nbPermutationsLignes >0) { 
        Bloc= 3*(rand()%3); 
        a = Bloc + rand()%3; 
        de = Bloc + rand()%3;
		
        if(de != a) 
            permuterLigne(Grille, de, a);
			
        nbPermutationsLignes--;
    }
  
}

/*
Permute deux lignes 
@params	Grille	    Grille
@params	de	    indice ligne source
@params	a	    indice ligne destination
*/
void permuterLigne(int Grille[9][9],int de,int a){
    int i,temp;
    for(i=0;i<9;i++) {
        temp = Grille[a][i];
        Grille[a][i] = Grille[de][i];
        Grille[de][i] = temp;
    }
}

/*
Permute deux colonnes
@params	Grille	    Grille
@params	de	    indice colonne source
@params	a	    indice colonne destination
*/
void permuterColonne(int Grille[9][9],int de,int a){
    int i,temp;
    for(i=0;i<9;i++) {
        temp = Grille[i][a];
        Grille[i][a] = Grille[i][de];
        Grille[i][de] = temp;
    }
}

/*
Vérifie si k est absent de la ligne i de la grille
@params	grille	    Grille
@params	i	        ligne
@params	k	        valeur
@return 1 si absent, 0 sinon
*/
int absentLigne(int Grille[9][9], int i, int k){
    int j;

    for(j=0; j < 9; j++){
        if(Grille[i][j] == k) return 0;
    }
    return 1;
}

/*
Vérifie si k est absent dans la colonne j de la grille
@params	grille	    Grille
@params	j	        colonne
@params	k	        valeur
@return 1 si absent, 0 sinon
*/
int absentColonne(int Grille[9][9], int j, int k){
    int i;

    for(i=0; i < 9; i++){
        if(Grille[i][j] == k) return 0;
    }

    return 1;
}

/*
Vérifie si k est absent du bloc de i,j de la grille
@params	grille	    Grille
@params	i	        ligne
@params	j	        colonne
@params	k	        valeur
@return 1 si absent, 0 sinon
*/
int absentBloc(int Grille[9][9], int i, int j, int k){
    int _i = i - (i % 3), _j = j - (j % 3);

    
    for (i=_i; i < _i+3; i++){
        for (j=_j; j < _j+3; j++){
            if (Grille[i][j] == k) return 0;
        }
    }
    return 1;
}

/*
Vérifie si k peut etre inserer dans cette case
@params	grille	    Grille
@params	i	        ligne
@params	j	        colonne
@params	k	        valeur
@return 1 si possible, 0 sinon
*/
int testerCase(int Grille[9][9],int i, int j, int k){
	return absentLigne(Grille,i,k) && absentColonne(Grille,j,k) && absentBloc(Grille,i,j,k);
}

/*
Affiche la grille
@params	grille	    Grille
*/
void afficherGrille(int Grille[9][9]){
    int i,j,count = 0;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            printf("%d", Grille[i][j]);
            if (Grille[i][j]>0)
                count++;
        }
       //printf("\n");
    }

    printf("\nnombre de cases remplies : %d\n", count);
}

/*
Résout une grille
@params	grille      Grille à résoudre
@params	pos   		Position en cours de test
@return 0 si plus d'une solution, 1 si solution unique
*/
int resoudreGrille(int Grille[9][9],int pos){
    int i,j,k;

    if (pos > 80)
    {
        nbSol++;
        if (nbSol > 1)
            return 0;
        else
            return 1;
    }

    i = pos / 9;
    j = pos % 9;

    if(Grille[i][j] == 0)
    {
        for(k = 1; k <= 9; k++)
        {
            if(testerCase(Grille, i, j, k))
            {
                Grille[i][j] = k;
                if(resoudreGrille(Grille, pos + 1) == 0)
                    return 0;
                Grille[i][j] = 0;
            }
        }
    }
    else
    {
        if(resoudreGrille(Grille, pos + 1) == 0)
            return 0;
    }
    return 1;
}

/*
Initialise une grille avec des zeros
@params	grille      Grille 
*/
void initGrille(int Grille[9][9]){
	memset(Grille,0, 81*sizeof(int));
}

/*
Génére une grille en brute force
@params	grille      Grille
@params	pos			Position en cours de test
@return 1 si aucune erreur, 0 sinon 
*/
int genererGrilleAleatoirement(int Grille[9][9], int pos){
    int i,j,k,nb;
    if(pos > 80) return 1; 
	
    i = pos/9;
	j = pos%9;

	for(k=1; k < 21; k++){
		nb = rand()%9 + 1; 
		if (testerCase(Grille, i, j, nb))
        {
			Grille[i][j] = nb;
			if(genererGrilleAleatoirement(Grille, pos+1)) return 1;
		}
	}
    
    Grille[i][j] = 0;
    return 0; 
}

/*
Copie une grille vers une autre
@params	de      Grille source
@params	a       Grille dest
*/
void copierGrille(int de[9][9],int a[9][9]){
	memcpy(a, de, 81*sizeof(int));
}

/*
Procède à l'effacement de 81-nbPresent cases en s'assurant à chaque suppression de l'unicité de la solution.
@params	Grille       Grille 
@params	nbPresent    Nombre d'éléments à conserver
*/
void effacerCases(int Grille[9][9],int nbPresent){

    int i,j,nbEffacement = 81 - nbPresent, nbEssai =0, tmp;
    while(nbEffacement > 0) {
		
		nbSol = 0;
		
        do {
			i=rand()%9;
			j=rand()%9;
        } while (Grille[i][j]== 0);
	
		tmp = Grille[i][j];
        Grille[i][j] = 0;
		
		if(solutionUnique(Grille))
			nbEffacement--;
		else
			Grille[i][j] = tmp;
		
		nbEssai++;
		if(nbEssai > 200){
			printf("il reste %d case(s) a supprimer\n",nbEffacement);
			nbEffacement = 0;
		}
		
    }
}

/*
Test l'unicité de solution
@params Grille    Grille
@return 1 si solution unique, 0 sinon
*/
int solutionUnique(int Grille[9][9]){
	int tmp[9][9],flag;
	nbSol = 0;
	copierGrille(Grille,tmp);
	flag = resoudreGrille(Grille,0);
	copierGrille(tmp,Grille);
	return flag;
}

/*
Genere une grille avec choix de méthode
@params Grille    Grille
@params methode    1 permutation, 0 bruteforce
*/
void genererGrille(int Grille[9][9], int methode){
initGrille(Grille);
(methode == 0) ? genererGrilleAleatoirement(Grille,0) : genererGrillePermutations(Grille);
}
