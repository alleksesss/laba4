#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Task
{
public:
    float R;
    float y;
    string line;
    string a;
    int n, i, j, **x;

    double algoritm1(float R)
    {
        if (R >= -10 && R < -6) // 1 диапазон значений
            y = sqrt(4 - pow((R + 8), 2)) - 2;

        else if (R < 2) // 2 диапазон значений
            y = 0.5 * R + 1;

        else if (R < 6) // 3 диапазон значений
            y = 0;

        else if (R <= 8) // 4 диапазон значений
            y = pow((R - 6), 2);
        return y;
    }
    void laba1()
    {
        algoritm1(R);

        cout << "При X = " << R << ", значение Y = " << y << endl; // Вывод значения Y, для заданного значения Х
    }

    void laba12()
    {
        int x = 0;

        for (x = -10; x <= 8; x++)
        {
            algoritm1(x);
            cout << "При X = " << x << ", значение Y = " << y <<endl; // Вывод значения Y, для заданного значения Х
        }
    }

    void laba2(int n, float y)
    {
        int **x;
        x = new int *[n];
        for (i = 0; i < n; i++)
            x[i] = new int[y];

        for (i = 0; i < n; i++)
            for (j = 0; j < y; j++)
                x[i][j] = rand() % 20;

        for (i = 0; i < n; i++)
        {
            cout << "\n";
            for (j = 0; j < y; j++)
                cout << "a[" << i << "]"
                     << "[" << j << "] = 4" << x[i][j] << "  ";
        }
    }

    void laba3()
    {
        ifstream fin("input.txt");  // вывод данных из файлf
        ofstream fout("input.txt"); // ввод данных в файл
        cout << '\n';
        int l = 0;
        string b;
        for (int x = -10; x < 8; x++)
        {
            l++;
            algoritm1(x);
            fout << y << endl;
        }
        fout.close();
        float *data = new float[l];
        l = 0;
        while (getline(fin, b))
        {
            data[l] = stof(b);
            l++;
        }
        for (int i = 0; i < l; i++)
            cout << data[i] << "\n";
        fin.close(); // закрываем файл
    }
};

int main()
{
    setlocale(LC_ALL, "RU");
    setlocale(LC_ALL, ".UTF8");

    Task laba5;
    cout << "Введите X от -10 до 8"<< endl;
    cin >> laba5.R;

    laba5.laba1();
    laba5.laba12();
    cout << "\n Введите Кол-во строк\n";
    cin >> laba5.n;
    cout << "\n Введите Кол-во столбцов\n";
    cin >> laba5.y;
    laba5.laba2(laba5.n, laba5.y);
    laba5.laba3();
}