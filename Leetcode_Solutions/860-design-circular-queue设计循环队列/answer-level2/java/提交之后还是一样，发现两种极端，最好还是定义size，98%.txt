![image.png](https://pic.leetcode-cn.com/de654481e1909a3945c7039b3b56e54bff3fc8e7ea1580fd4785c4a2b89120a7-image.png)

```
class MyCircularQueue {
    private int size;
    private int front;
    private int rear;
    private int [] data;
    
    public MyCircularQueue(int k) {
        data = new int[k+1];
        front = 0;
        rear = 0;
        size = 0;
    }
    
    public boolean enQueue(int value) {
        if(size == data.length - 1)return false;
        data[rear] = value;
        size++;
        rear = (rear+1)%data.length;
        return true;
    }
    
    public boolean deQueue() {
        if(isEmpty())return false;
        size--;
        front = (front + 1)%data.length;
        return true;
    }
    
    public int Front() {
        if(isEmpty())return -1;
        return data[front];
    }
    
    public int Rear() {
        if(isEmpty())return -1;
        return data[(rear - 1 + data.length)%data.length];
    }
    
    public boolean isEmpty() {
        return size == 0;
    }
    
    public boolean isFull() {
        return size == data.length - 1;
    }
}
```
