#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

int proverka(string input) {
	int chislo=-1;
	try {
		chislo = stoi(input);
		return chislo;
	}
	catch (const exception& input) {
		cout << "Введите число" << endl;
	}
}

/*bool proverka(string st) {
	for (int x = 0; x < st.length(); x++) {
		if (isdigit(st[x]) == false);
		return false;
	}
}*/

struct Tube {
public:
	void filesave(string tube[]) {
		length_input = tube[0];
		diameter_input = tube[1];
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
		cin >> length_input;
		length = proverka(length_input);
		if (length < 0 || length == 69)
			addparams();
		else {
			cout << "Введите диаметр: ";
			cin >> diameter_input;
			diameter = proverka(diameter_input);
			if (diameter < 0 || diameter == 69)
				addparams();
			else {
			cout << "Выберите № признака:\n 1.В ремонте\n 2.Не в ремонте";
			cin >> feature_num_input;
			feature_num = proverka(feature_num_input);
			if (feature_num <= 0 || feature_num >=3)
				addparams();
			else {
			if (feature_num == 1) {
				feature = "В ремонте";
			}
			else if (feature_num == 2) {
				feature = "Не в ремонте";
			}
			}
			}
		}
	}
	string show() {
		return (type + "   Длина: " + length_input + "   Диаметр: " + diameter_input + "   Признак: " + feature + " .");
	}
	void change() {
		cout << "Выберите № признака:\n 1.В ремонте\n 2.Не в ремонте";
		cin >> feature_num_input;
		feature_num = proverka(feature_num_input);
		if (feature_num <= 0 || feature_num >=3)
			change();
		else {
			if (feature_num == 1) {
				feature = "В ремонте";
			}
			else if (feature_num == 2) {
				feature = "Не в ремонте";
			}
		}
		
	}
private:
	string length_input, diameter_input, feature, feature_num_input, type="Tube";
	int change_number, length, diameter, feature_num;
};

struct Ks {
public:
	void filesave(string ks[]) {
		name = ks[0];
		departments_input = ks[1];
		departments_in_use_input = ks[2];
		feature_input = ks[3];
	}
	void addparams() {
		cout << "\nВведите название: ";
		cin.ignore();
		getline(cin, name);
		cout << "Введите эффективность: ";
		cin >> feature_input;
		feature = proverka(feature_input);
		if (feature < 0 ||feature==69)
			addparams();
		else {
			cout << "Введите колличество цехов: ";
			cin >> departments_input;
			departments = proverka(departments_input);
			if (departments < 0 || departments == 69)
				addparams();
			else {
				cout << "Введите количество цехов в работе: ";
				cin >> departments_in_use_input;
				departments_in_use = proverka(departments_in_use_input);
				if (departments_in_use < 0 || departments_in_use == 69)
					addparams();
				else if  (departments_in_use > departments) {
						cout << "Количесвто цехов в работе не может превышать количество цехов! Попробуйте еще раз";
						addparams();
					}
				}
			}
		
	}
	string show() {
		return (type + "     Название: " + name + "     Колличество_цехов: " + departments_input + "     Количество_цехов_в_работе: " + departments_in_use_input + "     Эффективность: " + feature_input+ " .");
	}
	void change() {
		cout << "Введите новое количество цехов в работе: ";
		cin >> departments_in_use_input;
		departments_in_use = proverka(departments_in_use_input);
		if (departments_in_use < 0 || departments_in_use == 69)
			change();
		else if (departments_in_use > stoi(departments_input)) {
			cout << "Количесвто цехов в работе не может превышать количество цехов! Попробуйте еще раз"<<endl;
			change();
		}
		}

private:
	int change_number, departments, departments_in_use, feature=-1;
	string name, departments_input, departments_in_use_input,feature_input, type = "KS";
};

class Main {
public:
	void start() {
		while (true) {
			cout << "\n1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\n";
			cin >> button;
			button_number=proverka(button);
			if (button_number < 0 || button_number>7)
				start();
			else {
				if (button_number == 1)
					button_1();
				else if (button_number == 2)
					button_2();
				else if (button_number == 3)
					button_3();
				else if (button_number == 4)
					button_4();
				else if (button_number == 5)
					button_5();
				else if (button_number == 6)
					button_6();
				else if (button_number == 7)
					button_7();
				else if (button_number == 0)
					break;
			}
			
		}
	}

private:
	vector<Tube> tubebox;
	vector<Ks> Ksbox;
	string button;
	string number;
	int i, number_number, button_number = 8;

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
			number_number = proverka(number);
			if (number_number < 0 || number_number> tubebox.size()-1)
				button_4();
			else {
				tubebox[number_number].change();
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
			number_number = proverka(number);
			if (number_number < 0 || number_number> Ksbox.size()-1)
				button_5();
			else {
				Ksbox[number_number].change();
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
		int t = 0, r = 0, i;
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
					t++;
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
				ks[0] = "";
				ks[1] = "";
				ks[2] = "";
				ks[3] = "";
				Ks realKs;
				fs >> txt;
				if (txt == "Название:") {
					while (!fs.eof()) {
						fs >> txt;
						if (txt != "Колличество_цехов:")
							ks[0] = ks[0] +" " + txt;
						else break;

					}
					if (txt == "Колличество_цехов:") {
						while (!fs.eof()) {
							fs >> txt;
							if (txt != "Количество_цехов_в_работе:")
								ks[1] = ks[1] + txt;
							else break;

						}
					}
					if (txt == "Количество_цехов_в_работе:") {
						while (!fs.eof()) {
							fs >> txt;
							if (txt != "Эффективность:")
								ks[2] = ks[2] + txt;
							else break;

						}
					}
					if (txt == "Эффективность:") {
						while (!fs.eof()) {
							fs >> txt;
							if (txt != ".")
								ks[3] = ks[3] + txt;
							else break;

						}
						if (txt == ".") {
							realKs.filesave(ks);
							Ksbox.push_back(realKs);
						}
					}
					/*			r = 0; t = 0; ks[3] = "";
								Ks realKs;
								while (!fs.eof()) {
									fs >> txt;
									t++;
									if (ks[0]=="" || txt=="Колличество_цехов:"){
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
							}*/
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