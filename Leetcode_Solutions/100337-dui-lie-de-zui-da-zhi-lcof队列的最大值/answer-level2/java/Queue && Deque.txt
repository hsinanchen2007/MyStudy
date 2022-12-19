```
class MaxQueue {
    
    private Queue<Integer> queue;
    private Deque<Integer> deque;
    public MaxQueue() {
        queue = new LinkedList<>();
        deque = new LinkedList<>();
    }
    
    public int max_value() {
        if (deque.isEmpty())
            return -1;
        return deque.peekFirst();
    }
    
    public void push_back(int value) {
        queue.offer(value);
        while (!deque.isEmpty() && value >= deque.peekLast())
            deque.pollLast();
        deque.offer(value);
    }
    
    public int pop_front() {
        if (queue.isEmpty())
            return -1;
        int res = queue.poll();
        if (res == deque.peekFirst())
            deque.pollFirst();
        return res;
    }
}
```
