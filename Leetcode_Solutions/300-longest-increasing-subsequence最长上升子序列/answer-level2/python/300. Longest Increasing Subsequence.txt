1. 动态规划
其实跟爬楼梯概念是一样的。

```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums: return 0
        _Store = [1] * len(nums)
        for i in range(1, len(nums)):
            _temp = 1
            for j in range(i-1, -1, -1):
                if nums[i] > nums[j]:
                    _temp = max(1 + _Store[j], _temp)
            _Store[i] = _temp
        return max(_Store)
```
