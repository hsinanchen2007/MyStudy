执行用时 :4 ms, 在所有 C++ 提交中击败了67.76%的用户
内存消耗 :9.5 MB, 在所有 C++ 提交中击败了5.73%的用户
### 代码

```cpp
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}
	stack<int> s1;
	stack<int> s2;

	/** Push element x to the back of queue. */
	void push(int x) 
	{
		if (s1.empty())
			s1.push(x);
		else
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			s2.push(x);
			while (!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop()
	{
		int t= s1.top();
		s1.pop();
		return t;

	}

	/** Get the front element. */
	int peek()
	{
		return s1.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() 
	{
		return s1.empty();
	}
};
```