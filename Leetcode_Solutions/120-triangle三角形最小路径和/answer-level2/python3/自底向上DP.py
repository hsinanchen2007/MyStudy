### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = [[float('inf') for _ in range(len(triangle[-1]))] for i in range(len(triangle))]
        for i in range(len(triangle[-1])):
            dp[-1][i]=triangle[-1][i]
        for i in range(len(triangle)-2,-1,-1):
            for j in range(len(triangle[i])):
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1])
        
        return min(dp[0])
```