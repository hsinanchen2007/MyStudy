### 解题思路
正则表达式
寻找所有非空子串，然后逆序组合

### 代码

```python3
import re
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(re.findall(r'[\S]+',s)[::-1])
```