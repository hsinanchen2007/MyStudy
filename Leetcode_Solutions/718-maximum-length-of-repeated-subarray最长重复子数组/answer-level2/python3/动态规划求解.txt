class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        """
           记得还有一题是A字符串如何经过增删改得到B字符串, 应该也是利用类似思路
           
           假设以dp[i][j]定义: 最终的公共子序列以A序列第i个元素结尾以及以B序列第j个元素结尾时
           长度。
           至于转移方程:
           dp[i][j], dp[i-1][j-1],   后续两项用不上(dp[i-1][j], dp[i][j-1])
           if A[i] == B[j]:
              dp[i][j] = dp[i-1][j-1] + 1
           else:
              df[i][j] = 0
           
           还有一个边界问题:
           即i全等于0以及j全等于0的情况
           for j in range(len(B)):
              if B[j] == a[0]:
                 dp[0][j] = 1
              else:
                 dp[0][j] = 0
           for i in range(len(A)):
              if A[i] == B[0]:
                 dp[i][0] = 1
              else:
                 dp[i][0] = 0
        """
        if len(A) == 0 or len(B) == 0:
            return 0
        
        max_length = 0
        dp = [[] for i in range(len(A))]
        for jk in range(len(dp)):
            dp[jk] = [0 for jjj in range(len(B))]
        
        for j in range(len(B)):
            if B[j] == A[0]:
                dp[0][j] = 1
            else:
                dp[0][j] = 0
            max_length = max(max_length, dp[0][j])
        for i in range(len(A)):
            if A[i] == B[0]:
                dp[i][0] = 1
            else:
                dp[i][0] = 0 
            max_length = max(max_length, dp[i][0])
        for ii in range(1, len(A)):
            for jj in range(1, len(B)):
                if A[ii] == B[jj]:
                    dp[ii][jj] = dp[ii-1][jj-1] + 1
                else:
                    dp[ii][jj] = 0
                max_length = max(max_length, dp[ii][jj])
        
        return max_length
        # return dp[len(A)-1][len(B)-1]