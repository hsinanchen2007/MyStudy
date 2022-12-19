### 解题思路
主要是要写出dp方程 dp[i] = max(max(i//2,dp[i//2]) * max(i-i//2,dp[i-i//2]),max(i//2-1,dp[i//2 - 1]) * max(i - i//2 + 1,dp[i - i//2 + 1]))，多试几次还是能找到这个规律的

### 代码

```python3
class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [0] * (n + 1)
        for i in range(2,n+1):
            max_num = 0
            for j in range(i//2+1):
                max_num = max(max_num,max(j,dp[j]) * max(i-j,dp[i-j]))
            dp[i] = max_num
        return dp[-1]
    ```

改进后的版本：
```
class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [0] * (n + 1)
        for i in range(2,n+1):
            dp[i] = max(max(i//2,dp[i//2]) * max(i-i//2,dp[i-i//2]),
                        max(i//2-1,dp[i//2 - 1]) * max(i - i//2 + 1,dp[i - i//2 + 1]))
        return dp[-1]
```
