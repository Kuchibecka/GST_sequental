#include <iostream>
#include <clocale>
#include <cstdio>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int n, m, v;   // размерности матрицы и длина вектора
    FILE *in=fopen("in.txt", "rt"); // файл чтения
    FILE *out=fopen("out.txt", "wt"); // файл записи

    cout << endl << "____________________________________________________________" << endl;
    cout << " Заполните файл in.txt в соответствии со следующим форматом:" << endl;
    cout << " A1  A2 ...  Ai  Av"  << endl;

    cout << " B11 B12 ... B1j B1n" << endl;
    cout << " B21 B22 ... B2j B2n" << endl;
    cout << " ... ... ... ... ..." << endl;
    cout << " Bi1 Bi2 ... Bij Bin" << endl;
    cout << " Bm1 Bm2 ... Bmj Bmn" << endl;

    cout << "                    , где Bij - [i][j]-ый элемент матрицы B размерности m x n," << endl;
    cout << "                      а Ai - i-ый элемент вектора A длины v." << endl;
    cout << "                      Учтите, что для умножения матрицы на вектор должно выполнятся равенство: m=v" << endl;
    cout << "____________________________________________________________" << endl << endl;

    cout << " Затем введите количество строк матрицы: ";
    cin >> n;
    cout << endl;
    cout << " Введите количество столбцов матрицы: ";
    cin >> m;
    cout << endl;
    cout << " Введите длину вектора: ";
    cin >> v;
    cout << endl;

    if(m != v) {
        cout << " Ошибка: длина вектора должна совпадать с кол-вом столбцов!" << endl;
        return -1;
    }


    // Выделение памяти под матрицу и вектор
    int **a = new int *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }

    int *vect = new int[v];


    // Считывание вектора из файла
    cout << " Считывание вектора из файла..." << endl;
    for (int i = 0; i < v; i++) {
        fscanf(in, "%d", &vect[i]);
    }

    // Вывод вектора на экран
    cout << " Ваш вектор: " << endl;
    for (int i = 0; i < v; i++) {
        cout << "(" << vect[i] << ")" << endl;
    }
    cout << endl << endl;


    // Считывание матрицы из файла
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            fscanf(in,"%d",&a[i][j]);
        }
    }


    // Вывод матрицы на экран
    cout << " Считанная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "(";
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
            if (j < m-1) {
                cout  << "\t";
            }
        }
        cout << ")" << endl;
    }
    cout << endl;


    // Перемножение вектора на матрицу
    int *result = new int[n];
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = 0; j < m; j++) {
            result[i] += vect[j] * a[i][j];
        }
    }

    cout << " Ответ: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "(" << result[i] << ")" << endl;
        fprintf(out,"%d ", result[i]);
    }

    // Закрыть фд
    fclose(in);
    fclose(out);

    // Очистить память
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    delete[] vect;
    delete[] result;

    return 0;
}