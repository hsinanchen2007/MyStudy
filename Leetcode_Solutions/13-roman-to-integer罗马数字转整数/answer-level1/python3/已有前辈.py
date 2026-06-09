### 解题思路
判断如果左边大于等于右边则加否则减
### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        dict_roman = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }
        a = 0
        n = 0
        for i in reversed(s):
            x = dict_roman[i]
            if x >= a:
                a = x
                n += x
            else:
                n -= x
        return n
```