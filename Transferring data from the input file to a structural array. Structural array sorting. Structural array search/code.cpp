#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <stdio.h>
#include <string.h>
using namespace std;



struct Product {
	char nameOfStore[20]{};
	int productPrice;
	int amountOfProducts;
};


void fillArr(const char* fileName, Product arr[], const int amount);
void sort(Product arr[], const int size);
void menu(Product arr[], const int size, char select[]);


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	const char FileName[] = "File.txt";
	const int ArrElAmount = 6;

	Product arr[ArrElAmount];

	fillArr(FileName, arr, ArrElAmount);
	char select[20];

	printf("Введите название магазина: ");
	cin.getline(select, 20);

	menu(arr, ArrElAmount, select);
}
void fillArr(const char* fileName, Product arr[], const int amount) {
	ifstream fin;
	fin.open(fileName);
	if (!fin) {
		printf("Неудачная попытка открытия файла\n");
	}
	char buff[20]{};
	printf("Информация в файле имеет вид:");
	for (int i = 0; i < amount; i++) {
		fin.getline(arr[i].nameOfStore, 20, ';');
		fin.getline(buff, 20, ';');
		arr[i].productPrice = atoi(buff);
		fin.getline(buff, 20, ';');
		arr[i].amountOfProducts = atoi(buff);
		cout << arr[i].nameOfStore << "; " << arr[i].productPrice << "; " <<
			arr[i].amountOfProducts << ";";
	}
	printf("\n");
	//Сортировка массива
	sort(arr, amount);
	fin.close();
}
void sort(Product arr[], const int size) {
	Product tmp;
	for (int k = 0; k < size; k++) {
		for (int i = 0; i < size - 1; i++) {
			if (arr[i].productPrice > arr[i + 1].productPrice) {
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
	printf("\n\SORTED:");
	for (int i = 0; i < size; i++) {
		cout << arr[i].nameOfStore << ", price: " << arr[i].productPrice << ", amount: " <<
			arr[i].amountOfProducts;
	}
	printf("\n\n");
}
void menu(Product arr[], const int size, char select[]) {
	for (int i = 0; i < size; i++) {
		if (strcmp(select, arr[i].nameOfStore)) {
			cout << "В выбранном вами магазине представлен товар в цену $" <<
				arr[i].productPrice;
			cout << " в количестве " << arr[i].amountOfProducts << " единиц" << endl;
			i = size;
		}
	}
}
