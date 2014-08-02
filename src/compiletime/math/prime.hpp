#ifndef PRIME_HPP_INCLUDED
#define PRIME_HPP_INCLUDED

#include <compiletime/core.hpp>
#include <compiletime/math/sqrt.hpp>

namespace compiletime
{
namespace math
{

template<size_t num, size_t t>
struct CheckDivisibility
{
  static const size_t value = util::StaticCheck< (num % t) == 0,
                                                 bool,
                                                 util::evaluate<bool, true>,
                                                 CheckDivisibility<num, t - 1>
                                                >::value;
};

template<size_t num>
struct CheckDivisibility<num, 1>
{
  static const bool value = false;
};

template <size_t num>
struct IsPrime
{
  static const bool value = !CheckDivisibility<num, c_sqrt(num)>::value;
};

}
}

#define c_isPrime(x) compiletime::math::IsPrime<x>::value

#endif // PRIME_HPP_INCLUDED
