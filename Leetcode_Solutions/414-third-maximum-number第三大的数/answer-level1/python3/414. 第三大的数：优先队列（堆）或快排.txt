![image.png](https://pic.leetcode-cn.com/a9dcca7feebd07bb748745075e92931a58ab7574c7e50ba4d0b4214555eef406-image.png)

最快72ms这样，理论上前两种优先队列$O(Nlog3)$会比快排$O(NlogN)$时间复杂度低，但实际速度都差不多。

方法一：优先队列，主要函数`heapreplace()`：

```python []
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums = [*{*nums}]
        if len(nums) < 3:
            return max(nums)
        a = [-float('inf')] * 3
        for i in nums:
            if i > a[0]:
                heapq.heapreplace(a, i)
        return a[0]
```

方法一：优先队列，主要函数`nlargest()`：

```python []
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums = [*{*nums}]
        if len(nums) < 3:
            return max(nums)
        return heapq.nlargest(3, nums)[2]
```

方法三：快速排序，主要函数`sorted()`：

```python []
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums = {*nums}
        if len(nums) < 3:
            return max(nums)
        return sorted(nums, reverse = True)[2]
```
