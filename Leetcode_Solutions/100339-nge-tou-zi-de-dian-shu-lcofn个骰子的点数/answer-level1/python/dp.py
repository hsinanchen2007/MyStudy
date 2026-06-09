### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def twoSum(self, n: int) -> List[float]:
        dp = [[0]*(6*n+1) for _ in range(n+1)]
        for i in range(1,7):dp[1][i] = 1
        for i in range(2,n+1):
            for j in range(i,6*i+1):
                for k in range(1,7):
                    if j - k >= i - 1 and j-k<=(i-1)*6:
                        dp[i][j] += dp[i-1][j-k]
        ans = dp[n][n:]
        ans = list(map(lambda x:x/6**n,ans))
        return ans

```