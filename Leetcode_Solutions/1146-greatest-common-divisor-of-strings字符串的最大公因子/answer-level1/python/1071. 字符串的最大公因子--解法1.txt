### 解题思路


### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        lenc = min(len(str1), len(str2))
        for i in range(lenc,0,-1):
            if len(str1) % i == 0 and len(str2) % i == 0:
                if str1[:i] * int(len(str1)//i) == str1 and str1[:i] * int(len(str2)//i) == str2:
                    return str1[:i]
        return ''
```