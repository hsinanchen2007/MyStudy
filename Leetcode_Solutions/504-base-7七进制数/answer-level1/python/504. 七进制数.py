### 解题思路

### 代码

```python3
class Solution:
    def convertToBase7(self, num: int) -> str:
        res = ''
        s = num
        num = abs(num)
        while num:
            res = str(num%7) + res
            num = num // 7
        if s < 0:
            res = '-' + res
        return res if s != 0 else '0'

```