### 解题思路
打家劫舍1只有两个状态：dp[房间编号][是否打劫]
这道题在1的基础上添加了一个状态：dp[房间编号][第一间房是否打结][当前房是否打结]
套用动态规划的base case + iteration框架即可

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) <= 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums[0], nums[1])
        else:
            dp = [[[None, None], [None, None]] for i in range(len(nums))]
            # base case
            inf = 999999999999999999999999999999999999
            dp[1] = [[0, nums[1]], [nums[0], -inf]]
            # iteration
            for i in range(2, len(nums)-1):
                dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][0][1])
                dp[i][1][0] = max(dp[i-1][1][1], dp[i-1][1][0])
                dp[i][0][1] = dp[i-1][0][0] + nums[i]
                dp[i][1][1] = dp[i-1][1][0] + nums[i]
            dp[-1][0][0] = max(dp[-1-1][0][0], dp[-1-1][0][1])
            dp[-1][1][0] = max(dp[-1-1][1][1], dp[-1-1][1][0])
            dp[-1][0][1] = dp[-1-1][0][0] + nums[-1]
            dp[-1][1][1] = -inf
            return max(max(dp[-1][0]), max(dp[-1][1]))
```