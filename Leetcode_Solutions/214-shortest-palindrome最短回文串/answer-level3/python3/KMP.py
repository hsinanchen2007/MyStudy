KMP算法比较逆序串后缀和正序串前缀最大重合子串
```python []
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        n = len(s)
        if n == 0: return ''
        if n == 1: return s
        if n == 2: return s if s[0] == s[1] else s[1] + s
        '''
        idx = 0
        for i in range(1, n + 1):
            if s[0 : i] == s[::-1][n - i : n]: idx = i
        return s[::-1] + s[idx : n]
        '''
        #s_r = s[::-1]
        s_new = s + '#' + s[::-1]
        n_new = len(s_new)
        f = [0 for _ in range(n_new)]
        for i in range(1, n_new):
            t = f[i - 1]
            while t > 0 and s_new[i] != s_new[t]: t = f[t - 1]
            if s_new[i] == s_new[t]: t += 1
            f[i] = t
        return s[::-1][0 :  n - f[n_new - 1]] + s
```

