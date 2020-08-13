#pragma once
#include"pch.h"
#include <SFML/Graphics.hpp>
#include <map>
#include "areamap.h"
using namespace sf;

const int gridx = 31, gridy = 21;
areamap ver[gridy];
int visited[gridx][gridy];
int cycle[gridx][gridy];

void cycleFinder(int x,int y,int color,int prevx,int prevy);

bool withinBounds(int min, int max, int num);

int main() {
	int res1 = 1440, res2 = 900;
	const float xlength = res1 / gridx, ylength = res2 / gridy;
	int x_grid, y_grid;
	Sprite grid[gridx][gridy];

	VideoMode vm(res1, res2);
	RenderWindow window(vm, "KLON", Style::Fullscreen);

	Texture textureBackground;
	textureBackground.loadFromFile("graphics/arena.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);

	Texture textureRomanSoldier;
	textureRomanSoldier.loadFromFile("graphics/Roman-tsereg.png");

	Texture textureHunSoldier;
	textureHunSoldier.loadFromFile("graphics/Hunnu-tsereg.png");

	bool acceptInput = true;
	bool ifHun = false;

	Event event;
	while (window.isOpen()) {
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}
		if (Mouse::isButtonPressed(Mouse::Left) && acceptInput == true) {

			Vector2i cursor = Mouse::getPosition();
			if (cursor.x >= 0 && cursor.x <= res1-20 && cursor.y >= 0 && cursor.y <= res2-20) {
				x_grid = float(cursor.x) / xlength;
				y_grid = float(cursor.y) / ylength;
				if (cycle[x_grid][y_grid] == 0) {
					if (ifHun) {
						cycle[x_grid][y_grid] = -1;
						ifHun = false;
						memset(visited, 0, sizeof(visited));
						cycleFinder(x_grid, y_grid, -1,-1,-1);
					}
					else {
						cycle[x_grid][y_grid] = -2;
						ifHun = true;
						memset(visited, 0, sizeof(visited));
						cycleFinder(x_grid, y_grid, -2,-1,-1);
					}
				}
			}

			acceptInput = false;
		}
		while (window.pollEvent(event)) {
			if (event.type == Event::MouseButtonReleased) {
				acceptInput = true;
			}
		}
		window.clear();
		window.draw(spriteBackground);
		for (int i = 0; i < gridx; i++) {
			for (int j = 0; j < gridy; j++) {
				if (cycle[i][j] == -1) {
					grid[i][j].setTexture(textureHunSoldier);
					grid[i][j].setScale(0.05, 0.05);
					grid[i][j].setPosition(i * xlength, j * ylength);
					window.draw(grid[i][j]);
				}
				else if (cycle[i][j] == -2) {
					grid[i][j].setTexture(textureRomanSoldier);
					grid[i][j].setScale(0.05, 0.05);
					grid[i][j].setPosition(i * xlength, j * ylength);
					window.draw(grid[i][j]);
				}
			}
		}
		window.display();
	}
}

bool withinBounds(int min, int max, int num) {
	if (min <= num && num <= max) {
		return true;
	}
	return false;
}

void cycleFinder(int x, int y, int target, int prevx, int prevy) {
	for (int i = x - 1; i < x + 2; i++) {
		for (int j = y - 1; j < y + 2; j++) {
			if (x == i && y == j)continue;
			else if ((visited[i][j] == 0 && cycle[i][j] == target) || (visited[i][j] == 1 && i != prevx && j != prevy)) {
				

			}
		}
	}
}