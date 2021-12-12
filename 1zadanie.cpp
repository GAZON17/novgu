#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    double a, b, c;
    char op;
    cout << "Доступные операции: +,-,*,/" << endl;
    while (true)
    {
        cout << "Введите пример: ";
        cin >> a >> op >> b;
        switch (op)
        {
        case '+':   
        {
            c = a + b;
            cout << "Результат: " << c << endl;
        }break;
        case '-':  
        {
            c = a - b;
            cout << "Результат: " << c << endl;
        }break;
        case '*':  
        {
            c = a * b;
            cout << "Результат: " << c << endl;
        }break;
        case '/':   
        {
            if (b != 0)
            {
                c = a / b;
                cout << "Результат: " << c << endl;
            }
            else cout << "На ноль делить нельзя." << endl;
        }break;
        default:    cout << "Неизвестная операция." << endl;
        }
        system("PAUSE");
    }
}