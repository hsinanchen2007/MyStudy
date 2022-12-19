### 解题思路
看了官方解题思路，才写出来的。
java版，双队列。
队列的最大值与栈的最大值不一样，栈的最大值也要维护另外一个栈。

### 代码

```java
class MaxQueue {

    private LinkedList<Integer> queue;
    private LinkedList<Integer> deQueue;

    public MaxQueue() {
        queue = new LinkedList<>();
        deQueue = new LinkedList<>();
    }

    public int max_value() {
        if (!deQueue.isEmpty())
            return deQueue.getFirst();
        else
            return -1;
    }

    public void push_back(int value) {
        queue.add(value);
        while (!deQueue.isEmpty() && deQueue.getLast() < value ) {
            deQueue.removeLast();
        }
        deQueue.add(value);
    }

    public int pop_front() {
        if (!queue.isEmpty()) {
            Integer value = queue.removeFirst();
            if (value == max_value())
                deQueue.removeFirst();
            return value;
        } else {
            return -1;
        }
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */
```