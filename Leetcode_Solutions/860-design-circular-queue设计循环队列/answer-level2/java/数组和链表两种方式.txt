### 解题思路
数组和链表两种方式

### 方法一：数组形式

```java
class MyCircularQueue {
    private int[] nums;
    private int size;
    private int front; //首个元素的位置
    private int tail;  //最后一个元素的位置

    /** Initialize your data structure here. Set the size of the queue to be k. */
    public MyCircularQueue(int k) {
        nums = new int[k];
        size = k;
        front = -1;
        tail = -1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            front = 0;
        }
        tail = (tail + 1) % size;
        nums[tail] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        if(isEmpty()){
            return false;
        }
        if(front == tail){
            front = -1;
            tail = -1;
            return true;
        }
        front = (front + 1) % size;
        return true;

    }
    
    /** Get the front item from the queue. */
    public int Front() {
        if(isEmpty()){
            return -1;
        }
        return nums[front];

    }
    
    /** Get the last item from the queue. */
    public int Rear() {
        if(isEmpty()){
            return -1;
        }
        return nums[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return tail == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        return front == (tail+1) % size;
    }
}
```

### 方法二: 链表
```java
class Node{
    public int value;
    public  Node nextNode;

    public Node(int v){
        value = v;
        nextNode = null;
    }
}

class MyCircularQueue {
    private Node head;
    private Node tail;
    private int count;
    private int capacity;

    /** Initialize your data structure here. Set the size of the queue to be k. */
    public MyCircularQueue(int k) {
        capacity = k;
        count = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {
        if(isFull()){
            return false;
        }
        Node node = new Node(value);
        if(count == 0){
            head = node;
            tail = node;
        }else{
            tail.nextNode = node;
            tail = node;
        }
        count++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        if(isEmpty()){
            return false;
        }
        head = head.nextNode ;
        count --;
        return true;
        

    }
    
    /** Get the front item from the queue. */
    public int Front() {
        if(isEmpty()){
            return -1;
        }
        return head.value;

    }
    
    /** Get the last item from the queue. */
    public int Rear() {
        if(isEmpty()){
            return -1;
        }
        return tail.value;
    }
    
    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return count == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        return count == capacity;
    }
}

```