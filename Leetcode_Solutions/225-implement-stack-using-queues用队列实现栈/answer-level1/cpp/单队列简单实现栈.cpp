### 解题思路
通过队列的头尾循环实现简单的栈
### 代码

```cpp
class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {
     
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(empty()) return -1;
        for(int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        if(empty()) return -1;
        for(int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.push(ans);
        q.pop();
        return ans;
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