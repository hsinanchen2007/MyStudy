### 算法分析
1. 使用数组存储元素，定义size表示数组大小，head表示队头下标，tail表示队尾下标
2. 初始时head = tail = -1
3. 当head==-1时队列为空
4. 当(tail + 1) % size == head时队列为满
5. 取队首元素：data[head]，取队尾元素：data[tail]
6. 入队：判断是否不满，tail = (tail + 1) % size，data[tail]=val，如果head==-1则head=0
7. 出队：判断是否非空，如果head==tail则head=tail=-1，否则head = (head + 1) % size
### 复杂度分析
+ 时间复杂度：O(1)
+ 空间复杂度：O(1)
### 源码
```C++ []
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        size = k;
        head = tail = -1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
            return false;

        tail = (tail + 1) % size;
        data[tail] = value;

        if (head == -1)
            head = 0;
        
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;
        
        if (head == tail)
        {
            head = tail = -1;
        }
        else
        {
            head = (head + 1) % size;
        }      

        return true;  
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty())
            return -1;

        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty())
            return -1;

        return data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (tail + 1) % size == head;
    }
private:
    vector<int> data;
    int size;
    int head;
    int tail;
};