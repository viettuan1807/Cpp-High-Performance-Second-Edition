#include "./lin_value.h"

#include <gtest/gtest.h>

#if defined(__cpp_concepts)
#include <concepts>
#endif // __cpp_concepts

#include <sstream>
#include <vector>

namespace {

#if defined(__cpp_concepts)

template <typename T, typename F>
requires std::invocable<F&, const T&> 
void lin_space(T start, T stop, size_t n, F&& f) {
  for (auto i = 0u; i < n; ++i) {
    const auto y = lin_value(start, stop, i, n);
    f(y);
  }
}

#else 

template <typename T, typename F>
void lin_space(T start, T stop, size_t n, F&& f) {
  for (auto i = 0u; i < n; ++i) {
    const auto y = lin_value(start, stop, i, n);
    f(y);
  }
}

#endif // __cpp_concepts

} // namespace


TEST(LinSpaceCallback, Example) {

  std::ostringstream os;
  auto print = [&](auto v) { os << v << ", "; };
  lin_space(-1.f, 1.f, 5, print);

   ASSERT_EQ("-1, -0.5, 0, 0.5, 1, ", os.str());
}