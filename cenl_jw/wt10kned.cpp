#include <stdio.h>
#include "wt100ned.h"

void WaardeTot10000InLetters(int getal)
{
	int honderdtal;
	int rest;

	honderdtal = getal / 100;
	rest = getal % 100;

	if (getal >= 0 && getal < 10000) {
		if (getal == 0) {
			printf("nul");
		}
		else {
			if (getal > 999 && honderdtal % 10 == 0) {
				if (getal > 1099) {
					WaardeTot100InLetters(honderdtal / 10);
					printf(" ");
				}
				printf("duizend");
			}
			else if (honderdtal > 0){
				if (honderdtal > 1) {
					WaardeTot100InLetters(honderdtal);
					printf(" ");
				}
				printf("honderd");					
			}
			if (getal > 100 && rest > 0) {
				printf(" ");
			}
			if (rest > 0) {
				WaardeTot100InLetters(rest);
			}
		}
	}
}
