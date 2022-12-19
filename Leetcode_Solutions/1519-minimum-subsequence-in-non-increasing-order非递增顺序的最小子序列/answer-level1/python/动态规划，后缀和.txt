## 解题思路

动态规划，从后先前扫描，由于两个人是平等的，所以`dp[i]`表示一个人从i之后的树中，最大能拿到的石子的重量。

同时可以计算一下后缀和，直接得到另一个拿到的石子的重量

时间复杂度`O(n)`  空间复杂度`O(n)`  可以优化到`O(1)` (每个状态只依赖后面三个状态，同时维护几个数记录后缀和即可)

## 代码

```python
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        
        l = len(stoneValue)
        t_s = [0] * (l + 10)
        for i in range(l-1, -1, -1):
            t_s[i] = stoneValue[i] + t_s[i + 1]
        stoneValue.extend([float('-inf')] * 3)
        dp = [0] * (l + 10)
        for i in range(l - 1, -1, -1):
            dp[i] = max(stoneValue[i] + t_s[i + 1] - dp[i + 1], stoneValue[i] + stoneValue[i + 1] + t_s[i + 2] - dp[i + 2], 
                       stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] + t_s[i + 3] - dp[i  + 3])
        if dp[0] > t_s[0] - dp[0]:
            return "Alice"
        elif dp[0] == t_s[0] - dp[0]:
            return "Tie"
        else:
            return "Bob"
```

