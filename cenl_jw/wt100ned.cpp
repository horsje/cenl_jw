#include <stdio.h>

static const char* EenTotVeertien[] = {"nul", "een", "twee", "drie", "vier", "vijf", "zes", "zeven", "acht", "negen",
                                       "tien", "elf", "twaalf", "der", "veer"};
static const char* TienTotNegentig[] = {"tig", "tien", "twin", "der", "veer", "vijf", "zes", "zeven", "tach", "negen"};

void WaardeTot100InLetters(int getal)
{
	if (getal >= 0 && getal < 100) {
		if (getal <= 12) {
			printf(EenTotVeertien[getal]);
		}
		else if (getal <= 14) {
			printf("%s%s", EenTotVeertien[getal], TienTotNegentig[getal / 10]);
		}
		else if (getal <= 19) {
			printf("%s%s", EenTotVeertien[getal % 10], TienTotNegentig[getal / 10]);
		}
		else if (getal % 10 == 0) {
			printf("%s%s", TienTotNegentig[getal / 10], TienTotNegentig[0]);
		}
		else if (getal % 10 != 0) {
			printf("%s en %s%s", EenTotVeertien[getal % 10], TienTotNegentig[getal / 10], TienTotNegentig[0]);
		}
	}		
}
