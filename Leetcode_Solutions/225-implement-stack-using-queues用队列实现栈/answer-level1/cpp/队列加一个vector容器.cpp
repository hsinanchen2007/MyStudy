### 解题思路
此处撰写解题思路

### 代码

```cpp
class MyStack {
private:
	deque<int>qe;
   
	vector<int>v;
    
public:
	/** Initialize your data structure here. */
	MyStack() {
		
		
		
	}

	/** Push element x onto stack. */
	void push(int x) {
		qe.push_front(x);
       
		v.push_back(x);
        
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
        int element=v.back();
		qe.pop_front();
		v.pop_back();
        return element;
		
	}

	/** Get the top element. */
	int top() {
		return v.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		if (v.size() == 0) return true;
		else return false;
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```
stack从底往上添加元素，相当于deque把每个元素插到队列前面