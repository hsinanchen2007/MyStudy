### 解题思路
借着题目学习正则表达式

### 代码

```python3
import re
class Solution:
    def myAtoi(self, str: str) -> int:
        matchObj=re.match(r'\s*([\+\-]?)([\d]+)',str)
        if matchObj==None:
            return 0
        else:
            num=int(matchObj.group(2))
            if matchObj.group(1)=='-':
                return 0-num if num<2147483649 else -2147483648
            else:
                return num if num<2147483648 else 2147483647
```

学习大佬的代码
```python3
class Solution:
    def myAtoi(self, s: str) -> int:
        return max(min(int(*re.findall('^[\+\-]?\d+', s.lstrip())), 2**31 - 1), -2**31)
```