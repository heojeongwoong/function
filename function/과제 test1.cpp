#include <fstream>
#include <iostream>

using namespace std;

int m1(int a) { return a * 5; }
float m2(float b) { return b * b; }
int main() {
    int i[1];
    int j[5];
    float k[3];

    int* reader1;
    int* reader2;
    float* reader3;
    reader1 = new int[1];
    reader2 = new int[5];
    reader3 = new float[3];

    // ���� ����
    ofstream outfile("mybin���1.dat", ios::out | ios::binary);
    if (!outfile) {
        cout << "no file : " << endl;
        return 0;
    }
    // int 1234 ����
    i[0] = 1234;
    outfile.write((char*)&i[0], sizeof(i[0]));

    // int 1000���� 5000���� ���ڿ� 5�� ���� �� 5�� ����

    for (int a=0, i = 1000; i <= 5000; i += 1000,a++) {
        int num1 = m1(i);
        j[a] = num1;

       outfile.write((char*)&j[a], sizeof(j[a]));
    }

    // float -0.5���� 0.5�� �����ϸ鼭 �ڽ��� �� �� 3�� ����
    for (int a = 0; a < 3; a++) {
        float f = -0.5 + 0.5 * a;
        float num2 = m2(f);
        k[a] = num2;
        outfile.write((char*)&k[a], sizeof(k[a]));
    }
    outfile.close();

    ifstream infile("mybin���1.dat", ios::binary | ios::in);
    infile.read((char*)reader1, sizeof(*reader1));
    infile.read((char*)reader2, sizeof(*reader2));
    infile.read((char*)reader3, sizeof(*reader3));
    // ���� �ݱ�
    infile.close();
    cout << "���� ���� �Ϸ�" << endl;

    delete[] reader1;
    delete[] reader2;
    delete[] reader3;
    return 0;
}