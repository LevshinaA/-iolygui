#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Tube
{
public:
    void addparams() {
        cout << "Введите длинну";
        cin >> length;
        cout << "Введите диаетр";
        cin >> diameter;
        cout << "Введите описание";
        cin >> feature;
    }
    void show() {
        cout << "Длина: " << length << "   Диаметр : " << diameter << "   Признак : " << feature;

    }

private:
    int length, diameter, i;
    string feature, type = "Труба";

};

int main()
{

    setlocale(LC_ALL, "Russian");

    vector<Tube> tubebox;
    int i;
    int button;

    while (true)
    {
        cout << "1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\n";
        cin >> button;
        if (button == 1) {
            Tube realtube;
            realtube.addparams();
            tubebox.push_back(realtube);
        }
        if (button == 3) {
            for (int i = 0; i < tubebox.size(); i++) {
                cout << i;
                tubebox[i].show();
            }
        }
    }
    return 0;
}