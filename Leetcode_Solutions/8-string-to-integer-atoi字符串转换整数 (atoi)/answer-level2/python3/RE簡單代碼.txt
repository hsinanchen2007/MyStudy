### 解题思路


### 代码

```python3
import re
class Solution:
    def myAtoi(self, s: str) -> int:
        pattern= re.compile(r'^(\s)*([+-]?\d+)')
        aim = pattern.search(s)
        if not aim:
            return 0
        return max(min( int(aim.group(2)),2**31-1),-2**31)

```