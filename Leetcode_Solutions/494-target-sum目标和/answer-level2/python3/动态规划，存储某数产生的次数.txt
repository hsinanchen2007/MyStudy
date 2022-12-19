使用 `dp[i][j]` 存储到达下标 `i` 位置所能产生的数字 `j` 的个数。

因为符号要么全正，要么全负，所以 `j` 的取值范围是 `-sum(nums) ~ sum(nums)`。

状态转移公式：

```
dp[i][j] = dp[i - 1][j + nums[i]] + dp[i - 1][j - nums[i]]
```

```python
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        if len(nums) == 0:
            return 0
        s = sum(nums)
        length = len(nums)
        dp = [dict() for _ in range(length)]
        if nums[0] == 0:
            dp[0][nums[0]] = 2
        else:
            dp[0][nums[0]] = 1
            dp[0][-nums[0]] = 1
        for i in range(1, length):
            for j in range(-s, s + 1):
                dp[i][j] = dp[i - 1].get(j - nums[i], 0) + dp[i - 1].get(j + nums[i], 0)
                
        return dp[length - 1].get(S, 0)
```

**复杂度**：

- 时间复杂度：`O(n * sum)`
- 空间复杂度：`O(n * sum)`