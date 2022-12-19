### 代码

```python3
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.max_heap = [] # 前半部分
        self.min_heap = [] # 后半部分

    def addNum(self, num: int) -> None:
        if len(self.max_heap) == len(self.min_heap):
            heapq.heappush(self.min_heap, -heapq.heappushpop(self.max_heap, -num)) # num放大根堆
        else:
            # 当数据流为奇数个时候，说明最小堆个数和最大堆个数不一样，这里我放在后半部分（最小堆）
            heapq.heappush(self.max_heap, -heapq.heappushpop(self.min_heap, num)) # num放小根堆

    def findMedian(self) -> float:
        if len(self.max_heap) == len(self.min_heap):
            return (self.min_heap[0] + -1 * self.max_heap[0]) / 2
        else:
            return self.min_heap[0]
```