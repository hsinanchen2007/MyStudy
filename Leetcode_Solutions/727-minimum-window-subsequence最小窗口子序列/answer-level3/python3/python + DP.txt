```python
class Solution:
    def minWindow(self, S: str, T: str) -> str:
        # T = 'bdd'
        # S = 'abcdebdde'
        # dp[0] = [-1, 1, -1, -1, -1, 5, -1, -1, -1]
        # dp[1] = [-1, -1, -1, -1, 1, -1, 5, 5, -1]
        # dp[2] = [-1, -1, -1, -1, -1, -1, 1, 5, 1]

        # Time complexity: O(MN)
        # Space complexity: O(MN)

        if len(T) > len(S): return ""
        dp = [[-1] * len(S) for _ in range(len(T))]
        for i in range(len(T)):
            pre = -1
            for j in range(len(S)):
                if i == 0:
                    if S[j] == T[i]:
                        dp[i][j] = j
                    continue
                if S[j] == T[i]:
                    dp[i][j] = pre
                if dp[i - 1][j] != -1:
                    pre = dp[i - 1][j]
        res = ''
        for j in range(len(S)):
            if dp[-1][j] != -1:
                sub_str = S[dp[-1][j]: j + 1]
                if len(sub_str) < len(res) or res == '':
                    res = sub_str
        return res
```