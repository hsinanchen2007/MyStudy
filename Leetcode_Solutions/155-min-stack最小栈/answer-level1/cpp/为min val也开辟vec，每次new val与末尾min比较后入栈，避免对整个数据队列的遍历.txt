### 解题思路
执行用时 :32 ms, 在所有 C++ 提交中击败了76.01% 的用户
内存消耗 :17 MB, 在所有 C++ 提交中击败了21.26%的用户

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
	private:
		vector<int> m_min_stack;
		vector<int> m_mins;
		int m_minimum = 0;
	public:
	    /** initialize your data structure here. */
	    MinStack() {
	    }
	    void push(int x) {
	    	m_minimum = m_mins.size() ? std::min(x, m_mins[m_mins.size()-1]) : x;
	    	m_mins.push_back(m_minimum);
	    	m_min_stack.push_back(x);
	    }
	    void pop() {
	    	m_mins.pop_back();
	    	m_min_stack.pop_back();
	    }
	    int top() {
	    	return m_min_stack[m_min_stack.size()-1];
	    }
	    int getMin() {
	    	return m_mins[m_mins.size()-1];
	    }
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