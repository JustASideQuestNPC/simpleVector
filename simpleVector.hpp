/* MIT License
 *
 * Copyright (c) 2023 Joseph Williams
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once
#include <numbers>
#include <cmath>

namespace simpleVector {
  // these are hard-coded to save a bit of performance
  constexpr float dtrFactor = std::numbers::pi / 180;
  constexpr float rtdFactor = 180 / std::numbers::pi;
  constexpr float tau = 2 * std::numbers::pi;

  enum AngleUnit{
    DEGREES,
    RADIANS
  };
  static AngleUnit defaultAngleUnit = DEGREES;

  // remind me why these aren't part of the standard library?
  template<typename T>
  T degToRad(const T angle) { return static_cast<T>(angle * dtrFactor); } // converts degrees to radians
  template<typename T>
  T radToDeg(const T angle) { return static_cast<T>(angle * rtdFactor); } // converts radians to degrees

  // probably unnecessary, but nice for organization
  template<typename T>
  T sqr(const T x) { return x * x; }

  // the main vector class
  struct Vec2D {
    double x, y;

    // ctors
    Vec2D(const double x, const double y) : x{x}, y{y} {}
    Vec2D() : x{0}, y{0} {}

    // angle/magnitude getters
    double angle(const AngleUnit unit = defaultAngleUnit) const {
      double a = atan2(y, x);
      if (unit == DEGREES) return radToDeg(a);
      else return a;
    }
    double magnitude() const {
      return sqrt(sqr(x) + sqr(y));
    }
  };
}