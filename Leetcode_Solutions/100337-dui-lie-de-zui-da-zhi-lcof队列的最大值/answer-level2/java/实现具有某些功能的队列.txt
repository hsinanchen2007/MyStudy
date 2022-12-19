### 解题思路
此处撰写解题思路
需要一个队列保存所有元素，而为了再求最大值时，避免每次遍历整个队列，所以还可以再使用一个辅助队列用来保存最大值
### 代码

```java
class MaxQueue {
    private Deque<Integer> queue;
    private Deque<Integer> help;

    public MaxQueue() {
        queue = new ArrayDeque<>();
        help = new ArrayDeque<>();
    }
    
    public int max_value() {
        return queue.isEmpty() ? -1 : help.peek();

    }
    
    public void push_back(int value) {
        queue.offer(value);
        while(!help.isEmpty() && value > help.peekLast()){
            help.pollLast();
        }
        help.offer(value);
    }
    
    public int pop_front() {
        if(help.isEmpty()){
            return -1;
        }
        int val = queue.pop();
        if(help.peek() == val)
            help.pop();
        return val;
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