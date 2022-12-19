### 解题思路
正则表达式
### 代码

```python3
import re
class Solution:
    def isNumber(self, s: str) -> bool:
        if not s:
            return False
        pattern = re.compile(r"^[+-]?(\.?\d+|\d+\.\d*)([eE][+-]?(\d+))?$")
        match = pattern.match(s.strip())
        if match:
            return True
        else:
            return False
```