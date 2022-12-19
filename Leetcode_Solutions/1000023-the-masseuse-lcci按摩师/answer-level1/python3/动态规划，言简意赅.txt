```
from typing import List
class Solution:
    # 思路：动态规划
    # 状态选择：①集合dp[i]：表示只看前i个预约，有多少种组合  ②属性：max
    # 状态计算：dp[i] = max(dp[i-1], dp[i-2]+a[i])
    def massage(self, nums: List[int]) -> int:
        dp = [0 for _ in range(len(nums)+2)]
        for i in range(2, len(dp)):
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-2])

        return dp[-1]
```
