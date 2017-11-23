#include <ios>
#include <iostream>
#include <ostream>
#include <string>
#include <variant>

template <typename... T> class overload : T... {
public:
  overload(T... t) : T(t)... {}
  using T::operator()...; // ← variadic using here
};

int main() {

  std::variant<int, std::string, bool> var{42};

  auto x =
      overload(
          [](int) { std::cout << "I am an int" << std::endl; },
          [](std::string) { std::cout << "I am a string" << std::endl; },
          [](auto) { std::cout << "I have no idea what I am" << std::endl; });
  // std::visit(visitor_obj, var);

  return 0;
}
