### 解题思路

有点麻烦，但是结果还行。

### 代码

```python3
class Solution:
    def strToInt(self, str: str) -> int:
        str = str.strip(' ')
        if not str: return 0
        is_positive = 1
        if str[0] == '-':
            is_positive = -1
            str = str[1:]
        elif str[0] == '+':
            str = str[1:]
        if not str or str[0] < '0' or str[0] > '9':
            return 0
        for i in range(0, len(str)):
            if str[i] < '0' or str[i] > '9':
                str = str[0:i]
                break
        res = min(int(str), 2 ** 31) * is_positive 
        if res >= 2**31:
            return res - 1
        return res
```