#include <ios>
#include <iostream>
#include <ostream>
#include <string>
#include <variant>

class visitor {
public:
  void operator()(std::string) {
    std::cout << "got a string" << std::endl;
  }
  void operator()(int) {
    std::cout << "got an int" << std::endl;
  }
  void operator()(auto) {
    std::cout << "got something else" << std::endl;
  }
};

int main() {

  std::variant<int, std::string, bool> var{42};

  visitor visitor_obj;
  std::visit(visitor_obj, var);

  return 0;
}
