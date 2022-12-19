### 解题思路
借助双端队列存放队列的下一个最大值，辅助队列是单调递减的（头->尾）

1、push_back时，判断辅助队列的尾是否大于等于当前入队元素，如果大于等于，则在辅助队列尾部添加该元素，
如果小于则将辅助队列的队尾元素poll，直到当前辅助队列为空或者队尾元素大于等于当前添加的元素，后添加该元素
2、pop_front时，需要判断辅助队列的头是否等于当前主队列的头元素，如果相等则辅助队列也需要pollFirst



### 代码

```java
class MaxQueue {

     Queue<Integer> queue;
    Deque<Integer> queueHelper;


    public MaxQueue() {
        queue = new LinkedList<>();
        queueHelper = new LinkedList<>();
    }

    public int max_value() {
        if (queue.isEmpty()) {
            return -1;
        }
        return queueHelper.peekFirst();

    }

    public void push_back(int value) {
        queue.offer(value);
        while (!queueHelper.isEmpty() && queueHelper.peekLast() < value) {
            queueHelper.pollLast();
        }
        queueHelper.offerLast(value);
    }

    public int pop_front() {
        if (queue.isEmpty()) {
            return -1;
        }
        if (queueHelper.peekFirst().equals(queue.peek())) {
            queueHelper.pollFirst();
        }
        return queue.poll();
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