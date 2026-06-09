### 解题思路
思路简单
用数组表示一个链表
start：第一个元素的索引
end：最后一个元素的索引
isEmpty：start=end时 是否为空

合理利用对数组length取余 来判断数组是否满和空
### 代码

```java
class MyCircularQueue {

    int[] a;
    int start;
    int end;
    boolean isEmpty;
    //start首个元素index end 最后一个元素的index， 
    /** Initialize your data structure here. Set the size of the queue to be k. */
    public MyCircularQueue(int k) {
        a = new int[k];
        start = 0;
        end = 0;
        isEmpty = true;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {
        if (start==end && isEmpty) {
            a[end] = value;
            isEmpty = false;
            return true;
        } 
        if (start == end ||(end+1)% a.length != start%a.length) {
            a[(++end)%a.length] = value;
            return true;
        }
        return false;
    }
    
//start end value
//0  0  []
//0  0  [1]
//0  1  [1 2]
//0  2  [1 2 3]
//false 


    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        if (isEmpty) {
            return false;
        }
        if (start == end) {
            isEmpty = true;
            return true;
        }
        start++;
        return true;
        }
    
    /** Get the front item from the queue. */
    public int Front() {
        if (isEmpty) {
            return -1;
        }
        return a[start%a.length];
    }
    
    /** Get the last item from the queue. */
    public int Rear() {
        if (isEmpty) {
            return -1;
        }
        return a[end%a.length];
    }
    
    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return isEmpty;
    }
    
    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        return (end + 1)% a.length == start%a.length;
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