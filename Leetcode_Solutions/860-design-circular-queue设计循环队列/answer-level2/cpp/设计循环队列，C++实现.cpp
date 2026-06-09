### 解题思路
循环队列可以用数组实现，也可以用链表实现。下面是用数组实现的代码。
实现一个循环队列，相比非循环队列比较难的一个点是：判断队空和队满的条件。只要确定好队空和队满的条件，就不容易出错。
循环队列队空的条件，和非循环队列一样：head == tail 
循环队列队满的条件，和非循环队列(tail == n)不同：head == (tail+1)%n
另外，这题还有一个容易踩坑的点，注意理解题目中设置队列长度为k的具体含义。看示例中设置长度为3，当插入第3个数字时，依旧返回true。但我们知道上述队空和队满的条件中，tail指针指向的位置是空的，可以理解为是一个哨兵，故在初始化数组大小时，n应该等于k+1.

### 代码

```cpp
class MyCircularQueue {
private:
    int* arr; // 数组 
    int n = 0;
    int head = 0;
    int tail = 0;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        arr = new int[k+1];
        n = k+1;
    }
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (head == (tail+1)%n) return false;
        arr[tail] = value;
        tail = (tail+1)%n;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (head == tail) return false;
        head = (head+1)%n;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (head == tail) return -1;
        return arr[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (head == tail) return -1;
        if (tail == 0) return arr[n-1];
        return arr[tail-1];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (head == tail) return true;
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (head == (tail+1)%n) return true;
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