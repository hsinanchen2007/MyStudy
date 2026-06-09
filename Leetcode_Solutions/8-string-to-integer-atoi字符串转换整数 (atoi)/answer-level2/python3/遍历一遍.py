### 解题思路
时间复杂度：O（n）
空间复杂度：O（1）

### 代码

```python3
INT_MAX = 2**31 - 1
INT_MIN = -2**31
class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        if not s:
            return 0
        count = 0
        negative = False
        sub_s = s
        if s[0] == "-"or s[0] == "+":
            if s[0] == "-":
                negative = True
            sub_s = s[1:]
        for ind, i in enumerate(sub_s):
            if "0" <= i <= "9":
                count *= 10
                count += int(i)
            else:
                break
        if negative:
            count *= -1
        if count > INT_MAX:
            count = INT_MAX
        if count < INT_MIN:
            count = INT_MIN
        return count

```