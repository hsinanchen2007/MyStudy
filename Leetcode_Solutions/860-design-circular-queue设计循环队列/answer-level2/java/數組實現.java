### 解题思路
rear指向最後一個元素的後面 即預留一個空位

### 代码

```java
class MyCircularQueue {
    private int front;
    private int rear;//環形初始值都爲0
    private int maxsize;//環形預留一個空間作爲緩衝，即可存儲元素個數maxsize-1
    private int[] arr;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    public MyCircularQueue(int k) {
        this.maxsize=k+1;
        arr=new int[maxsize];
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {
        if(!isFull()){
            arr[rear]=value;
            rear=(rear+1)%maxsize;
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        if(!isEmpty()){
           front=(front+1)%maxsize;
           return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    public int Front() {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    
    /** Get the last item from the queue. */
    public int Rear() {
        if(isEmpty()){
            return -1;
        }
        return arr[(rear-1+maxsize)%maxsize];//開始錯在這裏 rear=0的時候 0-1=-1越界 記得取模
    }
    
    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return rear==front;
    }
    
    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        return (rear+1)%maxsize==front;
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