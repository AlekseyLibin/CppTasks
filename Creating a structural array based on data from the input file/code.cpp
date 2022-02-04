#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;

//Before starting work, you need to createand fill in the input file



enum DesciplineType {
	necessarily_professional, 
	necessarily_general, 
	optionaly_general, 
	optionaly_professional 
};
struct Descipline {
	char code[7]; 
	char name[30]; 
	DesciplineType type; 
	char department[5]; 
	int lectureHours; 
	int practicalHours; 
	int consultationHours; 
	void hoursCountChecking(int hours) {
		if (hours > 50) {
			cout << "Слишком большое количество часов!\n";
		}
		else if (lectureHours < 0) {
			cout << "Не может быть отрицательное количество часов!\n";
		}
		if (hours % 2 == 1) {
			cout << "Количество часов не может быть нечетным!\n";
		}
	}
};
void fillArr(Descipline* arr, int amountOfDesciplines, const char* fname);
void menu(Descipline* arr, int numberOfDesciplines);
void showAll(Descipline* arr, int amountOfDesciplines);
void showDescipine(Descipline* arr, int n);
void desciplinesBySemester(Descipline* arr, int amountOfDesciplines);
void taskA(Descipline* arr, int amountOfDesciplines);
void taskB(Descipline* arr, int amountOfDesciplines);
void taskV(Descipline* arr, int amountOfDesciplines);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	//Задавание массива
	int amountOfDesciplines = 18 // Количество строк с описанием дисциплин
		Descipline * arr = new Descipline[amountOfDesciplines];
	fillArr(arr, amountOfDesciplines, "Desciplines.txt");
	menu(arr, amountOfDesciplines);
}
void menu(Descipline* arr, int amountOfDesciplines) {
	cout << "ВЫБЕРИТЕ ДЕЙСТВИЕ: \n";
	cout << "\t1. Показать всё \n\t2. Отобразить все дисциплины заданной кафедры \n\t3.
		Отобразить всю информацию о дисциплинах заданной кафедры(Задание А) \n\t4.Отобразить информацию о
		дисциплине, у которой больше всего часов за семестр(Задание Б) \n\t5.Отобразить для каждой кафедры
		количество дисциплин, которые на ней преподаются и их список(Задание В)" << endl;
		cout << "Введите номер действия: ";
	int choice;
	cin >> choice;
	if (choice > 5 || choice < 1) {
		cout << "Вы ввели неверный номер" << endl;
	}
	cout << endl;
	switch (choice) {
	case 1:
		showAll(arr, amountOfDesciplines);
		break;
	case 2:
		desciplinesBySemester(arr, amountOfDesciplines);
		break;
	case 3:
		taskA(arr, amountOfDesciplines);
		break;
	case 4:
		taskB(arr, amountOfDesciplines);
		break;
	case 5:
		taskV(arr, amountOfDesciplines);
		break;
	}
}
void showDescipine(Descipline* arr, int n) {
	cout << arr[n].code << "; " << arr[n].name << "; ";
	switch (arr[n].type) {
	case necessarily_professional:
		cout << "Обязательная профессиональная; ";
		break;
	case necessarily_general:
		cout << "Обязательная непрофессиональная; ";
		break;
	case optionaly_general:
		cout << "Выборочная непрофессиональная; ";
		break;
	case optionaly_professional:
		cout << "Выборочная профессиональная; ";
		break;
	default:
		cout << "Ошибка с выводом поля Descipline type\n";
		break;
	}
	cout << arr[n].department << "; " << arr[n].lectureHours << "; " <<
		arr[n].practicalHours << "; " << arr[n].consultationHours << endl;
	arr[n].hoursCountChecking(arr[n].lectureHours);
	arr[n].hoursCountChecking(arr[n].practicalHours);
	arr[n].hoursCountChecking(arr[n].consultationHours);
}
void showAll(Descipline* arr, int amountOfDesciplines) {
	for (int i = 0; i < amountOfDesciplines; i++) {
		showDescipine(arr, i);
	}
}
void desciplinesBySemester(Descipline* arr, int amountOfDesciplines) {
	int department;
	cout << "ДОУСТУПНЫЕ КАФЕДРЫ:\n";
	cout << "\t1. Информационные системы управления (ИУС)\n\t2. Физика (Ф)\n\t3.
		Системотехника(СТ)\n\t4.Иностранные языки(ИЯ)\n\t5.Философия(Ф)\n\t6.Прикладная математика
		(ПМ)\n";
		cout << "Выберите кафедру: ";
	cin >> department;
	if (department < 1 || department > 6) {
		cout << "Неверно выюрана кафедра\n";
	}
	switch (department) {
	case 1:
		for (int i = 0; i < amountOfDesciplines; i++) {
			if (strcmp(arr[i].department, "ИУС") == 0) {
				cout << "\t" << arr[i].name << endl;
				break;
			}
		}
		break;
	case 2:
		for (int i = 0; i < amountOfDesciplines; i++) {
			if (strcmp(arr[i].department, "Ф") == 0) {
				cout << "\t" << arr[i].name << endl;
				break;
			}
		}
		break;
	case 3:
		for (int i = 0; i < amountOfDesciplines; i++) {
			if (strcmp(arr[i].department, "СТ") == 0) {
				cout << "\t" << arr[i].name << endl;
				break;
			}
		}
		break;
	case 4:
		for (int i = 0; i < amountOfDesciplines; i++) {
			if (strcmp(arr[i].department, "ИЯ") == 0) {
				cout << "\t" << arr[i].name << endl;
				break;
			}
		}
		break;
	case 5:
		for (int i = 0; i < amountOfDesciplines; i++) {
			if (strcmp(arr[i].department, "Ф") == 0) {
				cout << "\t" << arr[i].name << endl;
				break;
			}
		}
		break;
	case 6:
		for (int i = 0; i < amountOfDesciplines; i++) {
			if (strcmp(arr[i].department, "ПМ") == 0) {
				cout << "\t" << arr[i].name << endl;
				break;
			}
		}
		break;
	}
}
void taskA(Descipline* arr, int amountOfDesciplines) {
	int department;
	cout << "ДОУСТУПНЫЕ КАФЕДРЫ:\n";
	cout << "\t1. Информационные системы управления (ИУС)\n\t2. Физика (Ф)\n\t3.
		Системотехника(СТ)\n\t4.Иностранные языки\n\t5.Философия(Ф)\n\t6.Прикладная математика(ПМ)\n";
		cout << "Выберите кафедру: ";
	cin >> department;
	if (department < 1 || department > 6) {
		cout << "Неверно выюрана кафедра\n";
	}
	switch (department) {
	case 1:
		for (int i = 0; i < amountOfDesciplines; i++) {
			if (strcmp(arr[i].department, "ИУС") == 0) {
				showDescipine(arr, i);
			}
		}
		break;
	case 2:
		for (int i = 0; i < amountOfDesciplines; i++) {
			if (strcmp(arr[i].department, "Ф") == 0) {
				showDescipine(arr, i);
			}
		}
		break;
	case 3:
		for (int i = 0; i < amountOfDesciplines; i++) {
			if (strcmp(arr[i].department, "СТ") == 0) {
				showDescipine(arr, i);
			}
		}
		break;
	case 4:
		for (int i = 0; i < amountOfDesciplines; i++) {
			if (strcmp(arr[i].department, "ИЯ") == 0) {
				showDescipine(arr, i);
			}
		}
		break;
	case 5:
		for (int i = 0; i < amountOfDesciplines; i++) {
			if (strcmp(arr[i].department, "Ф") == 0) {
				showDescipine(arr, i);
			}
		}
		break;
	case 6:
		for (int i = 0; i < amountOfDesciplines; i++) {
			if (strcmp(arr[i].department, "ПМ") == 0) {
				showDescipine(arr, i);
			}
		}
		break;
	}
}
void taskB(Descipline* arr, int amountOfDesciplines) {
	int maxValue = 0;
	for (int i = 0; i < amountOfDesciplines; i++) {
		if ((arr[i].lectureHours + arr[i].practicalHours + arr[i].consultationHours) > maxValue) {
			maxValue = arr[i].lectureHours + arr[i].practicalHours + arr[i].consultationHours;
		}
	}
	for (int i = 0; i < amountOfDesciplines; i++) {
		if ((arr[i].lectureHours + arr[i].practicalHours + arr[i].consultationHours) == maxValue) {
			cout << "Информация о дисциплине с наибольшим количеством часов:\n\t";
			showDescipine(arr, i);
			cout << "Где общее количество часов " << maxValue << endl;
			break;
		}
	}
}
void taskV(Descipline* arr, int amountOfDesciplines) {
	cout << "Выбрано действие: Отобразить для каждой кафедры количество дисциплин, которые на
		ней преподаются и их список\n";
		for (int i = 0; i < amountOfDesciplines; i++) {
			cout << "\tНа кафедре " << arr[i].department << " 1 дисциплина: " << arr[i].name << endl;
			for (int j = 0; j < 4; j++) {
				if (strcmp(arr[i].department, arr[i + 1].department) == 0) {
					i++;
				}
			}
		}
}
void fillArr(Descipline* arr, int amountOfDesciplines, const char* fname) {
	ifstream fin(fname);
	if (!fin) {
		cout << "Ошибка открытия файла" << fname;
	}
	char tmp[50];
	for (int i = 0; i < amountOfDesciplines; i++) {
		fin.getline(arr[i].code, 7, ';');
		fin.getline(arr[i].name, 30, ';');
		fin.getline(tmp, 50, ';');
		if (strcmp(tmp, "Обязательная профессиональная") == 0) {
			arr[i].type = necessarily_professional;
		}
		if (strcmp(tmp, "Обязательная непрофессиональная") == 0) {
			arr[i].type = necessarily_general;
		}
		if (strcmp(tmp, "Выборочная профессиональная") == 0) {
			arr[i].type = optionaly_professional;
		}
		if (strcmp(tmp, "Выборочная непрофессиональная") == 0) {
			arr[i].type = optionaly_general;
		}
		fin.getline(arr[i].department, 50, ';');
		fin >> arr[i].lectureHours;
		arr[i].hoursCountChecking(arr[i].lectureHours);
		fin.getline(tmp, 50, ';');
		fin >> arr[i].practicalHours;
		arr[i].hoursCountChecking(arr[i].practicalHours);
		fin.getline(tmp, 50, ';');
		fin >> arr[i].consultationHours;
		arr[i].hoursCountChecking(arr[i].consultationHours);
	}
	fin.close();
}
