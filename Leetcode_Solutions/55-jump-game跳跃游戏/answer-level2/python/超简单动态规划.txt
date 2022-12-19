
![image.png](https://pic.leetcode-cn.com/38ce0ef61e550a7a138558a8af012c231f99f5c972dd1151f28b112fa0134bc4-image.png)

dp[i]代表索引为i的时候能走的最远距离
例如nums = [2,3,1,1,4]
dp[0] = nums[0]
dp[1] = max(dp[0]-1,nums[1])
dp[2] = max(dp[1]-1,nums[2])
...............
状态转移方程
dp[i] = max(dp[i]-1,nums[i])
边界条件
dp[0] = nums[0]
```
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        #dp[i]代表，在i点可以走的最远距离
        if len(nums)==1:
            return True
        dp = [0]*len(nums)
        dp[0] = nums[0]
        for i in range(1,len(nums)):
            if dp[i-1]>=1:
                dp[i] = max(nums[i],dp[i-1]-1)
        if dp[-2]!=0:
            return True
        else:
            return False
```

