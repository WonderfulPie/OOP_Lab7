// Lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include<Windows.h>
using namespace std;

// Варіант без специфікації виключень
double CalculateSquareRootNoException(double a, double b, double c) {
    if (a == 0) {
        throw "a не може дорівнювати нулю";
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        throw "Дискримінант від'ємний, коренів немає";
    }

    return (-b + sqrt(discriminant)) / (2 * a);
}

// Варіант зі специфікацією throw();
double CalculateSquareRootThrowSpec(double a, double b, double c) throw() {
    if (a == 0) {
        throw "a не може дорівнювати нулю";
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        throw "Дискримінант від'ємний, коренів немає";
    }

    return (-b + sqrt(discriminant)) / (2 * a);
}

// Варіант з конкретною специфікацією та використанням стандартного виключення
double CalculateSquareRootStdException(double a, double b, double c) throw(exception) {
    if (a == 0) {
        throw invalid_argument("a не може дорівнювати нулю");
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        throw runtime_error("Дискримінант від'ємний, коренів немає");
    }

    return (-b + sqrt(discriminant)) / (2 * a);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        double a, b, c;
        cout << "Введіть a, b, c: ";
        cin >> a >> b >> c;

        // Варіант без специфікації виключень
        double result = CalculateSquareRootNoException(a, b, c);
        cout << "Результат: " << result << endl;
    }
    catch (const char* e) {
        cerr << "Помилка: " << e << endl;
    }

    try {
        double a, b, c;
        cout << "Введіть a, b, c: ";
        cin >> a >> b >> c;

        // Варіант зі специфікацією throw();
        double result = CalculateSquareRootThrowSpec(a, b, c);
        cout << "Результат: " << result << endl;
    }
    catch (const char* e) {
        cerr << "Помилка: " << e << endl;
    }

    try {
        double a, b, c;
        cout << "Введіть a, b, c: ";
        cin >> a >> b >> c;

        // Варіант з конкретною специфікацією та використанням стандартного виключення
        double result = CalculateSquareRootStdException(a, b, c);
        cout << "Результат: " << result << endl;
    }
    catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
