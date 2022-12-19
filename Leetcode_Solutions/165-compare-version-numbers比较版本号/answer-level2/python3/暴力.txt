### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        a = version1.split('.')
        b = version2.split('.')
        if len(a) > len(b):
            b += ['0'] * (len(a) - len(b))
        elif len(b) > len(a):
            a += ['0'] * (len(b) - len(a))

        i = 0
        while i < len(a) or i < len(b):
            if int(a[i]) > int(b[i]):
                return 1
            elif int(a[i]) < int(b[i]):
                return -1
            else:
                i += 1
        return 0
```