### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle:
            return 0

        lenth = len(triangle)
        if lenth == 1:
            return triangle[0][0]

        dp = [[0]*lenth for _ in range(lenth)]
        dp[0][0] = triangle[0][0]

        for i in range(1,lenth):
            for j in range(i+1):
                if j == 0:
                    dp[i][j] = dp[i-1][0]+triangle[i][j]
                elif j == len(triangle[i])-1:
                    dp[i][j] = dp[i-1][j-1]+triangle[i][j]
                else:
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j]
        ans = dp[lenth-1][0] 
        for k in range(lenth):
            ans = min(ans,dp[lenth-1][k])
        return ans

```