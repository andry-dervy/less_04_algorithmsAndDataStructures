//============================================================================
// Name        : less_03.cpp
// Author      : andry antonenko
// IDE         : Eclipse IDE
// Copyright   : lesson 4 of the algorithms and structures data
// Description : Simple Numbers in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

using namespace std;
//----------------------------------------------------------------------------
void decToBin(uint d)
{
  if(d != 0)
  {
    decToBin(d/2);
    printf("%c",'0' + d%2);
  }
  else
  {
    printf("%c",'0');
    return;
  }
}
//----------------------------------------------------------------------------
int pow_recursive_v01(int a, int b)
{
  if(b != 0)
  {
    return a * pow_recursive_v01(a, --b);
  }
  else
    return 1;
}

int pow_recursive_v02(int a, int b)
{
  if(b != 0)
  {
    if(b%2 == 0)
    {
      return pow_recursive_v02(a*a, b/2);
    }
    else
    {
      return a * pow_recursive_v02(a, --b);
    }
  }
  else
    return 1;
}
//----------------------------------------------------------------------------
#define xSize  8
#define ySize  8
int routes(int* arr, int x, int y)
{
  if( (x == 0 && y == 0))
  {
    return 0;
  }
  else if(*(arr + x*ySize + y) == 1)
  {
    return 0;
  }
  else if( x == 0 || y == 0 )
  {
    return 1;
  }
  else
    return routes(arr, x, y - 1) + routes(arr, x - 1, y);
}
//----------------------------------------------------------------------------
int main(int argc, const char** argv)
{

/*
  1. Реализовать функцию перевода чисел из десятичной системы в двоичную,
  используя рекурсию.
*/
//*
  printf("Задача 1\n");
  printf("Введите положительное целое число: ");
  uint d = 0;
  scanf("%d",&d);
  printf("0b");
  decToBin(d);
  printf("\n");
//*/
/*
  2. Реализовать функцию возведения числа [a] в степень [b] двумя способами:
  Рекурсивно.
  Рекурсивно, используя свойство чётности степени
  (то есть, если степень, в которую нужно возвести число, чётная,
  основание возводится в квадрат, а показатель делится на два,
  а если степень нечётная - результат умножается на основание,
  а показатель уменьшается на единицу)
*/

//*
  printf("\nЗадача 2\n");
  printf("Введите целое число a: ");
  int a = 0,b = 0;
  scanf("%d",&a);
  printf("Введите целое число b: ");
  scanf("%d",&b);

  printf("Результат функции pow_recursive_v01: %d\n",pow_recursive_v01(a,b));
  printf("Результат функции pow_recursive_v02: %d\n",pow_recursive_v02(a,b));
//*/

/*
  3. Реализовать нахождение количества маршрутов шахматного короля с препятствиями
  (где единица - это наличие препятствия, а ноль - свободная для хода клетка)

  Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и четыре функции, соответствующие каждому из заданий.
//*/

//*
  printf("\nЗадача 3\n");
  int chessArray[ySize][xSize] = {
    {0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,1,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}
  };

  for(int x = 0; x < xSize; x++)
  {
    for(int y = 0; y < ySize; y++)
    {
      printf("%5d",routes(&chessArray[0][0],x,y));
    }
    printf("\n");
  }
//*/

  return 0;
}


