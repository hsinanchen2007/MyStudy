先贴上代码
```cpp
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		if (in.empty()) {
			in.push(x);
		}
		else {
			out.push(x);
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int temp = in.top();
		in.pop();
		if (in.empty()) {
			while (!out.empty())
			{
				in.push(out.top());
				out.pop();
			}
		}
		return temp;
	}

	/** Get the front element. */
	int peek() {
		return in.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return in.empty() && out.empty();
	}
private:
	stack<int> in, out;
};
```
使用两个栈
in从栈顶至栈底存放FIFO的元素
所有新元素先加入out中,则是按照LIFO的顺序存放在栈中
取top和pop都从in中操作
若in为空了,就将out中的元素复制到in中去,现在的顺序又变为了FIFO了
判断空则是判断in和out都为空