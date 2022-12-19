### 解题思路
按照单位从大到小排列[1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4 , 1]。
目标数依次处以从大到小的单位。结果取整保存，余数保存。再用余数除以次大的单位，结果取整保存，余数保存。依次除到最小的单位。最后拼接结果。

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        li = list()
        li3 = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4 , 1]
        for q in li3:
            li.append(num // q)
            num = num % q
        
        li2 = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        p = 0
        s = ""
        for n in li:
            s = s + li2[p] * n
            p += 1
        return s

```