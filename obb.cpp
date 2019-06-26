#include "obb.h"
#include <cmath>
bool obb::intersects(obb &other)
{
  float distanceVector[2] = {
      other._x - _x,
      other._y - _y
  };

  for (int i = 0; i < 2; ++i) {
      if (getProjectionRadius(_vectors[i]) + other.getProjectionRadius(_vectors[i])
          < dot(distanceVector, _vectors[i])) {
          return false;
      }
      if (getProjectionRadius(other._vectors[i]) + other.getProjectionRadius(other._vectors[i])
          < dot(distanceVector, other._vectors[i])) {
          return false;
      }
  }

  return true;
}

void obb::resetVector()
{
  _vectors[0][0] = cos(_rotation);
  _vectors[0][1] = sin(_rotation);
  _vectors[1][0] = -_vectors[0][1];
  _vectors[1][1] = _vectors[0][0];
}


float obb::dot(float a[2], float b[2])
{
  return abs(a[0] * b[0] + a[1] * b[1]);
}
float obb::getProjectionRadius(float vector[2])
{
  return (_width * dot(_vectors[0], vector) / 2
      + _height * dot(_vectors[1], vector) / 2);
}
