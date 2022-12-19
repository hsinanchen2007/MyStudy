### 解题思路
stk_1为数据栈，stk_2为辅助栈

### 代码

```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        stk_1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        while(stk_1.size())
        {
            stk_2.push(stk_1.top());
            stk_1.pop();
        }
        int ans = stk_2.top();
        stk_2.pop();
        while(stk_2.size())
        {
            stk_1.push(stk_2.top());
            stk_2.pop();
        }
        return ans;
    }
    
    /** Get the front element. */
    int peek() 
    {
        while(stk_1.size())
        {
            stk_2.push(stk_1.top());
            stk_1.pop();
        }
        int ans = stk_2.top();
        while(stk_2.size())
        {
            stk_1.push(stk_2.top());
            stk_2.pop();
        }
        return ans;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        if(stk_1.empty()) return 1;
        return 0;
    }

private:
    stack<int> stk_1, stk_2;
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