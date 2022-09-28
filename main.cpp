#include <iostream>
#include <clocale>
#include <cstdio>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int n, m, v;   // ����������� ������� � ����� �������
    FILE *in=fopen("in.txt", "rt"); // ���� ������
    FILE *out=fopen("out.txt", "wt"); // ���� ������

    cout << endl << "____________________________________________________________" << endl;
    cout << " ��������� ���� in.txt � ������������ �� ��������� ��������:" << endl;
    cout << " A1  A2 ...  Ai  Av"  << endl;

    cout << " B11 B12 ... B1j B1n" << endl;
    cout << " B21 B22 ... B2j B2n" << endl;
    cout << " ... ... ... ... ..." << endl;
    cout << " Bi1 Bi2 ... Bij Bin" << endl;
    cout << " Bm1 Bm2 ... Bmj Bmn" << endl;

    cout << "                    , ��� Bij - [i][j]-�� ������� ������� B ����������� m x n," << endl;
    cout << "                      � Ai - i-�� ������� ������� A ����� v." << endl;
    cout << "                      ������, ��� ��� ��������� ������� �� ������ ������ ���������� ���������: m=v" << endl;
    cout << "____________________________________________________________" << endl << endl;

    cout << " ����� ������� ���������� ����� �������: ";
    cin >> n;
    cout << endl;
    cout << " ������� ���������� �������� �������: ";
    cin >> m;
    cout << endl;
    cout << " ������� ����� �������: ";
    cin >> v;
    cout << endl;

    if(m != v) {
        cout << " ������: ����� ������� ������ ��������� � ���-��� ��������!" << endl;
        return -1;
    }


    // ��������� ������ ��� ������� � ������
    int **a = new int *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }

    int *vect = new int[v];


    // ���������� ������� �� �����
    cout << " ���������� ������� �� �����..." << endl;
    for (int i = 0; i < v; i++) {
        fscanf(in, "%d", &vect[i]);
    }

    // ����� ������� �� �����
    cout << " ��� ������: " << endl;
    for (int i = 0; i < v; i++) {
        cout << "(" << vect[i] << ")" << endl;
    }
    cout << endl << endl;


    // ���������� ������� �� �����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            fscanf(in,"%d",&a[i][j]);
        }
    }


    // ����� ������� �� �����
    cout << " ��������� �������:" << endl;
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


    // ������������ ������� �� �������
    int *result = new int[n];
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = 0; j < m; j++) {
            result[i] += vect[j] * a[i][j];
        }
    }

    cout << " �����: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "(" << result[i] << ")" << endl;
        fprintf(out,"%d ", result[i]);
    }

    // ������� ��
    fclose(in);
    fclose(out);

    // �������� ������
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    delete[] vect;
    delete[] result;

    return 0;
}