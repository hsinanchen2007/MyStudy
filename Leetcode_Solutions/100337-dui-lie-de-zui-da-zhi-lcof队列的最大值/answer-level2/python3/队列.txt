### 解题思路
此处撰写解题思路

### 代码

```python3
from collections import deque
class MaxQueue:

    def __init__(self):
        self.queue = deque()
        self.max_queue = deque()

    def max_value(self) -> int:
        return self.max_queue[0] if self.queue else -1

    def push_back(self, value: int) -> None:
        self.queue.append(value)
        while self.max_queue and self.max_queue[-1]<value:
            self.max_queue.pop()
        self.max_queue.append(value)


    def pop_front(self) -> int:
        if not self.queue:
            return -1
        res = self.queue.popleft() #这种方式弹出的第一个元素，时间复杂度为O(1)
        if res== self.max_queue[0]:
            self.max_queue.popleft()
        return res



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```