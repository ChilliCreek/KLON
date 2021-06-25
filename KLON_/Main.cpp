#pragma once
#include"pch.h"
#include <SFML/Graphics.hpp>
#include <map>
#include"TextureHolder.h"


const int rows = 40, columns = 25;
const sf::Vector2f screenResolution(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
sf::Vector2f gridRectSize(screenResolution.x / rows, screenResolution.y / columns);

sf::Vector2i mouseToGrid(sf::Vector2i mousePos) {
	return sf::Vector2i(mousePos.x / gridRectSize.x, mousePos.y / gridRectSize.y);
}

int main() {
	TextureHolder textureHolder;

	sf::Sprite** grid = new sf::Sprite* [columns];
	for (int i = 0; i < columns; i++) {
		grid[i] = new sf::Sprite[rows];
	}

	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			grid[i][j].setPosition(sf::Vector2f(i * gridRectSize.x, j * gridRectSize.y));
		}
	}
	sf::VideoMode vm(screenResolution.x, screenResolution.y);
	sf::RenderWindow window(vm, "KLON", sf::Style::Fullscreen);

	sf::Texture textureBackground;
	textureBackground.loadFromFile("graphics/arena.png");
	sf::Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);

	sf::Texture textureRomanSoldier;
	textureRomanSoldier.loadFromFile("graphics/Roman-tsereg.png");

	sf::Texture textureHunSoldier;
	textureHunSoldier.loadFromFile("graphics/Hunnu-tsereg.png");

	bool ifHun = false;

	sf::Event event;
	while (window.isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2i tileClicked = mouseToGrid(sf::Mouse::getPosition());
				if (ifHun) {

				}
				else {

				}
			}
		}
		window.clear();
		window.draw(spriteBackground);

		window.display();
	}
}