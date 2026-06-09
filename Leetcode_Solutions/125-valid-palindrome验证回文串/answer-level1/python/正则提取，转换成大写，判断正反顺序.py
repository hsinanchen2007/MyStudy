### 解题思路
正则提取，转换成大写，判断正反顺序

### 代码

```python3
import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join(re.findall("[0-9a-zA-Z]+", s)).upper()
        if s == s[::-1]:
            return True
        else:
            return False
```