### 解题思路
利用双栈，对于队列来说，是先进先出，栈是先进后出，那么利用两个栈，就可以模拟完成先进先出。
![image.png](https://pic.leetcode-cn.com/347ba7ab14967f1206eaf5230c04b359afecdd5808156da58a62e3496ded8ad2-image.png)


### 代码

```cpp
class MyQueue {
public:
    stack<int> pushstack; 
    stack<int> popstack;
    
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
         if(popstack.empty())
         {
             pushstack.push(x);
         }
         else
         {
             while(!popstack.empty())
             {
                pushstack.push(popstack.top());
                popstack.pop();
             }
             pushstack.push(x);
         }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!pushstack.empty())
        {
            popstack.push(pushstack.top());
            pushstack.pop();
        }
        int x=popstack.top();
        popstack.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        while(!pushstack.empty())
        {
            popstack.push(pushstack.top());
            pushstack.pop();
        }
        return popstack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
         return popstack.empty() && pushstack.empty();
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