
### 代码

```cpp
#include <vector>

using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        maxLen = k+1;
        myQueue = new vector<int>(k+1);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (!isFull()) {
            flagRear = (flagRear+1)%maxLen;
            (*myQueue)[flagRear] = value;
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (!isEmpty()) {
                flagFront = (flagFront+1)%maxLen;
                return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (!isEmpty()) {
            return (*myQueue)[(flagFront+1)%maxLen];
        }
        return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (!isEmpty()) {
            return (*myQueue)[flagRear];
        }
        return -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (flagFront == flagRear)
            return true;
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if ((flagRear+1)%maxLen == flagFront)
            return true;
        return false;
    }

private:
    int maxLen = 0;
    vector<int> *myQueue;
    int flagFront=0, flagRear=0;
};
```