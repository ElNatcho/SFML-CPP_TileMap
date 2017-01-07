#include<SFML\Graphics.hpp>
#include<iostream>
#include<map>

#include"TileMapMgr.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(650, 400), "Tile Map");
	sf::Event sfEvent;

	std::map<char, sf::IntRect> TexRectData;
	TexRectData.insert(std::make_pair('0', sf::IntRect(50,0,50,50)));
	TexRectData.insert(std::make_pair('1', sf::IntRect(0,0,50,50)));

	TileMapMgr TileMap(&window);
	TileMap.LoadData("Map.txt");
	TileMap.BuildMap("TileSet.png", TexRectData);

	while (window.isOpen()){
		while (window.pollEvent(sfEvent)){
			if (sfEvent.type == sf::Event::Closed){
				window.close();
			}
		}
		window.clear();

		TileMap.Draw();

		window.display();
	}

	return 0;
}