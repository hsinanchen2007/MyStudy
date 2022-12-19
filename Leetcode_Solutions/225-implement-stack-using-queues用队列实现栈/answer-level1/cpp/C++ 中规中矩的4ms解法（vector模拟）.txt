```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    vector<int> res; 
    MyStack() {     

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        res.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int back = res.back();
        res.pop_back();
        return back;
    }
    
    /** Get the top element. */
    int top() {
        return res.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return res.empty();
    }
};
```