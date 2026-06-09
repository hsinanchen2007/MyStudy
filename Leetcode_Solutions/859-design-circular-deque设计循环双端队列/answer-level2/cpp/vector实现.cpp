### 解题思路

### 代码

```cpp
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(v.size() + 1 <= size)
        {
            v.insert(v.begin(), value);
            return true;
        }
        return false;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(v.size() + 1 <= size)
        {
            v.push_back(value);
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(v.size() > 0)
        {
            v.erase(v.begin());
            return true;
        }
        else    
            return false;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(v.size() > 0)
        {
            v.pop_back();
            return true;
        }
        else    
            return false;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(v.size() == 0)
            return -1;
        return v[0];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(v.size() == 0)
            return -1;
        return v.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return v.size() == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return v.size() == size;
    }
private:
    vector<int> v;
    int size;
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