### 解题思路
 首先理解环形队列（循环队列），然后稍加改造即可。
### 环形队列（循环队列）
#### 参考资料

- [Java版-数据结构-队列（循环队列）](https://juejin.im/post/5c95d2515188252dab3ebfc5)
- [Using an Array to represent a Circular Queue](https://www.youtube.com/watch?v=ia__kyuwGag&list=LLlpO8jYosbBe-EetMvDzbMg&index=3&t=0s)

#### 环形队列（循环队列）主要概念
- 先进先出
- capacity：数组容量
- front：表示队列队首，始终指向队列中的第一个元素（当队列空时，front指向索引为0的位置）
- tail：表示队列队尾，始终指向队列中的最后一个元素的下一个位置
- 元素入队，维护tail的位置，进行tail++操作，计算公式：(tail + 1) % capacity
- 元素出队，维护front的位置，进行front++操作，计算公式：(front + 1) % capacity
- 在循环队列中，总是浪费一个空间，来区分队列为满时和队列为空时的情况，也就是当 (tail + 1) % capacity == front的时候，表示队列已经满了，当front == tail的时候，表示队列为空。

#### 疑问解答
- 为什么front的计算公式为：(front + 1) % capacity ？

1. 元素出队时，弹出当前front的元素，front向数组右边移动一位，所以新的front = front + 1
2. 因为front的取值范围是[0, capacity - 1]，当front = capacity - 1时（数组的最后一位）front + 1就会出现数组越界！这时有2种方法可以处理：
 - 2.1. 判断数组越界后，直接将front赋值为0。因为是环形数组，开始循环了。
 - 2.2. 根据“余数定理”，%操作可以保证结果范围在[0, capacity - 1]内。因为front的最大值是capacity - 1。
3. 取余操作相对于每次判断是否最大索引值的方式，代码更简洁，但相对难理解。

### 代码

```java
class MyCircularDeque {

    private int[] ring;

    private int capacity;

    private int head;

    private int tail;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    public MyCircularDeque(int k) {
        capacity = k + 1; // 因为环形队列需要一个空位判断队列为空
        ring = new int[capacity];
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    public boolean insertFront(int value) {
        if (isFull()) {
            return false;
        }

        head = (head + capacity - 1) % capacity; // 移动到前一位
        ring[head] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    public boolean insertLast(int value) {
        if (isFull()) {
            return false;
        }

        ring[tail] = value;
        tail = (tail + 1) % capacity;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    public boolean deleteFront() {
        if (isEmpty()) {
            return false;
        }

        head = (head + 1) % capacity;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    public boolean deleteLast() {
        if (isEmpty()) {
            return false;
        }

        tail = (tail + capacity - 1) % capacity; // 移动到前一位
        return true;
    }

    /** Get the front item from the deque. */
    public int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return ring[head];
    }

    /** Get the last item from the deque. */
    public int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return ring[(tail + capacity - 1) % capacity];
    }

    /** Checks whether the circular deque is empty or not. */
    public boolean isEmpty() {
        return head == tail;
    }

    /** Checks whether the circular deque is full or not. */
    public boolean isFull() {
        return (tail + 1) % capacity == head;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */
```