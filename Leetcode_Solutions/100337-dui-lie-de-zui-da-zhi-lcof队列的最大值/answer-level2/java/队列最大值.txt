### 解题思路
维护一个双端队列，保持单调递减，队首元素是当前队列的最大值。对比队尾元素与当前元素大小，如果当前元素大于队尾元素，将队尾元素移除，直到当前元素小于队尾元素或队列为空。另外为满足pop_front操作还需维护一个普通队列。

### 代码

```java
class MaxQueue {

    LinkedList<Integer> deque = new  LinkedList<>();
    Queue<Integer> queue = new LinkedList<>();
    public MaxQueue() {

    }
    
    public int max_value() {
        return !deque.isEmpty()?deque.getFirst():-1;
    }
    
    public void push_back(int value) {
        while(!deque.isEmpty()&&deque.getLast()<=value){
            deque.pollLast();
        }
        deque.offer(value);
        queue.offer(value);
    }
    
    public int pop_front() {
        if(!queue.isEmpty()){
            int val = queue.poll();
            if(val==deque.getFirst()){
                deque.pollFirst();
            }
            return val;
        }
        return -1;
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