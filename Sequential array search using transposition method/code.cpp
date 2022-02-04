
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;

void fillArray(int* arr, int size);
void oneFindingCycle(int* arr, int size, int searchingElement);
void coutArray(int* arr, int size);
void allFindingCycles(int* arr, int size, int** searchedElements, int element, int timesOfSearched);
void fillMatrix(int** matrix, int rows, int cols);
void coutMatrix(int** matrix, int rows, int cols);
void statistics(int** searchedElements, int element);




int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));


	//Реализация необходимых массивов
	int size = 10;
	int* arr = new int[size];
	int element = 20;
	int timesOfSearched = 2;
	int** searchedElements = new int* [element];
	for (int i = 0; i < element; i++) {
		searchedElements[i] = new int[timesOfSearched];
	}
	fillArray(arr, size);
	allFindingCycles(arr, size, searchedElements, element, timesOfSearched);
	fillMatrix(searchedElements, element, timesOfSearched);
	delete[] arr;
}
void statistics(int** searchedElements, int element) {
	for (int i = 0; i < element; i++) {
		if (searchedElements[i][0] != 0) {
			cout << "\tЭлемент " << searchedElements[i][0] << " подвергался поиску " <<
				searchedElements[i][1] << " раз(а)\n";
		}
	}
}
void fillMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = 0;
		}
	}
}
void allFindingCycles(int* arr, int size, int** searchedElements, int element, int
	timesOfSearched) {
	int tmp;
	for (int i = 0; i < element; i++) {
		cout << "Введите искомый элемент: ";
		int searchingElement;
		cin >> searchingElement;
		tmp = searchingElement;
		if (searchingElement != 0) {
			for (int j = 0; j < element; j++) {

				//Проверка на схожесть с другими элементами массива searchedElements
				if (searchedElements[j][0] == tmp) {
					searchedElements[j][1]++;
					tmp = 0;

				}
			}
			if (tmp != 0) {
				searchedElements[i][0] = tmp;
				searchedElements[i][1] = 1;

			}
			for (int k = 0; k < element; k++) {
				if (searchedElements[k][0] == 0) {
					searchedElements[k][1] = 0;
				}
			}
			oneFindingCycle(arr, size, searchingElement);
		}
		else {
			cout << "Поиск элементов завершен, статистика по поиску: " << endl;
			statistics(searchedElements, element);
			break;
		}
	}
}
void oneFindingCycle(int* arr, int size, int searchingElement) {

	//Найти элемент, вывести его индекс и совершить транспозицию
	int tmp;
	for (int i = 0; i < size; i++) {
		if (arr[i] == searchingElement) {
			cout << "Искомый элемент под номером " << i + 1 << " в массиве";
			if (i >= 1) {
				tmp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = tmp;
				cout << "\n\nПосле транспозиции массив имеет вид: ";
				coutArray(arr, size);
				cout << "\n\n" << endl;
			}
			else if (i < 1) {
				cout << ", по этому транспозиция не производится\n\n\n" << endl;
			}
			i = size;
		}
	}
}
void fillArray(int* arr, int size) {
	cout << "Массив:\t";
	int a;
	for (int i = 0; i < size; i++) {
		a = rand() % size + 1;
		for (int j = 0; j < size; j++) {
			if (arr[j] ==
				a) {
				a = 0;
			}
		}
		if (a != 0) {
			arr[i] = a;
			cout << arr[i] << ", ";
		}
		else {
			i--;
		}
	} cout << endl;
}
void coutArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	} cout << endl;
}
void coutMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << ", ";
		} cout << endl;
	}
}
