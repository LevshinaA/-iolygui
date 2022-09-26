

#include <iostream>
#include <vector>
using namespace std;
struct Myclass
{

};


int main()
{
    bool povtor = 1;
    int number = 0;
    vector <Myclass> v={Myclass};

    setlocale(LC_ALL, "Russian");
    while (povtor == true)
    {
        cout << "1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\n";
        cin >> number;
        if (number == 0){
            break;
        }
        if (number > 0 && number <= 7){
            cout << "function\n";
        }
        else {
            cout << "Ошибка!\n";
        }
    }
}

