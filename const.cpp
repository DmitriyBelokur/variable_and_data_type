#include <iostream>

#define MACRO_INT 40

enum {
  FIRST, // равен 0
  SECOND, // равен 1
  THIRD // равен 2
};

enum {
  FORTY = 40,
  FORTY_ONE // равен 41
};

int main(int argc, char const *argv[])
{
  const int const_int = 10;
  // const_int = 20; // compiler error

  std::cout << const_int << std::endl;
  std::cout << MACRO_INT << std::endl;
  int value = FORTY;
  std::cout << value << std::endl;
  std::cout << FORTY_ONE << THIRD << std::endl;;

  return 0;
}
