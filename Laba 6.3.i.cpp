#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);
int SumOdd(int* a, const int size);

template <typename T>
void Create(T* a, const int size, const T Low, const T High);

template <typename T>
void Print(T* a, const int size);

template <typename T>
T SumOdd(T* a, const int size);

int main()
{
    srand((unsigned)time(NULL));    // ініціалізація генератора випадкових чисел

    const int n = 10;
    int a[n];

    int Low = -20;
    int High = 50;

    cout << "Ordinary functions:" << endl;
    Create(a, n, Low, High);
    Print(a, n);
    cout << "SumOdd = " << SumOdd(a, n) << endl;

    cout << endl;

    cout << "Template functions:" << endl;
    Create<int>(a, n, Low, High);
    Print<int>(a, n);
    cout << "SumOdd<int> = " << SumOdd<int>(a, n) << endl;

    return 0;
}

// звичайні функції

// формування масиву випадковими числами з [Low; High]
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// виведення масиву в рядок
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// сума непарних елементів масиву цілих чисел
int SumOdd(int* a, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0)
            s += a[i];
    return s;
}

// шаблони функцій

// формування масиву випадковими числами з [Low; High]
template <typename T>
void Create(T* a, const int size, const T Low, const T High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// виведення масиву в рядок
template <typename T>
void Print(T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// сума непарних елементів масиву цілих чисел
template <typename T>
T SumOdd(T* a, const int size)
{
    T s = T();    // присвоїли нульове значення
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0)
            s += a[i];
    return s;
}