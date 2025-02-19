#include <iostream>
using namespace std;
int count;

void vizualization(int n) {
    cout << n << endl;
    return;
}

void han(int n, int start, int point, int temp) {
    if (n != 0) {
        han(n - 1, start, temp, point);
        vizualization(n);
        cout << start << "=>" << point << endl;
        han(n - 1, temp, point, start);
    }
    return;
}
int main()
{
    setlocale(LC_ALL, "russian");
    int n;
    
    while (true) {
        cout << "Введите количество дисков: ";
        cin >> n;
        count = n;
        cout << endl;

        han(n, 1, 3, 2);
    }
    return 0;
}

