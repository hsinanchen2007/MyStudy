#### 栈
标准的栈的操作，但是额外加上了请求栈内最小值的接口需求。
标准思路就是另外添加一个存放当前最小值的栈minValueStack，外部每次push/pop的时候同步往minValueStack中push当前的最小值/pop。

```
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		m_stkValue.push(x);
		if (m_stkMinVal.empty() || x < m_stkMinVal.top())
			m_stkMinVal.push(x);
		else
			m_stkMinVal.push(m_stkMinVal.top());
	}

	void pop() {
		m_stkValue.pop();
		m_stkMinVal.pop();
	}

	int top() {
		return m_stkValue.top();
	}

	int getMin() {
		return m_stkMinVal.top();
	}

private:
	std::stack<int> m_stkValue;
	std::stack<int> m_stkMinVal;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```
由代码可以发现，当push进来的值大于等于valueStack栈顶的值的时候，都会往minValueStack栈中压入一个一样的最小值，可以基于这一点，优化一点minValueStack的空间。详见下面推荐的题解。
文末推荐LeetCode精选题解：[Min Stack - 最小栈不同步的做法](https://leetcode-cn.com/problems/min-stack/solution/shi-yong-fu-zhu-zhan-tong-bu-he-bu-tong-bu-python-/)
以及GitHub上一个差值计算的方法：[Min Stack - 差值计算栈内最小值](https://github.com/azl397985856/leetcode/blob/master/problems/155.min-stack.md)
我果真不适合写题解，写文章啊！