#include "vector2f.h"

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