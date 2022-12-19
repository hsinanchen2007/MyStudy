### 解题思路


### 代码

```cpp
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        m_head = 0;
        m_tail = 0;
        m_capacity = k;
        m_size = 0;
        m_arr = new int[k];
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
            return false;

        m_arr[m_tail] = value;

        ++m_tail;
        if (m_tail == m_capacity)
        {
            m_tail = 0;
        }

        ++m_size;

        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;

        ++m_head;
        if (m_head == m_capacity)
        {
            m_head = 0;
        }

        --m_size;

        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty())
            return -1;

        return m_arr[m_head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty())
            return -1;

        //注意：最后元素的索引是m_tail的上一个元素
        int index = m_tail - 1;
        if (index < 0)
        {
            index = m_capacity - 1;
        }
        return m_arr[index];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return m_size == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return m_size == m_capacity;
    }


    int size() {
        return m_size;
    }

private:
    int* m_arr;
    int m_head; //待出队位置
    int m_tail; //待入队位置
    int m_size; //元素个数
    int m_capacity; //容量 固定长度
};
```