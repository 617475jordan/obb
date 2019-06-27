#ifndef _obb_H_
#define _obb_H_

#include <math.h>

class obb {
public:
    obb(float x, float y, float width, float height, float rotation = 0.0f)
        : _x(x), _y(y), _width(width), _height(height), _rotation(rotation) {
        resetVector();
    }

    bool intersects(obb& other) {
        float distanceVector[2] = {
            other._x - _x,
            other._y - _y
        };

        for (int i = 0; i < 2; ++i) {
            if (getProjectionRadius(_vectors[i]) + other.getProjectionRadius(_vectors[i])
                <= dot(distanceVector, _vectors[i])) {
                return false;
            }
            if (getProjectionRadius(other._vectors[i]) + other.getProjectionRadius(other._vectors[i])
                <= dot(distanceVector, other._vectors[i])) {
                return false;
            }
        }

        return true;
    }

private:
    void resetVector() {
        _vectors[0][0] = cos(_rotation);
        _vectors[0][1] = sin(_rotation);
        _vectors[1][0] = -_vectors[0][1];
        _vectors[1][1] = _vectors[0][0];
    }

    float dot(float a[2], float b[2]) {
        return abs(a[0] * b[0] + a[1] * b[1]);
    }

    float getProjectionRadius(float vector[2]) {
        return (_width * dot(_vectors[0], vector) / 2
            + _height * dot(_vectors[1], vector) / 2);
    }

    float _x;
    float _y;
    float _width;
    float _height;
    float _rotation;
    float _vectors[2][2];
};

#endif // _obb_H_
