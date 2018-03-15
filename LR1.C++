# LR1.15.03.2018
#include <QtCore/QCoreApplication>
#include <iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

#define size 500

using namespace std;

  /*  глупая сортировка
  void stupidSort(int *data, int n)
  {
  int i = 0, tmp;
  FILE *f1; string in;
  clock_t start = clock();
  while (i < n - 1)
  {
      if (data[i + 1] < data[i])
      {
          tmp = data[i];
          data[i] = data[i + 1];
          data[i + 1] = tmp;
          i = 0;
      }
      else i++;

  }
  cout << endl;

  clock_t end = clock();
  double sim_sort_Time = double(end - start)/ CLOCKS_PER_SEC;
  cout << "stupidSort" << endl;
  cout << "Time:";
  cout << sim_sort_Time << endl;

  for(int i = 0; i < size; i++)
  {
      cout << data[i] << "\t";
  }
  }
  */

  /*  выбором сортировка
  void selectSort(int* arr, int)
  {
      int tmp, i, j, pos;
       FILE *f1; string in;
       clock_t start = clock();
      for(i = 0; i < size; ++i) // i - номер текущего шага
      {
          pos = i;
          tmp = arr[i];
          for(j = i + 1; j < size; ++j) // цикл выбора наименьшего элемента
          {
              if (arr[j] < tmp)
              {
                 pos = j;
                 tmp = arr[j];
              }
          }
          arr[pos] = arr[i];
          arr[i] = tmp; // меняем местами наименьший с a[i]
      }

      clock_t end = clock();
      double selectSort = double(end - start)/ CLOCKS_PER_SEC;
      cout << "selectSort" << endl;
      cout << "Time:";
      cout << selectSort << endl;

      for(int i = 0; i < size; i++)
      {
          cout << arr[i] << "\t";
      }
  }*/

  /*  поразрядная сортировка
  void siftDown(int *numbers, int root, int bottom)
  {
    int maxChild; // индекс максимального потомка
    int done = 0; // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done))
    {
      if (root * 2 == bottom)    // если мы в последнем ряду,
        maxChild = root * 2;    // запоминаем левый потомок
      // иначе запоминаем больший потомок из двух
      else if (numbers[root * 2] > numbers[root * 2 + 1])
        maxChild = root * 2;
      else
        maxChild = root * 2 + 1;
      // если элемент вершины меньше максимального потомка
      if (numbers[root] < numbers[maxChild])
      {
        int temp = numbers[root]; // меняем их местами
        numbers[root] = numbers[maxChild];
        numbers[maxChild] = temp;
        root = maxChild;
      }
      else // иначе
        done = 1; // пирамида сформирована
    }
  }
  // Функция сортировки на куче
  void heapSort(int *numbers, int )
  {
      int i = 0, tmp;
      FILE *f1; string in;
      clock_t start = clock();
    // Формируем нижний ряд пирамиды
    for (int i = (size / 2) - 1; i >= 0; i--)
      siftDown(numbers, i, size);
    // Просеиваем через пирамиду остальные элементы
    for (int i = size - 1; i >= 1; i--)
    {
      int temp = numbers[0];
      numbers[0] = numbers[i];
      numbers[i] = temp;
      siftDown(numbers, 0, i - 1);
    }
    clock_t end = clock();
    double heapSort = double(end - start)/ CLOCKS_PER_SEC;
    cout << "heapSort" << endl;
    cout << "Time: ";
    cout << heapSort << endl;

    for(int i = 0; i < size; i++)
    {
        cout << numbers[i] << "\t";
    }
  }*/

void swap (int *a, int *b){
    int t = *a; *a = *b; *b = t;
   int a[max], n = 0, i, sh = 0, b = 0;
   for (i = 0; i < n; ++i)
   {
     if (i*2 + 2 + sh < n)
     {
       if (a[i+sh] > a[i*2 + 1 + sh] || a[i + sh] > a[i*2 + 2 + sh])
   {
     if (a[i*2+1+sh] < a[i*2+2+sh])
     {
       swap (&a[i+sh], &a[i*2+1+sh]);
       b = 1;
     }
     else if (a[i*2+2+sh] < a[i*2+1+sh])
     {
       swap (&a[i+sh],&a[i*2+2+sh]);
       b = 1;
     }
   }
     }
     else if (i * 2 + 1 + sh < n)
     {
       if (a[i+sh] > a[i*2+1+sh])
   {
     swap (&a[i+sh], &a[i*2+1+sh]);
     b=1;
   }
     }
   }
   if (!b) sh++;
   if (sh+2==n)
     break;
 }

  int main()
  {
      ifstream f, g;
      int n = 0;
      int data[size];
      string line;
      f.open("E://ALL//STUD//ZHOLOBOVA//LAB2//DELETE//bbbb-build-desktop//500.txt", ios::in);
      g.open("E://ALL//STUD//ZHOLOBOVA//LAB2//DELETE//bbbb-build-desktop//Result.txt", ios::in);
      if(f)
      {
          while(!f.eof())
          {
              f >> data[n];
              n++;
              getline(g, line);
          }
          // cout<<line<<"\t";
          //stupidSort(data,n);
          swap(data, n);
         //heapSort(data, 0, size-1);
         //V_mergeSort(data, n);
          f.close();
      }


     system("pause");
  }


