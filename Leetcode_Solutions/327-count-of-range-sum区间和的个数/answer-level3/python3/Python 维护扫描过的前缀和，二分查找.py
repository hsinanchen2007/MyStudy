![image.png](https://pic.leetcode-cn.com/02dc941f861a4c2f302b67a877a24bed7f0a977757724f9c87e21a2d68709666-image.png)


```

'''
有序结构维护扫描过的前缀和，用二分法查找合适的前缀和
'''

from typing import List
from sortedcontainers import SortedList
class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        n = len(nums)
        if n == 0:
            return 0

        dp = [0 for _ in range(n)]
        buf = SortedList()
        dp[0] = nums[0]
        buf.add(dp[0])

        ans = 1 if dp[0] >= lower and dp[0] <= upper else 0
        for i in range(1, n):
            dp[i] = dp[i-1] + nums[i]
            if dp[i] >= lower and dp[i] <= upper:
                ans += 1

            target_low, target_high = dp[i] - upper, dp[i] - lower
            idx1, idx2 = buf.bisect_left(target_low), buf.bisect_right(target_high)
            ans += idx2 - idx1
            buf.add(dp[i])

        return ans
```
