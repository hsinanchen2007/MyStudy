```python
class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.queue = collections.deque()
        self.size = 0
        self.window = size
        self.sum = 0


    def next(self, val: int) -> float:
        self.sum += val
        if self.size < self.window:
            self.size += 1
        else:
            self.sum -= self.queue.popleft()
        self.queue.append(val)
        return self.sum / self.size

        


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
```