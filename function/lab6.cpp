#include <iostream>
using namespace std;
void cel2faren(int, float*, float*);
int main() { // ��ȯ���� �ִ� main �Լ��� ����
    float cel[] = { 20, 30, 100 }, faren[3];
    cel2faren(3, cel, faren);
    for (int i = 0; i < 3; i++) {
        cout << faren[i] << endl; // ��ȯ�� ȭ�� �µ� ���
    }
    return 0; // ��ȯ�� 0�� ����
}
void cel2faren(int n, float* cc, float* ff) {
    for (int i = 0; i < n; i++) {
        ff[i] = cc[i] * 9.0 / 5.0 + 32;
    }
    return; // ���� ����
}