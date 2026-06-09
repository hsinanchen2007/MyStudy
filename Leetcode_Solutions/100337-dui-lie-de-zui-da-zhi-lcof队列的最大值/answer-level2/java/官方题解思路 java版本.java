### 解题思路
官方题解思路 java版本

### 代码

```java
class MaxQueue {

    private Queue<Integer> q = null;
    private Deque<Integer> deq = null;

    public MaxQueue() {
        q = new LinkedList<>();
        deq = new ArrayDeque<>();
    }
    
    public int max_value() {
        return deq.isEmpty() ? -1 : deq.peek();
    }
    
    public void push_back(int value) {
        while(!deq.isEmpty()){
            if(value > deq.getLast())
                deq.removeLast();
            else
                break;
        }
        q.add(value);
        deq.add(value);
    }
    
    public int pop_front() {
        if(q.isEmpty()) return -1;
        int ans = q.peek();
        if(ans == deq.peek()) deq.poll();
        return q.poll();
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