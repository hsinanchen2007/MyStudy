### 解题思路
此处撰写解题思路

### 代码

```cpp
class MyQueue {
public:
    stack<int> s1,s2;
    int front;
    /** Initialize your data structure here. */
    MyQueue() {
        while(!s1.empty())
            s1.pop();
        while(!s2.empty())
            s2.pop();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
       
        if(s1.empty())
            front=x;
         s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s2.empty())
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        int t=s2.top();
        s2.pop();
        return t;
    }
    
    /** Get the front element. */
    int peek() {
        if(!s2.empty())
            return s2.top();
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty()&&s2.empty();
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