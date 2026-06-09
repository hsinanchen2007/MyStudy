### 解题思路
为什么用双向队列？
1、如果只用Int变量存储的话，最大值出队后，第二大的值就丢失了
2、如果辅助队列用单向的话，无法处理，3,2 ,3的情况，此时2在队尾，需要出队列，所以要双端队列

### 代码

```java
import java.util.ArrayDeque;

class MaxQueue {

    Queue<Integer> q;
    Deque<Integer> maxQ;
    public MaxQueue() {
        q = new LinkedList<Integer>();
        maxQ = new ArrayDeque<Integer>();
    }
    
    public int max_value() {
        if (maxQ.isEmpty()) {
            return -1;
        }
        return maxQ.peekFirst();
    }
    
    public void push_back(int value) {
        q.add(value);
        while (!maxQ.isEmpty()) {
            if (maxQ.peekLast() < value) {
                maxQ.pollLast();
            } else {
                break;
            }
        }
        maxQ.addLast(value);
    }
    
    public int pop_front() {
        if (q.isEmpty()) {
            return -1;
        }
        int result = q.poll();
        if (result == maxQ.peekFirst()) {
            maxQ.pollFirst();
        }
        return result;
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