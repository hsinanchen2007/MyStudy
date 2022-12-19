### 解题思路
此处撰写解题思路

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    //方法1
    void push(int x) {
        
        if(m_min_s.empty() || x <= getMin()) //注意：相等也入栈
            m_min_s.push(x);

        m_s.push(x);
    }
    
    void pop() {
        // if(!m_s.empty())
        // {
        //     if(!m_min_s.empty() && m_s.top() == getMin())
        //         m_min_s.pop();

        //     m_s.pop();
        // }

        if(m_s.top() == getMin())
            m_min_s.pop();
        m_s.pop();
    }

    //方法2
    void push(int x) {
        
        if(m_min_s.empty() || x <= getMin()) //注意：相等也入栈
            m_min_s.push(x);
        else // x > getMin();
        {
            m_min_s.push(getMin());  //保证两个栈size一致，且当前最小值在栈顶
        }

        m_s.push(x);
    }
    
    void pop() {
        m_min_s.pop();  //出栈时就不用比较两个栈顶的相等性了，两个栈同时出栈即可
        m_s.pop();
    }
    
    int top() {
        return m_s.top();
    }
    
    int getMin() {
        return m_min_s.top();    
    }

private:
    stack<int> m_s;
    stack<int> m_min_s;  //栈顶到栈底  数据从小到大存储  栈顶为当前最小值
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```