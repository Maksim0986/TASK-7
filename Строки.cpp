#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>

using namespace std;

vector<string> split(string str, string pattern) {
    vector<string> res;
    str += pattern;       
    string word;
    int pos = str.find(pattern);
    while (pos != string::npos) {
        word = str.substr(0, pos);               
        res.push_back(word);                    
        str.erase(0, pos + pattern.length());   
        pos = str.find(pattern);                
    }
    res.push_back(str);                         
    return res;
}

int test1() {
    setlocale(LC_ALL, "rus");
    char b[1000];
    ifstream fin("TextFile1.txt");
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        fin.getline(b, 1000);
        fin.close();
    }

    vector<string>words = split(b, " ");
    int n = words.size();
    for (int i = 0; i < n; i++) {
        cout << words[i] << endl;
    }


    int sl, count = 0;

    int i = 0;
    while (b[i] == ' ' && b[i] != '\0') {
        i++;
    }
    sl = 0;

    while (b[i] != '\0') {
        if (b[i] != ' ' && sl == 0)
        {
            sl = 1;
            count++;
        }
        else if (b[i] == ' ') {
            sl = 0;
        }
        i++;
    }
    cout << "Количество выделенных частей: " << count;
    cin.get();
    return 0;
    
}
        
int test2(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    setlocale(LC_ALL, "Rus");
    cout << "Введите строку: " << endl;
    char* n = new char[250];
    gets_s(n, 250);

    int sl, count = 0;
    
    vector<string>words = split(n, " ");
    int p = words.size();
    
    for (int i = 0; i < p; i++) {
        cout << words[i] << endl;
    }

    int i = 0;
    while (n[i] == ' ' && n[i] != '\0') {
        i++;
    }

    sl = 0;

    while (n[i] != '\0') {
        if (n[i] != ' ' && sl == 0)
        {
            sl = 1;
            count++;
        }
        else if (n[i] == ' ') {
            sl = 0;
        }
        i++;
    }
    cout << "Количество выделенных частей:  " << count;
    cin.get(); 
    return 0;
}

int main() {

    setlocale(LC_ALL, "rus");
    cout << "Лабораторная работа 7" << endl;

    while ("") {

        while ("") {

            cout << " " << endl;
            cout << "1. Запустить программу\t" << endl;
            cout << "2. Выйти из программы\t" << endl;
            cout << " " << endl;

            int m;
            cin >> m;

            switch (m) {

            case 1:
                test1();
                cout << endl;
                test2();
                break;
            case 2:
                cout << "Выход из программы\t" << endl;
                _getch();
                return 0;
                break;
            default:
                cout << "Вы ввели неверный пункт меню, введите его еще раз\t" << endl;
                _getch();
                break;
            }
        }
    }


}

















    
    
    


