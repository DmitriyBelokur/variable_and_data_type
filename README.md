# Переменные и базовые типы языка
## Переменные
Программы чаще всего манипулируют данными, например расчет формул, или отображения каких либо данных на экране и т.д. Т.е. для выполнения задач над этими данными, нам необходимая некая сущность чтобы управлять этими данными, например хранить результат вычесление одной формулы и использовать как часть входных параметров для другой формулы. И этой сущностью являеться переменная. Т.е. переменная это ячейка в памяти которая предназначенна для манипуляции даными в этой ячейке, т.е. хранить или записывать данные в ячейке. Другими словами переменная это уникальное идентификатор через который мы можем сослаться на участок памяти, с которой связана переменная. Переменная это просто имя предназначеное для удобности чтения кода, при компиляции переменная это просто адресс ячейки памяти. Переменная должна удовлетворять правилам идентификаторов, которые описаны в предыдущем разделе.
Например представте вы пишете персонажа к игре, и персонаж в какойто момент времени имеет позицию на карте и персонаж может перемещаться по карте, и нам необходимо сохранять координаты персонажа в переменной, т.е. в памяти, и если нам необходимо перерисовать карту или уточнить где находиться персонаж мы можем обратиться к переменой и взять от туда текущие координаты персонажа.
Необходимо обьязательно запомнить что назначение правильного имени идентификатору, играет ключевую роль при написании приложения.
Для того что бы использовать переменную ее неободимо обьявить, для этого указывают тип переменной и ее имя, другими словами зарезервировать память под эту переменную. Почему зарезервировать, т.к. если переменная не будет использована в программе компилятор может удалить эту переменную и обьектного файла.
```cpp
// синтаксис обьявления переменной
тип_данных имя_переменной;
```
В отличие от литералов под которые не выделяется место в памяти(исключением является строковые литералы), переменные обычно храняться в стеке или куче, реже в памяти сегмента кода. При этом выделяют три вида переменных локальные, статические и динамические. В этом разделе будут в основном расматриваться локальные переменные которые будут храниться на стеке.
Если в двух словах стек это структура данных работающая по принципу LIFO(последний вошел, первый вышел), т.е. предоставляет автоматическую работу с памятью. Т.е. перемення попавшая на стек имеет предустановленное правило жизни, и вы никак не можете на это повлиять. Стек более подробно будет рссмотрен при работе с поматью.

## Типы данных
Как было сказано выше переменная это просто именновая ячейка памяти. И все операции чтения или записи это просто оперрации с байтами(т.к. самая маленькая единица памяти это байт). Поэтому тип данных при указании переменой это на самом деле узакание компилятору сколько байт выделить под эту ячейку памяти, т.е. сколько байт надо прочитать и сколько записать. С++ присутствут большое количество типов. Различают два вида типов встроенные и пользовательские. В этом разделе мы расмотрем только встроенные типы(фундаментальные типы), а вот пользовтельсткие мы будем рассматривать в друих разделах.
https://ru.cppreference.com/w/cpp/language/types
https://en.cppreference.com/w/cpp/language/types
https://en.cppreference.com/w/cpp/header/cstdint

### Целочисленные типы
В основном в языке С++ выделяют 3 основных целочисленных типа int, short, long. С появлением С++11 появились также новые типы int8_t, int16_t и т.д. Целочисленый тип предназначен, как можно сделать вывод с названия, для хранения целых данных без дробной частью. Целый тип характерезиуеться размером в битах, до С++11 размер был 16, 32, 64 бит соответсвенно, с появлением С++ появились  так называемые типы с фиксированым размером. Связано это с тем что например тип int на разных моделях данных(архитектурах) может быть разной, может быть 16, а может и 32, и это иногда вызывало проблемы когда программа портировалась с одной архитектуры на другую, так и появились типы с фиксированым размером, для того чтобы гарантировать фиксацию размера переменной. В зависимости от количества бит которое представляет тип и связано какое число можно считать и записать в память. Целочисленные типы выделяют как знаковые так и безнаковые, разница заключаеться только диапазоне минимального и максимального хранимого значения в переменной.
```cpp
int a; // на самом деле это signed int ~32 bit
short b; // signed short int ~16
long c; // signed long int ~32-64
unsigned int d; // это беззнаковое целое ~32
unsigned short e; // беззнаковое короткое целое ~16
unsigned long f; // беззнаковое длиное целое ~32-64
long long g; // long long int ~64 начиная с C++11
```
Как видно с выше перечисленных примеров `int` иногда опускаю при указании короткого целого или длиного целого, также все целые типы по умолчанию знаковые.
А что произойдет если попробывать записать цисло которое привышает количество бит, произойдет так называемое переполнение, причем число после переполнения зависит от знакости типа. Что бы понять переполнение надо перевести число в двоичный формат и посмотреть сколько битов необходимо для представления этого числа, и если количество битов больше максимального числа, то крайние левы биты будут отброшены.
```cpp
unsigned short x = 65535;
x = x + 1; // вданом случае произойдет переполнение и x возможно будет равен 0
/*
возможеная работа
65535 в доичной форме это 1111 1111 1111 1111 занимает 16 бит
65536 1 0000 0000 0000 0000 и занимает 17 бит
и соответсвенно главныйлевый бит теряеться, а остальные 16 остаються
*/
```
Стандарт строго гарантирует что:
sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long).
Целочисленные литералы по умолчанию представленны типом int если литерал может поместиться в этом типе, иначе типом long
Также стоит отметить что в С++ есть специальные макросы для представления максимального и минимального допустимого хранимого значения в переменной
http://www.cplusplus.com/reference/climits/
Но я бы рекомендовал использовать так называемый клас std::numeric_limits, которое предлагает огромный функционал для представленого типа(например, как знак, так минимальное или максимальное значение)
https://en.cppreference.com/w/cpp/types/numeric_limits
### Символьный тип
Симвльный тип имеет нескольк особенностей. Во-первых он представлен для хранения символов, а во-вторых он является целочисленным типом. Давайте последовательно со всем этим разбермся.
Символьный тип в базовой форме имеет название `char`, размер его на разных архитектурах может быть разным, но в основном он представлен 1 байтом. Также как и целые тип `char` может быть знаковым и беззнаковым. Разница только в диапазоне допустимых чисел. Для знаковых это от -128 до 127, для беззнаковых от 0 до 255.
Часто в программах можно видеть что тип char используется для хранения целых чисел, например в циклах, это связано с тем что этот тип представлен только одним байтом. Но это редкость. В основном тип char используют для хранения символов, т.е. представляет диапазон ASCII таблицы (которая содержит спец символы, знаки и английский алфавит), т.е. вмещаеться в диапазон от 0..127. В таблице кодировки представлян числовой диапазон в котором закодированы символы, например числом 89, в таблице представлен(закодирован) символ `A`. Один вопрос зачем отрицательный диапазон, наверное когда его придумали решили а давайте отрицательную часть будем использовать для арифимитических целей необольших чисел, наверное так, два в одном. В однобайтового char хватает для представляения латиницы и работы с симолами. По умолчанию тип `char` представляет однобайтовую кодировку ASCII, но есть и другие таблицы кодировки,такназываемые расширенные, Windows-1251(поддерживает кирилицу), CP866(поддерживает кирилицу), в которых таблица представленна 256ю значениями, являються устаревшими.
Все эти кодировки это так называемые 8 битовые кодировки. Большое распостранения получили так называемые кодировка Unicode, т.е. поддерживает все символы мира, упоминают такие кодировки(способы представления символов) как UTF-8(ASCII), UTF-16, UTF-32. Для этого в С++ есть следующие типы, т.к. называемые широкие строки `wchar_t`, и более специализированные char16_t, char32_t начиная с С++11 стандарта. Для UTF-8 в основном применяют `unsigned char`
Вообщем стандартом оговорено следующее:
1 == sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long).
### Пустой тип void
Тип `void` не являеться как типом таковым, он больше являеться индикатором. Используеться при указании в функции что функция не возвращает значение(или ее иногда называют процедурой), используют когда компилятору указывают что результат выражения игнорируеться `(void)(ptr++)`. И очень частое применение это с указателями, мое мнение когда указываеться следующее обьявление `void *ptr`, такое обьявление называеться нетипизированый указатель, т.е. в данном контексте мы указываем что указатель хранит просто адресс, без укаания типов(называют еще не полный тип). Такое применение нетипизированых указателей очень частое в С библиотеках, например выделение памяти malloc, также его применяют в так называемых callback функциях, когда одна функция просто передает нетипизированный указатель callback функции.
Бывают случаи когда в качестве параметров фунции указывают `void`, что означает что функция не принимает параметров, но это редкий случай такого применения
```cpp
// обьявление нетипизированого указателя
void *ptr;
. . .
// обьявление функции которая ничего не возращает
void func(int x);

// обьявление функции которая в качестве параметров ничего не принимает
int func(void); // тоже что и (int func())

```
### Логический тип
Логический тип предназначен для хранения значение только `false` или `true`, т.е для хранения логического результата выполнения опрерации или функции и т.д. Логический тип обьявляеться ключевым словом `bool`, размер типа в соответствии со стандартом не меньше 1 байта. Логический тип автоматически конвертируеться в целый тип, т.е. `true` конвертируеться в 1., а `false` в 0, и на оборот, но с одным отличием все ненулевые знчения неявно конвертируються в `true`. Часто в С библиотеках можно увидить возращаемый тип `int`, где возращаемое число 0 это результат успешной выполнения операции, а все ненулевые числа это коды ошибок(для этого применяют трюк `!!bool_expresion`, о есть конвертировать из любого типа в `bool`)
### Типы с плавающей точкой
Вещественные типы призванны решать матиматические задачи или хранить например диагностические числа потребления энергии, и т.д. Т.е. в вещественных числах выделяют целую и дробную часть. Выделяют числа с одинарной точностью (float), двойной точностью (double), и четверной точностью (long double), точность часто выражают машинным словом. Частый пример использования вещественных чисел можно встретить при работе с графикой, это координаты. Размеры вещественых типов варьируються от архитектуры к архитектуры, но стандарт гарантирует
sizeof(float) <= sizeof(double) <= sizeof(long double)
Как видно из размера допустимых значений вещественных типов, они предназначенны для работы с точными значениями(мат формулами и т.д.).
Что означает точность? Ну представим что есть некая дробь 1/3, если ее перевести в веществееное представление, правильно сказать десятичную форму, то получим 0,333333... где дробная часть продолжается до бесконечности, но так как наша память не бесконечная, то для этого и применяться понятие точности для представление значищих цифр, а остальное теряеться. Т.е. число точности завист от размера представленого типа, например float — от 6 до 9 цифр (в основном 7), double — от 15 до 18 цифр (в основном 16), long double — 15, 18 или 33 (в зависимости от того, сколько байтов занимает тип). Вещественные типы соотносятся стандарту IEEE 754 (стандарт описывающий формат представления вещестенных чисел). Если попытаться присвоить число с большей точностью переменной которая может содержать число с меньшей точностью, то мы получим так называемое потерю в точности.
```cpp
// ошибка присвоение типу с меньшей точностью, число с большей точностью
float value {12345678910.0};
std::cout << std::setprecision(10);
std::cout << value << std::endl;
```
```cpp
// на экране мы увидим не то что ожидаем
1.234567885e+10 // или 12'345'678'850 , видим потерю точности
```
В отличии от целых чисел все вещественные числа знаковые. Также вещественные числа используют для предсталения больших трудночитемых чисел. Т.е. вещественное чисо часто представляют в так называемой экспоненциальной форме, которая имеет следующий вид мантисса * 10(экспонент). Мантисса это значищая часть, например 2.5 *10^4, где 2.5 это мантисса, а 4 это экспонент(т.е. порядок числа), результат этого числа будет 25000. 
При работе с вещественными числами, надо быть очень акуратными, в часности поблемы округления, т.е. если число неможет быть представлено с указаной точностью то оно округляеться(с првилами матиматичекого округления). Т.е. вопрос в том как вещественные часла храняться в памяти, и это надо всегда помнить.
```cpp
double d_value {0.1};
std::cout << std::setprecision(6); // default precision
std::cout << d_value << std::endl;
std::cout << std::setprecision(17); // posible double precision
std::cout << d_value << std::endl;
```

```cpp
// на экране мы увидим
0.1
0.10000000000000001
```
С выше перечисленого примера физическое хранения числа и того числа которое мы привыкли использовать в десятичной форме (как с числом 0.1), не совсем идентичное. Часто эти ошибки приводят в неправильном сравнении вещественных чисел, т.е. переменных с литералом, или перемееной установленной литералом с переменной которая была вычисленна с формулы (например 0.2 + 0.3).
Inf и Nan
При работе с вещественными числами выделяют две категории специальных чисел: бесконечность Inf, и не число NaN.

Ниже приведенна ссылка на бинарное представление вещественных чисел
https://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D1%80%D0%B5%D0%B4%D1%81%D1%82%D0%B0%D0%B2%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5_%D0%B2%D0%B5%D1%89%D0%B5%D1%81%D1%82%D0%B2%D0%B5%D0%BD%D0%BD%D1%8B%D1%85_%D1%87%D0%B8%D1%81%D0%B5%D0%BB

```cpp
double div_by_zero = 5.0 / 0.0; // == INF, but we are divide 5.0 / -0.0 result will be == -INF
std::cout << div_by_zero << std::endl;
std::cout << (0.0 / 0.0) << std::endl;
```

```cpp
// на экране мы увидим
inf
-nan
```

А что если вещественное число присвоить целочисленной переменной? Тут произойдет так называемая срезка, не округление, т.е. целочисленой переменной присвоться только целая часть, а дробная урежиться. Это особенно важно при матиматических расчетах когда в аргументах формул используються целые числа. Если два числа при делении будут целыми литералами, например `5/2`, то результат этого выражения будет целое число `2`, а для того чтобы получить результат в вещественном формате, необходимо один из форматов привести к вещественой форме. например `5.0/2`. Вследствии веше сказано при делении целого числа на ноль, результат работы будет не таким как при работе с вещесвенными числами, программа просто упадет, т.е. аварийно завершиться.

```cpp
double float_point = 5 / 2;
std::cout << float_point << std::endl;
float_point = 5.0 / 2;
std::cout << float_point << std::endl;

float_point = 2.0 / (1 + 5) ;
std::cout << float_point << std::endl;
```

```cpp
// на экране мы увидим
2
2.5
0.33333333333333331
```
Маленькое замечание, если Вы пишете программу с поддержкой вещественных чисел в кажестве входных аргументов, всегда оговаривайте точность представленных чисел, это спасет Вас от многочасового дебага в поисках ошибок.
### Литеральные суфиксы
Как мы знаем что при написании целочисленного литерала по умолчанию если тип помещается в int, то он представляется типом int, иначе он будет представлен значением long long, также и для вещественных литералов по умолчанию это double. Но иногда применяют так называемые типовые суфиксы как для целых так и для вещественных. Иногда их применяют в контексте присвоение переменной литерала, но как по мне с типа переменной и так ясно какой тип литарала будет. Использование суфикса часто имеет место при выражениях.
```cpp
u/U - unsigned int
l/L - long
ll/LL - long long
ull, uLL, Ull, ULL, llu, llU, LLu, or LLU - unsigned long long
f/F - float
l/L - long double
```
Суфикс l/L может применяться как и для целых так и для вещественных, в зависимости от контекста

```cpp

float f = 5.0f/2; // если мы не указали суфикс f то вещественный литерал бы приводился бы по умолчанию к double
```
## Объявление и инициализация переменных
В С++ важную роль играет так называемое обьявление идентификатора(имя переменной, имя функции, или имя типа и т.д.) и инициализация. Стоит отметить что сейчас мы рсмотрим только обьявление и инициализацию переменных. В языке разделяют два подхода это обьявление и инициализация. Обьявление есть ввод в программу индитификатора переменной. Т.е. выделить память под переменную указав количество байтов в качестве индетификатора типа, и связать адресс выделенной памяти с переменной. Не стоит путать определение переменной с инициализацей. При обьявлении переменной происходит так званноя неявная инициализация, иногда говорят муссором, т.е. неисвестным значение которое было использовано до этого другой переменной. Но при явной инициализации мы указываем конкретное значение переменной. В С++ запрещаеться использовать переменную до ее обьявления(имеется ввиду присваивать ей значения или что то с нее читать), т.к. С++ является строго типизированным.
В С++ есть множество подхода для обьявления и инициализации переменных

```cpp
  int int_value; // происходит обьявление переменной целого типа и неявная инициализация неизвестным значением
  printf("int_value is = %d\n", int_value);
  int value = 42; // происходит обьявление переменной целого типа и явная инициализация числом 42
  /*
  следующая инициализация такая же как и выше
  int value(42);
  int value = int(42);
  */
  printf("value is = %d\n", value);
  // с появление С++11 повилось так называемая универсальная инициализация
  int value_uni{42};
  /*
   или избыточные
   int value_uni1 = {42};
   int value_uni2 = int{42};
  */
  printf("value_uni is = %d\n", value_uni);
  // инициализация нулем
  int zero = 0;
  /*
   следующая инициализация такая же как и выше
   int zero1 = int();
   но следующуе обьявление не есть ошибочное с точки зрения компилятора, но интерпритируеться им по другом
   int zero(); // обьявляеться функция
   следующее обьявление тоже ошибочное
   int zero = (); // error
   int zero = {}; // compiled ok)
   int zero2{};
  */
  printf("zero is = %d\n", zero);

  // можно объвлять переменные в один ряд, только в том случае если у них общий тип
  int oneline_value1, oneline_value2 = 20, oneline_value3;
  printf("oneline_value1 is = %d, oneline_value2 is = %d, oneline_value1 is = %d\n", oneline_value1, oneline_value2, oneline_value3);

  int tricks = (7, 9);
  printf("tricks is = %d\n", tricks); // напечатает 9, срабатывает правило запятой
  /*
   но если написать
   int tricks(7, 9); // ошибка компиляции
   или
   int tricks = int(7, 9);
  */
  // если мы будем использовать универсальную иницализацию то получим грамотную ошибку компиляции
  //int error_initializing = {7, 9};
  /*
  очень полезной функциональностью универсальныч инициализаций есть, уменьшение ошибки сужающего преобразования
  int reduce{1.5f}; // compilation error
  */
  int reduce = 1.5f; // compiles fine
  printf("reduce is = %d\n", reduce); // print 1
```

```
// получим следующий вывод
int_value is = 0
value is = 42
value_uni is = 42
zero is = 0
oneline_value1 is = 0, oneline_value2 is = 20, oneline_value1 is = 0
tricks is = 9
reduce is = 1
```

Если внимательно присмотреться. то можно заметить очень важную особенность, что при использовании старых подходов к инициализации возможно множество неожидаемых ошибок. Но с появлением в С++11 универсальной инициализации, количество ошибочных подходов с инициализацией уменьшилась. Т.е унифицированная инициализация это единиый сиснтаксис инициализации, котопый может, как минимум концептуально, использоватьс везде и выражать все. Новая возможность фигурной инициализации заключается в том, что она запрещает неявное сужающие преобразование среди встроенных типов (narrowing conversion), т.е. если значение выражения в фигурном инициализаторе не может быть гарантировано выражено типом инициализируемого обьекта, код не компилируеться как видно с примера. Инициализация с применением круглых скобок не выполняет проверку сужающего преобразования, т.к. это может привести к неработоспособности много старого кода. Поэтому вывод так и напрашивается старайтесь больше использовать универсальную инициализацию.
### Автоматический вывод типов ключевое слово auto
До появляение стандарта С++11, при обьявлении переменной необходимо всегда было явно писать тип переменной. С появление стандарта С++11 появилось ключевое слово `auto` которое позволяет выводить типы с инициализируещего выражения
```cpp
  auto i = 10; // i type -> int
  auto f = 10.5; // f type -> double
  auto ch = 'h'; // ch type -> char
  auto var_uint(5u); // var_uint type -> unsigned int
```
Как видно с выше приведенных примеров на не нужно больше писать тип возле переменной за нас это сделает компилятор. На самом деле это базовое применение ключевого слова `auto` оно имеет более широкое применение, и мы с ним будем больше знакомиться на протяжении курса.
Но рассмотрим плюсы применения `auto` перед привычным нам приемом указания явно типа. Это то что при обьявлении переменной с `auto` неяобходимо явно указывать начальное значение т.к. компилятор по этому выражению будет выводить тип, т.е. пропадает проблема неинициализированных переменных (но правда есть случай с применением ключевого слова `decltype`)
```cpp
  // auto unknown; // ошибка комиляции неизвестен тип
  decltype(i) new_int; // ok, new int is the same type how in i variables, but variables is uninitialized
```
Но как на счет применения унифицированной инициализации, например если написать
```cpp
auto val_unif{20}; // ???
```
Если вы подумали что тип переменной `val_unif`, то вы будете правы, но это не всегда было так. До версий компилятора clang 3.8 и g++ 5 тип переменной `val_unif` был так называемый инициализироанный список `std::initializer_list<int>`
## Константы
Перед этим мы с вами рассмотрели литералы целочисленные и т.д., что важно то что в стандарте не оговоренно как именно в памяти храняться литералы, но большинство склоняеться что они храняться непосредственно на регистрах. Т.е. место хранения литералов это детали реализации, которые могут быть разными на разных архитектурах. Как мы знаем переменная это в общем ячейка в памяти которая имеет адресс. Тогда возникает вопрос, а что такое константа? Константа это то что не может быть изменнено на всей протяжении жизни сущности(в програмировани это можно назвать деталью реализации, т.к. есть механизмы позволяющие изменить значение переменной). В отличии от обычной переменной, значение которой мы можем менять многократно, с константой все иначе раз установленное значение не может меняться на протяжении жизни всей переменной.
Немного разберемся с константой. В языке С++ константа применяеться во многих контекстах. Но в данном разделе мы рассмотрим константу как переменную. До этого мы рассматривали литералы, которые также являються константами, и вместо того чтобы по всей программе писать повторяющийся литерал(неважно какого он типа), ему можно дать имя, как имя переменной, и на протяжении программы или блока ссылаться на него. Но в программировании часто употребляют термин "magic number", когда делают код ревью колег, т.е. когда встречают в коде литерал, просят дать ему логическое имя что делает этот литерал, или зачем нужен (например вычисление формул, логическое описания коэфициэнтов). В С++ есть как минимум три вида переменных констант:
 - Это использования макроопределения #define
 - Использования ключевого слова const
 - Перечисления enum

### #define как именованная константа препроцессора
В далеком С небыло такого понятия как константа, но были литералы. Но литералы это источник больших логических ошибок в коде, т.к. например если один и тот же литерал встречаеться много раз в коде и необходимо изменить этот литерал, то иногда можно изменить не во всех местах, и получим так называемую ошибку логики программы(семантическую ошибку). Тогда програмисты начали давать имена этим литералам с помощью дериктивы препроцессора `#define`, т.е. если надо поменять значение литерала, то не надо бегать по всему коду, а можно поменять только в одном месте. Когда препроцессор орабатывает наш код на первом этапе он заменяет все макроопределения которые мы определяли для литералов, т.е. вставляет наши литералы на место где мы писали имена литералов.
```cpp
#define VAL1 20
#define VAL2 30.0

float summ = VAL1 / VAL2; // (20 / 30.0)

#undef VAL1
#define VAL1 40
float summ = VAL1 / VAL2; // (20 / 40)
```
### Ключевое слово const
Проблемой макросов `#define` есть то что они не типобезопасны, т.е. макрос не имеет никакого типа, он просто вставлят значение в контексте и все. Это очень важно например при написании формул или присвоение значений. Важной особенностью обьявление констант с помощью ключевого слова `const`, то что это переменная которая имеет имя, тип, и много других особенностей которые мы будем рассматривать на протяжении курса. Отличием обьявление констант от обычных переменных, то что константу необходимо инициализировать при обьявлении, иначе будет ошибка компиляции. Инициализировать можно как литералом, так и значением другой переменной. Константа проинициализированна раз, неможет быть изменна на протяжении своей жизни, иначе мы получим ошибку компиляции.
```cpp
const int i = 20;

// i = 40; // compiler error, значение не может быть изменено

// const int k; // compiler error, константу необходимо проинициализировать
```
Простым словом константа это память только для чтения. Хотя стандартом не определено как должна храниться константа в памяти, стандартом оговорено что переменная обьявленна с помощью ключевого слова const не может быть измена на протяжении своей жизни. Есть предпосылки что если обьявить константу и не брать ее адресс(инициализация указателя), то литерал использующийся при инициализации контсанты будет загружен в регистры. Но если взять адресс константы, то для нее (возможно) память (зависит от того как константа обьявленна была) будет выделенна. Но это все зависит от реализации компилятора и архитектуры, и флагов компилятора при билде.
### Константы с приминением ключевого слова enum
Перечисление enum мы подробно будет рассматривать в следующих раздел, а сдесь мы расмотрим ее как еще один способ обьявление констант.
```cpp
enum {
  FIRST,
  SECOND,
  THIRD
};
. . .
enum {
  FORTY = 40,
  FORTY_ONE
};
```
Как видно перечисления похожи на макросы, на ключевое слово похожи. Такие перечесления могут быть только целочисленные. Попытка например написать один из перечислений вещественным литералом даст ошибку компиляции, т.е. перечисления неявно имеют тип int.
```cpp
enum {
  FLOAT = 1.1 // ошибка компиляции то что перечисления должны быть интегрального типа.
}
```
По умолчанию первый элемент перичесления имеет значение ноль, и следующие элементы перечисления соответственно плюс 1, т.е. FIRST инициализируеться нулем, SECOND инициализируеться 1 и т.д. Но можно задавать и явно инициализирующее значение как в примере с FORTY равное 40, и соответсвенно следующий элемент будет равен 41.
### Свёртка констант
Это один из видов оптимизации, который применяеться на этапе компиляции, для уменьшения избыточности вычеисление. Заменяет переменные константы их значение и замены константных выражений их значением. Лучше пример
```cpp
const int i =10;

int test() {
    return i * 20;
}

int func() {
    return test();
}

int main() {
    return func();
}
```
Если запустить компиляцию с флагом -O2 и посмотреть асемблерный код то увидим следующее
```
test():
  mov eax, 200
  ret
func():
  mov eax, 200
  ret
main:
  mov eax, 200
  ret
```
Мы видим что вместо инструкций взятие значения с переменной и инструкции умножения, мы просто помещаем значение вычесленное на этапе компиляции прямо в регистр.
### Constexpr, константа времени компиляции
Ключевое слово constexpr имеет много особеностей влияющий на поведение программы в зависимости от конктекста где это ключевое слово применяеться. В данном разделе рассмотрим только в контексте к переменным.
Это ключевое слово было добавлено в страндарт С++11, и главной его целью было не только указание его как константа, а и то что значение было известно на этапе компиляции. В основном такие переменные применяються в контекстах где необходимо целочисленное константное выражение, например размер массива и т.д.
Есть отличие между const и constexpr. В отличие от constexpr const необьязан быть проинициализированным во время компиляции, а может быть проинициализирован во время выполнения. Проще говоря все обьекты являющиеся constexpr, являются const, но не все обьекты, являющиеся const, являются constexpr. Запутано, согласен, давайте примеры.
```cpp
#include <cstdint>
#include <cstdio>

int main() {
    // инициализация во время компиляции
    constexpr int cvalue = 10;
    uint8_t value = 20;
    // инициализировать константу во время выполнения
    const int rconst = value;
    constexpr float pi = 1.22;
    // ошибка компиляции
    // constexpr int econst = value;
    printf("compile time const %d\n", cvalue);
    printf("run time const %d\n", rconst);
    printf("%.2f\n", pi);
    return 0;
}
```

