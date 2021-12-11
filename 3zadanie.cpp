#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
#include <windows.h>

using namespace std;

unordered_map<string, int> calc()
{
    unordered_map<string, int> dictionary;
    string s;
    getline(cin, s);
    char* cstr = &s[0];
    char* dim = strtok(cstr, " ");

    while (dim != NULL)
    {
        dictionary[string(dim)]++;
        dim = strtok(NULL, " ");
    }
    return dictionary;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введите текст, в котором будет искаться наиболее встречаемое слово." << endl;
    while (true)
    {
        unordered_map<string, int> dictionary = calc();

        int max = -1;
        string maxS = "";
        for (const auto& kv : dictionary)
        {
            if (kv.second > max) {
                max = kv.second;
                maxS = kv.first;
            }
        }
        cout << "Слово, которое встречается чаще всего: ";
        cout << maxS << endl;
    }
    return 0;
}