### 解题思路
此处撰写解题思路

### 代码

```cpp
class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
    while (!stack1.empty())
        {
            int top = stack1.top();
            stack1.pop();
            stack2.push(top);
        }
        int pop_value = stack2.top();
        stack2.pop();
        while (!stack2.empty())
        {
            int top = stack2.top();
            stack2.pop();
            stack1.push(top);
        }

        return pop_value;
    }
    
    /** Get the front element. */
    int peek() {
        while (!stack1.empty())
        {
            int top = stack1.top();
            stack1.pop();
            stack2.push(top);
        }
        int peek_value = stack2.top();
        
        while (!stack2.empty())
        {
            int top = stack2.top();
            stack2.pop();
            stack1.push(top);
        }

        return peek_value;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (stack1.empty())
            return true;
        
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```