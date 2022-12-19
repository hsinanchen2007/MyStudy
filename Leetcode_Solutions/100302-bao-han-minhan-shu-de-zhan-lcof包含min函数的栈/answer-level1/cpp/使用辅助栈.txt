
### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        stackdata.push(x);
        //stackdata中的最小元素始终应为minstack.top()
        if(minstack.empty()) minstack.push(x);
        else if(minstack.top()>x) minstack.push(x);
        else minstack.push(minstack.top());
    }
    
    void pop() {
        stackdata.pop();
        minstack.pop();
    }
    
    int top() {
        return stackdata.top();
    }
    
    int min() {
        return minstack.top();
    }

    stack<int> stackdata;
    stack<int> minstack;//用于记录此时栈中的最小元素
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