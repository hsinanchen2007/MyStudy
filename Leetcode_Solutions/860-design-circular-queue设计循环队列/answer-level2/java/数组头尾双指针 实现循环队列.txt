### 解题思路
详见代码注释

### 代码

```java
class MyCircularQueue {
    private int [] queue;
    private int headIndex;
    private int count;
    private int tailIndex;
    private int cap;
    //尾部指针通过计算获得
    //tailIndex=(headIndex+count−1) mod cap

    /** Initialize your data structure here. Set the size of the queue to be k. */
    public MyCircularQueue(int k) {
        this.queue = new int [k];
        this.headIndex = 0;
        this.tailIndex = headIndex;
        //当前队列已入队的容量
        this.count =0;
        //初始化的缓冲区容量为队列大小
        this.cap = k;

    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {
        if (this.count == this.cap) {
            return false;
        }
        //尾部添加 tailIndex=(headIndex+count -1 ) mod cap 
        //计算尾部指针 插入元素
        ++this.count;
        this.tailIndex = (this.headIndex + this.count -1 ) % this.cap;
        this.queue[tailIndex]= value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        if (this.count == 0) {
            return false;
        }
        this.headIndex = (this.headIndex +1 ) % this.cap;
        this.count--;
        return true;

    }
    
    /** Get the front item from the queue. */
    public int Front() {
        if (this.count == 0){
            return -1;
        }
        return queue[this.headIndex];
    }
    
    /** Get the last item from the queue. */
    public int Rear() {
        if (this.count == 0){
            return -1;
        }
        return queue[(this.headIndex + this.count -1) % this.cap];
    }
    
    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return (this.count ==0);
    }
    
    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        return (this.count == this.cap);

    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */
```