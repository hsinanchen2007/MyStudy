首先要推导最优子结构：

我们使用变量 `dp[i]` 保存截止到前 `i` 个房间能够获得的最大金额。

在计算 `dp[i]` 的过程中，有如下两种情况：

1. 如果不打劫第 `i` 个房间，那么获得的金额等于 `dp[i-1]`。
2. 如果打劫第 `i` 个房间，就得舍弃第 `i-1` 个房间，获得的最大金额为 `dp[i-2] + nums[i]`。

所以有：

`dp[i] = max(dp[i-1], dp[i-2] + sums[i])`

上述推导为了方便理解把 `dp` 写成了数组的形式，但在实际解题过程中，我们并不需要保存整个 `dp` 数组，只需要保存其最近的两个元素即可（类似于斐波那契数列），这样可以把空间复杂度压缩到 O(1)。

具体代码如下：

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums: return 0
        if len(nums) == 1: return nums[0]
        pprev = nums[0]
        prev = max(nums[0], nums[1])
        for i in range(2, len(nums)):
            pprev, prev = prev, max(pprev + nums[i], prev)
        return prev
```
