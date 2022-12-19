### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        ans = ''
        num = str(num)
        if len(num) == 4:
            ans = 'M' * int(num[0])
        if len(num) > 2:
            cd = int(num[-3])
            if cd == 4:
                ans += 'CD'
            elif cd == 9:
                ans += 'CM'
            elif cd >= 5:
                ans += 'D' + ('C' * (cd - 5))
            else:
                ans += 'C' * cd
        if len(num) > 1:
            cd = int(num[-2])
            if cd == 4:
                ans += 'XL'
            elif cd == 9:
                ans += 'XC'
            elif cd >= 5:
                ans += 'L' + ('X' * (cd - 5))
            else:
                ans += 'X' * cd
        cd = int(num[-1])
        if cd == 4:
            ans += 'IV'
        elif cd == 9:
            ans += 'IX'
        elif cd >= 5:
            ans += 'V' + ('I' * (cd - 5))
        else:
            ans += 'I' * cd
        return ans
```