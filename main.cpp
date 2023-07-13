#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

const sf::Vector2f SLIDER_SIZE(50, 25);
const sf::Vector2f CRANE_EXTENTION_SIZE(200, 24);

class MassBody{
    private:
        int mMass;
        int mPosX;
        int mPosY; 
        std::vector<int> mVelocity;
        std::vector<int> mAcceleration;
    public:
        void setMass(int x){
            mMass = x;
        }

        std::vector<int> getVelocity(){
            return mVelocity;
        }

        std::vector<int> getAcceleration(){
            return mAcceleration;
        }
};

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
    sf::RectangleShape crane_sprite_extention;
    crane_sprite_extention.setSize(CRANE_EXTENTION_SIZE);
    crane_sprite_extention.setFillColor(sf::Color(255,235,59));
    crane_sprite_extention.setPosition(600,75);

    sf::RectangleShape slider;
    slider.setSize(SLIDER_SIZE);
    slider.setFillColor(sf::Color(180,180,180));
    slider.setPosition(300,95);

    dt = 0.001;
    

    while(window.isOpen()){
        sf::Event event;
        sf::Vector2f offset(7,0);

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.scancode == sf::Keyboard::Scan::D && !(slider.getGlobalBounds().contains(790,95))){
                    slider.move(offset);
                }
                if (event.key.scancode == sf::Keyboard::Scan::A && !(slider.getGlobalBounds().contains(295,95))){
                    slider.move(-offset);
                }
            }

        }

        window.clear(sf::Color(255,255,255));
        window.draw(crane_sprite);
        window.draw(crane_sprite_extention);
        window.draw(slider);
        window.display();
    }

    return 0;
}