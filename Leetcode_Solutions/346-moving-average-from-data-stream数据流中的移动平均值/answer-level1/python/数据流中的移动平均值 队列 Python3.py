### 解题思路
执行用时 :112 ms, 在所有 Python3 提交中击败了61.52%的用户
内存消耗 :16.5 MB, 在所有 Python3 提交中击败了5.66%的用户

注释部分是另一种方法，速度稍慢一丢丢
### 代码

```python3
class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.capacity = size
        self.queue = [0]*size
        self.cnt = 0
        # self.head = -1

    def next(self, val: int) -> float:
        if self.cnt < self.capacity:
            self.cnt += 1
        self.queue = self.queue[1:]
        self.queue.append(val)
        return sum(self.queue)/self.cnt
        # if self.cnt < self.capacity:
            # self.cnt += 1
        # self.head = (self.head+1) % self.capacity
        # self.queue[self.head] = val
        # return sum(self.queue)/self.cnt


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
```