#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 700), "Crane Simulator");

    sf::Texture texture;

    if(!texture.loadFromFile("img/crane_image.png")){
        std::cout << "There was an error" << std::endl;
        system("pause");
    }

    sf::Sprite crane_sprite;
    crane_sprite.setTexture(texture);
    

    while(window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        window.clear(sf::Color(255,255,255));
        window.draw(crane_sprite);
        window.display();
    }

    return 0;
}