2 个队列维护，一个当前值，一个记录当前队列最大值

思路：
- 假如 5 入队，那么当前队列中最小值也是 5 ，所以那些小于 5 的就不需要了。
- 假如 5 出队，那么当前队列最大值如果是 5 ，移除。因为使用 > 移除，如果队列中还有 5 ，那么下一个最大值就是 5.

```java
class MaxQueue {
    private final Queue<Integer> val = new ArrayDeque<>(); // 保存 push 数据
    private final Deque<Integer> maxVal = new ArrayDeque<>(); // 最大值记录，递增队列，头部为最大值

    public MaxQueue() { }

    public int max_value() {
        return maxVal.isEmpty() ? -1 : maxVal.peekFirst();
    }

    public void push_back(int value) {
        val.add(value);

        // 从 maxVal 队列尾部，移除比当前 value 小的元素
        while (!maxVal.isEmpty() && value > maxVal.peekLast()) 
            maxVal.pollLast();

        maxVal.addLast(value);
    }

    public int pop_front() {
        if (val.isEmpty()) return -1;
        int r = val.poll();
        if (r == maxVal.peekFirst()) maxVal.removeFirst(); // 如果当前移除值是最大值进行移除
        return r;
    }
}
```