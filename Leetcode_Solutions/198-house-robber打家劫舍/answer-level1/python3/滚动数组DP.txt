

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        # O(N)+O(N) -> O(N)+O(1)
        # dp[i] = max(dp[i-1],dp[i-2]+nums[i]) , i is robbed
        if not nums:return 0
        if len(nums) == 1:return nums[0]
        dp_0,dp_1 = nums[0],max(nums[0],nums[1])
        for i in range(2,len(nums)):
            dp_0,dp_1 = dp_1,max(dp_1,dp_0+nums[i])
        return dp_1
```