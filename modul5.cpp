// #define _HAS_STD_BYTE 0
// #define NOMINMAX
#include "laura5.h"
#include <iostream>
#include <fstream>
#include <set>
#include <cctype> // для ispunct()
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
//f,gfgffg - fffd в файл б.тхт

void fillFromKeyboard(string& str) {
    clearString(str);
    cout << "Введите строку: ";
    cin.ignore(); //игнорируем переход на новую строчку
    getline(cin, str); //с гетлайн можно заполнть строчку вместе с пробелами 
    cout << "Строка заполнена с клавиатуры" << endl;
}

void printString(const string& str) { //const неизменяемая только для чтения строка
    if (str.empty()) {
        cout << "Строка пуста" << endl;
        return;
    }
    cout << "Строка: " << str << endl;
    cout << endl;
}

void clearString(string& str) {
    str.clear();
    cout << "Строка очищена" << endl;
}


bool fillFromFile(string& str, const string& filename) {
    clearString(str);
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return false;
    }
    string line;
    while (getline(file, line)) { //проходимся по строчкам и склеиваем все в одну строку
        str += line;
    }
    file.close();
    cout << "Строка загружена из файла" << endl;
    cout << str << endl;
    return true;
}


void task1(string& str) {
    int index = 0;
    while ((index = str.find(" ", index)) != string::npos) { 
        if (index == str.size() - 1) { 
            str.erase(index, 1);
            break;
        }
        if (str.back() == ' ') { 
            str.erase(str.size() - 1, 1);
        }
        str.replace(index, 1, ".");
        index++;
    }
    cout << "Ваша строка: " << endl;
    cout << str << endl;
}

void task2(string& str) {
    int p = 0;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c == '-') {
            str[i] = char(151);
            p = p + 1;
        }
    }
    if (p > 0) {
        cout << "В строке заменились - на — " << endl;
        cout << str << endl;
    }
    else {
        cout << "В строке не было знаков -" << endl;
        cout << str << endl;
    }
}

void task36(string& str) {
    string chars;
    for (char c : str) { // для каждого символа с в строке str
        if (!ispunct(c) && c != ' ') { // игнорируем знаки препинания и пробелы
            if (chars.find(c) == string::npos) { 
                chars += c;
            }
        }
    }
    cout << "Количество различных символов: " << chars.size() << endl;
    cout << "Различные символы: ";
    for (char c : chars) { //цикл выода символов
        cout << "'" << c << "' ";
    }
    cout << endl;
}

void task24(string& str) {
    int gamma;
    cout << "Введите значение гаммы от 127 до 255" << endl;
    cin >> gamma;
    if (gamma <= 127 && gamma >= 255) {
        cout << "Неправильное значение гаммы " << endl;
        return;
    }
    cout << "Исходная строка: " << str << endl;
    string str1 = str;
    for (int i = 0; i < str.size(); i++) {
        str1[i] = str[i] ^ gamma; // XOR - исключающая или(побитовая операция) если 1 0 или 0 1 то 1 иначе 0
    }
    cout << "Результат: " << str1 << endl;
    cout << endl;
}

void task32(string& str) {
    string up = str;
    // Преобразуем все символы строки в верхний регистр
    for (char& c : up) {
        c = toupper(c);
    }
    // Проверяем, состоит ли строка только из допустимых 20теричных цифр
    for (char c : up) {
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'J'))) {
            cout << "Не 20теричное число" << endl;
            return;
        }
    }

    // Преобразуем 20теричное число в десятичное
    int dec = 0;
    for (char c : up) {
        int digit;
        if (isdigit(c)) { //проыерка явл ли этот символ цифрой
            digit = c - '0'; //перевод по ASCII кодировке в инт значение
        } 
        else {
            digit = c - 'A' + 10; 
        }
        dec = dec * 20 + digit;
    }
    cout << "В десятичной: " << dec << endl;

    // Преобразуем десятичное число в 16сс
    string hex;
    int t = dec;
    if (t == 0) {
        hex = "0";
    } else {
        while (t > 0) {
            int r = t % 16;
            char hex_digit;
            if (r < 10) {
                hex_digit = '0' + r; // Цифры 0-9 обратно возвращ значение в этоц кодировке
            } else {
                hex_digit = 'A' + (r - 10); // Буквы A-F
            }
            hex = hex_digit + hex; // Добавляем цифру в начало строки
            t /= 16;
        }
    }
    cout << "В 16сс: " << hex << endl;
}

void task12() {
    
    cout << "\nГенератор паролей" << endl;
    const string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string digits = "0123456789";
    const string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    int level;
    cout << "Выберите уровень сложности пароля:" << endl;
    cout << "1 - Простой (5 символов, только буквы)" << endl;
    cout << "2 - Средний (10 символов, буквы + цифры)" << endl;
    cout << "3 - Сложный (25 символов, буквы + цифры + символы)" << endl;
    cin >> level;
    int length;
    string charPool;
    string description;
    switch (level) {
        case 1:
            length = 5;
            charPool = lowercase + uppercase;
            description = "Простой (только буквы)";
            break;
        case 2:
            length = 10;
            charPool = lowercase + uppercase + digits;
            description = "Средний (буквы + цифры)";
            break;
        case 3:
            length = 25;
            charPool = lowercase + uppercase + digits + symbols;
            description = "Сложный (буквы + цифры + символы)";
            break;
        default:
            cout << " Выберите уровень сложности 1-3" << endl;
            break;
    }
    string password;
    for (int i = 0; i < length; i++) {
        password += charPool[rand() % charPool.length()];
    }
    cout << "\nРезультат генерации: " << endl;
    cout << "Уровень: " << level << endl;
    cout << "Пароль: " << password << endl;
}
//В нашем коде string::npos используется для проверки,
// нашлись ли в строке нужные символы (+, -, *, =) перед проверкой формата примера.

// Перевод из 12-ричной системы в 10-ричную
int base12ToDec(string s) {
    int value = 0;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        int digit = 0;
        if (c >= '0' && c <= '9')
            digit = c - '0';
        else if (c == 'A')
            digit = 10;
        else if (c == 'B')
            digit = 11;

        value = value * 12 + digit;// yмножаем текущее значение на 12 прибавляем текущую цифру
    }
    return value;
}

void task7() {
    ifstream in("FN1.txt");
    ofstream out("FN2.txt");
    string line;
    while (getline(in, line)) {
        int znak = -1; //для запоминания индекса +-*
        int ravno = -1;//для =
        // Ищем знак операции и '='
        for (int i = 0; i < line.length(); i++) { //проходим по симолам строки
            if (line[i] == '+' || line[i] == '-' || line[i] == '*')
                znak = i;
            if (line[i] == '=')
                ravno = i;
        }

        string op1str = line.substr(0, znak);
        char operation = line[znak]; //сохраняем знак операции
        string op2str = line.substr(znak + 1, ravno - znak - 1);
        string ansstr = line.substr(ravno + 1);

        // Переводим из 12-ричной в 10-ричную
        int op1 = base12ToDec(op1str);//переводим в 10сс 
        int op2 = base12ToDec(op2str);
        int ans = base12ToDec(ansstr);

        int result = 0;

        if (operation == '+') result = op1 + op2;
        if (operation == '-') result = op1 - op2;
        if (operation == '*') result = op1 * op2;

        if (result != ans)
            line += "-";

        out << line << endl;
    }

    in.close();
    out.close();
}

//------------------------------------------------------------------
void fillRandom32(string& str, int length) { //для задаия с сист счисления
    clearString(str);
    srand(time(0));
    string two = "0123456789ABCDEFGHIJabcdefghij";
    for (int i = 0; i < length; i++) {
        str += two[rand() % two.size()];
    }
}

void fillRandomAll(string& str, int length) {
    clearString(str);
    srand(time(0));
    const string engllow = "abcdefghijklmnopqrstuvwxyz";
    const string englup = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string digits = "0123456789";
    const string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    const string ruslow = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    const string ruslup = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    const string probel = " ";
    string chars = engllow + englup + digits + symbols + ruslow + ruslup + probel;
    for (int i = 0; i < length; i++) {
        str += chars[rand() % chars.size()];
    }
}

void fillRandom19(string& str, int length) {
    clearString(str);
    srand(time(0));
    string tire = "-------";
    string probel = " ";
    string bukvi = "лоапатвпthghfdjf";
    string chars1 = tire + probel + bukvi;
    for (int i = 0; i < length; i++) {
        str += chars1[rand() % chars1.size()];
    }
}

void fillRandom47(string& str, int length) {
    clearString(str);
    srand(time(0));
    vector<std::string> slova = {
        "мягкие ", "котик ", "милые ", "котиков ", "пушистые ", 
        "котики ", "классные ", "веселые ", "котята", "смешные ", "любознательные ", "милашки"};
    
    for (int i = 0; i < length; i++) {
        str += slova[rand() % slova.size()];
    }
}
