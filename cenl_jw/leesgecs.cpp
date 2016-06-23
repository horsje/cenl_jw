#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "leesgecs.h"

int LeesGetalCheckStop(long *waarde)	
{
	long getal;
	int cijfers;
	int symbol;
	int teken;

	for (; ; )		//Start oneindige lus
	{
		printf("Voer een getal in van maximaal 6 cijfers (x om te stoppen)> ");

		for (getal = 0, cijfers = 0, teken = 1; ; )
		{
			symbol = getchar();
			if (symbol == '\n')
			{
				if (!cijfers)	//Blokkering weergave default waarde van getal.
				{				//Er moet 0 ingevoerd worden om "nul" weer te geven.	
					break;
				}
				*waarde = getal * teken;
				return (GADOOR);
			}
			else if (symbol == ' ')
			{
				;	//Verwijderen (voorloop) spaties, met niets doen, input buffer wordt
			}		//wel geleegd.
			else if (symbol == 'x' || symbol == 'X')
			{
				return (STOP);
			}
			else if (isdigit(symbol))
			{
				if (cijfers >= 6)	//controle op aantal ingevoerde cijfers, telling begint bij nul
				{
					printf("\n\n*** fout - meer dan 6 cijfers ingevoerd, "
						"opnieuw invoeren svp\n\n\n");
					while (getchar() != '\n');
					break;
				}
				getal = getal * 10 + (symbol - '0');
				cijfers++;
			}
			else
			{
				if (symbol == '-' && cijfers == 0)
					teken = -1;
				else
				{
					printf("\n\n*** fout - ongeldig symbool '%c', "
						"opnieuw invoeren svp\n\n\n", symbol);

					while (getchar() != '\n');		//Leegmaken input buffer
					break;
				}
			}
		}
	}
}