### 解题思路
一个栈维护最小值
一个栈维护传值
如 2 0 -3
最小栈则为 2 0 -3
类似前缀和
### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */


    stack<int>stk, stk_min;

    MinStack() {

    }
    
    void push(int x) {
        stk.push(x);
        if(stk_min.empty())stk_min.push(x);
        else stk_min.push(min(stk_min.top(),x));
        return;
    }
    
    void pop() {
        stk.pop();
        stk_min.pop();
        return;
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stk_min.top();
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