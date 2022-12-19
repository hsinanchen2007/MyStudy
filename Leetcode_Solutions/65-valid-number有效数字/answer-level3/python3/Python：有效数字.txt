### 解题思路
正则

### 代码

```python3
import re
class Solution:
    def isNumber(self, s: str) -> bool:
        return bool(re.match(r'\s*[+-]?([\d]+(\.[\d]*)?|\.[\d]+)(e[+-]?[\d]+)? *$', s))
```