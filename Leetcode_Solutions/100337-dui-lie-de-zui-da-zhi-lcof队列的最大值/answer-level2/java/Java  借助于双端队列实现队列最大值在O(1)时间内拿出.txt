### 解题思路
解题思路：两个队列，由于存最大值，后入队的比之前元素大时需要更新以前元素对应的最大值为当前元素，因此需要使用一个双端队列存储最大值信息。

### 代码

```java
class MaxQueue {
    private Queue<Integer> queue;
    private Deque<Integer> deque;
    public MaxQueue() {
        queue = new LinkedList<Integer>();
        deque = new LinkedList<Integer>();
    }
    
    // 输出最大值
    public int max_value() {
        if (deque.isEmpty()) {
            return -1;
        }
        return deque.peekFirst();
    }
    
    // 入队
    public void push_back(int value) {
        queue.offer(value);
        if (deque.isEmpty()) {
            deque.offer(value);
        } else {
            int count = 1;
            while (deque.size() > 0 && deque.peekLast() < value) {
                deque.pollLast();
                count++;
            }
            while (count > 0) {
                count--;
                deque.offerLast(value);
            }
        }
    }
    
    // 出队
    public int pop_front() {
        if (queue.isEmpty()) {
            return -1;
        }

        deque.pollFirst();
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