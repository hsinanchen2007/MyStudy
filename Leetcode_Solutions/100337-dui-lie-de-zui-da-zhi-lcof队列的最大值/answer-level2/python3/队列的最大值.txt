### 解题思路
一、原始方法：普通队列，但是求最大值时间复杂度O(N)
二、双队列
一个队列正常
一个队列存储最大值，队头是最大值，递减
（1） 入队时，第一个正常，第二个把尾部小于当前value的删除，保证头部是最大的
（2） 出队，第一个正常，第二个头部和第一个出队相等时，一同出队

### 代码

```python []
import queue
class MaxQueue:
    import queue
    def __init__(self):
        self.queue = queue.deque()  # 正常队列
        self.deque = queue.deque()   # 递减的双端队列

    def max_value(self) -> int:
        return self.deque[0] if self.deque else -1
        # 保证递减队列的头是最大 所以返回最大


    def push_back(self, value: int) -> None:
        self.queue.append(value) # 正常队列正常入队
        while self.deque and self.deque[-1] < value:
            self.deque.pop()
        # 保证队列末端小于当前值的弹出
        self.deque.append(value)


    def pop_front(self) -> int:
        if not self.queue:
            return -1
        ans = self.queue.popleft()
        # 当相同时 一同出队
        if ans == self.deque[0]:
            self.deque.popleft()
        return ans
```
```java []
class MaxQueue {
    Queue<Integer> queue;
    Deque<Integer> maxQueue;
    public MaxQueue() {
        queue=new ArrayDeque();
        maxQueue=new ArrayDeque();
    }
    public int max_value() {
        if(maxQueue.isEmpty())
            return -1;
        return maxQueue.peek();
    }
    public void push_back(int value) {
        queue.add(value);
        while(!maxQueue.isEmpty() && value>maxQueue.getLast())
            maxQueue.pollLast();
        maxQueue.add(value);
    }
    public int pop_front() {
        if(queue.isEmpty())
            return -1;
        int ans=queue.poll();
        if(ans==maxQueue.peek())
            maxQueue.poll();
        return ans;
    }
}
```
