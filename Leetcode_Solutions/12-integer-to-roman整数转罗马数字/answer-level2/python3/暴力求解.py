### 解题思路
暴力求解

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:

        n = [0] * 13
        res = ""
        value = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        char = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        
        for i in range(13):
            n[i] = num // value[i]
            num = num % value[i]
            res = res + (char[i]*n[i])

        return res
```