#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

int main()
{
	int x = 0, y = 0;
	int dir = 0;
	int textureSize = 16;
	const float delay = 0.1; //time between snake's moves
	int size = 2; //start value of snake's size

	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML Snake!");
	sf::Event event;

	// declare and define texture variables //
	sf::Texture t1, t2;
	t1.loadFromFile("images/white.png");
	t2.loadFromFile("images/red.png");

	sf::Sprite sprite1(t1);
	sf::Sprite sprite2(t2);

	sf::Clock clock;
	sf::Time time;	//important to make comparison with delay

	while (window.isOpen())	//main window's loop
	{
		while (window.pollEvent(event))	//event to close the window
		{
			window.display();
			if (event.type == sf::Event::Closed)
				window.close();
		}

		for (int i = 0; i < 400; i += 16)	//draw snake board
		{
			for (int j = 0; j < 400; j += 16)
			{
				sprite1.setPosition(i, j);
				window.draw(sprite1);
			}
		}

		 //specifies direction of snake's move
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dir != 1)
			dir = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dir != 0)
			dir = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dir != 3)
			dir = 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dir != 2)
			dir = 3;

		time = clock.getElapsedTime();
			if (time.asSeconds() > delay)
			{
				switch (dir)
				{
				case 0:
					if (x >= 400)
						x = 0;

					sprite2.setPosition(x, y);
					window.draw(sprite2);
					sprite2.setPosition(x - 16, y);
					window.draw(sprite2);
					window.display();
					x += 16;
					clock.restart();
					break;

				case 1:
					if (x <= 0)
						x = 400;

					sprite2.setPosition(x, y);
					window.draw(sprite2);
					sprite2.setPosition(x + 16, y);
					window.draw(sprite2);
					window.display();
					x -= 16;
					clock.restart();
					break;

				case 2:
					if (y >= 400)
						y = 0;

					sprite2.setPosition(x, y);
					window.draw(sprite2);
					sprite2.setPosition(x, y - 16);
					window.draw(sprite2);
					window.display();
					y += 16;
					clock.restart();
					break;

				case 3:
					if (y <= 0)
						y = 400;

					sprite2.setPosition(x, y);
					window.draw(sprite2);
					sprite2.setPosition(x, y + 16);
					window.draw(sprite2);
					window.display();
					y -= 16;
					clock.restart();
					break;
				}
			}
			
	}
	return 0;
}