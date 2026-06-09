
```
class Solution:
    def intToRoman(self, num: int) -> str:
        nDict = [
            ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX'],
            ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC'],
            ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM'],
            ['', 'M', 'MM', 'MMM']
        ]
        result = ''
        level = 0
        while num > 0:
            idx = num % 10
            result = nDict[level][idx] + result

            num = num // 10
            level +=1

        return result
```
