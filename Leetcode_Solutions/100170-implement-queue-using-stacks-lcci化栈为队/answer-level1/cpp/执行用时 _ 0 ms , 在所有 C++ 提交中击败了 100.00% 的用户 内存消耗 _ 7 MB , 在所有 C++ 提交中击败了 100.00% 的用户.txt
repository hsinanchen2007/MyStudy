### 解题思路
此处撰写解题思路

### 代码

```cpp
class MyQueue {
public:
	/** Initialize your data structure here. */
	stack<int> s1, s2;
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		s1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int temp;
		//temp = s1.top();
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		temp = s2.top();
		s2.pop();
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
		return temp;
	}

	/** Get the front element. */
	int peek() {
		int temp;
		//temp = s1.top();
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		temp = s2.top();
		//s2.pop();
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
		return temp;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s1.empty();
	}
};

```