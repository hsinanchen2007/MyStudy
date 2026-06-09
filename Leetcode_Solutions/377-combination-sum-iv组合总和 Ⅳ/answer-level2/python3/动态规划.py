### 思路

* 这道题采用动态规划。
* 声明一个数组 dp ，dp\[i] 表示使用数组 nums 中的数构成新数组，使其和为 i 的新数组的个数；
* 转移方程：dp\[i] = sum(dp\[i-num] for num in nums if i-num>=0),也就是说，为了找到使得和为 i 的所有组合，我们可以在和为 i - j 的组合后面加上一个 j，于是构成和为 i 的组合就有 dp\[i-j]组，此时 j 的取值范围是 num 数组中所有小于 i 的数。
* 我们需要将 dp\[0] 初始化为 1，表示当 i 和 j 相等的时候可以有一种组合方式。
* 结果，dp 数组的最后一个数。

```py
from typing import List


class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        if not nums:
            return 0
        dp = [0 for _ in range(target + 1)]
        dp[0] = 1
        for i in range(1, target + 1):
            dp[i] = sum(dp[i - j] for j in nums if i - j >= 0)

        return dp[-1]
```