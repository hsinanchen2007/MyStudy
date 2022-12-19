### 解题思路
思路来源：https://mp.weixin.qq.com/s?__biz=MzI4Njc4MzMwMw==&mid=2247483871&idx=1&sn=70ef8591a98312a1836b39e90bf878ad&scene=19#wechat_redirect

用一个队列保存正常元素，另一个双向队列保存单调递减的元素
入栈时，第一个队列正常入栈；第二个队列是递减队列，所以需要与之前的比较，从尾部把小于当前value的全部删除（因为用不到了）
出栈时，第一个队列正常出栈；第二个队列的头部与出栈的值作比较，如果相同，那么一起出栈

### 代码

```java
class MaxQueue {
    Queue<Integer> queue;
    Deque<Integer> maxQueue;
    public MaxQueue() {
        queue = new ArrayDeque();
        maxQueue = new ArrayDeque();
    }
    
    public int max_value() {
        if(maxQueue.isEmpty())
            return -1;
        return maxQueue.peek();
    }
    
    public void push_back(int value) {
        queue.add(value);
        while(!maxQueue.isEmpty() && value > maxQueue.getLast()){
            maxQueue.pollLast();
        }
        maxQueue.add(value);
    }
    
    public int pop_front() {
        if(queue.isEmpty())
            return -1;
        int ans = queue.poll();
        if(ans == maxQueue.peek())
            maxQueue.poll();
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