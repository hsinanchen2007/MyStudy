### 解题思路
此处撰写解题思路
要最大限度的利用存储空间，一个都不浪费，就需要区分区分队满和队空两种情况，
因为这两种情况下，头指针和尾指针都相等。这个时候用另外一个标记存储是否队满，
如果入队导致头指针和尾指针相等，则标记一下队满，如果出队导致头指针和尾指针相等，
则标记一下队没满。

### 代码

```cpp
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        queue_ = new int[k];
        queue_size_ = k;
        head_ = 0;
        tail_ = 0;
        full_ = false;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
            return false;
        queue_[tail_] = value;
        tail_ = getNext(tail_);
        if (tail_ == head_)
            full_ = true;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;
        head_ = getNext(head_);
        if (full_)
            full_ = false;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
         if (isEmpty())
            return -1;
        return queue_[head_];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty())
            return -1;
        return queue_[getPrev(tail_)];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (isFull())
            return false;
        return head_ == tail_;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return full_;
    }
    
private:
    int getNext(int pos) {
        return (pos + 1) % queue_size_;
    }

    int getPrev(int pos) {
        return (pos - 1 + queue_size_) % queue_size_;
    }
    
private:
    int head_;
    int tail_;
    int* queue_;
    int queue_size_;
    bool full_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```