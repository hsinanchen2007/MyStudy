- 注意两种特殊情况：k=4时，dp[10][0] 这种必须在dp[9][0]为真的才可以
- 注意二维数组的初始化  不能 直接[[0]*n]*m 会使得地址相连
```
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def valid(m,n,k):
            if m%10 + m//10 + n%10 + n//10 >k:
                return False
            else:
                return True

        def main(m,n,k):
            res = 0
            dp = [[0 for _ in range(n)] for _ in range(m)]#dp=[[0]*n]*m 这种一次赋值 会同时 赋值 n个 二维初始化 注意
            
            for i in range(0,m):
                for j in range(0,n):
                    if i==0 and j==0:
                        dp[i][j]=1
                        res+=1
                        continue
                    if valid(i,j,k) and ((i==0 and dp[i][j-1] == 1) or (j==0 and dp[i-1][j] == 1) or (dp[i-1][j]+dp[i][j-1]>0)):
                            dp[i][j] = 1
                            res += 1
            return res
        return main(m,n,k)
```
