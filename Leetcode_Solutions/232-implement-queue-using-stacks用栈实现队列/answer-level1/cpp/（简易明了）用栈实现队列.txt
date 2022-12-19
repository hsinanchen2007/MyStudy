### 解题思路
对于常用的方法中，只需要实现其中一个，比如push操作。
让先进后出的逻辑变为先进先出即可。
除了代码中的解题思路外，图片中提供了一种更为简易的方法供参考。
![栈实现队列.jpg](https://pic.leetcode-cn.com/f86f36fee9f6f6a76f4545676f58ab1652ca5f578ed208429557f4073d649bc2-%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.jpg)

### 代码

```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        m_s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> temp;
        int a;
        while(!m_s.empty())
        {
            temp.push(m_s.top());
            m_s.pop();
        }
        a=temp.top();
        temp.pop();
        while(!temp.empty())
        {
            m_s.push(temp.top());
            temp.pop();
        }
        return a;
    }
    
    /** Get the front element. */
    int peek() 
    {
        stack<int> temp=m_s;
        int b;
        while(!temp.empty())
        {
            b=temp.top();
            temp.pop();
        }
        return b;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return m_s.empty();
    }
private:
    stack<int> m_s;
};
```