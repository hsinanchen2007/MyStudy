
### 代码

```cpp
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        maxLen = k+1;
        myQueue = new int[k+1];
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
            return false;
        else {
            myQueue[flagFront] = value;
            flagFront = (flagFront+maxLen-1)%maxLen;
            return true;
        }
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
            return false;
        else {
            flagRear = (flagRear+1)%maxLen;
            myQueue[flagRear] = value;
            return true;
        }
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
            return false;
        else {
            flagFront = (flagFront+1)%maxLen;
            return true;
        }
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false;
        else {
            flagRear = (flagRear+maxLen-1)%maxLen;
            return true;
        }
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty())
            return -1;
        else
            return myQueue[(flagFront+1)%maxLen];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty())
            return -1;
        else
            return myQueue[flagRear];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if (flagFront == flagRear)
            return true;
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if ((flagRear+1)%maxLen == flagFront)
            return true;
        return false;
    }

private:
    int *myQueue;
    int flagFront=0, flagRear=0;
    int maxLen = 0;
};
```