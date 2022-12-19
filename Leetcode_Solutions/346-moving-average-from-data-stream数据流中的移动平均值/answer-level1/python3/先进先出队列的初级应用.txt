### 解题思路
这是一个典型的利用队列的题目，而且是应用的先进先出的队列，在python中应用queue.Queue即可。

### 代码

```python3
from queue import Queue,LifoQueue,PriorityQueue


class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.q = Queue(maxsize=size)

    def next(self, val: int) -> float:
        if not self.q.full():
            self.q.put(val)
        else:
            self.q.get()
            self.q.put(val)
        return sum(self.q.queue)/self.q.qsize()


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
```