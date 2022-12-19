### 解题思路
此处撰写解题思路

### 代码

```python3
import heapq
class MedianFinder:

    def __init__(self):
        self.bigheap = []
        self.smallheap = []

    def addNum(self, num: int) -> None:
        if len(self.bigheap)==len(self.smallheap):
            heapq.heappush(self.bigheap,-heapq.heappushpop(self.smallheap,num))
        else:
            heapq.heappush(self.smallheap,-heapq.heappushpop(self.bigheap,-num))

    def findMedian(self) -> float:
        if len(self.bigheap)==len(self.smallheap):
            return (self.smallheap[0]-self.bigheap[0])/2
        else:
            return -self.bigheap[0]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
```