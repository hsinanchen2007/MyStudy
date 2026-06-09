### 解题思路
直接用正则就很简单

### 代码

```python3
import re
class Solution:
    def myAtoi(self, str: str) -> int:
        s=str.lstrip()
        r=re.match('[+-]?\d+',s)
        if not r:
            return 0
        res=int(r.group())
        if res<-2**31:
            return -2**31
        if res>2**31-1:
            return 2**31-1
        return res

```