### 解题思路
题友phoenix-13的思路，自己一写，发现如此简单

```python3
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        ind_a = [0]*(n+1)
        ind_b = [0]*(n+1)
        ind_c = [0]*(n+1)
        ans = [0]*(n + 1)

        for i in range(1, n+1):
            ind_a[i] = i if s[i-1] == 'a' else ind_a[i-1]
            ind_b[i] = i if s[i-1] == 'b' else ind_b[i-1]
            ind_c[i] = i if s[i-1] == 'c' else ind_c[i-1]
            ans[i] = min(ind_a[i], ind_b[i], ind_c[i])
        return sum(ans)

```