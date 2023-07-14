#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
// #include "vector2f.h"

const sf::Vector2f SLIDER_SIZE(50, 25);
const sf::Vector2f CRANE_EXTENTION_SIZE(200, 24);

struct Vector2f
{
    float x;
    float y;

    Vector2f(){}

    Vector2f(float x, float y){
        this->x = x;
        this->y = y;
    }
};

void operator+=(Vector2f& vec1, Vector2f& vec2){
    vec1.x += vec2.x;
    vec1.y += vec2.y;
}
Vector2f operator/(Vector2f& vec, float& divisor){
    vec.x = vec.x/divisor;
    vec.y = vec.y/divisor;
    return vec;
}
Vector2f operator*(Vector2f& vec, float& num){
    vec.x = vec.x*num;
    vec.y = vec.y*num;
    return vec;
}

class MassBody{
    private:
        float mMass;
        Vector2f mPosition;
        Vector2f mVelocity;
        Vector2f mForce;
    public:
        MassBody(float mass){
            this->mMass = mass;
            mForce.x = 0;
            mForce.y = 0;
        }

        void applyForce(Vector2f force){
            this->mForce += force;
        }   

        void simulate(float dt){
            Vector2f acceleration = mForce / mMass;

            mVelocity = acceleration * dt;

            mPosition = mVelocity * dt;
        }
};

class Spring{
    private:
        MassBody* mMass1;
        MassBody* mMass2;

        float mSpringConstant;                           // A Constant To Represent The Stiffness Of The Spring
        float mSpringLength;                         // The Length That The spring Does Not Exert Any Force
        float mFrictionConstant;                         // A Constant To be Used For The Inner Friction
    public:
        Spring(MassBody* mass1, MassBody* mass2, float springConstant, float springLength, float frictionConstant){
            this->mMass1 = mass1;
            this->mMass2 = mass2;

            this->mSpringConstant = springConstant;
            this->mSpringLength = springLength;
            this->mFrictionConstant = frictionConstant;
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

    sf::Sprite crane_sprite;                                        // defining sprite of the crane
    crane_sprite.setTexture(texture);
    sf::RectangleShape crane_sprite_extention;
    crane_sprite_extention.setSize(CRANE_EXTENTION_SIZE);           // extending the length of the crane sprite using recteangle shape
    crane_sprite_extention.setFillColor(sf::Color(255,235,59));
    crane_sprite_extention.setPosition(600,75);

    sf::RectangleShape slider;                                      // defining slieder whitch is the moving part of the crane
    slider.setSize(SLIDER_SIZE);
    slider.setFillColor(sf::Color(180,180,180));
    slider.setPosition(300,95);

    float dt = 0.001;
    Vector2f dupa(5.,6.);

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