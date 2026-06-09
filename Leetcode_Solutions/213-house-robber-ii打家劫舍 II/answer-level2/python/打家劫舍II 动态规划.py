### 解题思路
将数组分为前n-1个和后n-1个

### 代码

```python
class Solution(object):
    def rob(self, nums):
        if not nums:return 0
        if len(nums) <= 2:return max(nums)
        dp = [0] * (len(nums)-1)  #dp代表到当前元素为止可以拿到的最大金额，可以选择也可放弃
        #首先考虑nums[0:len(nums)-1]
        dp[0] = nums[0]
        dp[1] = max(nums[0],nums[1])
        for i in range(2,len(nums)-1):
            dp[i] = max(dp[i-1],dp[i-2]+nums[i])
        cur_max = max(dp)
        dp = dp = [0] * (len(nums)-1)
        #现在考虑nums[1:]的情况
        dp[0] = nums[1]
        dp[1] = max(nums[1],nums[2])
        for i in range(3,len(nums)):
            dp[i-1] = max(dp[i-2],dp[i-3]+nums[i])
        return max(cur_max,max(dp))
```