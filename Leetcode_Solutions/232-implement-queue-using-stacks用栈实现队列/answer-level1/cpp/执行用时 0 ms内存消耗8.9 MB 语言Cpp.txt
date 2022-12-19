```
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> a;
    stack<int> b;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int cur;
        if(!b.empty())
        {
          cur=b.top();
          b.pop();
        }
        else
        {
            while(!a.empty())
            {
            int temp=a.top();
            a.pop();
            b.push(temp);
            }
            cur=b.top();
            b.pop();
        }
        return cur;
    }
    
    /** Get the front element. */
    int peek() {
        if(!b.empty())
        {
            return b.top();
        }
        else
        {
            while(!a.empty())
            {
            int temp=a.top();
            a.pop();
            b.push(temp);
            }
            return b.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty()&b.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool p8.9 MBaram_4 = obj->empty();
 */
```
