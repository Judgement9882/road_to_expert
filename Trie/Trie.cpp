#include <iostream>

using namespace std;

class Node {
public:
	Node* childs[26] = { NULL };
	bool fin = false;
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
			if (cur->childs[idx] != NULL)
				cur = cur->childs[idx];
			else {
				cur->childs[idx] = new Node();
				cur = cur->childs[idx];
			}
		}

		cur->fin = true;
	}

	bool find(const char* str) {
		Node* cur = this->root;
		for (int i = 0; i < strlen(str); i++) {
			int idx = str[i] - 'a';
			if (cur->childs[idx] == NULL) return 0;
			else cur = cur->childs[idx];
		}

		if (cur->fin) return 1;
		return 0;
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
