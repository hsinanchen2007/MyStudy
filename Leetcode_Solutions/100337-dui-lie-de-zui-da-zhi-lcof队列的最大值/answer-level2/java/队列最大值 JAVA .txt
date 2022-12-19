### 解题思路
此处撰写解题思路

### 代码

```java
class MaxQueue {

    private Queue<Integer> queue;
    private Deque<Integer> deque;

    public MaxQueue() {
        queue = new LinkedList<>();
        deque = new LinkedList<>();
    }
    
    public int max_value() {
        if(deque.isEmpty()){
            return -1;
        }
        return deque.peekFirst();
    }
    
    public void push_back(int value) {
        queue.add(value);
        while(!deque.isEmpty() && deque.peekLast() < value){
            deque.pollLast();
        }
        deque.addLast(value);
    }
    
    public int pop_front() {
        if(queue.isEmpty()){
            return -1;
        }
        int ans = queue.poll();
        if(ans == deque.peekFirst()){
            deque.pollFirst();
        }
        return ans;
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