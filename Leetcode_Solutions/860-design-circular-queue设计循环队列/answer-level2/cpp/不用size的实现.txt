不用size，但需要多一个数组元素空间作为队列满时的分界。代码较为简洁。
```
class MyCircularQueue {
private:
    int qHead, qTail;
    vector<int> data;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k + 1);
        qHead = qTail = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        qTail = (qTail + 1) % data.size();
        data[qTail] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        qHead = (qHead + 1) % data.size();
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return data[(qHead + 1) % data.size()];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return data[qTail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return qTail == qHead;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (qTail + 1) % data.size() == qHead;
    }
};
```
