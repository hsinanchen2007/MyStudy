# 题解
## 动态规划

$dp[i]$表示到第$i$个房屋的偷窃最高金额。
显然，递推公式为：$dp[i]=max(dp[i-2]+nums[i-1],dp[i-1])$。
含义为，当前房屋的最高金额为前前个房屋的最高金额加上当前房屋的财富和上一个房屋的最高偷窃金额中的最大值。

 1. 特判，若数组为空，返回$0$
 2. 初始化$dp=[0,\cdots,0]$为$n+1$的全零数组。
 3. 初始化第一个房屋的最高偷窃金额：$dp[1]=nums[0]$
 4. 遍历$dp$，遍历区间$[2,n+1)$：
 	+ $dp[i]=max(dp[i-2]+nums[i-1],dp[i-1])$
 
 5. 返回$dp[n]$

                                                                                                                                             
### 复杂度分析
 - 时间复杂度：$O(n)$
 - 空间复杂度：$O(n)$

### Python
```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        if(not nums):
            return 0
        n=len(nums)
        dp=[0]*(n+1)
        dp[1]=nums[0]
        for i in range(2,n+1):
            dp[i]=max(dp[i-2]+nums[i-1],dp[i-1])
        return dp[-1]
```