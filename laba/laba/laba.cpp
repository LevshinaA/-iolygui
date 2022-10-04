#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

struct Tube {
public:
	void filesave(string tube[]) {
		length = tube[0];
		diameter = tube[1];
		if (tube[2] == "В" || tube[2] == "Не") {
			if (tube[2] == "Не")
				feature = "Не в ремонте";
			else
				feature = "В ремонте";
		}
		else
			cout << "Некорректные данные из файла";
	}
	void addparams() {
		cout << "\nВведите длинну: ";
		cin >> length;
		cout << "Введите диаетр: ";
		cin >> diameter;
		cout << "Выберите № признака:\n 1.В ремонте\n 2.Не в ремонте";
		cin >> feature_num;
		cout << feature_num;
		if (stoi(feature_num) == 1) {
			feature = "В ремонте";
		}
		else if (stoi(feature_num) == 2) {
			feature = "Не в ремонте";
		}
		else {
			cout << ("Ошибка! 1 или 2") << endl;
			addparams();

		}
	}
	string show() {
		return (type + "   Длина: " + length + "   Диаметр: " + diameter + "   Признак: " + feature);
	}
	void change() {
		cout << "\n1.Длина: " << length << "\n2.Диаметр: " << diameter << "\n3.Признак: " << feature << "\n\nВведите № параметра для редактирования";

		cin >> change_number;
		if (change_number == 1) {
			cout << "\nВведите новую длину:";
			cin >> length;
		}
		else if (change_number == 2) {
			cout << "Введите новый диаметр:";
			cin >> diameter;
		}
		else if (change_number == 3) {
			cout << "Выберите № признака:\n 1.В ремонте\n 2.Не в ремонте";
			cin >> feature_num;
			if (stoi(feature_num) == 1)
				feature = "В ремонте";
			else if (stoi(feature_num) == 2)
				feature = "Не в ремонте";
			else {
				cout << ("Ошибка! 1 или 2") << endl;
				change();
			}
		}
		else {
			cout << "\nOшибка\n";
			change();
		}
		
	}
private:
	string length, diameter, feature, feature_num, type="Tube";
	int change_number;
};

struct Ks {
public:
	void filesave(string ks[]) {
		name = ks[0];
		departments = ks[1];
		departments_in_use = ks[2];
		feature = ks[3];
	}
	void addparams() {
		cout << "\nВведите название: ";
		cin >> name;
		cout << "Введите колличество цехов: ";
		cin >> departments;
		cout << "Введите количество цехов в работе: ";
		cin >> departments_in_use;
		cout << "Введите эффективность: ";
		cin >> feature;
		
	}
	string show() {
		//SetConsoleCP(1251);
		return (type + "     Название: " + name + "     Колличество_цехов: " + departments + "     Количество_цехов_в_работе: " + departments_in_use + "     Эффективность: " + feature);
		//SetConsoleCP(866);
	}
	void change() {
		cout << "\n1.Название: " << name << "\n2.Колличество цехов: " << departments << "\n3.Количество цехов в работе: " << departments_in_use << "\n4.Эффективность: " << feature << "\nВведите № параметра для редактирования";
		cin >> change_number;
		if (change_number == 1) {
			cout << "\nВведите новое название:";
			cin >> name;
		}
		else if (change_number == 2) {
			cout << "Введите новое колличество цехов:";
			cin >> departments;
		}
		else if (change_number == 3) {
			cout << "Введите новое колличество цехов в работе:";
			cin >> departments_in_use;
		}
		else if (change_number == 4) {
			cout << "Введите новую эффективность:";
			cin >> feature;
		}
		else {
			cout << "\nOшибка\n";
			change();
		}
	}
private:
	int change_number;
	string name, departments, departments_in_use,feature, type = "KS";
};

class Main {
public:
	void start() {
		while (true) {
			cout << "\n1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\n";
			cin >> button;
			if (button == 1)
				button_1();
			else if (button == 2)
				button_2();
			else if (button == 3)
				button_3();
			else if (button == 4)
				button_4();
			else if (button == 5)
				button_5();
			else if (button == 6)
				button_6();
			else if (button == 7)
				button_7();
			else if (button == 0)
				break;
			else start();
		}
	}

private:
	vector<Tube> tubebox;
	vector<Ks> Ksbox;
	int button, i, number;

	void button_1() {
		Tube realtube;
		realtube.addparams();
		tubebox.push_back(realtube);
	}
	void button_2() {
		Ks realKs;
		realKs.addparams();
		Ksbox.push_back(realKs);
	}
	void button_3() {
		if (tubebox.size() != 0 || Ksbox.size() != 0) {
			for (int i = 0; i < tubebox.size(); i++)
				cout << i << ". " << tubebox[i].show() << endl;
			for (i = tubebox.size(); i < Ksbox.size() + tubebox.size(); i++)
				cout << i << ". " << Ksbox[i - tubebox.size()].show() << endl;
		}
		else
			cout << "\nСписок пуст\n";
	}
	void button_4() {
		if (tubebox.size() != 0) {
			for (int i = 0; i < tubebox.size(); i++)
				cout << i << ". " << tubebox[i].show() << endl;
			cout << "Выберите номер трубы: ";
			cin >> number;
			if (number <= tubebox.size())
				tubebox[number].change();
			else {
				cout << "Такой Трубы не существует!" << endl;
				button_4();
			}
		}
		else
			cout << "\n Ёще нет труб\n";
	}
	void button_5() {
		if (Ksbox.size() != 0) {
			for (int i = 0; i < Ksbox.size(); i++)
				cout << i << ". " << Ksbox[i].show() << endl;
			cout << "Выберите номер кс: ";
			cin >> number;
			if (number <= Ksbox.size())
				Ksbox[number].change();
			else {
				cout << "Такой Кс не существует!" << endl;
				button_5();
			}
		}
		else
			cout << "\n Ёще нет кс\n";
	}
	void button_6() {
		string path = "Text.txt";
		fstream fs;
		fs.open(path, fstream::in | fstream::out | fstream::app);
		if (!fs.is_open())
			cout << "Ошибка открытие файла";
		for (int i = 0; i < tubebox.size(); i++)
			fs << i << ". " << tubebox[i].show() << endl;
		for (i = tubebox.size(); i < Ksbox.size() + tubebox.size(); i++)
			fs << i << ". " << Ksbox[i - tubebox.size()].show() << endl;
		fs.close();
	}
	void button_7() {
		string path = "Text.txt", txt, proverka;
		string tube[3],
			   ks[4];
		int t=0, r=0, i;
		fstream fs;
		fs.open(path, fstream::in | fstream::out | fstream::app);
		if (!fs.is_open())
			cout << "Ошибка открытие файла";
		while (!fs.eof()) {
			fs >> txt;
			if (txt == "Tube") {
				r = 0; t = 0; tube[2] = "";
				Tube realtube;
				while (!fs.eof()) {
					fs >> txt;
					t ++;
					if (t % 2 == 0) {
						tube[r] = txt;
						r++;
					}
					if (tube[2] == "В" || tube[2] == "Не") {
						realtube.filesave(tube);
						tubebox.push_back(realtube);
						break;
					}

				}
			}
			if (txt == "KS") {
				r = 0; t = 0;ks[3]="";
				Ks realKs;
				while (!fs.eof()) {
					fs >> txt;
					t++;
					if (t % 2 == 0) {
						ks[r] = txt;
						r++;
					}
					if (ks[3] != "") {
						realKs.filesave(ks);
						Ksbox.push_back(realKs);
						break;
					}
				}
			}
		}
	}
};

int main() {
	Main programm;

	setlocale(LC_ALL, "Russian");

	programm.start();

	
	return 0;
}

/*slovar = {"button_1": button1,
		  "button_2" : button2,
		  "chislo": 123}

defaultbutton = "button_"

>> 2

slovar["defaultbutton"+input]()*/