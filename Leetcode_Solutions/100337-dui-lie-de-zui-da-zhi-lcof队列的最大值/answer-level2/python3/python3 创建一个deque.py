### 解题思路
此处撰写解题思路

### 代码

```python3
from collections import deque
class MaxQueue:

    def __init__(self):
        self.de=deque()

    def max_value(self) -> int:
        if not self.de:
            return -1
        else:
            return max(self.de)

    def push_back(self, value: int) -> None:
        self.de.append(value)

    def pop_front(self) -> int:
        if not self.de:
            return -1
        else:
            return self.de.popleft()


# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```