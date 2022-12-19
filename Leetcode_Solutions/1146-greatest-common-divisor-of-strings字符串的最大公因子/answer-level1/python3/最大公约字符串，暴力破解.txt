### 解题思路
最大公约字符串，暴力破解

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        m = len(str1)
        n = len(str2)
        for i in range(n,0,-1):
            if n%i == 0:
                if str2[:i]*(n//i) == str2:
                    if str2[:i]*(m//i) == str1:
                        return str2[:i]
        return ''
```