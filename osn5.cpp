#ifdef _WIN64
#include <windows.h>
#endif
// #define _HAS_STD_BYTE 0
// #define NOMINMAX
// #define WIN32_LEAN_AND_MEAN 
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string>
#include "laura5.h"
#include <algorithm> //библиотека для команд строки
// #include <windows.h>
using namespace std;


int main() {
    //SetConsoleOutputCP(65001);
    #ifdef _WIN64
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    #endif
    int choice;
    string myString;
    do {
        cout << "1. Заполнить строку с клавиатуры" << endl;//+
        cout << "2. Заполнить строку случайным способом" << endl;//++
        cout << "3. Заполнить строку из файла" << endl;//++
        cout << endl;
        cout << "4. Задание String47" << endl;//++
        cout << "5. Задание Str19" << endl;//++
        cout << "6. Задание Str24" << endl;//++
        cout << "7. Задание Str36" << endl;//++
        cout << "8. Задание Str32" << endl;
        cout << "9. Задание 1" << endl;
        cout << "10. Задание Five7" << endl;
        cout << "999. Выход из программы" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                fillFromKeyboard(myString);
                break;
            }
            case 2: {
                cout << "Введите задание, которое хотите ввести рандомом" << endl;
                cout << "11) Для задания 1 (Str47)" << endl;
                cout << "22) Для задания 2 (Str19)" << endl;
                cout << "33) Для задания 5 (Str32)" << endl;
                cout << "44) Просто рандом" << endl;
                int randomk;
                cin >> randomk;
                switch (randomk) {
                    case 11: {
                        cout << "Введите количество слов" << endl;
                        int length;
                        cin >> length;
                        fillRandom47(myString, length);
                        printString(myString);
                        break;
                    }
                    case 22: {
                        cout << "Введите длину строки" << endl;
                        int length;
                        cin >> length;
                        fillRandom19(myString, length);
                        printString(myString);
                        break;
                    }
                    case 33: {
                        cout << "Введите длину строки" << endl;
                        int length;
                        cin >> length;
                        fillRandom32(myString, length);
                        printString(myString);
                        break;
                    }
                    case 44: {
                        cout << "Введите длину строки" << endl;
                        int length;
                        cin >> length;
                        fillRandomAll(myString, length);
                        printString(myString);
                        break;
                    }  
                }
                break;
            }
            case 3: {
                string filename;
                cout << "Введите имя файла: ";
                cin >> filename;
                fillFromFile(myString, filename);
                break;
            }
            case 4: {
                task1(myString);
                break;
            }
            case 5: {
                task2(myString);
                break;
            }
            case 6: {
                task24(myString);
                break;
            }
            case 7: {
                task36(myString);
                break;
            }
            case 8: {
                task32(myString);
                break;
            }
            case 9: {
                task12();
                break;
            }
            case 10: {
                task7();
                break;
            }
            case 999: {
                cout << "Выход из программы" << endl;
                break;
            }
            default:
                cout << "Введены неверные данные" << endl;
                break;
        }
    } while (choice != 999);
    return 0;
}
//g++ osn5.cpp modul5.cpp -o program.exe
