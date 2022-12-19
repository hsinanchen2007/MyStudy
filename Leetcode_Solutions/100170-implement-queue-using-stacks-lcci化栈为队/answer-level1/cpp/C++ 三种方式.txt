### 解题思路
方法1：入队时，栈1入栈；出队时，将栈1元素全部出栈再入栈2，栈2栈顶出栈，再将栈2元素全部出栈再入栈1.

方法2：将方法1出队的最后一个操作：栈2元素全部出栈再入栈1  改为入队的第一个操作
      这时，可能两个栈中都有元素，判空时 需要对两个栈同时判空
      相比方法1 提高了连续出队的效率

方法3、不必多次来回倒腾数据， 入队时，栈1入栈；出队时，如果栈2为空，则将栈1全部元素倒过去，如果栈2仍有元素，栈2出栈
      

### 代码

```cpp

//方法1:
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        m_stack_1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!m_stack_1.empty())
        {
            m_stack_2.push(m_stack_1.top());
            m_stack_1.pop();
        }

        int top = m_stack_2.top(); //一个空的队列不会调用 pop 则不用判断m_stack_2是否为空
        m_stack_2.pop();

        while(!m_stack_2.empty())
        {
            m_stack_1.push(m_stack_2.top());
            m_stack_2.pop();
        }

        return top;
    }
    
    /** Get the front element. */
    int peek() {
        while(!m_stack_1.empty())
        {
            m_stack_2.push(m_stack_1.top());
            m_stack_1.pop();
        }

        int top = m_stack_2.top(); //一个空的队列不会调用 pop 则不用判断m_stack_2是否为空
        
        while(!m_stack_2.empty())
        {
            m_stack_1.push(m_stack_2.top());
            m_stack_2.pop();
        }

        return top;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return m_stack_1.empty();
    }


private:
    stack<int> m_stack_1;
    stack<int> m_stack_2;

};


//方法2:
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {

        while(!m_stack_2.empty())
        {
            m_stack_1.push(m_stack_2.top());
            m_stack_2.pop();
        }

        m_stack_1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!m_stack_1.empty())
        {
            m_stack_2.push(m_stack_1.top());
            m_stack_1.pop();
        }

        int top = m_stack_2.top(); //一个空的队列不会调用 pop 则不用判断m_stack_2是否为空
        m_stack_2.pop();

        return top;
    }
    
    /** Get the front element. */
    int peek() {
        while(!m_stack_1.empty())
        {
            m_stack_2.push(m_stack_1.top());
            m_stack_1.pop();
        }

        int top = m_stack_2.top(); //一个空的队列不会调用 peek 则不用判断m_stack_2是否为空

        return top;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return m_stack_1.empty() && m_stack_2.empty();
    }


private:
    stack<int> m_stack_1;
    stack<int> m_stack_2;

};


//方法3:
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        m_stack_1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(m_stack_2.empty())
        {
            while(!m_stack_1.empty())
            {
                m_stack_2.push(m_stack_1.top());
                m_stack_1.pop();
            }
        }

        int top = m_stack_2.top(); //一个空的队列不会调用 pop 则不用判断m_stack_2是否为空
        m_stack_2.pop();

        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if(m_stack_2.empty())
        {
            while(!m_stack_1.empty())
            {
                m_stack_2.push(m_stack_1.top());
                m_stack_1.pop();
            }
        }

        int top = m_stack_2.top(); //一个空的队列不会调用 peek 则不用判断m_stack_2是否为空
        return top;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return m_stack_1.empty() && m_stack_2.empty();
    }


private:
    stack<int> m_stack_1;
    stack<int> m_stack_2;

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