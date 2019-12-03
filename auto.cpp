#include <iostream>
#include <iomanip> // for std::boolalpha
#include <type_traits> // std::is_same

int main(int argc, char const *argv[])
{
  auto i = 10; // i type -> int
  auto f = 10.5; // f type -> double
  auto ch = 'h'; // ch type -> char

  // auto unknown; // ошибка комиляции неизвестен тип
  decltype(i) new_int; // ok, new int is the same type how in i variables, but variables is uninitialized
  return 0;
}
