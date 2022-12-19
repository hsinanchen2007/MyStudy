### 解题思路
Python的heapq的文档：https://docs.python.org/3.0/library/heapq.html

1、heapq.heapify可以原地把一个list调整成堆
2、heapq.heappop可以弹出堆顶，并重新调整
3、heapq.heappush可以新增元素到堆中
4、heapq.heapreplace可以替换堆顶元素，并调整下
5、为了维持为K的大小，初始化的时候可能需要删减，后面需要做处理就是如果不满K个就新增，否则做替换；
6、heapq其实是对一个list做原地的处理，第一个元素就是最小的，直接返回就是最小的值

### 代码

```python
import heapq


class KthLargest(object):

    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """
        # self k
        self.k = k
        self.heap = nums
        # heap其实就是个list
        heapq.heapify(self.heap)
        # 减小到k
        while len(self.heap) > k:
            heapq.heappop(self.heap)

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """
        # 不过堆不够，则直接添加进去
        if len(self.heap) < self.k:
            heapq.heappush(self.heap, val)
        elif self.heap[0] < val:
            # 新的值更大，更新
            heapq.heapreplace(self.heap, val)

        return self.heap[0]
```