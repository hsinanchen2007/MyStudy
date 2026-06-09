### 解题思路
此处撰写解题思路

### 代码

```java
class MaxQueue {
    Queue<Integer>queue;
    Deque<Integer>deque;

    public MaxQueue() {
        queue=new LinkedList<>();
        deque=new LinkedList<>();
    }
    
    public int max_value() {
        if(queue.isEmpty()){
            return -1;
        }
        return deque.peek();
    }
    
    public void push_back(int value) {
        queue.add(value);
        if(queue.isEmpty()){
            deque.add(value);
        }
        else{
            int count=0;
            while(!deque.isEmpty() && value>deque.getLast()){
                deque.pollLast();
                count++;
            }
            while(count>=0){
                deque.add(value);
                count--;
            }
        }

    }
    
    public int pop_front() {
        if(queue.isEmpty()){
            return -1;
        }
        deque.poll();
        return queue.poll();

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