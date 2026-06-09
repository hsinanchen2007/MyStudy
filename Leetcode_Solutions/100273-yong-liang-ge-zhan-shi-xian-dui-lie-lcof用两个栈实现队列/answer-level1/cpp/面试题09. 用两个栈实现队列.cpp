### 解题思路
// (1) 申请两个栈 data_stack 和 m_stack
// (2) 当入队(添加数据)时, 执行如下三个步骤
//      - 将 data_stack 中的数据逐个 放到 m_stack 中
//      - 将 value 添加到 m_stack 中
//      - 将 m_stack 中的数据 逐个放入到 data_stack 中 
// (3) 当出队(删除数据)时， 直接弹出 data_stack 栈顶数据即可 
                
### 代码

```cpp
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        while(!data_stack.empty()){
            m_stack.push(data_stack.top());
            data_stack.pop();
        }
        m_stack.push(value);
        while(!m_stack.empty()){
            data_stack.push(m_stack.top());
            m_stack.pop();
        }
    }
    
    int deleteHead() {
        if(data_stack.empty()) return -1;
        
        int x = data_stack.top();
        data_stack.pop();
        return x;
    }
private:
    stack<int> data_stack;
    stack<int> m_stack;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```