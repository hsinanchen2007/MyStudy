

自下向顶构造 DP矩阵：
```
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        # 一共要向右走 n-1 步，向下走 m-1 步
        # DP[m,n] = DP[m,n-1](向右走) + DP[m-1,n](向下走)
        if m==1 or n==1: return 1
        DP = [ [None] * (n+1) for i in range(m+1)]
        for i in range(1,n+1):
            DP[1][i] = 1
        for j in range(1,m+1):
            DP[j][1]= 1
        
        # Bottom-up approach
        for i in range(2,m+1):
            for j in range(2,n+1):
                DP[i][j] = DP[i-1][j] + DP[i][j-1]
        return DP[m][n]

```



自顶向下 Recursion版本：
```
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        # 一共要向右走 n-1 步，向下走 m-1 步
        # DP[m,n] = DP[m,n-1](向右走) + DP[m-1,n](向下走)
        if m==1 or n==1: return 1
        DP = [ [None] * (n+1) for i in range(m+1)]
        for i in range(1,n+1):
            DP[1][i] = 1
        for j in range(1,m+1):
            DP[j][1]= 1
        
        # Bottom-up approach
        for i in range(2,m+1):
            for j in range(2,n+1):
                DP[i][j] = DP[i-1][j] + DP[i][j-1]
        return DP[m][n]
```

