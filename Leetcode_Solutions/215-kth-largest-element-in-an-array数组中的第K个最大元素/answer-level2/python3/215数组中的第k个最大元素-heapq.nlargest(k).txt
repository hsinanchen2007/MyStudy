### 解题思路
heapq.nlargest(k)返回前k大的元素的列表
第k大元素为heapq.nlargest(k)[-1]

### 代码

```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        #优先队列：最小堆
        import heapq
        heapq.heapify(nums)
        return heapq.nlargest(k,nums)[-1]
```