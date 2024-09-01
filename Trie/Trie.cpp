#include <iostream>

using namespace std;

class Node {
public:
	Node* childs[26] = { NULL }; // 자식 노드 초기화
	bool fin = false; // fin은 해당 단어의 끝
	Node() {}
};

class Trie {
public:
	Node* root;
	Trie() { this->root = new Node(); }

	void insert(const char* str) {
		Node* cur = this->root;
		for (int i = 0; i < strlen(str); i++) {
			int idx = str[i] - 'a';
			if (cur->childs[idx] != NULL) // 해당하는 글자가 이미 있을경우
				cur = cur->childs[idx]; // 이동
			else { // 없을 경우
				cur->childs[idx] = new Node(); // 노드 생성
				cur = cur->childs[idx]; // 이동
			}
		}

		cur->fin = true; // 해당 단어의 끝을 true로 처리
	}

	bool find(const char* str) {
		Node* cur = this->root;
		for (int i = 0; i < strlen(str); i++) {
			int idx = str[i] - 'a';
			if (cur->childs[idx] == NULL) return 0; // 없을 경우
			else cur = cur->childs[idx]; // 있을 경우 이동
		}

		if (cur->fin) return 1; // 해당하는 단어의 fin이 true라면 해당 단어가 있음.
		return 0; // 없으면 0 반환
	}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	Trie* trie = new Trie();

	const char* str[3];
	str[0] = "abc";
	str[1] = "def";
	str[2] = "ertr";

	for (int i = 0; i < 3; i++) trie->insert(str[i]);

	for (int i = 0; i < 3; i++) {
		if (trie->find(str[i])) {
			cout << str[i] << "는 존재합니다.\n";
		}
	}

	delete(trie);

	return 0;
}
