#include<bits/stdc++.h>
using namespace std;

class Stack {
private:
	vector<int> v;

public:
	void push(int data) {
		v.push_back(data);
	}

	bool isEmpty() {
		return v.size() == 0;
	}

	int top() {
		return v[v.size() - 1];
	}
	void pop() {
		if (!isEmpty()) {
			v.pop_back();
		}
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("imput.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	Stack s;

	s.push(5);
	s.push(6);
	s.push(7);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	return 0;
}
