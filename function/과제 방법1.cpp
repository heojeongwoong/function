#include <fstream>
#include <iostream>

using namespace std;


int main() {
    // int 1234 ����
    int num1 = 1234;
    // int 1000���� 5000���� ���ڿ� 5�� ���� �� 5�� ����
    for (int i = 1000; i <= 5000; i += 5) {
        int num2 = i * 5;
    }
    // float -0.5���� 0.5�� �����ϸ鼭 �ڽ��� �� �� 3�� ����
    for (float f = -0.5f; f <= 0.5f; f += 0.5f) {
        float num3 = f * f;   
    }
    ofstream outfile("mybin.dat", ios::out | ios::binary);
    outfile.write((char*)&num1, sizeof(num1));
    outfile.write((char*)&num2, sizeof(num2));
    outfile.write((char*)&num3, sizeof(num3));

    // ���� �ݱ�
    outfile.close();
    return 0;
}