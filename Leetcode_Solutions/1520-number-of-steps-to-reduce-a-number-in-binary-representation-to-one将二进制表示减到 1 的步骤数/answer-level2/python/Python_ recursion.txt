### 解题思路
简单递归。

### 代码

```python
class Solution:
    def numSteps(self, s: str) -> int:
        if len(set(s)) == 1:
            return 0 if len(s) == 1 else len(s) + 1
        if s[-1] == '0': 
            return self.numSteps(s[:-1]) + 1
        idx = s.rfind('0')
        return self.numSteps(s[:idx] + '1' + s[idx+1:-1]) + 2
```