### 解题思路
此处撰写解题思路

### 代码

```cpp
class CQueue {
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        m_stack_1.push(value);
    }
    
    int deleteHead() {
        if(m_stack_2.empty())
        {
            while(!m_stack_1.empty())
            {
                m_stack_2.push(m_stack_1.top());
                m_stack_1.pop();
            }
        }
        
        if(m_stack_2.empty()) //如果m_stack_1之前就为空， m_stack_2仍为空
        {
            return -1;
        }
        
        int top = m_stack_2.top();
        m_stack_2.pop();
        return top;
    }

private:
    stack<int> m_stack_1;
    stack<int> m_stack_2;

};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```