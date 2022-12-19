### 解题思路
其实就是动态规划的问题，将dp设为上一层，通过新的ans[i][j]=dp[j-1]+dp[j]就可以算出ans

### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0: return []
        if numRows == 1: return[[1]]

        ans = [[1]*i for i in range(1, numRows+1)]
        for i in range(1, numRows):
            dp = ans[i-1]
            for j in range(1, len(ans[i])-1):
                ans[i][j] = dp[j-1] + dp[j]
        return ans
```