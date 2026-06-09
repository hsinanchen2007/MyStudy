### 代码

```python3
class Solution:
    def translateNum(self, num: int) -> int:
        s = str(num)
        n = len(s) - 1

        def helper(i):
            nonlocal s, n
            if i >= n:
                return 1
            prefix = int(s[i]) * 10 + int(s[i + 1])
            if prefix >= 10 and prefix <= 25:
                return helper(i + 1) + helper(i + 2)
            else:
                return helper(i + 1)
        return helper(0)
```