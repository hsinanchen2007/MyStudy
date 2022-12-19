### 解题思路

区间DP 按照区间最后一个被扎破的气球对问题划分，找到所有可能中的最大的即可。

递推方程 : $dp[i][j] = max_{k = i}^{j} dp[i][k-1] + dp[k+1][j] + nums[k] * numds[i-1] * nums[j + 1]$

时间复杂度$O(n ^ 3)$
空间复杂度$O(n ^ 2)$

### 代码

```python3
class Solution:
    def maxCoins(self, nums) -> int:
        # 按照第一个扎破的气球分类发现不能把问题转为子问题
        # 按照最后一个被扎破的气球，发现这个气球将左右两侧划分为了不可能相遇的两个区间
        # 所以就可以使用dp求解
        # 区间dp
        l = len(nums)
        nums = [1] + nums + [1]
        dp = [[0] * (l + 2) for _ in range(l + 2)]
        for i in range(1, l + 1):
            dp[i][i] = nums[i] * nums[i  - 1] * nums[i + 1]
        for _len in range(2, l + 1):
            for i in range(1, l - _len + 2):
                dp[i][i + _len - 1] = float('-inf')
                for j in range(i, i + _len):
                    dp[i][i + _len - 1] = max(dp[i][i + _len - 1], dp[i][j -1] + dp[j + 1][i + _len - 1] + nums[j] * nums[i- 1] * nums[i + _len])
        return dp[1][l]
```