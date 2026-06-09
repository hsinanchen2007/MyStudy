### 解题思路
`push`操作直接压到队列尾；
`top`操作去队列尾的值；
`pop`操作需求队列尾前的值先移出，然后追加，最终将目标值出队列即可；

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        m_queue.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = m_queue.back();
        int size = m_queue.size();
        int popCnt = 0;
        while (popCnt != size - 1) {
            int tmp = m_queue.front();
            m_queue.pop();
            m_queue.push(tmp);
            popCnt++;
        }
        m_queue.pop();

        return top;
    }
    
    /** Get the top element. */
    int top() {
        return m_queue.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return m_queue.empty();
    }

private:
    queue<int> m_queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```