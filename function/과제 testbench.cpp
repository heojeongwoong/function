#include <fstream>
#include <iostream>

using namespace std;

int main() {
    int reader1;
    int reader2[5];
    float reader3[3];

    // ���� ����
    ifstream infile("mybin���4.dat", ios::binary | ios::in);
    if (!infile) {
        cout << "no file : " << endl;
        return 0;
    }

    // �� �б�
    infile.read((char*)&reader1, sizeof(reader1));
    infile.read((char*)&reader2, sizeof(reader2));
    infile.read((char*)&reader3, sizeof(reader3));

    // ���� �ݱ�
    infile.close();

    // �� ���
    cout << "reader1: " << reader1 << endl;
    for (int i = 0; i < 5; i++) {
        cout << "reader2[" << i << "]: " << reader2[i] << endl;
    }
    for (int i = 0; i < 3; i++) {
        cout << "reader3[" << i << "]: " << reader3[i] << endl;
    }

    return 0;
}