思路：就是倒数
入栈是，出栈s2，数从s1倒到s2中关键遵循两个原则：1 只要倒，就要一次性倒完。
                                             2 如果s2不为空，不能倒。

```
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
    void dao()
    {
        //遵循两个原则：1 只要倒，就要一次性倒完
                      // 2 如果s2不为空，不能倒
        if(!s2.empty())
        {
            return;
        }
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }


public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
        dao();
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res=s2.top();
        s2.pop();
        dao();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        int res=s2.top();
        return res;
    }
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s1.empty()&&s2.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


```
