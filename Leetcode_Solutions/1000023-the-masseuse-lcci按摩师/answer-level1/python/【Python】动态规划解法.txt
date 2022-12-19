### 解题思路
这道题和打家劫舍一模一样，简单说的话，dp[i]定义为第i天的按摩时间总长，可以有两种情况，（1）今天不接受预约，那么时长就按照前一天的算（2）今天接受预约，那么昨天肯定是没有接受预约的，就加上大前天的总时长

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) < 3:
            return max(nums)
        dp = [0] * len(nums)
        dp[0] = nums[0] 
        dp[1] = max(nums[0], nums[1])
        for i in range(2, len(nums)):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        return dp[-1]
```