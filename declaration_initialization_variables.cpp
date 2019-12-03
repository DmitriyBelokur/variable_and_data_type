#include <iostream>

/*   float value {123.};
  std::cout << value << std::endl;

  double d_value {0.1};
  std::cout << std::setprecision(6);
  std::cout << d_value << std::endl;
  std::cout << std::setprecision(17);
  std::cout << d_value << std::endl;

  double div_by_zero = 5.0 / 0.0;
  std::cout << div_by_zero << std::endl;
  std::cout << (0.0 / 0.0) << std::endl;

  double float_point = 5 / 2;
  std::cout << float_point << std::endl;
  float_point = 5.0 / 2;
  std::cout << float_point << std::endl;

  float_point = 2.0 / (1 + 5) ;
  std::cout << float_point << std::endl;
  
  std::cout << INFINITY << std::endl;
  // float_point = 5 / 0;  programm will be terminate with exception (core dump)
 */

int main(int argc, char const *argv[])
{
  int int_value; // происходит обьявление переменной целого типа и неявная инициализация неизвестным значением
  std::cout << int_value << std::endl;
  int value = 42; // происходит обьявление переменной целого типа и явная инициализация числом 42
  /*
  следующая инициализация такая же как и выше
  int value(42);
  int value = int(42);
  */
  std::cout << value << std::endl; ;
  // с появление С++11 повилось так называемая универсальная инициализация
  int value_uni{42};
  /*
   или избыточные 
   int value_uni1 = {42};
   int value_uni2 = int{42};
  */
  std::cout << value_uni << std::endl;
  // инициализация нулем
  int zero = 0;
  /*
   следующая инициализация такая же как и выше
   int zero1 = int();
   но следующуе обьявление не есть ошибочное с точки зрения компилятора, но интерпритируеться им по другом
   следующее обьявление тоже ошибочное
   int zero = (); // error
   int zero = {}; // compiled ok)
   int zero2{};
  */
  std::cout << zero << std::endl;
  
  // можно объвлять переменные в один ряд, только в том случае если у них общий тип
  int oneline_value1, oneline_value2 = 20, oneline_value3;
  std::cout << oneline_value1 <<  " " << oneline_value2 << " " << oneline_value3 << std::endl;

  // старый подход
  // возможно если повезет получим предупреждения копилятора
  short x1 = 32768;
  short x2  = 1.25; // часто называют срезкой, т.е. x2 будет содержать только целую часть, т.е. 1

  // новый подход
  // ниже если раскоментировать код, то получим ошибки компиляции
  /*
    short y1 {32768};
    short y2 {1.25};
  */

  std::cout << std::boolalpha;
  bool bl1 = true;
  bool bl2 = false;
  std::cout << bl1 << " " << bl2 << std::endl;
  // неправильное испольвания типа bool
  bool bl3 = 6; // это равносильно присвоение true
  bool bl4 = -10; // это равносильно присвоение true
  bool bl5 = 0; // это равносильно присвоение false
  std::cout << bl3 << " " << bl4 << " " << bl5 << std::endl;


  float value {123.};
  std::cout << value << std::endl;
  double value1 {123.123};
  std::cout << value1 << std::endl;

  long double value2 {1.1231111};
  std::cout << value2 << std::endl;

  return 0;
}
