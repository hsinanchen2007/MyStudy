### 代码

```java
class MyCircularQueue {

    int[] array;
    // array[front] 不储存值
    int front; 
    int last;

    /** Initialize your data structure here. Set the size of the queue to be k. */
    public MyCircularQueue(int k) {
        array = new int[k + 1];
        front = 0;
        last = front;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {
        if(isFull())
            return false;
        last = (last == array.length - 1)? 0 : last + 1;
        array[last] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        if(isEmpty())
            return false;
        front = (front == array.length - 1)? 0 : front + 1;
        return true;
    }
    
    /** Get the front item from the queue. */
    public int Front() {
        if(isEmpty())
            return -1;
        int index = (front == array.length - 1)? 0 : front + 1;
        return array[index];
    }
    
    /** Get the last item from the queue. */
    public int Rear() {
        if(isEmpty())
            return -1;
        return array[last];
    }
    
    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return front == last;
    }
    
    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        if(last == array.length - 1 && front == 0 || front == last + 1)
            return true;
        else 
            return false;
    }
}

```