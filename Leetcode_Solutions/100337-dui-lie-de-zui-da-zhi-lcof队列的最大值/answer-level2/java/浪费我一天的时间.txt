**粗体**### 解题思路
# 双端队列

### 代码

```java
class MaxQueue {
	private Queue<Integer> queue;
	private ArrayDeque<Integer> deque;
    public MaxQueue() {
    	queue=new LinkedList<>();
    	deque=new ArrayDeque<>();
    }
    
    public int max_value() {
    	if(queue.isEmpty())return -1;
    	return deque.getFirst();
    }
    
   public void push_back(int value) {
    	queue.add(value);
    		while(!deque.isEmpty()&&deque.getLast()<value) {
    			deque.removeLast();
            }
    	deque.addLast(value);
    }
    
    public int pop_front() {
    	if(queue.isEmpty())return -1;
    	if(queue.peek()<deque.getFirst())return queue.poll();
    	deque.removeFirst();
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