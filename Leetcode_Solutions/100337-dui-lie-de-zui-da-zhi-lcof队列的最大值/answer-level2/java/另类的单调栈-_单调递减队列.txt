### 解题思路
普通的一个队列，求最大值都需要遍历一遍求最大值。这种思路固然可以，但不是最优。

在数学函数中，最值情况，一般都伴随这函数的单调性（二次函数那种，在某个区间范围，存在单调性）。只要能记录一个单调递增，或者单调递减的集合，就可以知道最值的情况。

此题的集合是队列，也就是说**当一个元素进入队列的时候，它前面所有比它小的元素就不会再对最大值产生影响**。

什么意思呢，原队列在最大值的元素，如果没有出队列，那么最大值就会一直存在（因为队列的先进先出特性，先来的元素总是先出）。所以，我们只要维护一个单调递减的队列。当一个元素大于队尾元素了，我们就把比他小的元素，从队列里全部移除，再加入当前元素。元素小于队尾元素，直接加入即可。

### 代码

```java
class MaxQueue {

    private Queue<Integer> queue;// 标准队列
    private Deque<Integer> maxDeque;// 单调双端队列，用来存储一个单调递减的元素数组

    public MaxQueue() {
        queue = new LinkedList<>();
        maxDeque = new LinkedList<>();
    }

    public int max_value() {
        return maxDeque.isEmpty() ? -1 : maxDeque.peek();
    }

    public void push_back(int value) {
        queue.offer(value);
        // 单调递减队列，移除掉之前比当前元素小的元素
        while (!maxDeque.isEmpty() && value > maxDeque.peekLast()) {
            maxDeque.pollLast();
        }
        maxDeque.offer(value);
    }

    public int pop_front() {
        // 队列空，返回-1，否则返回队头元素
        if (queue.isEmpty()) {
            return -1;
        }
        int value = queue.poll();
        if (value == maxDeque.peek()) {
            maxDeque.pop();
        }
        return value;
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