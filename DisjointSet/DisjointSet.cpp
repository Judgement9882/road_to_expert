#include <iostream>

using namespace std;

int N; // ��ü ũ��
int p[10]; // �θ�

// �ڱ� �ڽ����� �ʱ�ȭ
void makeSet() {
	for (int i = 0; i < N; i++) p[i] = i;
}

// �θ� ã��
int findSet(int a) {
	if (p[a] == a) return a;
	return p[a] = findSet(p[a]); // ��� ����
}

bool unionSet(int a, int b) {
	int aRoot = findSet(a);
	int bRoot = findSet(b);

	if (aRoot == bRoot) return false; // �̹� ���� ����
	p[bRoot] = aRoot; // union
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	N = 5;
	makeSet();

	unionSet(0, 1);
	unionSet(1, 2);
	unionSet(3, 4);

	cout << findSet(4); // 3
	cout << findSet(2); // 0
	if (!unionSet(0, 2)) cout << "�̹� ���� �����Դϴ�."; // o
	else cout << "��ġ�� ����.";
	if (!unionSet(3, 2)) cout << "�̹� ���� �����Դϴ�.";
	else cout << "��ġ�� ����."; // o

	return 0;
}
