```
class MovingAverage:
 
    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.queue = []
        for _ in range(size):
            self.queue.append(0)
        self.length = 0
        return
 
    def next(self, val: int) -> float:
        if self.length < len(self.queue):
            self.queue[self.length] = val
            self.length += 1
            return sum(self.queue)/self.length
        else:
            self.queue[:-1] = self.queue[1:]
            self.queue[-1] = val
            return sum(self.queue)/self.length
```

执行用时 :144 ms, 在所有 Python3 提交中击败了53.85%的用户

内存消耗 :16.7 MB, 在所有 Python3 提交中击败了100.00%的用户