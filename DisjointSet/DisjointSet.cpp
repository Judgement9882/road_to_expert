#include <iostream>

using namespace std;

int N; // 전체 크기
int p[10]; // 부모

// 자기 자신으로 초기화
void makeSet() {
	for (int i = 0; i < N; i++) p[i] = i;
}

// 부모 찾기
int findSet(int a) {
	if (p[a] == a) return a;
	return p[a] = findSet(p[a]); // 경로 압축
}

bool unionSet(int a, int b) {
	int aRoot = findSet(a);
	int bRoot = findSet(b);

	if (aRoot == bRoot) return false; // 이미 같은 집합
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
	if (!unionSet(0, 2)) cout << "이미 같은 집합입니다."; // o
	else cout << "합치기 성공.";
	if (!unionSet(3, 2)) cout << "이미 같은 집합입니다.";
	else cout << "합치기 성공."; // o

	return 0;
}
