### 解题思路
正则表达式
其实就是寻找非空字符串的数量

### 代码

```python3
import re
class Solution:
    def countSegments(self, s: str) -> int:
        return len(re.findall(r'[\S]+',s))
```