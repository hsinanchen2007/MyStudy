### 解题思路
使用两个队列，一个普通队列 和 一个双端队列
普通队列正常入队、出队
双端队列在插入时保持从队首到队尾为递减的 如果待入队的元素大于双端队列的队尾，则队尾出队 直到入队 出队的不用管了


### 代码

```cpp
class MaxQueue {
public:
    MaxQueue() {

    }

    int max_value() {
        if (m_max_queue.empty())
        {
            return -1;
        }
        return m_max_queue.front();
    }

    void push_back(int value) {
        m_queue.push(value);

        //双端队列入队
        while (!m_max_queue.empty() && value > m_max_queue.back())
        {
            m_max_queue.pop_back();
        }
        m_max_queue.push_back(value);
    }

    int pop_front() {
        if (m_queue.empty())
        {
            return -1;
        }

        int front = m_queue.front();
        m_queue.pop();

        //双端队列出队
        if (!m_max_queue.empty() && m_max_queue.front() == front)
        {
            m_max_queue.pop_front();
        }

        return front;
    }

private:
    queue<int> m_queue;
    list<int> m_max_queue;  //双端队列
};
```