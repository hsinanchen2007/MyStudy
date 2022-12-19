

```
class RLEIterator:

    def __init__(self, A):
        self.A = A
        self.index = 0

    def next(self, n: int) -> int:
        # 如果n大于或等于游程编码当前的计数, 则将当前计数置0
        while self.index < len(self.A) - 1 and self.A[self.index] < n:
            n -= self.A[self.index]
            self.A[self.index] = 0
            self.index += 2

        if self.index >= len(self.A) - 1:
            return -1

        self.A[self.index] -= n

        return self.A[self.index + 1]
```

