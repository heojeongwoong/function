#include <fstream>
#include <iostream>

using namespace std;

int main() {
    int reader1;
    int reader2[5];
    float reader3[3];

    // 파일 열기
    ifstream infile("mybin방법4.dat", ios::binary | ios::in);
    if (!infile) {
        cout << "no file : " << endl;
        return 0;
    }

    // 값 읽기
    infile.read((char*)&reader1, sizeof(reader1));
    infile.read((char*)&reader2, sizeof(reader2));
    infile.read((char*)&reader3, sizeof(reader3));

    // 파일 닫기
    infile.close();

    // 값 출력
    cout << "reader1: " << reader1 << endl;
    for (int i = 0; i < 5; i++) {
        cout << "reader2[" << i << "]: " << reader2[i] << endl;
    }
    for (int i = 0; i < 3; i++) {
        cout << "reader3[" << i << "]: " << reader3[i] << endl;
    }

    return 0;
}