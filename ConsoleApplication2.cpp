// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>   // Для роботи з файлами
using namespace std;

int main() {
    // Розмір матриці
    const int row = 5, cols = 5;
    long long матриця[row][cols]; // Двовимірний масив

    // Відкриття текстового файлу для читання
    ifstream file("matrix.txt");
    if (!file) {
        cerr << "Не вдалося відкрити файл matrix.txt!" << endl;
        return 1;
    }

    // Зчитування матриці з файлу
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < cols; ++j) {
            file >> матриця[i][j];
        }
    }
    file.close(); // Закриваємо файл

    // Виведення зчитаної матриці
    cout << "Зчитана матриця 5x5:\n";
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << матриця[i][j] << "\t";
        }
        cout << endl;
    }

    // Обчислення суми додатних елементів над головною діагоналлю
    int sum = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = i + 1; j < cols; ++j) { // Елементи над головною діагоналлю
            if (матриця[i][j] > 0) {
                sum += матриця[i][j];
            }
        }
    }

    // Виведення результату
    cout << "Сума додатних елементів над головною діагоналлю: " << sum << endl;

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
