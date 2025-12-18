#ifndef H_H
#define H_H

#include <vector>
#include <string>
using namespace std;

void fillFromKeyboard(string& str);
void printString(const string& str);
void clearString(string& str);
bool fillFromFile(string& str, const string& filename);

void fillRandom32(string& str, int length);
void fillRandomAll(string& str, int length);
void fillRandom19(string& str, int length);
void fillRandom47(string& str, int length);

void task1(string& str);

void task2(string& str);

void task36(string& str);

void task24(string& str);

void task32(string& str);

void task12();

int base12ToDec(string s);
void task7();
#endif