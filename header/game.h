#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

class game
{
private:
	int width, height;
	std::string title;
	std::unique_ptr< sf::RenderWindow> window;
	bool run{};
	sf::Event event{};
	void setup();

public:
	
	game();
	~game() = default;

	void start();

};

