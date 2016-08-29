#include "stdafx.h"
#include "Plansza.h"


Plansza::Plansza()
{

	czasPauzy = 100;
	rozmiar = 20;
	szerokosc = 40;
	wysokosc = 25;
	punkty = 0;
	zycia = 5;
	ileZjedzonychBonusow = 0;
	poziom = 1;
	if (!font.loadFromFile("BornAddict.ttf"))
	{
		cout << "Nie udalo sie wczytac czcionki" << endl;
	}
}


Plansza::~Plansza()
{
}

sf::Text Plansza::wyswietlDane(int dlugoscW) {

	// wybranie czcionki
	napis.setFont(font);
	napis.setCharacterSize(24); // w pikselach, nie punktach!
	napis.setColor(sf::Color::White);
	sf::String coWyswietlic = "Witaj w grze Snake\n Punkty " + to_string(punkty) + "   Zycia " + to_string(zycia) + "     Ilosc blokow " + to_string(dlugoscW) + "  Czas Pauzy " + to_string(czasPauzy);
	napis.setString(coWyswietlic);
	napis.setPosition(20, 520);
	return napis;
}




