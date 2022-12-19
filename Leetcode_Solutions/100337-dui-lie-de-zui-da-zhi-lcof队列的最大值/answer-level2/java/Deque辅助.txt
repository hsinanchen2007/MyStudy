### 解题思路

使用双端辅助队列，存放每次遍历最大值
如果是求栈的最大值的话，辅助应该用栈

### 代码

```java
class MaxQueue {

    // 如果offer的值比辅助队列的值（从后往前）都大，那么删除直到offer小于队列的值
    private Queue<Integer> queue;
    private Deque<Integer> deque; 
    public MaxQueue() {
        queue = new LinkedList<>();
        deque = new LinkedList<>();
    }
    
    public int max_value() {
        if(deque.isEmpty()) return -1;
        return deque.peek();
    }
    
    public void push_back(int value) {
        queue.offer(value);
        while(!deque.isEmpty() && value >= deque.peekLast()) deque.pollLast();
        deque.offer(value);
    }

    public int pop_front() {
        int out = -1;
        if(!queue.isEmpty() && (out = queue.poll()) == deque.peek()) deque.poll();
        return out;
    }
    
}
```