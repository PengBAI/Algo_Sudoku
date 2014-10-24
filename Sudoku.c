/*
*  Polytech Tours, France
* All right reserved to Pengt BAI
*/
#include "fonctionsSudoku.h"


int main()
{
	srand(time(NULL));
    int Grille[9][9];

    while(1)
    {
		genererGrille(Grille,1);
		effacerCases(Grille,nbRemplies);
		afficherGrille(Grille);
    }
    return 0;
}
