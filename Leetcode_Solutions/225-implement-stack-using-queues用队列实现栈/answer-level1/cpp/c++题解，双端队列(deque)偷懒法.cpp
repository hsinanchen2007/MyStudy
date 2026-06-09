**没啥思路可讲，直接用双端队列模拟就好，注意`pop_back()`方法没有返回值**
```
class MyStack {
public:
    /** Initialize your data structure here. */
    deque<int>de;
    MyStack() {
        de.clear();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        de.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x=de.back();
        de.pop_back();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return de.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return de.empty();
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
