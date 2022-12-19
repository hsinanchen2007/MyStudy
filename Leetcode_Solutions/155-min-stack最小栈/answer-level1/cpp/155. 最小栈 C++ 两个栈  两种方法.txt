### 解题思路
此处撰写解题思路

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {

        m_stack.push(x);

        if(m_stack_min.empty() || x <= m_stack_min.top())
        {
            m_stack_min.push(x);
        }
    }
    
    void pop() {
        if(m_stack.top() == m_stack_min.top())
        {
            m_stack_min.pop();
        }
        m_stack.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_stack_min.top();
    }

private:
    stack<int> m_stack;
    stack<int> m_stack_min;
};


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {

        m_stack.push(x);

        if(m_stack_min.empty())
        {
            m_stack_min.push(x);
        }
        else if(x < m_stack_min.top())
        {
            m_stack_min.push(x);
        }
        else
        {
            m_stack_min.push(m_stack_min.top());
        }
    }
    
    void pop() {
        m_stack_min.pop();
        m_stack.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_stack_min.top();
    }

private:
    stack<int> m_stack;
    stack<int> m_stack_min;
};


```