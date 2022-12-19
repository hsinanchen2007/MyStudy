### 解题思路
这一个和上一题基本是一样的，唯一不同的就是存在环的问题。
假设有N个房子，从0,1,...,N-1
- 分析：房子0和房子N-1成了邻居，那么就不同同时偷窃
- 解决：分类：1.不偷房子0      2.不偷房子N-1
这两种情况就解决了环的问题，从而转化成了和上一题一样的排的情况。

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        #动态规划：
        size = len(nums)
        if size == 0:
            return 0
        if size == 1:
            return nums[0]
        
        def func(nums):
            dp = [0]*(size-1)
            if len(nums)<=1:
                return nums[0]
            dp[0] = nums[0]
            dp[1] = max(nums[0],nums[1])
            for i in range(2,size-1):
                dp[i] = max(dp[i-1],dp[i-2]+nums[i])
            return dp[-1]
        res1 = func(nums[1:])#不偷房子0
        res2 = func(nums[:-1])#不偷房子N-1
        return max(res1,res2)

```