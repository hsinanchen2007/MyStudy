### 解题思路
//TODO
### 代码

```java
class MaxQueue {
    //想到滑动窗口求最大值，维护一个队列和一个双端递减队列
    Queue<Integer> queue;
    Deque<Integer> deque;
    public MaxQueue() {
        queue = new ArrayDeque();
        deque = new ArrayDeque();
    }
    
    public int max_value() {
        return deque.isEmpty() ? -1 : deque.peekFirst();
    }
    
    public void push_back(int value) {
        queue.add(value);
        while(!deque.isEmpty() && deque.peekLast() < value) deque.pollLast();
        deque.addLast(value);
    }
    
    public int pop_front() {
        if(queue.isEmpty()) return -1;
        int x = queue.remove();
        if(deque.peekFirst() == x) deque.pollFirst();
        return x;
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