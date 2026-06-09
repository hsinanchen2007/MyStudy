### 解题思路
1. 把所有的数相加
2. 把多加的数去除

### 代码

```python3
class Solution:
    def romanToInt(self, s):
        roman = {'I': 1,
                 'V': 5,
                 'X': 10,
                 'L': 50,
                 'C': 100,
                 'D': 500,
                 'M': 1000}
        roman_no = {'IV': -2,
                    'IX': -2,
                    'XL': -20,
                    'XC': -20,
                    'CD': -200,
                    'CM': -200}
        sum = 0
        for i in s:
            sum += roman[i]
        for k, v in roman_no.items():
            sum += v * s.count(k)
        return sum
```