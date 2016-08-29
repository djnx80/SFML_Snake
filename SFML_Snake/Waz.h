#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Waz
{
private:
	struct Ogon {
		int x, y;
	}	ogon[1000];
	int dlugoscWeza;
	int kierunek;	// 0-stoj, 1-lewo, 2-prawo, 3-gora, 4-dol
	int szerokosc;	// szerokosc i wysokosc planszy w jednostach [rozmiar]
	int wysokosc;
	int przyrostDlugosci;

public:
	Waz();
	~Waz();

	void updateMe();
	bool czyWazSieZjada();
	sf::Vector2i nowaPozycjaDlaBonusa();

	void addDlugoscWeza(int ile) { dlugoscWeza = dlugoscWeza + ile; }
	int getDlugoscWeza() { return dlugoscWeza; }
	void setKierunek(int);
	int getKierunek() { return kierunek; }
	int getOgonX(int index) { return ogon[index].x; }
	int getOgonY(int index) { return ogon[index].y; }



};

