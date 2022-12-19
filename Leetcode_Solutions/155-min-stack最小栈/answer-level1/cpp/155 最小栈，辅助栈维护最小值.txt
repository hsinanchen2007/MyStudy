### 解题思路
此处撰写解题思路

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    stack<int> _s;
    stack<int> _min;
    void push(int x) {
        if (_s.empty() || x <= _min.top()) _min.push(x);
        _s.push(x);
    }
    
    void pop() {
        if (_s.empty()) return;
        int m = _s.top();
        _s.pop();
        if (m == _min.top()) {
            _min.pop();
        }

    }
    
    int top() {
        return _s.top();
    }
    
    int getMin() {
        return _min.top();
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