#include "header/game.h"

void game::setup()
{
	std::ifstream from_file;
	from_file.open("config.txt");
	if (from_file.fail())
	{
		std::cout << "failed to load config file\nsafe config will be used";
		this->width = 852, this->height = 480,this->title = "Snake";
	
	}
	else
	{
		std::string tmp;
		from_file >> tmp;
		this->width = std::stoi(tmp.substr(tmp.find('=') + 1));
		from_file >> tmp;
		this->height = std::stoi(tmp.substr(tmp.find('=') + 1));
		from_file >> tmp;
		this->title = tmp.substr(tmp.find('=') + 1);

	}
	this->window = std::make_unique <sf::RenderWindow>(sf::VideoMode(this->width, this->height), this->title, sf::Style::Close | sf::Style::Titlebar);
}

game::game()
{
	setup();
}



void game::start()
	
{
	this->run = true;
	while (run)
	{
		    while (window->pollEvent(this->event))//s
	    {
	        if (this->event.type == sf::Event::Closed)
	            this->window->close();
	    }
		this->window->display();
	}
}
