### 解题思路
当前一个罗马数对应的数值小于后一个罗马数对应的数值时，减去当前罗马数对应的数值，否则，加上当前罗马数对应的数值
### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        d = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        sum = 0
        for index in range(len(s) - 1):
            if d[s[index]] < d[s[index+1]]:
                sum -= d[s[index]]
            else:
                sum += d[s[index]]
        sum += d[s[-1]]
        return sum
```