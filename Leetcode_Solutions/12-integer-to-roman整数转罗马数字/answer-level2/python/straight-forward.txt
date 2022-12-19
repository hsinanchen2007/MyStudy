### 解题思路
A quit straight-forward solution.

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        d1 = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
        d2 = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
        d3 = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
        d4 = ['', 'M', 'MM', 'MMM']
        d = [d1, d2, d3, d4]

        r = ''    # result
        i = 0
        while num:
            num, idx = divmod(num, 10)
            r = d[i][idx] + r
            i += 1

        return r
```