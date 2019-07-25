#include <SFML\Graphics.hpp>
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(100.f, 100.f));
	player.setFillColor(sf::Color::Red);
	player.setOrigin(50.0f, 50.0f);
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				std::cout << "New Window Width: "<< e.size.width <<" New Window Height: "<< e.size.height << std::endl;
				break;
			case sf::Event::TextEntered:
				if (e.text.unicode < 128)
				{
					printf("%c", e.text.unicode);

				}
			}
		}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		//{
		//	player.move(-0.1f, 0.0f);
		//}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		//{
		//	player.move(0.1f, 0.0f);
		//}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		//{
		//	player.move(0.0f, -0.1f);
		//}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		//{
		//	player.move(0.0f, 0.1f);
		//
		//}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition((float)mousePos.x, (float)mousePos.y);
		}
		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}