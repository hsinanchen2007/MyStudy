```
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        """
           典型的背包问题.
        """
#         # 1. O(N*m*n)的空间复杂度 
#         dp = []
#         for i in range(len(strs)+1):
#             dp.append([[0 for k in range(n+1)] for j in range(m+1)])

#         for i in range(1, len(strs)+1):
#             count_0 = strs[i-1].count('0')
#             count_1 = strs[i-1].count('1')
#             for j in range(m+1):
#                 for k in range(n+1):
#                     if j >= count_0 and k >= count_1:
#                         dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-count_0][k-count_1] + 1)
#                     else:
#                         # 不满足匹配当前的单词, 那么当前单词不可能被匹配，说明和第i-1代的值相等
#                         dp[i][j][k] = dp[i-1][j][k]

#         return dp[-1][-1][-1]
            
        # 2. O(m*n)的空间复杂度
        dp = [[0 for j in range(n+1)] for i in range(m+1)]
        for str_i in strs:
            count_0 = str_i.count('0')
            count_1 = str_i.count('1')
            for i in range(m, -1, -1):
                for j in range(n, -1, -1):
                    if i >= count_0 and j >= count_1:
                        dp[i][j] = max(dp[i][j], dp[i - count_0][j - count_1] + 1)

        return dp[-1][-1]
            
```
