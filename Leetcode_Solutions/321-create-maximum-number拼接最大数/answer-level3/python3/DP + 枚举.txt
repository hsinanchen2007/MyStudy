1. 能直接想到的 DP 状态 f[i][j][k] 使用 a 的前 i 个，b 的前 j 个构造 k 位最大数，其复杂度为 O(mnk)， 超时；
2. 而发现如果只有一个数组 a，那么复杂度是 O(mk)，而最终答案可以由两个数组的解枚举得到，枚举的复杂度 O(k^2)， 总复杂度 O((m+n+k)k)， 通过

```python []
class Solution:
    def maxNumber(self, a: List[int], b: List[int], c: int) -> List[int]:
        m, n = len(a), len(b)
        from collections import defaultdict as dd
        f = dd(lambda:dd(int))
        g = dd(lambda:dd(int))
        
        def dp(a, f, m):
            f[0][1] = a[0]
            for i in range(1, m):
                for j in range(1, min(c+1, i+2)):
                    f[i][j] = max(f[i-1][j], f[i-1][j-1]*10 + a[i])
        
        if m: dp(a, f, m)
        if n: dp(b, g, n)

        def deal(x, y):
            x = list(str(x)) if x else []
            y = list(str(y)) if y else []
            m, n = len(x), len(y)
            if m+n!=c: return 0
            i, j, ret = 0, 0, ''

            def yes(l, r):
                if l<m and r<n and x[l]==y[r]: return yes(l+1, r+1)
                return (l>=m and r>=n) or (r>=n) or(l<m and x[l]>y[r])

            while i<m or j<n:
                if j>=n or (i<m and (x[i]>y[j] or x[i]==y[j] and yes(i,j))):
                    ret += x[i]
                    i += 1
                else:
                    ret += y[j]
                    j += 1
            return int(ret)
        
        return list(str(max([deal(f[m-1][i], g[n-1][c-i]) for i in range(min(m,c)+1)])))
```
