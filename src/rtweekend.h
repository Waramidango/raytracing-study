#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

// C++ Std Usings

using std::make_shared;
using std::shared_ptr;

// Constants

// double型で表現できる無限大を取得する
const double infinity = std::numeric_limits<double>::infinity();

const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degree) {
    return degree * pi / 180.0;
}

// Common Headers

#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"

#endif