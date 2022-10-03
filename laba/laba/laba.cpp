#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Tube
{
public:
    void addparams() {
        cout << "\nВведите длинну: ";
        cin >> length;
        cout << "Введите диаметр: ";
        cin >> diameter;
        cout << "Введите признак: ";
        cin >> feature;
        if (feature == "В ремонте" || feature == "в ремонте" || feature == "не в ремонте" || feature == "Не в ремонте" )
            feature = feature;
        else {
            cout << "Ошибка (в ремонте/не в ремонте)\n";
            cout << "Введите признак: ";
            cin >> feature;
        }
    }
    void show() {
        cout << "Длина: " << length << "   Диаметр : " << diameter << "   Признак : " << feature<<"\n";

    }
    void change() {
        cout << "\n1.Длина: " << length <<"\n2.Диаметр: " << diameter << "\n3.Признак: " << feature<<"\n\nВведите № параметра ";
        
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
            if (feature == "В ремонте" || feature == "в ремонте" || feature == "не в ремонте" || feature == "Не в ремонте" )
                feature = feature;
            else {
                cout << "Ошибка (в ремонте/не в ремонте)\n";
                cout << "Введите признак: ";
                cin >> feature;
            }
        }
        else {
            cout << "\nOшибка\n";
            change();
        }

    }
        

private:
    int length, diameter, i,change_number;
    string feature, type = "Труба";

};

class Ks
{
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
    void show() {
        cout << "Название: " << name << "     Колличество цехов: " << departments << "     Количество цехов в работе: " << departments_in_use << "     Эффективность: " << feature <<"\n";

    }
    void change() {
        cout << "\n1.Название: " << name << "\n2.Колличество цехов: " << departments << "\n3.Количество цехов в работе: " << departments_in_use << "\n4.Эффективность: " << feature << "\nВведите № параметра ";

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
    int departments, departments_in_use,change_number;
    string name, feature, type = "Кс";

};

int main()
{

    setlocale(LC_ALL, "Russian");

    vector<Tube> tubebox;
    vector<Ks> Ksbox;
    int i,number;
    int button;


    while (true)
    {
        cout << "\n1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\n";
        cin >> button;
        if (button == 1) {
            Tube realtube;
            realtube.addparams();
            tubebox.push_back(realtube);
        }
        if (button == 2) {
            Ks realKs;
            realKs.addparams();
            Ksbox.push_back(realKs);
        }
        if (button == 3) {
            if (tubebox.size() != 0 || Ksbox.size() != 0) {
                for (int i = 0; i < tubebox.size(); i++) {
                    cout << i << ". " ;
                    tubebox[i].show();
                }
                for (i= tubebox.size(); i < Ksbox.size()+ tubebox.size(); i++) {
                    cout << i << ". ";
                    Ksbox[i- tubebox.size()].show();
                }
            }
            else
                cout << "\nСписок пуст\n";
        }
        if (button == 0) {
            break;
        }
        if (button == 4) {
            if (tubebox.size() != 0) {
                for (int i = 0; i < tubebox.size(); i++) {
                    cout << i << ". ";
                    tubebox[i].show();
                }

                cout << "\nНомер трубы:";
                cin >> number;
                tubebox[number].change();
            }
            else
                cout << "\n Ёще нет труб\n";
        }
        if (button == 5) {
            if (Ksbox.size() != 0) {
                for (int i = 0; i < Ksbox.size(); i++) {
                    cout << i << ". ";
                    Ksbox[i].show();
                }
                cout << "\nНомер Кс:";
                cin >> number;
                Ksbox[number].change();
            }
            else
                cout << "\nЁще нет кс\n";
        }
    }
    return 0;
}