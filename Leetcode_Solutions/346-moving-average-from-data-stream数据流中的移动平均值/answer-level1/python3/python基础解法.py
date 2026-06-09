### 解题思路
利用单队列实现

### 代码

```python3
class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.size = size
        self.q = list()

    def next(self, val: int) -> float:
        size, queue = self.size, self.q
        queue.append(val)
        wind_sum = sum(queue[-size:])
        return wind_sum/min(len(queue), size)


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
```