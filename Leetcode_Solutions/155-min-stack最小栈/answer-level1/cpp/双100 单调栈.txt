### 解题思路


### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        data = {};
		minVal = {};
    }
    
    void push(int x) {
        data.push_back(x);
		if (minVal.size() == 0) {
			minVal.push_back(x);
		} else {
			if (x <= minVal.back()) {
				minVal.push_back(x);
			}
		}
    }

    void pop() {
        int v = data.back();
		data.pop_back();
		if (v == minVal.back()) {
			minVal.pop_back();
		}
		
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return minVal.back();
    }
private:
	vector<int> data;
	vector<int> minVal;
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