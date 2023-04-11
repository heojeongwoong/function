#include <fstream>
#include <iostream>

using namespace std;

// ����ü ����
struct Data {
    int v1;
    int v2[5];
    float v3[3];
};

// int 1234 �Է�
void m0(int* v1) {
    *v1 = 1234;
}

// int 1000���� 5000���� ���ڿ� 5�� ���� �� 5�� ����
void m1(int* v2) {
    for (int i = 1000; i <= 5000; i += 1000) {
        int a = (i - 1000) / 1000;
        v2[a] = i * 5;
    }
}

// float -0.5���� 0.5�� �����ϸ鼭 �ڽ��� �� �� 3�� ����
void m2(float* v3) {
    for (int a = 0; a < 3; a++) {
        float f = -0.5 + 0.5 * a;
        v3[a] = f * f;
    }
}

int main() {
    Data data;

    m0(&data.v1);
    m1(data.v2);
    m2(data.v3);

    // ���� ����
    ofstream outfile("mybin���3.dat", ios::out | ios::binary);
    if (!outfile) {
        cout << "no file : " << endl;
        return 0;
    }

    // �� ����
    outfile.write((char*)&data, sizeof(data));

    // ���� �ݱ�
    outfile.close();

    // ���� ����
    ifstream infile("mybin���3.dat", ios::binary | ios::in);
    infile.read((char*)&data, sizeof(data));

    // ���� �ݱ�
    infile.close();
    cout << "���� ���� �Ϸ�" << endl;

    return 0;
}