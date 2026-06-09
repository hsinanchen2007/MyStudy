

### 代码

```cpp
class MyStack {
public:
    queue<int> num;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        num.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = num.size();
        for(int i = 0 ; i < size - 1 ; i ++) {
            num.push(num.front());
            num.pop();
        }
        int n = num.front();
        num.pop();
        return n;
    }
    
    /** Get the top element. */
    int top() {
        return num.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(num.empty())  return true;
        else return false;
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