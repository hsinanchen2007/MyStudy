### 解题思路
分类讨论？这个44ms，思路大都没什么区别，就是在实现上的优化技巧，包括代码行数优化和时间内存优化。

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        one_digits = ['I', 'X', 'C', 'M']
        five_digits = ['V', 'L', 'D']
        ans = ""
        bit = 0
        while num > 0:
            temp = num % 10
            num = num // 10
            if temp < 4:
                ans = one_digits[bit] * temp + ans
            elif temp == 4:
                ans = one_digits[bit] + five_digits[bit] + ans
            elif temp == 5:
                ans = five_digits[bit] + ans
            elif temp < 9:
                ans = five_digits[bit] + one_digits[bit] * (temp - 5) + ans
            else:
                ans = one_digits[bit] + one_digits[bit + 1] + ans
            bit = bit + 1
        return ans
```