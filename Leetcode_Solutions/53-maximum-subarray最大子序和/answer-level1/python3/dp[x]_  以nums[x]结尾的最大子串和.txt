### 解题思路
dp[x]: 以nums[x]结尾的最大子串和
dp[n] = max(dp[n-1]+nums[n], nums[n])
res = max(dp)
### 代码

```python3
class Solution:
    """
    dp[x] 以nums[x]结尾的最大子串和
    dp[n] = max(dp[n-1]+nums[n], nums[n])
    """
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * n
        dp[0] = nums[0]
        for i in range(1, n):
            dp[i] = max(dp[i-1]+nums[i], nums[i])
        return max(dp)

```