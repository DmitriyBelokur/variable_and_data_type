#include <iostream>

// определяем псевдоним типа
using my_time_t = unsigned long long; // начиная с С++11
// typedef unsigned long long my_time_t; // до С++11

int main(int argc, char const *argv[])
{
  int a; // на самом деле это signed int ~32 bit, т.е. ключевое слово signed можно опускать
  short b; // ~16 bit
  // signed short int b; это идентичная обьявление как и выше, только можно опускать ключевые слова signed и int
  long c; // ~32-64 bit
  // signed long int c; это идентичная обьявление как и выше, только можно опускать ключевые слова signed и int
  unsigned int d; // это беззнаковое целое ~32, как видно чтобы создать беззнаковое значение нужно указать unsigned
  unsigned short e; // беззнаковое короткое целое ~16
  // unsigned short int e; это идентичная обьявление как и выше, только можно опустить ключевое слово int
  unsigned long f; // беззнаковое длиное целое ~32-64, 
  // unsigned long  int f; это идентичная обьявление как и выше, только можно опустить ключевое слово int
  long long g; // long long int ~64 начиная с C++11

  // присваиваем символьной переменной занчение 65 
  char ch = 65;

  // и выводим значение этой переменной на экран, но на экране мы увидем не значение 90, а символ А
  // это связано с тем что в соотвтетсвии с таблицей кодировки 65 соответсвует символу A
  std::cout << ch << std::endl;

  my_time_t stat;
  my_time_t end;
  return 0;
}
