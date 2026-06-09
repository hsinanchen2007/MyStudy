![image.png](https://pic.leetcode-cn.com/a05b247a94a98ab5b36b07c64ee4ea8c55d640c9a7e9d32ff579015344f3b1cd-image.png)
```python []
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        ans, p, q, d = 0, 0, 1j, {complex(*w) for w in obstacles}
        for c in commands:
            if c == -2:
                q *= 1j
            elif c == -1:
                q /= 1j
            else:
                for t in range(c):
                    if p + q in d:
                        break
                    p += q
                    ans = max(ans, round(abs(p) ** 2))
        return ans
```
