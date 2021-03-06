#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>


/*
	Implement QUEUE using std::stack
	-deque is more expensive

*/
using namespace std;
class Queue {
public:
	stack<int> primary;
	stack<int> secondary;

	void push(int val) {
		primary.push(val);
	}

	void pop() {
		if (primary.empty() && secondary.empty()) {
			cout << "Queue is empty" << endl;
		}

		if (!secondary.empty()) {
			cout << secondary.top() << endl;
			secondary.pop();
		}
		else {
			while (!primary.empty()) {
				secondary.push(primary.top());
				primary.pop();
			}
			cout << secondary.top() << endl;
			secondary.pop();
		}
	}

};

int main()
{
	Queue q;

	q.push(1);
	q.push(2);
	q.push(3);

	q.pop();
	q.push(4);
	q.push(5);
	q.pop();
	q.pop();
	q.pop();

	string n;
	cin >> n;
	return 0;
}

