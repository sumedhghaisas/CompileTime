#ifndef STATIC_CHECK_HPP_INCLUDED
#define STATIC_CHECK_HPP_INCLUDED

namespace compiletime
{
namespace util
{

template <bool cond, typename ret, typename t1, typename t2>
struct StaticCheck
{};

template <typename ret, typename t1, typename t2>
struct StaticCheck<true, ret, t1, t2>
{
  static const ret value = t1::value;
};

template <typename ret, typename t1, typename t2>
struct StaticCheck<false, ret, t1, t2>
{
  static const ret value = t2::value;
};

}
}

#endif // STATIC_CHECK_HPP_INCLUDED
