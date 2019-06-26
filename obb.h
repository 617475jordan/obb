#pragma once
#include <math.h>

class obb {
public:
     obb(float x, float y, float width, float height, float rotation = 0.0f)
        : _x(x), _y(y), _width(width), _height(height), _rotation(rotation) {
        resetVector();
    }
    ~obb()
    {
      resetVector();
    };
    bool intersects(obb & other);

private:
    void resetVector();
    float dot(float a[2], float b[2]);
    float getProjectionRadius(float vector[2]) ;

    float _x;
    float _y;
    float _width;
    float _height;
    float _rotation;
    float _vectors[2][2];
};
