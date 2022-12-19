```
class Solution:
    def subarraySum(self, nums: list, k: int) -> int:
        d = {0:1} #初始化，累积和为0的情况已经出现了一次
        Sum = 0
        count = 0
        for p in range(len(nums)):
            Sum += nums[p]
            count += d.get(Sum-k, 0)
            d.setdefault(Sum, 0)
            d[Sum] += 1
        return count
```
官方题解方法四的Python3版本。