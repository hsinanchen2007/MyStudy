### 解题思路
此处撰写解题思路
很简单，就不多说了
### 代码

```cpp
class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int front=0;
        while (!q1.empty())
        {
            front = q1.front();
            q1.pop();
            if (q1.size() > 0)
                q2.push(front);
        }

        while (!q2.empty())
        {
            int temp_front = q2.front();
            q2.pop();
            q1.push(temp_front);
        }
        return front;
    }
    
    /** Get the top element. */
    int top() {
        return q1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (q1.empty())
            return true;
        return false;
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