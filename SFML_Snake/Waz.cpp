#include "stdafx.h"
#include "Waz.h"


Waz::Waz()
{
	kierunek = 0;
	dlugoscWeza = 1;
	szerokosc = 40;
	wysokosc = 25;
	ogon[0].x = 15;
	ogon[0].y = 10;
	for (int i = 0; i < 1000; i++) {
		ogon[i].x = -5;
		ogon[i].y = -5;
	}
}


Waz::~Waz(){}

sf::Vector2i	Waz::nowaPozycjaDlaBonusa() {
	int tx, ty;
	bool ok= false;
	tx = (rand() % szerokosc);
	ty = (rand() % wysokosc);
	
	do
	{
		for (int i = 0; i < dlugoscWeza; i++) {
			if (tx != ogon[i].x && ty != ogon[i].y)
				ok = true;
		}
	} while (ok==false);

	return sf::Vector2i(tx, ty);
}

bool Waz::czyWazSieZjada() {
	for (int i = 1; i<dlugoscWeza; i++)
		if (ogon[0].x == ogon[i].x && ogon[0].y == ogon[i].y)  return true;
	return false;	// nie zjada siê
}

void Waz::setKierunek(int nowyKierunek) {
	if (nowyKierunek == 1 && kierunek != 2) {
		kierunek = 1;
		return;
	}
	if (nowyKierunek == 2 && kierunek != 1) {
		kierunek = 2;
		return;
	}
	if (nowyKierunek == 3 && kierunek != 4) {
		kierunek = 3;
		return;
	}
	if (nowyKierunek == 4 && kierunek != 3) {
		kierunek = 4;
		return;
	}
}

void Waz::updateMe() {
	for (int i = dlugoscWeza; i>0; --i)
	{
		ogon[i].x = ogon[i - 1].x;
		ogon[i].y = ogon[i - 1].y;
	}

	if (kierunek == 1) ogon[0].x--;
	if (kierunek == 2) ogon[0].x++;
	if (kierunek == 3) ogon[0].y--;
	if (kierunek == 4) ogon[0].y++;

	if (ogon[0].x < 0)	ogon[0].x = szerokosc-1;
	if (ogon[0].x > szerokosc-1)	ogon[0].x = 0;
	if (ogon[0].y < 0)	ogon[0].y = wysokosc-1;
	if (ogon[0].y > wysokosc-1)	ogon[0].y = 0;

}

