### 解题思路
动态规划

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        l=len(nums)
        dp=[1 for _ in range (l)]
        if l<2:
            return l
        for i in range(1,l):
            for j in range(i):
                if nums[i]>nums[j]:
                    dp[i]=max(dp[i],dp[j]+1)
        return max(dp)

```