执行用时 : 36 ms, 在House Robber的Python3提交中击败了99.77% 的用户

内存消耗 : 13 MB, 在House Robber的Python3提交中击败了96.17% 的用户

### 动态规划

当前最大的累计收益= max(前一家的收益，前前一家的收益加上当前的收益)

状态转移方程： dp[i] = max(dp[i-1], dp[i-2]+nums[i])

代码如下：
```
class Solution:
    # dp[i] = max(dp[i-1],dp[i-2]+nums[i])
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n==0:
            return 0
        if n==1:
            return nums[0]
        p = nums[0]
        q = max(nums[0],nums[1])
        
        
        for i in range(2,n):
            next_ = max(p+nums[i],q)
            p,q = q, next_
            
        return q
```