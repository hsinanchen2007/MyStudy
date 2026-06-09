```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        res = False
        visited = set()

        def back_tracking(i: int, j: int) -> None:
            nonlocal res
            if i == len(s) and j == len(p):
                res = True
                return
            if res or (i, j) in visited or j == len(p): return
            visited.add((i, j))
            if i < len(s) and (s[i] == p[j] or p[j] == '?'):
                back_tracking(i + 1, j + 1)
            elif p[j] == '*':
                back_tracking(i, j + 1)
                if i < len(s):
                    back_tracking(i + 1, j + 1)
                    back_tracking(i + 1, j)

        back_tracking(0, 0)
        return res

    def isMatch1(self, s: str, p: str) -> bool:
        s_len, p_len = len(s), len(p)
        dp = [[0] * (p_len + 1) for _ in range(s_len + 1)]
        dp[0][0] = 1
        for i in range(1, p_len + 1):
            if p[i - 1] == '*':
                dp[0][i] = 1
            else:
                break
        for i in range(1, s_len + 1):
            for j in range(1, p_len + 1):
                if (dp[i - 1][j] or dp[i][j - 1]) and p[j - 1] == '*':
                    dp[i][j] = 1
                elif dp[i - 1][j - 1] and (s[i - 1] == p[j - 1] or p[j - 1] == '?'):
                    dp[i][j] = 1
        return dp[-1][-1] == 1

    def isMatch2(self, s: str, p: str) -> bool:
        s_len, p_len = len(s), len(p)
        dp = [0] * (p_len + 1)
        dp[0] = 1
        for i in range(1, p_len + 1):
            if p[i - 1] == '*':
                dp[i] = 1
            else:
                break
        for i in range(1, s_len + 1):
            left_upper, dp[0] = dp[0], 0
            for j in range(1, p_len + 1):
                tmp = dp[j]
                if (dp[j] or dp[j - 1]) and p[j - 1] == '*':
                    dp[j] = 1
                elif left_upper and (s[i - 1] == p[j - 1] or p[j - 1] == '?'):
                    dp[j] = 1
                else:
                    dp[j] = 0
                left_upper = tmp
        return dp[-1] == 1
```