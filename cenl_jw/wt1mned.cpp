#include <stdio.h>
#include "wt10kned.h"

void WaardeTot1000000InLetters(long getal)
{
	int duizendtal;
	int rest;

	duizendtal = getal / 1000;

	if (getal >= 0 && getal < 1000000) {
		if (getal == 0) {
			printf("nul");
		}
		else {
			if (duizendtal >= 10) {
				WaardeTot10000InLetters(duizendtal);
				printf(" duizend");
				rest = getal % 1000;
				if (rest > 0) {
					printf(" ");
				}
			}
			else {
				rest = getal;
			}
			if (rest > 0) {
				WaardeTot10000InLetters(rest);
			}
		}
	}
}