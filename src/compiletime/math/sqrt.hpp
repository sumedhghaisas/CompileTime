#ifndef SQRT_HPP_INCLUDED
#define SQRT_HPP_INCLUDED

#include <compiletime/core.hpp>

namespace compiletime
{
namespace math
{

template<size_t num, size_t bit>
struct Incre
{
  static const size_t n_bit = bit >> 2;
  static const size_t value = util::StaticCheck< (bit > num),
                                                  size_t,
                                                  Incre<num, n_bit>,
                                                  util::evaluate<size_t, bit>
                                               >::value;
};

template<size_t num, size_t bit, size_t res>
struct IntSqrt
{
  typedef util::StaticCheck<  (num >= res + bit),
                             size_t,
                             util::evaluate<size_t, num - (res + bit)>,
                             util::evaluate<size_t, num>
                             >
          cond1_num;
  typedef util::StaticCheck<  (num >= res + bit),
                             size_t,
                             util::evaluate<size_t, (res >> 1) + bit>,
                             util::evaluate<size_t, (res >> 1)>
                          >
          cond1_res;

  static const size_t value = util::StaticCheck<  bit != 0,
                                                  size_t,
                                                  IntSqrt< cond1_num::value,
                                                           (bit >> 2),
                                                           cond1_res::value>,
                                                  util::evaluate<size_t, res>
                                               >::value;
};

template<size_t num>
struct IntSqrtCaller
{
  static const size_t init = 1 << 30;
  static const size_t bit = Incre<num, init>::value;
  static const size_t value = IntSqrt<num, bit, 0>::value;
};

}
}

#define c_sqrt(a) compiletime::math::IntSqrtCaller<a>::value

#endif // SQRT_HPP_INCLUDED
