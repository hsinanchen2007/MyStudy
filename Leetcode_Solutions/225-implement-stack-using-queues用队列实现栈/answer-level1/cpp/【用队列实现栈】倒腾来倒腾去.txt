### 思路

### 答题
```C++
class MyStack 
{
public:
	/** Initialize your data structure here. */
	MyStack() 
		: m_topMark(true)
	{

	}

	/** Push element x onto stack. */
	void push(int x) 
	{
		queue<int> *pTop = m_topMark ? &m_dataA : &m_dataB;
		queue<int> *pBase = m_topMark ? &m_dataB : &m_dataA;
		if (!pTop->empty())
		{
			pBase->push(pTop->front());
			pTop->pop();
		}
		pTop->push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop()
	{
		int i = top();

		queue<int> *pTop = m_topMark ? &m_dataA : &m_dataB;

		pTop->pop();
		return i;
	}

	/** Get the top element. */
	int top()
	{
		queue<int> *pTop = m_topMark ? &m_dataA : &m_dataB;
		queue<int> *pBase = m_topMark ? &m_dataB : &m_dataA;

		if (!pTop->empty()) return pTop->front();

		for (int i = 0; i < pBase->size() - 1; i++)
		{
			pTop->push(pBase->front());
			pBase->pop();
		}
		m_topMark = !m_topMark;

		return pBase->front();
	}

	/** Returns whether the stack is empty. */
	bool empty()
	{
		return m_dataA.empty() && m_dataB.empty();
	}

private:
	queue<int> m_dataB;
	queue<int> m_dataA;
	bool m_topMark;
};
```


### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)


