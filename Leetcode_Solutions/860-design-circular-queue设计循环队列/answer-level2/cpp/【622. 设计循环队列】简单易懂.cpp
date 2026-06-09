## 思路
### 代码
```c++
class MyCircularQueue {
    int* data;
    int size;
    int head;
    int tail;    
    int capicity;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data = new int[k];
        size = k;
        head = 0;
        tail = 0;  
        capicity = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (capicity < size) {
            data[tail++] = value;
            ++capicity;
            if (tail == size) {
                tail = 0;
            }
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (capicity > 0) {
            ++head;
            --capicity;
            if (head == size) {
                head = 0;
            }
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (capicity == 0) {
            return -1;
        }
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (capicity == 0) {
            return -1;
        }
        return tail == 0 ? data[size - 1] : data[tail - 1];   
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return capicity == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return capicity == size;
    }
};
```
#### 简化代码
- 用模运算取代 if
- 使用vector
```c++
class MyCircularQueue {
    vector<int> data;
    int size;
    int head;
    int tail;    
    int capicity;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        size = k;
        head = 0;
        tail = 0;  
        capicity = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (capicity < size) {
            data[tail] = value;
            tail = (tail + 1) % size;
            ++capicity;
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (capicity > 0) {
            head = (head + 1) % size;
            --capicity;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (capicity == 0) return -1;
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (capicity == 0) return -1;
        return tail == 0 ? data[size - 1] : data[tail - 1];   
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return capicity == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return capicity == size;
    }
};
```

