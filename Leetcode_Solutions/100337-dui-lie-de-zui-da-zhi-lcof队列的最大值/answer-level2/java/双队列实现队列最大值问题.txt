### 解题思路
队列q:保存队列元素
队列helper:保存最大元素，用双端队列实现
           当要向队尾插入元素value时，从队尾开始将比value小的所有元素全部出队丢弃
            之所以能够被全部丢弃的原因是根据队列FIFO的特性，它们会比value先出队
            所以他们不会影响到最大值的变化

### 代码

```java
class MaxQueue {
    private Queue<Integer> q;
    private Deque<Integer> helper;//双端队列辅助空间存储可能的最大值
    public MaxQueue() {
        q = new LinkedList<>();
        helper = new LinkedList<>();
    }
    
    public int max_value() {

        return helper.isEmpty() ? -1 : helper.peek();
    }
    
    public void push_back(int value) {
        q.offer(value);//q保存入队的元素
        /*
        helper存储可能的最大值，比value小的元素全部丢弃
        因为他们会在value之前被弹出，
        */
        while(! helper.isEmpty() && helper.getLast() < value)
            helper.removeLast();
        helper.addLast(value);
    }
    
    public int pop_front() {
        if(q.isEmpty())
            return -1;
        int val = q.poll();
        if(val == helper.getFirst())
            helper.removeFirst();
        return val;
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