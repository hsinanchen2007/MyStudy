解题思路：
    1.首先建立一个列表dp=[0]*len(nums)
    2.指定第一个元素dp[1] = nums[0]
    3.循环nums，如果dp上一个值小于等于0则更新dp[i] = nums[i]
               否则dp[i] = dp[i-1] + nums[i]
    4.返回dp最大值（dp内存储着到当前位置的最大总和）

```
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [0]*len(nums)
        dp[0] = nums[0]
        for i in range(1,len(nums)):
            if dp[i-1] <= 0:
                dp[i] = nums[i]
            else:
                dp[i] = dp[i-1] + nums[i]
        return max(dp)
```

