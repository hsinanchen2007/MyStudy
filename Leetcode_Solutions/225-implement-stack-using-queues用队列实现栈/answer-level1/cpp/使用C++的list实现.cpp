### 解题思路
list的基本操作。

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        mystack.push_front(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int result=mystack.front();
        mystack.pop_front();
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return mystack.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return mystack.empty();
    }
private:
    list<int> mystack;
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