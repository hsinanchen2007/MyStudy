执行用时:20ms,在所有Python提交中击败了83.96%的用户
内存消耗:11.7MB,在所有Python提交中击败了36.79%的用户

    def uniquePaths(self, m, n):
      dp=[[0]*n for i in range(m)]
      dp[0]=[1]*n
      for i in range(m):
          dp[i][0]=1
      for i in range(1,m):
          for j in range(1,n):
              dp[i][j]=dp[i-1][j]+dp[i][j-1]
      return dp[-1][-1]