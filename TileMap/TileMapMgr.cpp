#include"TileMapMgr.hpp"

TileMapMgr::TileMapMgr(sf::RenderWindow *rWin)
{
	std::cout << ">TileMapMgr: Konstruktor." << std::endl;

	//_window = new sf::RenderWindow(); //Declare the pointer of the main window
	_window = rWin; //Set the value of the pointer
}

void TileMapMgr::LoadData(std::string sFileDir)
{
	std::cout << ">TileMapMgr: Loading Map Data..." << std::endl;
	_sFileDir = sFileDir; //Set the value of the file path variable
	_fstream.open(_sFileDir); //Open the file with the map data
	while (!_fstream.eof()){   //Check wether the last line of the file is reached
		std::getline(_fstream, _sTempData); //Get the current line and set it to the value of the temp string
		_MapDataMatrix.push_back(_sTempData); //Insert the temp string into the string vector
	}
	std::cout << ">TileMapMgr: HEIGHT = " << _MapDataMatrix.size() << std::endl;		 //Show the height of the tile map
	std::cout << ">TileMapMgr: WIDHT  = " << _MapDataMatrix.at(0).length() << std::endl; //Show the width of the tile map
	for (int i = 0; i < _MapDataMatrix.size(); i++){ //Show the data of the array in the console
		std::cout << ">TileMapMgr: MapData = " << _MapDataMatrix.at(i) << std::endl;
	}
	std::cout << ">TileMapMgr: Loading finished." << std::endl;
}

void TileMapMgr::BuildMap(std::string sTileSetDir, std::map<char, sf::IntRect> TextureRectData)
{
	std::cout << ">TileMapMgr: Building the TileMap..." << std::endl;
	_TextureRectData = TextureRectData; //Set the value of the map for the TextureRectData
	_sTileSetDir = sTileSetDir; //Set the value of the path var to the tile set
	for (int y = 0; y < _MapDataMatrix.size(); y++){
		for (int x = 0; x < _MapDataMatrix.at(y).length(); x++){
			switch (_MapDataMatrix.at(y).at(x)){
			case '0':
				_tempTileTexture.loadFromFile(_sTileSetDir);  //Load the texture of the temp texture
				_tempTileSprite.setTexture(_tempTileTexture); //Set the texture to the temp sprite
				_tempTileSprite.setTextureRect(_TextureRectData.at(_MapDataMatrix.at(y).at(x))); //Set a specific rect as texture 
				_tempTileSprite.setPosition(50 * x, 50 * y);  //Set the position of the temp sprite
				_tempSpriteVector.push_back(_tempTileSprite); //Insert the temp sprite in the temp vector
				break;

			case '1':
				_tempTileTexture.loadFromFile(_sTileSetDir);  //Load the texture of the temp texture
				_tempTileSprite.setTexture(_tempTileTexture); //Set the texture to the temp sprite
				_tempTileSprite.setTextureRect(_TextureRectData.at(_MapDataMatrix.at(y).at(x))); //Set a specific rect as texture 
				_tempTileSprite.setPosition(50 * x, 50 * y);  //Set the position of the temp sprite
				_tempSpriteVector.push_back(_tempTileSprite); //Insert the temp sprite in the temp vector
				break;

			default:
				std::cout << ">TileMapMgr: FATAL ERROR!" << std::endl;
				std::cout << ">TileMapMgr: No defined character at POSITION(" << x << "|" << y << ")." << std::endl;
				break;
			}
		}
		_TileMapMatrix.push_back(_tempSpriteVector); //Insert the temp sprite vector in the tile matrix
		_tempSpriteVector.clear(); //Clear the temp sprite matrix
	}
	std::cout << ">TileMapMgr: Building finished" << std::endl;
}

void TileMapMgr::Update()
{

}

void TileMapMgr::Draw()
{
	for (int y = 0; y < _TileMapMatrix.size(); y++){
		for (int x = 0; x < _TileMapMatrix.at(y).size(); x++){
			_window->draw(_TileMapMatrix.at(y).at(x)); //Draw the tile at pos x y
		}
	}
}

TileMapMgr::~TileMapMgr() { std::cout << ">TileMapMgr: Destruktor." << std::endl; }