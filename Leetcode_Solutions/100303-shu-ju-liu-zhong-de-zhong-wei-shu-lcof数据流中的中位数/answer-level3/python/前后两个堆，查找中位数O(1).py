### 解题思路
前半部分用最大堆，后半部分用最小堆
python只有小堆顶，大堆顶要将元素转为负数


### 代码

```python3
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        # 前半部分用最大堆，后半部分用最小堆
        self.max_heap = []
        self.min_heap = []


    def addNum(self, num: int) -> None:
        # python只有小堆顶，大堆顶要将元素转为负数
        # 先放到最大堆，把堆顶取出来放最小堆
        import heapq
        heapq.heappush(self.max_heap, -num)
        heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
        # 如果最小堆更大，放回最大堆
        if len(self.min_heap) > len(self.max_heap):
            heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))


    def findMedian(self) -> float:
        if not self.max_heap and not self.min_heap:
            return 0
        # 两个堆一样大
        if len(self.max_heap) == len(self.min_heap):
            return (-self.max_heap[0] + self.min_heap[0]) / 2
        else:
            return -self.max_heap[0]
            
```