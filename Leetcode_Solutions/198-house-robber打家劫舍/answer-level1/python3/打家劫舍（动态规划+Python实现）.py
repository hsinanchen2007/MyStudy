## 这道题使用动态规划比较简单。首先要找到它的状态转移方程：
# **dp[i] = max(dp[i-2]+a[i],dp[i-1])**
# 之后dp数组的最后一个元素就是其最大值
# 时间复杂度是O(n),空间复杂度也是O(n)
```
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        dp = []
        for i in range(len(nums)):
            if i==0:
                dp.append(nums[i])
            elif i == 1:
                if nums[0]<nums[1]:
                    dp.append(nums[1])
                else:
                    dp.append(nums[0])
            else:
                tmp = dp[i-2]+nums[i]
                if tmp>dp[i-1]:
                    dp.append(tmp)
                else:
                    dp.append(dp[i-1])
                
        return dp[len(nums)-1]
```
