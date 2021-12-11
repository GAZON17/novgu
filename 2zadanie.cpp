#include <iostream> // ввод-вывод
#include <conio.h>
#include <cctype> // toupper, tolower
#include <locale>
#include <fstream>
#include <windows.h> // getline, setconsolecp
#include <string> // string
#include <stdlib.h> // pause


using namespace std;

void strtolower(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
		str[i] = tolower(str[i]);
}
void strtoupper(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = toupper(str[i]);
		if ((str[i]) == 'я') str[i] = 'Я';
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char n;
	do
	{
		system("cls");
		cout << "Выберите номер задания" << endl;
		cout << "1 - Бесконечный цикл с выходом" << endl;
		cout << "2 - Преобразование введенной строки в верхний регистр" << endl;
		cout << "3 - Преобразование введенной строки в нижний регистр" << endl;
		cout << "4 - Конкатенация введенных строк" << endl;
		cout << "5 - Вывод строки в файл" << endl;
		cout << "6 - Чтение из произвольного файла" << endl;
		cout << "0 - Выход" << endl;
		n = _getch();
		cout << n << endl;
		switch (n)
		{
		case '1':
		{
			system("cls");
			int i;
			i = 0;
			while (!_kbhit())
			{
				i++;
				cout << "(" << i << ")" << "Чтобы остановить это безумие, нажмите любую кнопку." << endl;
			}
			system("pause");
		}break;
		case '2':
		{
			system("cls");
			char word[1000];
			cout << "Введите строку для преобразоваия в верхний регистр:" << endl;
			cin.getline(word, 1000);
			strtoupper(word);
			cout << "Преобразованная строка:" << endl << word << endl;
			system("pause");
		}break;
		case '3':
		{
			system("cls");
			char word[1000];
			cout << "Введите строку для преобразоваия в нижний регистр:" << endl;
			cin.getline(word, 1000);
			strtolower(word);
			cout << "Преобразованная строка:" << endl << word << endl;
			system("pause");
		}break;
		case '5':
		{
			system("cls");
			ofstream fout;
			string s;
			cout << "Введите строку для записи в файл." << endl;
			fout.open("file.txt");
			getline(cin, s);
			fout << s;
			fout.close();
			system("pause");
		}break;
		case '4':
		{
			system("cls");
			int k;
			cout << "Введите количество строк: ";
			cin >> k;
			string s;
			string arr[10000];
			int j = 0;
			for (int i = 0; i <= k; i++)
			{
				getline(cin, s);
				arr[j] = s;
				j++;
			}
			cout << "Конкатенация:" << endl;
			for (j = 0; j <= k; j++)
				cout << arr[j];
			cout << endl;
			system("pause");
		}break;
		case'6':
		{
			system("cls");
			string s;
			cout << "!!!Чтобы выводился текст на русском языке, файл должен быть с кодировкой ANSI!!!" << endl;
			cout << "Для того, чтобы сохранить файл с такой кодировкой, делаем следующие действия:" << endl;
			cout << "Файл -> сохранить как -> кодировка 'ANSI'." << endl << endl;
			cout << "Введите полный путь к файлу: ";
			getline(cin, s);
			cout << endl;
			ifstream inf(s);
			if (!inf)
			{
				cerr << "Путь указан неверно или файл не может быть открыт." << endl;
				exit(1);
			}
			while (inf)
			{
				string strInput;
				getline(inf, strInput);
				cout << strInput << endl;
			}
			system("pause");
		}break;
		}
	} while (n != '0');
}
	
