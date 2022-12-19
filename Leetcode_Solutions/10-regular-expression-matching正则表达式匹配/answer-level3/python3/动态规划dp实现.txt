主要需要处理 * 多做0个，或 * 当做多个的情况

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p:
            return not s

        nrow = len(s) + 1
        ncol = len(p) + 1

        dp = [[False for c in range(ncol)] for r in range(nrow)]
        dp[0][0] = True
        for j in range(1, ncol):
            dp[0][j] = False
            if j>=2 and p[j-1]=="*" and dp[0][j-2]==True:
                dp[0][j] = True

        for i in range(1, nrow):
            dp[i][0] = False

        for i in range(1, nrow):
            for j in range(1, ncol):
                dp[i][j] = False
                if dp[i-1][j-1] == True and (p[j-1] == "." or s[i-1] == p[j-1]):   #
                    dp[i][j] = True
                    continue
                if j >= 2:
                    if dp[i][j-2] == True and p[j-1] == "*":   # * 当做 0 个
                        dp[i][j] = True
                        continue
                    if dp[i-1][j] == True and p[j-1] == "*" and (s[i-1] == p[j-2] or p[j-2] == "."): # * 当做多个
                        dp[i][j] = True
                        continue
        return dp[nrow-1][ncol-1]
