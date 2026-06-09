### 解题思路
此处撰写解题思路

### 代码

```python3
"""方法三：动态规划 + 空间优化  时间复杂度：O(N^2); 空间复杂度：O(N)
对于方法二中动态规划的状态转移方程，我们发现 dp(i, j) 只和 dp(i+1, j) 和 dp(i, j-1) 有关，即在计算第 i 行的 dp 值时，只有该行与第 i + 1 行是有用的，意思其实是说一行只取一个数，而不是一行需要取不同列上的不同数。因此我们可以将空间优化至一维。"""
class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        lens = len(nums)
        dp = [0 for _ in range(lens)]
        for row in range(lens-1, -1, -1):
            dp[row] = nums[row]
            for col in range(row+1, lens):
                dp[col] = max(nums[row]-dp[col], nums[col]-dp[col-1])
        return dp[lens-1] >= 0
```