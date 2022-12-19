### 解题思路
思路：
1. 首先想到把栈中元素排序，但这样就不能先进后出了；
2. 然后想到用一个最小值变量min保存每次入栈的最小值，但是这样一旦发生了出栈，最小值就没法更新了；
3. 想到辅助栈，压栈入栈，最小值也压栈入栈，保存每次的最小值在辅助栈中。
- 另外，虽然本题不会遇到，但还是要考虑返回top和min时，如果栈为空的情况。保证鲁棒性~

### C++代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> mainS;
    stack<int> minS;
    MinStack() {
    }
    
    void push(int x) {
        mainS.push(x);
        if(minS.empty())
            minS.push(x);
        else
        {
            if(x<=minS.top())
                minS.push(x);
            else
                minS.push(minS.top());
        }
    }
    
    void pop() {
        if(mainS.empty()) return;
            mainS.pop();
            minS.pop();
    }
    
	int top() {
		if (!mainS.empty())
			return mainS.top();
		else
			return INT_MIN;
	}

	int min() {
		if (!minS.empty())
			return minS.top();
		else
			return INT_MIN;
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