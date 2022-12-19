```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # nums为空，返回0，否则先取出数组中最大的数
        res = len(nums) and max(nums)
        temp = 0
        for i in nums:
            # 比较当前这个数和之前的子序列和，取它们的最大值
            temp = max(i, temp+i)
            # 每次更新res的值
            res = max(res, temp)
        return res
```
