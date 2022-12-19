```
class MyCircularDeque {
public:
    vector<int> que;
    int front,rear,len,full;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        que = vector<int>(k);
        front = rear = full = 0;
        len = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(full == len) return false;
        ++full;
        front = (front-1+len)%len;
        que[front] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(full == len) return false;
        ++full;
        que[rear] = value;
        rear = (rear+1)%len;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(full == 0) return false;
        --full;
        front = (front+1)%len;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(full == 0) return false;
        --full;
        rear = (rear-1+len)%len;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(full == 0) return -1;
        return que[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(full == 0) return -1;
        return que[(rear-1+len)%len];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (full == 0);
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (full == len);
    }
};
```
