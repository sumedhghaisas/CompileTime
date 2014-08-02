#ifndef EVALUATE_HPP_INCLUDED
#define EVALUATE_HPP_INCLUDED

namespace compiletime
{
namespace util
{

template <typename T, T val>
struct evaluate
{
  static const T value = val;
};

}
}

#define c_eval(a, b) compiletime::util::evaluate<a, b>::value

#endif // EVALUATE_HPP_INCLUDED
