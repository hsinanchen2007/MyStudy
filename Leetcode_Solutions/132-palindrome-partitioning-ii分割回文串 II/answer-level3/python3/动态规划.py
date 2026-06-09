
dp[i][0] 表示以i为结尾的最长回文串的长度。
dp[i][1] = k 表示前i个字符最少需要划分k次才能确保所有的子串为回文串。
dp[i][2] = m 经过k次划分，以第i字符为结尾的回文串的长度。
f[i][j] 表示s[i ... j]是否为回文串
最终结果为dp[-1][-2]

递推公式:
    三种情况:
        pre = i - dp[i][0]        
        case 1: dp[i][1] = dp[i-1][1] + 1 直接在i处进行划分。
        case 2: dp[i-1][1] = dp[pre][1] + 1 s[pre+1:i+1]为回文串，直接在pre+1处划分。
        case 3: dp[i][1] = dp[i-1][1] 能够与前面的子串构成回文串
```
class Solution:
    def minCut(self, s):
        """
        dp[i][0] 表示以i为结尾的最长回文串的长度。
        dp[i][1] = k 表示前i个字符最少需要划分k次才能确保所有的子串为回文串。
        dp[i][2] = m 经过k次划分，以第i字符为结尾的回文串的长度。
        f[i][j] 表示s[i ... j]是否为回文串
        最终结果为dp[-1][-2]
        """
        l = len(s)
        dp = [[1,0,1] for _ in range(l+1)]
        f = [[0 for _ in range(l+1)] for _ in range(l+1)]
        f[0][0] = 1
        for right in range(1,l):
            f[right][right] = 1
            k = 1
            for left in range(0,right):
                if (left+1 >= right-1 or f[left+1][right-1] == 1) and s[left] == s[right]:
                    f[left][right] = 1
                    k = max(right-left+1,k)
            dp[right][0] = k
        for i in range(1,l):
            pre = i - dp[i][0]
            if pre < 0:
                dp[i][1] = 0
                dp[i][2] = dp[i][0]
            else:
                # case 1 和case 2 
                # dp[i][1] = dp[i-1][1] + 1 在i处划分,dp[i][1] = dp[pre][1]跟前面组合起来形成回文串
                dp[i][1] = min(dp[i-1][1] + 1,dp[pre][1] + 1)
                dp[i][2] = 1 if dp[i-1][1] < dp[pre][1] else dp[i][0]
                
                # case 3 
                if dp[i][1] > dp[i-1][1] and (f[i-dp[i-1][2]][i] == 1):
                    dp[i][1] = dp[i-1][1]
                    dp[i][2] = dp[i-1][2] + 1
#         print(dp)
#         for i in range(len(dp)-1):
#             print(s[i],dp[i])
#         print(dp[-2][-2])
        return dp[-2][-2]
```
