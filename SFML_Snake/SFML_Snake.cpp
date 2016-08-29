#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plansza.h"
#include "Waz.h"

using namespace std;

void rysujWszystko();
bool isCollide(sf::Sprite, sf::Sprite);
void sprawdzKolizje();
void dodajBonus();



sf::Sprite klocek;
sf::Sprite bonus;
sf::Sprite tlo;
Plansza level;
Waz waz;
sf::RenderWindow okno;

int main()
{
	srand(time(0));
	sf::Clock zegar;
	okno.create(sf::VideoMode(800, 600), "Okno");
	okno.setVerticalSyncEnabled(true);	// 60fps

	// wczytaj obiekty
	sf::Image img;
	img.loadFromFile("tlo.png");
	img.createMaskFromColor(sf::Color::White);
	sf::Texture t1, t2, t3;
	t1.loadFromFile("klocek.png");
	t2.loadFromFile("bonus.png");
	t3.loadFromImage(img);
	klocek.setTexture(t1);
	bonus.setTexture(t2);
	tlo.setTexture(t3);

	waz.setKierunek(0);
	dodajBonus();

	while (okno.isOpen())
	{
		zegar.restart();
		sf::Event event;
		while (okno.pollEvent(event)) {
			if (event.type == sf::Event::Closed)	okno.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))	okno.close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 	waz.setKierunek(1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))	waz.setKierunek(2);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))		waz.setKierunek(3);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))		waz.setKierunek(4);

		rysujWszystko();
		sprawdzKolizje();
		waz.updateMe();

		do		{		// odczekaj czas
		} while (zegar.getElapsedTime().asMilliseconds()<level.getCzas());

	}
	return 0;
}

void rysujWszystko() {
	okno.clear();

	// rysuj tlo planszy
	for (int i = 0; i < level.getSzerokosc(); i++)	{
		for (int j = 0; j < level.getWysokosc(); j++)		{
			tlo.setPosition(i*level.getRozmiar(), j*level.getRozmiar());
			okno.draw(tlo);
		}
	}

	// rysuj w꿹
	for (int i = 0; i < waz.getDlugoscWeza(); i++) {
		klocek.setPosition(waz.getOgonX(i)*level.getRozmiar(), waz.getOgonY(i)*level.getRozmiar());
		okno.draw(klocek);
	}

	//	rysuj bonus
	bonus.setPosition(level.getBonusX()*level.getRozmiar(), level.getBonusY()*level.getRozmiar());
	okno.draw(bonus);

	okno.draw(level.wyswietlDane(waz.getDlugoscWeza()));		// rysuj napis
	okno.display();
}

void sprawdzKolizje() {
	// kolizja glowy z bonusem
	if (waz.getOgonX(0) == level.getBonusX() && waz.getOgonY(0) == level.getBonusY()) {
		level.addPunkty(100);
		dodajBonus();
		dodajBonus();
		waz.addDlugoscWeza(3);	// dodaj 1 do ogona
		level.addIleZjedzonychBonusow(1);
		level.setCzas(100 - (level.getIleZjedzonychBonusow() * 2));
	}

	if (waz.czyWazSieZjada() == true) {
		level.addZycia(-1);
		cout << "WAZ SIE ZJADA!" << endl;
	}
}

void dodajBonus() {

	sf::Vector2i nowaPoz =	waz.nowaPozycjaDlaBonusa();

	level.setBonusX(nowaPoz.x);
	level.setBonusY(nowaPoz.y);
}
bool isCollide(sf::Sprite s1, sf::Sprite s2) {
	return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}