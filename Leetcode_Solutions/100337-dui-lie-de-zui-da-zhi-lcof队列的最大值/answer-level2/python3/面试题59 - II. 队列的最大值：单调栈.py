单调栈：

```python []
class MaxQueue:

    def __init__(self):
        self.q = collections.deque()
        self.p = collections.deque()

    def max_value(self) -> int:
        return not self.q and -1 or self.p[0]

    def push_back(self, value: int) -> None:
        self.q.append(value)
        while self.p and value > self.p[-1]:
            self.p.pop()
        self.p.append(value)

    def pop_front(self) -> int:
        if not self.q:
            return -1
        self.q[0] == self.p[0] and self.p.popleft()
        return self.q.popleft()
```

二分插入：

```python []
class MaxQueue:

    def __init__(self):
        self.q = collections.deque()
        self.p = []

    def max_value(self) -> int:
        return not self.q and -1 or self.p[-1]

    def push_back(self, value: int) -> None:
        self.q.append(value)
        bisect.insort(self.p, value)

    def pop_front(self) -> int:
        if not self.q:
            return -1
        del self.p[bisect.bisect(self.p, self.q[0]) - 1]
        return self.q.popleft()
```

时间复杂度不一样，但实际线上测试差不多。