递归关系式：如果说我现在在第3行

那么第3行有就3列
 
我取第一个数获得的最小路径 = 取第2行第一个数的最小路径 + 第3行第一个数
取最后一个数同理。

取中间的数的最小路径 = min (取第2行第一个数的最小路径，取第2行第二个数的最小路径) +第3行这个数。




```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        if n==0:
            return 0
        
        # dp = [[0 ]*i for i in range(1,n+1)]
        dp = [0 for i in range(n)]
        dp[0]=triangle[0][0]
        for i in range(1,n):
          
            for j in range(i,-1,-1):
                
                if j==0:
                    dp[j]=dp[j]+triangle[i][j]
                if j==i:
                    dp[j]=dp[j-1]+triangle[i][j]
                if 0<j<i:
                    dp[j]=min(dp[j],dp[j-1])+triangle[i][j]
            # print(dp)
        return min(dp)
```
