#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

struct Tube {
public:
	void addparams() {
		cout << "\nВведите длинну: ";
		cin >> length;
		cout << "Введите диаетр: ";
		cin >> diameter;
		cout << "Введите описание: ";
		cin >> feature;

	}
	string show() {
		return ("Длина: " + length + "   Диаметр : " + diameter + "   Признак : " + feature);
	}
	void change() {
		cout << "\n1.Длина: " << length << "\n2.Диаметр: " << diameter << "\n3.Признак: " << feature << "\n\nВведите № параметра для редактирования";

		cin >> change_number;
		if (change_number == 1) {
			cout << "\nВведите новую длину:";
			cin >> length;
		}
		if (change_number == 2) {
			cout << "Введите новый диаметр:";
			cin >> diameter;
		}
		if (change_number == 3) {
			cout << "Введите новый признак:";
			cin >> feature;
		}
		else {
			cout << "\nOшибка\n";
			change();
		}
	}
private:
	string length, diameter, feature;
	int change_number;
};

struct Ks {
public:
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
		return ("Название: " + name + "     Колличество цехов: " + departments + "     Количество цехов в работе: " + departments_in_use + "     Эффективность: " + feature);
		//SetConsoleCP(866);
	}
	void change() {
		cout << "\n1.Название: " << name << "\n2.Колличество цехов: " << departments << "\n3.Количество цехов в работе: " << departments_in_use << "\n4.Эффективность: " << feature << "\nВведите № параметра для редактирования";
		cin >> change_number;
		if (change_number == 1) {
			cout << "\nВведите новое название:";
			cin >> name;
		}
		if (change_number == 2) {
			cout << "Введите новое колличество цехов:";
			cin >> departments;
		}
		if (change_number == 3) {
			cout << "Введите новое колличество цехов в работе:";
			cin >> departments_in_use;
		}
		if (change_number == 4) {
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
	string name, feature, departments, departments_in_use, type = "КС";
};

class Main {
public:
	void start() {
		while (true) {
			cout << "\n1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\n";
			cin >> button;
			if (button == 1)
				button_1();
			if (button == 2)
				button_2();
			if (button == 3)
				button_3();
			if (button == 4)
				button_4();
			if (button == 5)
				button_5();
			if (button == 6)
				button_6();
			if (button == 7)
				button_7();
			if (button == 0)
				break;
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
			cout << "\n Ёще нет труб\n";
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
		string path = "Text.txt",txt,proverka;
		int t;
		fstream fs;
		fs.open(path, fstream::in | fstream::out | fstream::app);
		if (!fs.is_open())
			cout << "Ошибка открытие файла";
		while (!fs.eof()) {

			getline(fs, txt);
			
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