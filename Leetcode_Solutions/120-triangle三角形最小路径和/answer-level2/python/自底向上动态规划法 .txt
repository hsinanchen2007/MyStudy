### 解题思路
此处撰写解题思路
dp[i][j]:表示从开始到第i行，第j列最短 路径之和路径
重叠子问题：
     dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j]
### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        len_triangle = len(triangle)
        dp = [[0 for _ in range(i+1)] for i in range(len_triangle)]
        
        dp[0][0] = triangle[0][0]
        for i in range(1,len_triangle):
            for j in range(i+1):
                if j-1 < 0:
                    dp[i][j] = dp[i-1][j] + triangle[i][j]
                elif i-1 < j:
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j]
                else:
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) +  triangle[i][j]
        return min(dp[len_triangle-1])
        
        

            

        

```