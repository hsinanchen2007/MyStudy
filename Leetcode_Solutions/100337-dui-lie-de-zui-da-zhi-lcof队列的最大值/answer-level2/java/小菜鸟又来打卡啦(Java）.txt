# 队列的最大值
# 思路
定义两个队列，一个用来存储最大值，因为最大值队列涉及到从前面出队，从后面出队，所以用ArrayDeque中的方法
```
class MaxQueue {
    Queue<Integer> queue;
    ArrayDeque<Integer> maxQueue;
    public MaxQueue() {
        queue=new ArrayDeque<>();
        maxQueue = new ArrayDeque<>();
    }
    
    public int max_value() {
        return maxQueue.isEmpty()?-1:maxQueue.peek();
    }
    
    public void push_back(int value) {
        queue.add(value);
        while(!maxQueue.isEmpty() && maxQueue.getLast()<value)
        {
            maxQueue.removeLast();
        }
        maxQueue.add(value);
    }
    
    public int pop_front() {
        if(queue.isEmpty())
        return -1;
        int res=queue.poll();
        if(res==maxQueue.getFirst())
        {
            maxQueue.removeFirst();
        }
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
- 时间复杂度：O(1),每次操作都是O(1)复杂度
- 空间复杂度：O(n)，队列需要额外的空间
