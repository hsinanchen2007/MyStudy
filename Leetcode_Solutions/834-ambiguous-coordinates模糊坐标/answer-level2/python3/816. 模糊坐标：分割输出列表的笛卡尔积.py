![image.png](https://pic.leetcode-cn.com/f667f94bbdbed9427be994f071ff5e6fb45099f34f751b41d48772018ca7958f-image.png)

```python []
class Solution:
    def ambiguousCoordinates(self, S: str) -> List[str]:
        def f(s):
            if not s or len(s) > 1 and s[0] == s[-1] == '0':
                return []
            if len(s) > 1:
                if s[0] == '0':
                    return [s[0] + '.' + s[1: ]]
                if s[-1] == '0':
                    return [s]
            return [s] + [s[: i] + '.' + s[i: ] for i in range(1, len(s))]
        S = S[1: -1]
        return ['(%s, %s)'%(x, y) for i in range(1, len(S)) for x, y in itertools.product(f(S[: i]), f(S[i: ]))]
```
