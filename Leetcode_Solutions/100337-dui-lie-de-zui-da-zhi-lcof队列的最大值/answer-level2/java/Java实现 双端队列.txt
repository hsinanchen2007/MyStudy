### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
class MaxQueue {
    Deque<Integer> deque;
    Queue<Integer> queue;
    public MaxQueue() {
        deque = new LinkedList<>();
        queue = new LinkedList<>();
    }
    
    public int max_value() {
        if(queue.peek()==null) return -1;
        return deque.peekFirst();
    }
    
    public void push_back(int value) {
        while (deque.peekLast()!=null&&value > deque.peekLast()) {
            deque.pollLast();
        }
        deque.offerLast(value);
        queue.offer(value);
    }
    
    public int pop_front() {
        if(queue.peek()==null) return -1;
        int res=queue.peek();
        if(res==deque.peekFirst()){
            deque.pollFirst();
        }
        queue.poll();
        return res;
        
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