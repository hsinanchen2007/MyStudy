### 解题思路
维护一个最小栈记录历史最小值

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> minstk;
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if(minstk.empty())minstk.push(x);
        else minstk.push(min(x,minstk.top()));
    }
    
    void pop() {
        stk.pop();
        minstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
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