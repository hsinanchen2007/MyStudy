### 解题思路
定义辅助队列来获取队列最大值，需要注意的是：队列是先进先出

```python3
while self.maxq and self.maxq[-1] < value:
    self.maxq.pop()
self.maxq.append(value)
```
因为题目是一个值一个值插入队列的，在使用辅助队列时，将value值和队尾的值进行比较，小于value值的就可以直接抛弃了，因为这些值小于value且会比value值先离开队列，他们的存在不影响value值做为假象的最大值。

### 代码

```python3
class MaxQueue:

    def __init__(self):
        from collections import deque
        self.queue = deque()
        self.maxq = deque()

    def max_value(self) -> int:
        return self.maxq[0] if self.maxq else -1

    def push_back(self, value: int) -> None:
        self.queue.append(value)
        while self.maxq and self.maxq[-1] < value:
            self.maxq.pop()
        self.maxq.append(value)

    def pop_front(self) -> int:
        if not self.queue:
            return -1
        temp = self.queue.popleft()
        if temp == self.maxq[0]:
            self.maxq.popleft()
        return temp


# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```