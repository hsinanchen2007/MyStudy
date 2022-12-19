小堆取负，大堆取正，根据堆的大小输出堆顶。

```python []
class MedianFinder:
    
    def __init__(self):
        self.s, self.l = [], []

    def addNum(self, num: int) -> None:
        if len(self.s) == len(self.l):
            heapq.heappush(self.s, -heapq.heappushpop(self.l, num))
        else:
            heapq.heappush(self.l, -heapq.heappushpop(self.s, -num))
        
    def findMedian(self) -> float:
        return len(self.s) == len(self.l) and (self.l[0] - self.s[0]) / 2 or -self.s[0]
```