### 解题思路
动态规化难点在于一子状态，二状态转移方程，关键是在思路这块想到了纯奇纯偶子数组的和，则可以看二楼的解，写得很巧妙，将非奇非偶子数组和整合了起来，如果能按照for循环遍历数组时保存最大利益。动态规划问题的首先看局部，局部如果能达到极值就可以按照路径推
### 代码

```python
class Solution(object):
    def rob(self, nums):
        n=len(nums)
        dp=[0]*(n+2)
        dp[0]=dp[1]=0
        for i in range(2,n+2):
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-2])
        return dp[-1]
```