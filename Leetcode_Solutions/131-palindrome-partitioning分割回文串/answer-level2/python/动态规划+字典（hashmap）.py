```python []
class Solution:
    def partition(self, s: str):
        # 动态规划
        # dp[i][j]表示第i到第j个字符是否是回文串

        if len(s) == 0:
            return []

        hashmap = {}
        dp = [[False] * len(s) for _ in range(len(s))]

        for end in range(len(s)):
            r = []
            for start in range(end, -1, -1):
                if s[start] == s[end] and (end - start <= 2 or dp[start + 1][end - 1]):
                    dp[start][end] = True
                    if start == 0:
                        r.append([s[start:end + 1]])
                    else:
                        # 如果s[start:end + 1]是回文子串，那么s[:end + 1]的分割形式可以是s[:start]的分割形式+s[start:end + 1]
                        # hashmap[s[:start]]就保存着s[:start]的分割形式
                        for temp in hashmap[s[:start]]:
                            r.append(temp + [s[start:end + 1]])
            hashmap[s[:end + 1]] = r
        return hashmap[s]
```
