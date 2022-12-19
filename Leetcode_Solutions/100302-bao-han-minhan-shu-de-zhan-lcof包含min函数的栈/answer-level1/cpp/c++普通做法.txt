### 解题思路
此处撰写解题思路

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> sta;
    //Stack<Integer> stack;
    stack<int> minstack;
    MinStack() {
        //sta=new stack;
        //minstack=new stack;
    }
    
    void push(int x) {
        sta.push(x);
        if(minstack.empty())
            minstack.push(x);
        else minstack.push(minstack.top()<x?minstack.top():x);
    }
    
    void pop() {
        sta.pop();
        minstack.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int min() {
        return minstack.top();
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