设置一个辅助栈，让辅助栈中的元素为原栈中元素的非增序的值

```
class MinStack {
public:
    /** initialize your data structure here. */

    stack<int> a;
    stack<int> b;
    MinStack() {

    }
    
    void push(int x) {
        a.push(x);
        if(!b.empty())
        {
            if(b.top()>=x)
            b.push(x);
        }
        else
        {
            b.push(x);
        }

    }
    
    void pop() {
        if(a.top()==b.top())
        {
            b.pop();
        }
        a.pop();

    }
    
    int top() {
        return a.top();
    }
    
    int min() {
        return b.top();
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


