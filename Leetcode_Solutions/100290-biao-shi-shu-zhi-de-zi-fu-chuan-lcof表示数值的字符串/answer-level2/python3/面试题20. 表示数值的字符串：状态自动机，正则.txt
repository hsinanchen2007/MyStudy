### 状态自动机

```python []
class Solution:
    def isNumber(self, s: str) -> bool:
        S = [
            {'b': 0, 's': 1, 'd': 2, '.': 4},
            {'d': 2, '.': 4},
            {'d': 2, '.': 3, 'e': 5, 'b': 8},
            {'d': 3, 'e': 5, 'b': 8},
            {'d': 3},
            {'s': 6, 'd': 7},
            {'d': 7},
            {'d': 7, 'b': 8},
            {'b': 8}
        ]
        t = {'0': 'd', '1': 'd', '2': 'd', '3': 'd', '4': 'd',
             '5': 'd', '6': 'd', '7': 'd', '8': 'd', '9': 'd',
             ' ': 'b', '.': '.', 'e': 'e', '+': 's', '-': 's'}
        p = 0
        for c in s:
            if t.get(c, '') not in S[p]:
                return False
            p = S[p][t[c]]
        return p in {2, 3, 7, 8}
```

### 正则

```python []
class Solution:
    def isNumber(self, s: str) -> bool:
        return re.match(" *[+-]?((\d+(\.\d*)?)|\.\d+)([e][+-]?\d+)? *$", s)
```