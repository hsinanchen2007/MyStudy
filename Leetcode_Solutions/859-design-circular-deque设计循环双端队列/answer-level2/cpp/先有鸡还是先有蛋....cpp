### 解题思路
投机取巧一把...CPP中这不就是deque数据结构么~套了个壳，正解应该是数组还有首尾哨兵来做~这个解法纯粹偷懒;

### 代码

```cpp
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    int capacity;
    int size;
    deque<int> dq;
    MyCircularDeque(int k) {
       //dq.resize(k);
        capacity = k;
        size = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
       if (dq.size() >= capacity)
        return false;
        dq.push_front(value);
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (dq.size() >= capacity)
            return  false;
        dq.push_back(value);
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (dq.size() <= 0)
            return false;
        dq.pop_front();
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (dq.size() <= 0) 
            return false;
        dq.pop_back();
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (dq.size() == 0)
            return -1;
        return dq.front();
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (dq.size() == 0)
            return -1;
        return dq.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return dq.size() == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return dq.size() == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
```