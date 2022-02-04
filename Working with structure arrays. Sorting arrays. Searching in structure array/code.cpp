#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;


struct coin {
	char manufactureCountry[30];
	int manufactureYear;
	int denomination;
	char coinName[20];
};
void input(coin* massiv, const int amount);
void menu(coin* massiv, const int amount);
void output(coin* massiv, const int amount, char* country, int denomination);
void sort(coin* massiv, const int amount);
void display(coin* massiv, const int amout);


int main() {
	setlocale(LC_ALL, "Rus");
	const int count = 5;
	coin arr[count] = {};

	input(arr, count);
	menu(arr, count);
	sort(arr, count);
	display(arr, count);
}
void input(coin* massiv, const int amount) {
	for (int i = 0; i < amount; i++) {
		cout << (i + 1) << "/" << amount;
		cout << "\nEnter a manufacture country: ";
		cin >> massiv[i].manufactureCountry;
		cout << "\nEnter a coin name: ";
		cin >> massiv[i].coinName;
		cout << "\nManufacture year: ";
		cin >> massiv[i].manufactureYear;
		cout << "\nEnter a denomination: ";
		cin >> massiv[i].denomination;
		cout << "\n\n\n";
	}
}
void menu(coin* massiv, const int amount) {
	cout << "Countries: \n";
	for (int i = 0; i < amount; i++) {
		cout << "\t" << massiv[i].manufactureCountry << endl;
	}
	char country[20];
	cout << "Choose the country: ";
	cin >> country;
	cout << "\nDenominations: \n";
	for (int i = 0; i < amount; i++) {
		cout << "\t" << massiv[i].denomination << endl;
	}
	int denomination;
	cout << "Choose denomination: ";
	cin >> denomination;
	output(massiv, amount, country, denomination);
}
void output(coin* massiv, const int amount, char* country, int denomination) {

	for (int i = 0; i < amount; i++) {

		if ((massiv[i].denomination == denomination)) {
			if ((massiv[i].manufactureCountry[0] = country[0]) ||
				(massiv[i].manufactureCountry[1] = country[1]) ||
				(massiv[i].manufactureCountry[2] = country[2])) {
				cout << "\n\t\t\tTask 1\n";
				cout << "The coin accoarding to your data: \n";
				cout << "\nCountry: " << massiv[i].manufactureCountry << ", " << "Year: " <<
					massiv[i].manufactureYear << ", " << "denomination " << massiv[i].denomination
					<< ", " << "name: " << massiv[i].coinName << endl;
			}
		}
	}
}
void sort(coin* massiv, const int amount) {
	coin temp;
	for (int i = 0; i < (amount - 1); i++) {
		for (int j = 0; j < (amount - i - 1); j++) {

			if (massiv[j].denomination > massiv[j + 1].denomination) {
				temp = massiv[j];
				massiv[j] = massiv[j + 1];
				massiv[j + 1] = temp;
			}
		}
	}
}
void display(coin* massiv, const int amount) {
	cout << "\n\t\t\tTask 2\n";
	cout << "\n\t\t\tSorted array:\n";
	for (int i = 0; i < amount; i++) {
		cout << "\nCountry: " << massiv[i].manufactureCountry << ", " << "Year: " <<
			massiv[i].manufactureYear << ", " << "denomination " << massiv[i].denomination
			<< ", " << "name: " << massiv[i].coinName << endl;
	}
}