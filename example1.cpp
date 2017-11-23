#include <ios>
#include <iostream>
#include <ostream>
#include <string>
#include <variant>

int main() {
  std::variant<int, std::string, bool> var1;

  // (1) Access with std::get
  var1 = std::string("Hello, there!");
  auto str = std::get<std::string>(var1);
  std::cout << str << std::endl;

  // (2) std::bad_variant_access
  var1 = false;
  // int i = std::get<int>(var1); // throws
  var1 = std::string("Hello, there!");

  // auto str = std::get<std::string>(var1); // throws

  // (3) Access by index
  // str = std::get<0>(var1); // compiler warning
  str = std::get<1>(var1);
  std::cout << str << std::endl;

  // (4) std::get_if
  std::variant<int, float> number{42};
  if (auto val = std::get_if<int>(&number)) {
    std::cout << "variant value: " << *val << std::endl;
  } else {
    std::cout << "failed to get value!" << std::endl;
  }

  // (5) std::holds_alternative
  std::variant<int, std::string> var2 = "xyz";
  std::cout << std::boolalpha << "variant holds int? "
            << std::holds_alternative<int>(var2) << "\n"
            << "varaint holds string? "
            << std::holds_alternative<std::string>(var2)
            << std::endl;

  // (6) variant::index() returns the index of the current
  // alternative (or 0)
  std::cout << "var2.index() = " << var2.index() << std::endl;
  var2 = {};
  std::cout << "var2.index() = " << var2.index() << std::endl;

  return 0;
}
