### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        dp = [0]*(len(nums)+1)
        for i in range(1,len(nums)+1):
            dp[i]=max(dp[i-2]+nums[i-1],dp[i-1])
        return max(dp)

```