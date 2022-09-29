#include <iostream>
#include <clocale>
#include <cstdio>
#include <ctime>
#include <fstream>

using namespace std;

// ���������� ��������� �������: 192000 �����, 1000 ��������, 1000 ����� �������
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
    cout << "                      ������, ��� ��� ��������� ������� �� ������ ������ ���������� ���������: m=v (���-�� �������� ������� = ����� �������)" << endl;
    cout << "____________________________________________________________" << endl << endl;

    cout << " ����� ������� ���������� ����� �������: " << endl;
    cin >> n;
    cout << " ������� ���������� �������� �������: " << endl;
    cin >> m;
    cout << " ������� ����� �������: " << endl;
    cin >> v;

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
    /*cout << " ��� ������: " << endl;
    for (int i = 0; i < v; i++) {
        cout << "(" << vect[i] << ")" << endl;
    }
    cout << endl << endl;*/

    // ���������� ������� �� �����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            fscanf(in,"%d",&a[i][j]);
        }
    }

    // ����� ������� �� �����
    /*cout << " ��������� �������:" << endl;
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
    cout << endl;*/

    // ������������ ������� �� �������
    int *result = new int[n];
    clock_t start_time =  clock(); // ��������� �����
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = 0; j < m; j++) {
            result[i] += vect[j] * a[i][j];
        }
    }
    double calculation_time = (double) (clock() - start_time)/CLOCKS_PER_SEC; // ����� ������������
    cout << "����� ���������� ������������: " << calculation_time << endl;
    std::ofstream log_out;
    log_out.open("log.txt", std::ios::app);
    log_out << "m: " << m << ", n: " << n << ", v: " << v << ", elapsed time: " << calculation_time << endl;
    log_out.close();
    cout << "���� log.txt �������� ����������� � �������" << endl;

    // ������ ������������ � �������� ����
    for (int i = 0; i < n; i++) {
        fprintf(out,"%d ", result[i]);
    }
    cout << "��������� ��������� ������� � ���� out.txt " << endl;

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