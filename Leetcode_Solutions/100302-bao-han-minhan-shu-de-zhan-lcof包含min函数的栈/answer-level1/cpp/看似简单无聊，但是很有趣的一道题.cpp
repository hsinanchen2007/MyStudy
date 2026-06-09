
```cpp
class MinStack 
{
private:
	/*存储所有数据*/
	stack<int> s1;
	/*自顶向下存储连续的最小值*/
	stack<int> s2;
public:
	/** initialize your data structure here. */
	MinStack() 
	{

	}

	void push(int x) 
	{
		s1.push(x);
		/*等于的时候也要push进去，不然之后pop的时候就会出问题*/
		if (s2.empty() || x <= s2.top())
		{
			s2.push(x);
		}
	}

	void pop() 
	{
		if (s1.top() == s2.top())
		{
			s2.pop();
		}
		s1.pop();
	}

	int top() 
	{
		return s1.top();
	}

	int min() 
	{
		return s2.top();
	}
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```