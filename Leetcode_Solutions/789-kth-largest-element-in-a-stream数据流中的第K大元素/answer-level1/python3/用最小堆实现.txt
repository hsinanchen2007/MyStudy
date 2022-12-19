

![84a059c5df2c5441003dd5139470de7.png](https://pic.leetcode-cn.com/bbd97fefc7f1f6c9407a52a16912366d811b86adf0a68705edc61f7adb6bc3e6-84a059c5df2c5441003dd5139470de7.png)




```python []
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.nums = heapq.nlargest(k, nums)[::-1]  ## 把nums的最大的k个数从小到大排序。注意如果nums=k-1的话，heapq.nlargest也是有效的，会把k-1个数从小到大排序。
        self.k = k  ## 用self.k记录k

    def add(self, val: int) -> int:
        if len(self.nums) == self.k:  ## 如果是k个数
            if val > self.nums[0]:  ## 如果val大于k个数中最小的
                    heapq.heapreplace(self.nums, val)  ##那么丢掉nums[0],把val塞进堆里。
            return self.nums[0]  ## 返回最小的数
        heapq.heappush(self.nums, val)  ## 如果是k-1个数，把val塞进堆里
        return self.nums[0]  ## 返回最小的数
```
