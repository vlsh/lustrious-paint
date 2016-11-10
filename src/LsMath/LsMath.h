//===============================================================================
// @ LsMath.
// 
// Base math macros and functions
// ------------------------------------------------------------------------------
// Copyright (C) 2004 by Elsevier, Inc. All rights reserved.
//
//===============================================================================

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

//#include "IvTypes.h"
#include <math.h>
#include <algorithm>

#define kEpsilon    1.0e-6f

#define kPI         3.1415926535897932384626433832795f
#define kHalfPI     1.5707963267948966192313216916398f
#define kTwoPI      2.0f*kPI

#ifdef PLATFORM_OSX
#define sqrtf sqrt
#define sinf sin
#define cosf cos
#define fabsf fabs
#define tanf tan
#define atan2f atan2
#define acosf ac
#endif

inline float IvSqrt( float val )        { return sqrtf( val ); }
inline float IvInvSqrt( float val )     { return 1.0f/sqrtf( val ); }
inline float IvAbs( float f )           { return fabsf(f); }

//-------------------------------------------------------------------------------
//-- Classes --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//-- Functions ------------------------------------------------------------------
//-------------------------------------------------------------------------------
extern void IvFastSinCos( float a, float& sina, float& cosa );

//-------------------------------------------------------------------------------
//-- Inlines --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
// @ IsZero()
//-------------------------------------------------------------------------------
// Is this floating point value close to zero?
//-------------------------------------------------------------------------------
inline bool IsZero( float a ) 
{
    return ( fabsf(a) < kEpsilon );

}   // End of IsZero()

//-------------------------------------------------------------------------------
// @ IvAreEqual()
//-------------------------------------------------------------------------------
// Are these floating point values close to equal?
//-------------------------------------------------------------------------------
inline bool IvAreEqual( float a, float b ) 
{
    return ( ::IsZero(a-b) );

}   // End of IvAreEqual()

//-------------------------------------------------------------------------------
// @ LsAreEqualRelative()
//-------------------------------------------------------------------------------
// Same as IvAreEqual, but using more advanced method.
//-------------------------------------------------------------------------------
inline bool LsAreEqualRelative(float a, float b) {
    const float absA = std::abs(a);
    const float absB = std::abs(b);
    const float diff = std::abs(a - b);

    if (a == b) { // shortcut, handles infinities
      return true;
    } else if (a == 0 || b == 0 || diff < FLT_MIN) {
      // a or b is zero or both are extremely close to it
      // relative error is less meaningful here
      return diff < (kEpsilon * FLT_MIN);
    } else { // use relative error
      return diff / std::min((absA + absB), FLT_MAX) < kEpsilon;
    }
}

//-------------------------------------------------------------------------------
// @ IvSin()
//-------------------------------------------------------------------------------
// Returns the floating-point sine of the argument
//-------------------------------------------------------------------------------
inline float IvSin( float a )
{
    return sinf(a);

}  // End of IvSin


//-------------------------------------------------------------------------------
// @ IvCos()
//-------------------------------------------------------------------------------
// Returns the floating-point cosine of the argument
//-------------------------------------------------------------------------------
inline float IvCos( float a )
{
    return cosf(a);

}  // End of IvCos


//-------------------------------------------------------------------------------
// @ IvTan()
//-------------------------------------------------------------------------------
// Returns the floating-point tangent of the argument
//-------------------------------------------------------------------------------
inline float IvTan( float a )
{
    return tanf(a);

}  // End of IvTan

//-------------------------------------------------------------------------------
// @ IvSinCos()
//-------------------------------------------------------------------------------
// Returns the floating-point sine and cosine of the argument
//-------------------------------------------------------------------------------
inline void IvSinCos( float a, float& sina, float& cosa )
{
    sina = sinf(a);
    cosa = cosf(a);

}  // End of IvSinCos

inline bool LsOdd(int x) {
  return x % 2;
}

inline bool LsEven(int x) {
  return !(x % 2);
}

//-------------------------------------------------------------------------------
// @ LsOddCount()
//-------------------------------------------------------------------------------
// Returns a count of odd numbers on the closed interval [min, max]
//-------------------------------------------------------------------------------
inline int LsOddCount(int min, int max) {
  int N = max - min;
  if ( LsEven(min) )
  {
    return std::ceil(N/2.0f);
  } else {
    return std::floor(N/2.0f) + 1;
  }
}

//-------------------------------------------------------------------------------
// @ LsEvenCount()
//-------------------------------------------------------------------------------
// Returns a count of even numbers on the closed interval [min, max]
//-------------------------------------------------------------------------------
inline int LsEvenCount(int min, int max) {
  int N = max - min;
  if ( LsOdd(min) )
  {
    return std::ceil(N/2.0f);
  } else {
    return std::floor(N/2.0f) + 1;
  }
}

//-------------------------------------------------------------------------------
//-- Externs --------------------------------------------------------------------
//-------------------------------------------------------------------------------
