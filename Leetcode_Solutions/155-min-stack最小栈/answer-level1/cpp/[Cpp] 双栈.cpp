### 解题思路
此处撰写解题思路

### 代码

```cpp
class MinStack {
public:
    stack<int> st1;
    stack<int> st2;

    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st1.push(x);
        if (st2.empty() || x <= st2.top()) st2.push(x);
    }
    
    void pop() {
        if (st1.empty()) return;
        int now = st1.top();
        st1.pop();
        if (now == st2.top()) st2.pop();
    }
    
    int top() {
        if (st1.empty()) return -1;
        return st1.top();
    }
    
    int getMin() {
        if (st2.empty()) return -1;
        return st2.top();
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