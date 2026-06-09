### 解题思路
![image.png](https://pic.leetcode-cn.com/974ab44e0955acbde533424a148d52a5cde10d57a582345c385d529ddbb3569e-image.png)

https://www.cnblogs.com/DarrenChan/p/9535557.html
### 代码

```java
class MyCircularQueue {

    int[] arr;
    int size;
    int front;//第一个有效元素
    int rear;//最后一个有效元素的下一个

    /**
     * Initialize your data structure here. Set the size of the queue to be k.
     */
    public MyCircularQueue(int k) {
        arr = new int[k + 1];
        size = k + 1;
        for (int i = 0; i < k; i++) {
            arr[i] = -1;
        }
    }

    /**
     * Insert an element into the circular queue. Return true if the operation is successful.
     */
    public boolean enQueue(int value) {
        if (!isFull()) {
            arr[rear] = value;
            rear = (rear + 1) % size;
            return true;
        }
        return false;
    }

    /**
     * Delete an element from the circular queue. Return true if the operation is successful.
     */
    public boolean deQueue() {
        if(!isEmpty()){
            front = (front + 1) % size;
            return true;
        }
        return false;
    }

    /**
     * Get the front item from the queue.
     */
    public int Front() {
        return arr[front];
    }

    /**
     * Get the last item from the queue.
     */
    public int Rear() {
        if(isEmpty()) {
            return arr[front];
        }
        return arr[(rear + size - 1) % size];
    }

    /**
     * Checks whether the circular queue is empty or not.
     */
    public boolean isEmpty() {
        return front == rear;
    }

    /**
     * Checks whether the circular queue is full or not.
     */
    public boolean isFull() {
        return (rear + 1) % size == front;
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