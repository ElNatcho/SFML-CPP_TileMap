#ifndef TILEMAPMGR_HPP
#define TILEMAPMGR_HPP

#include<SFML\Graphics.hpp>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

#define SAFE_DELETE(X) {if(X != NULL){delete(X);}} //Makro for deleting a pointer save

class TileMapMgr
{
public:
	TileMapMgr(sf::RenderWindow *rWin); //Konstuktor
	~TileMapMgr(); //Destrukor

	void LoadData(std::string sFileDir);    //Method for loading the map data
	void BuildMap(std::string sTileSetDir, std::map<char, sf::IntRect> TextureRectData); //Method for building the map
	void Update();   //Method for updating the map
	void Draw();     //Method for drawing the map

private:
	sf::RenderWindow *_window; //Pointer on the main window

	std::string _sFileDir;  //Direction of the file with the map-data
	std::string _sTileSetDir; //Direction of the tile set
	std::string _sTempData; //Temporary string for the map-data
	std::fstream _fstream;  //Fstream for opening and reading the file with the map-data

	std::map<char, sf::IntRect> _TextureRectData; //A map for the .setTextureRect funct of the temp sprites
	  
	std::vector<std::string> _MapDataMatrix; //String vector (matrix) for the map-data

	sf::Texture _tempTileTexture; //Temporary texture for the building method bzw the temp sprite
	sf::Sprite  _tempTileSprite;  //Temporary sprite for the building method bzw the temp vector
	
	std::vector<sf::Sprite> _tempSpriteVector; //Temporary sprite vector for the building method bzw the tile matrix
	std::vector<std::vector<sf::Sprite>> _TileMapMatrix; //Sprite matrix representing the tile map

};

#endif