### 解题思路
    其实这个题不难，主要是使用一个标记标记是否满了就可以
    满了的情况莫过于 ends 走到了 fronts 那么这就是满了
    空的情况就是ends == fronts，并且标记为false
    判断完这两种情况下 其他的就是正常的++ % len
### 代码

```cpp
class MyCircularQueue {
public:
    int arr[10005];
    int fronts, ends, len;
    bool flag = false;//标记是否满了
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        fronts = ends = 0;
        len = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(!flag){
            arr[ends] = value;
            ends ++;
            ends %= len;
            if(ends == fronts){
                flag = true;
            }
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(flag == false && fronts == ends){
            return false;
        }
        fronts ++;
        fronts %= len;
        flag = false;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(flag == false && fronts == ends) return -1;
        return arr[fronts];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(flag == false && fronts == ends) return -1;
        int x = ends + len;
        x --;
        x %= len;
        return arr[x];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(flag == false && fronts == ends) return true;
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(flag == true)    return true;
        return false;
    }
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