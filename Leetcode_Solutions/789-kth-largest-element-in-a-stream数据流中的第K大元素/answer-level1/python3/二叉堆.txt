### 解题思路
此处撰写解题思路

### 代码

```python3
import heapq
class KthLargest:
    '''
 	heap = [] 定义一个空堆
 	1,heapq.heappush(heap,x):向heap堆中添加元素
 	2,heapq.heappop(heap)：弹出堆中最小的元素，并且维持剩余元素的堆结构
 	3,heapq.heapify(heap)：将列表转换为堆
 	4,heapq.heapreplace(heap, x)：弹出堆中最小的元素，然后将新元素插入。
 	5,heapq.nlargest(n, iter)、nsmallest(n, iter)   注意，里面可以有key参数，作为一个函数
 	用来寻找任何可迭代对象iter中的前n个最大的或前n个最小的元素。
    '''
    def __init__(self, k: int, nums: List[int]):
        self.heap = nums
        self.k = k
        heapq.heapify(self.heap)
        while len(self.heap) > self.k:
            heapq.heappop(self.heap)
    def add(self, val: int) -> int:
        if len(self.heap) < self.k:
            heapq.heappush(self.heap,val)
        elif val > self.heap[0]:
            heapq.heapreplace(self.heap,val)
        return self.heap[0]
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
```