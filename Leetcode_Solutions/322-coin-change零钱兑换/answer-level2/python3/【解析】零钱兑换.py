### 解题思路
一开始想到用贪心做，但是一直考虑得不全面，试了解析里的方法也通不过（是我太菜了），就学了这个DP的方法。
这是一个自底向上的DP。dp[i]代表金额为i时所需的硬币枚数，金额为0时硬币枚数为0。
接着，dp[i] = min(dp[i - coins[j]]) + 1，即金额为i时所需的硬币枚数为金额为0~i-1时所需的硬币枚数+1的最小值。
如此遍历，最后返回dp[-1]即可得到答案。

### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # dp[i] = min(dp[i-coins[j]])

        dp = [float("inf")] * (amount+1)
        dp[0] = 0
        for i in range(1, amount+1):
            dp[i] = min(dp[i-c] if i-c >= 0 else float("inf") for c in coins) + 1
        return dp[-1] if dp[-1] != float("inf") else -1
        
```