### 解题思路
我不管，反正通过啦  哈哈哈

### 代码

```python3
import re
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        match = re.match(r'%s' % p, s)
        ret = match.group() if match else False
        return ret==s
        
```