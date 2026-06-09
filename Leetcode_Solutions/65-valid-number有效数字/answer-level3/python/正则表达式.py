![image.png](https://pic.leetcode-cn.com/7856ef46fc53d2fc7bb69d2418f463ea9fddbdd654adad0a933ccd3f430bd8de-image.png)

### 解题思路
正则表达式

### 代码

```python3
import re

class Solution:
    def isNumber(self, s: str) -> bool:
        return bool(re.match(r' *[+-]?([0-9]+(\.[0-9]*)?|\.[0-9]+)(e[+-]?[0-9]+)? *$', s))
```