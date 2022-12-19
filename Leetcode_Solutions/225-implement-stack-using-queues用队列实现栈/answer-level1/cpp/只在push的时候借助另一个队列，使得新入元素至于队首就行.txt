### 解题思路
此处撰写解题思路

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q,aq;
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while(!q.empty()){
            aq.push(q.front());
            q.pop();
        }
        q.push(x);
        while(!aq.empty()){
            q.push(aq.front());
            aq.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t=q.front();
        q.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
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