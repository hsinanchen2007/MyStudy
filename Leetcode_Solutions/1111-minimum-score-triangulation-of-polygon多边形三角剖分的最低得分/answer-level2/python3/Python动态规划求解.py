由于对一个大凸多边形的三角剖分可以得到的最低分进行分析时需要用到对包含在该多边形中的小凸多边形的三角剖分可以得到的最低分，而一个小凸多边形可能包含在多个大凸多边形中，也就是说该问题可以分解为多个重复的子问题，因此考虑使用动态规划进行求解，dp[i][j]表示子多边形A[i]...A[j]的三角剖分可以得到的最低分 ，先求解小的多边形可以得到的最低分，然后再求解大的多边形可以得到的最低分，最后返回dp[0][n-1]即可。  
### 代码：  
```Python
class Solution:
    def minScoreTriangulation(self, A: List[int]) -> int:
        n = len(A)
        dp = [[float('inf')] * n for _ in range(n)]
        for j in range(n):
            for i in range(j-1,-1,-1):
                if j - i < 2:
                    dp[i][j] = 0
                else:
                    for k in range(i+1,j):
                        dp[i][j] = min(dp[i][j],A[i]*A[j]*A[k]+dp[i][k]+dp[k][j])
        return dp[0][n-1]
```  