#pragma once

struct Vector2f
{
    float x;
    float y;

    Vector2f();
    Vector2f(float x, float y);
};

void operator+=(Vector2f& vec1, Vector2f& vec2);
Vector2f operator/(Vector2f& vec, float& divisor);
Vector2f operator*(Vector2f& vec, float& num);