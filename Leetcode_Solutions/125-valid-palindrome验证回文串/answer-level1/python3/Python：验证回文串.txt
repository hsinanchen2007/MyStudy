### 解题思路
有字符串，优先正则解决，权当是学习的一种

### 代码

```python3
import re
class Solution:
    def isPalindrome(self, s: str) -> bool:
        p=''.join(re.findall(r'[\w\d]+',s))
        p=p.lower()
        return True if p==p[::-1] else False
```