```Java
public class MaxQueue {
    /**
     * 所有元素都入队的队列
     */
    private Queue<Integer> dataQueue;
    /**
     * 最大值队列，其中队头元素最大
     */
    private Deque<Integer> maximumQueue;
    /**
     * 初始化
     */
    public MaxQueue() {
        dataQueue = new ArrayDeque<>();
        maximumQueue = new ArrayDeque<>();
    }
    /**
     * 新的元素入队
     *  dataQueue 直接入队
     *  maximumQueue 淘汰队尾比入队元素小的值
     */
    public void push_back(int value) {
        dataQueue.offer(value);
        while (!maximumQueue.isEmpty() && value > maximumQueue.peekLast()) {
            maximumQueue.pollLast();
        }
        maximumQueue.offer(value);
    }
    /**
     * 出队
     */
    public int pop_front() {
        int front = dataQueue.isEmpty() ? -1: dataQueue.poll();
        if (!maximumQueue.isEmpty() && maximumQueue.peek() == front) {
            maximumQueue.poll();
        }
        return front;
    }
    /**
     * 最大值
     */
    public int max_value() {
        return maximumQueue.isEmpty() ? -1: maximumQueue.peek();
    }

}
```
