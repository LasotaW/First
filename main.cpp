#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Snake!");
	sf::Event event;

	// make and declare texture variables //
	sf::Texture t1, t2;
	t1.loadFromFile("images/white.png");
	t2.loadFromFile("images/red.png");

	sf::Sprite sprite1(t1);
	sf::Sprite sprite2(t2);

	int textureSize = 16;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			window.display();
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		for(int i=0; i<textureSize; i++)
			for (int j = 0; j <textureSize; j++)
			{
				sprite1.setPosition(i*textureSize, j*textureSize);
				window.draw(sprite1);
			}


	}
	return 0;
}