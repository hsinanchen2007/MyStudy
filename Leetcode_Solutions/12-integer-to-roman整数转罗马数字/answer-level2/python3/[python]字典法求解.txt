1. 用字典建立基础数值（1，4，5，9，10，40，50，90，100，400，500，900，1000）与字符间的映射关系，将6种特殊情况也包括在内
2. 将num转化成基础数值表示形式，例如58=1*50+1*5+3*1， 1994=1×1000+1×900+1×90+1×4
3. 根据拆解后的基础数值表示形式的系数和值，利用字典转化成字符

代码：
```
class Solution:
    def intToRoman(self, num: int) -> str:
        map_roman = {1: 'I', 4: 'IV', 5: 'V',
                    9: 'IX', 10: 'X', 40: 'XL', 50: 'L',
                    90: 'XC', 100: 'C', 400: 'CD', 500: 'D',
                    900: 'CM', 1000: 'M'}
        num_level = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000]
        num_level.reverse()
        num_fq = []
        for l in num_level:
            num_fq.append(num // l)
            num = num % l
        res = []
        for f, l in zip(num_fq, num_level):
            if f != 0:
                for i in range(f):
                    res.append(map_roman[l])
        res = ''.join(res)
        return res
```
