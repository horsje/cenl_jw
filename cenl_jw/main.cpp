#include <stdio.h>
#include "wt1mned.h"
#include "leesgecs.h"

int main(void)
{
	long getal;

	while (LeesGetalCheckStop(&getal) != STOP) 
	{
        printf("\nDe waarde van het getal %li is in letters:\n\n", getal);
		printf("--->");

		if (getal < 0)
		{
			getal = -1 * getal;		//min teken wordt verwijderd
			printf("min ");			//en in tekst weergegeven.
		}

		WaardeTot1000000InLetters(getal);	//Positieve integer naar functie, voor 
		printf("<---\n\n");					//omzetting naar tekst.
	}

	return 0;
}
