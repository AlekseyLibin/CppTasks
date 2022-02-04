
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <ctype.h>
using namespace std;



int charToInt(char character);
bool operation(char* arr, int index);
bool isOperation(char symbol);
bool isDigit(char symbol);
void exchange(char* arr, int first, int second);
void swipeToStart(char* arr, int index);
void prefixForm(char* arr, int size);
char intToChar(int integer);
void multipliesAndDevides(char* arr, int size);
void hideNulls(char* arr, int size);
void sum(char* arr, int size);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	cout << "Введите математическую операцию: ";
	int size = 50;
	char* str = new char[size];
	cin.getline(str, 50);
	prefixForm(str, size);             //Переводит выражение в префиксную форму
	multipliesAndDevides(str, size);   //Считает все умножения и деления
	sum(str, size);                    //Считает все суммы и разности
	delete[] str;
}
void sum(char* arr, int size) {
	for (int i = 4; i >= 0; i--) {
		if (isOperation) {
			switch (arr[i]) {
			case '+':
				arr[i] = intToChar(charToInt(arr[i + 1]) + charToInt(arr[i + 2]));
				arr[i + 1] = '0';
				arr[i + 2] = '0';
				break;
			case '-':
				arr[i] = intToChar(charToInt(arr[i + 1]) - charToInt(arr[i + 2]));
				arr[i + 1] = '0';
				arr[i + 2] = '0';
				break;
			}
			hideNulls(arr, size);
			cout << arr << endl;
		}
	}
	cout << "Результат вычисления: " << arr << endl;
}
void multipliesAndDevides(char* arr, int size) {
	for (int i = size - 1; i >= 0; i--) {
		if (operation(arr, i)) {
			switch (arr[i]) {
			case '*':
				arr[i] = intToChar(charToInt(arr[i + 1]) * charToInt(arr[i + 2]));
				arr[i + 1] = '0';
				arr[i + 2] = '0';
				break;
			case '/':
				arr[i] = intToChar(charToInt(arr[i + 1]) / charToInt(arr[i + 2]));
				arr[i + 1] = '0';
				arr[i + 2] = '0';
				break;
			}
		}
	}
}
void hideNulls(char* arr, int size) {
	for (int n = 0; n < size; n++) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == '0') {
				for (int j = i; j < size; j++) {
					exchange(arr, j, j + 1);
				}
			}
		}
	}
}
bool operation(char* arr, int index) {
	if (arr[index] == '+' || arr[index] == '-' || arr[index] == '*' || arr[index]
		== '/') {
		return true;
	}
	else {
		return false;
	}
}
void prefixForm(char* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == '+' || arr[i] == '-') {
			swipeToStart(arr, i);
		}
		else if (arr[i] == '*' || arr[i] == '/') {
			exchange(arr, i, i - 1);
		}
	}
	cout << "Префиксная форма уравнения имеет вид: \n" << arr << endl;
}
bool isOperation(char symbol) {
	switch (symbol) {
	case '+':
		return true;
		break;
	case '-':
		return true;
		break;
	case '*':
		return true;
		break;
	case '/':
		return true;
		break;
	default:
		return false;
	}
}
bool isDigit(char symbol) {
	switch (symbol) {
	case '0':
		return false;
		break;
	case '1':
		return true;
		break;
	case '2':
		return true;
		break;
	case '3':
		return true;
		break;
	case '4':
		return true;
		break;
	case '5':
		return true;
		break;
	case '6':
		return true;
		break;
	case '7':
		return true;
		break;
	case '8':
		return true;
		break;
	case '9':
		return true;
		break;
	default:
		return false;
	}
}
int charToInt(char character) {
	switch (character) {
	case '0':
		return 0;
		break;
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	default:
		cout << "Ошибка\n";
	}
}
char intToChar(int integer) {
	switch (integer) {
	case 0:
		return '0';
		break;
	case 1:
		return '1';
		break;
	case 2:
		return '2';
		break;
	case 3:
		return '3';
		break;
	case 4:
		return '4';
		break;
	case 5:
		return '5';
		break;
	case 6:
		return '6';
		break;
	case 7:
		return '7';
		break;
	case 8:
		return '8';
		break;
	case 9:
		return '9';
		break;
	default:
		cout << "Ошибка\n";
	}
}
void swipeToStart(char* arr, int index) {
	for (int i = 0; i < index; i++) {
		exchange(arr, index - i, index - (i + 1));
	}
}
void exchange(char* arr, int index1, int index2) {
	char tmp;
	tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}
