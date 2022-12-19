### 解题思路
用一个单调非递增队列q2记录最大值

### 代码
```
from collections import deque
class MaxQueue:

    def __init__(self):
        self.q1=deque()
        self.q2=deque()


    def max_value(self) -> int:
        return self.q2[0] if self.q2 else -1


    def push_back(self, value: int) -> None:
        self.q1.append(value)
        while self.q2 and self.q2[-1]<value:
            self.q2.pop()
        self.q2.append(value)


    def pop_front(self) -> int:
        if not self.q1:
            return -1
        res=self.q1.popleft()
        if self.q2[0]==res:
            self.q2.popleft()
        return res



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```
