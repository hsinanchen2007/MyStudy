```
class Solution:
    def countLetters(self, S: str) -> int:
        p, q = 0, 0
        ans = 0
        while q <= len(S)-1:
            if S[q] == S[p]:
                q += 1
            else:
                n = q - p
                p = q
                ans += self.fun(n)
        return ans + self.fun(q - p)

    def fun(self, n):
        return (n+1) * n // 2
```
