### 解题思路
双队列实现一个栈（当初夏令营面试遇到的一道机试）

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = q1.size();
        for(int i=0; i<n-1; i++){
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q1 = q2;
        q2 = queue<int>();
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        int n = q1.size();
        for(int i=0; i<n-1; i++){
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(q1.front());
        q1.pop();
        q1 = q2;
        q2 = queue<int>();
        return ans;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
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