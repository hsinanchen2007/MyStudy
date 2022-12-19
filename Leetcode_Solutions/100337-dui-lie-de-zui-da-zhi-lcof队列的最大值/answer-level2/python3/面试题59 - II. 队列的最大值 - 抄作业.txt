### 解题思路
暴力

### 代码

```python3
class MaxQueue:
    import queue
    def __init__(self):
        self.dq = self.queue.deque()

    def max_value(self) -> int:
        return max(self.dq) if self.dq else -1

    def push_back(self, value: int) -> None:
        self.dq.append(value)

    def pop_front(self) -> int:
        return self.dq.popleft() if self.dq else -1
```