#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Plansza
{

private:

	int czasPauzy;
	int punkty;
	int rozmiar;	// rozmiar obiektu, tutaj 20
	int szerokosc;	// szerokosc i wysokosc planszy w jednostach [rozmiar]
	int wysokosc;
	int zycia;
	int poziom;
	int bonusX;
	int bonusY;
	int ileZjedzonychBonusow;
	sf::Font font;
	sf::Text napis;

public:
	Plansza();
	~Plansza();

	sf::Text wyswietlDane(int);

	void addIleZjedzonychBonusow(int ile) { ileZjedzonychBonusow = ileZjedzonychBonusow + ile; }
	int getIleZjedzonychBonusow() { return ileZjedzonychBonusow; }
	int getCzas() { return czasPauzy; }
	void setCzas(int czas) { czasPauzy = czas; }
	void addPunkty(int ile) { punkty = punkty + ile; }
	int getRozmiar() { return rozmiar; }
	int getSzerokosc() { return szerokosc; }
	int getWysokosc() { return wysokosc; }
	int getBonusX() { return bonusX; }
	int getBonusY() { return bonusY; }
	void setBonusX(int nx) { bonusX = nx; }
	void setBonusY(int ny) { bonusY = ny; }
	void addZycia(int ile) { zycia = zycia + ile; }
//	inline sf::Text getDaneDoWysietlenia() { return napis; }

};

