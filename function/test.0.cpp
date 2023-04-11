#include <fstream>
#include <iostream>

using namespace std;

int m1(int a) {return a*5;}
float m2(float b) { return b * b; }
int main() {
    // ���� ����
    ofstream outfile("mybin���1.dat", ios::out | ios::binary);

    // int 1234 ����
    int num1 = 1234;
    outfile.write((char*)&num1, sizeof(num1));

    // int 1000���� 5000���� ���ڿ� 5�� ���� �� 5�� ����
    for (int i = 1000; i <= 5000; i += 1000) {
        int num2 = m1(i);
        outfile.write((char*)&num2, sizeof(num2));
    }

    // float -0.5���� 0.5�� �����ϸ鼭 �ڽ��� �� �� 3�� ����
    for (float f = -0.5; f <= 0.5; f += 0.5) {
        float num3 = m2(f);
        outfile.write((char*)&num3, sizeof(num3));
    }

    // ���� �ݱ�
    outfile.close();

    return 0;
}