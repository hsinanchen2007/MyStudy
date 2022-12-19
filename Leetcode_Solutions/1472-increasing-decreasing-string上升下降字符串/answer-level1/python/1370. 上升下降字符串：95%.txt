![image.png](https://pic.leetcode-cn.com/085437a532bf07e8adf981a3da367f0fd862abd0e91dcf4918f20136f2437d1d-image.png)

涉及到了字典操作就没有用Counter。

```python []
class Solution:
    def sortString(self, s: str) -> str:
        ab = 'abcdefghijklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba'
        d = collections.defaultdict(int)
        for c in s:
            d[c] += 1
        ans = ''
        while d:
            for c in ab:
                if c in d:
                    ans += c
                    d[c] -= 1
                    if not d[c]:
                        del d[c]
        return ans
```