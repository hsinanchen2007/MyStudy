### 解题思路
两个队列  速度有点慢

### 代码

```cpp
class MaxQueue {
    queue<int> m_queue;
    deque<int> m_deque;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(m_deque.empty()){
            return -1;
        }
        return m_deque.front();
    }
    
    void push_back(int value) {
        while(!m_deque.empty()&&m_deque.back()<value){
            m_deque.pop_back();
        }
        m_deque.push_back(value);
        m_queue.push(value);
    }
    
    int pop_front() {
        if(m_deque.empty()){
            return -1;
        }
        int tmp=m_queue.front();
        m_queue.pop();
        if(tmp==m_deque.front()){
            m_deque.pop_front();
        }
        return tmp;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```