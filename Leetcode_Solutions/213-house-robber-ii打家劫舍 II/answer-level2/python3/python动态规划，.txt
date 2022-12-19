### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        length = len(nums)
        if length == 0:
            return 0
        if length == 1 or length == 2:
            return max(nums)
        dp  = [0 for i in range(length)]
        dp[0] = nums[0]
        dp[1] = max(nums[0:2])
        res = 0
        for i in range(2,length-1):
            dp[i] = max(dp[i-1], dp[i-2]+nums[i])
        res = max(dp)
        dp[0] = 0
        dp[1] = nums[1]
        dp[2] = max(nums[1:3])
        for i in range(3,length):
            dp[i] = max(dp[i-1], dp[i-2]+nums[i])
        return max(res, max(dp))
```