### 解题思路
此处撰写解题思路
这是个老生常谈的题目了，要清楚栈和队列主要区别：
- 栈：数据先入后出
- 队列：数据先入先出

清楚了这个区别后，入队列和入栈是一样的，我认为关键点就是出队列和出栈。接下来可以考虑：
简单情况：入了2个数据，当有一个栈A时，先入的后出，导致出栈顺序跟入栈是相反的；有了两个栈A、B的话，可以把A栈中所有数据挨个弹出，弹出一个就放入B栈中，这样等A的数据全放到B中时，B中数据的顺序正好是跟入A栈的顺序是相反的，那么接着从B中挨个弹出数据，那么这第二次出B栈的顺序就跟原来入A栈一样了。
复杂情况：当A入了2个数据后，此时B要弹出1个数据，那么先把A的都放到B中，恰巧此时A又要入栈一些数据，但此时B中还有一个数据，直接把A中的放入B中，那么顺序就乱逃了，所以需要等待，等待下一次需要B弹出数据时，先把剩下的那一个数据弹出，这样B中就没数据了，再把A中的都放入B中，这时的B中的数据就跟A中入栈顺序相反了，那么依次弹出B的数据，顺序就正好跟A中入栈顺序一样了。以此类推得到思路，每次都要先等待把B中的数据先完全弹出清空，然后再从A中放到B中。
### 代码

```cpp
class CQueue {
public:
    stack<int> m_Hstack;
    stack<int> m_Tstack;
    CQueue() {
    }
    
    void appendTail(int value) {
        m_Tstack.push(value);
    }
    
    int deleteHead() {
        if((m_Hstack.empty()) && (m_Tstack.empty()))
        {
            return -1;
        }     
        if(m_Hstack.empty())  
        { 
            while(!m_Tstack.empty())
            {
                m_Hstack.push(m_Tstack.top());
                m_Tstack.pop();
            }
        }
        int ret = m_Hstack.top();
        m_Hstack.pop();
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```