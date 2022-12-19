```
    /** Initialize your data structure here. Set the size of the queue to be k. */
    vector<int> data;
    int len,front,rear;
    MyCircularQueue(int k) {
        len = k+1;
        data = vector<int>(len);
        front = 0,rear = 0; //front指向队头 rear 指向队尾的下一个位置
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;//满时队列无法插入
        data[rear] = value,rear = (rear+1)%len;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front+1)%len;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return data[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(rear==front) return -1;
        return data[(rear-1+len)%len];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return rear==front;
    }
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (rear+1)%len==front;
    }
};
```
