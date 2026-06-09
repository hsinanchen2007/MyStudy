```
class MyCircularQueue {
    private int maxSize;
    private int front = 0;
    private int rear = 0;尾指针指向尾部有效数据的后一个
    private int[] arr;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    public MyCircularQueue(int k) {
        maxSize = k+1;//预留一个空位，方便再尾部添加数据
                      //也就是说数组长度若为4 实际数据长度为3
        arr = new int[maxSize];
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {

        if(isFull()){
            return false;
        }else{
            arr[rear] = value;
            rear = (rear+1) % maxSize;//环形队列，需取模
            return true;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        if(isEmpty()){
            return false;
        }else{
            front = (front+1) % maxSize;
            return true;
        }
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
            return arr[(rear-1+maxSize) % maxSize];//当rear为0时防止数组越界，需取模
    }
    
    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return front == rear;
    }
    
    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        return (rear+1) % maxSize == front;
    }
}
```
