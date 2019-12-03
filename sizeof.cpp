#include <iostream>

int main(int argc, const char** argv) {
  int value {0};
  std::cout << sizeof(value) << std::endl;

  std::cout << sizeof(long) << std::endl;

  std::cout << sizeof(double) << std::endl;

  std::cout << sizeof(true) << std::endl;

  std::cout << sizeof(10) << std::endl;
  double float_variable {123};
  std::cout << sizeof(float_variable ) << std::endl;
  return 0;
}