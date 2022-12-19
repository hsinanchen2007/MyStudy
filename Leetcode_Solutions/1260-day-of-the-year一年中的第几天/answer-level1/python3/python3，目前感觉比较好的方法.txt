### 解题思路
默认2月28天，闰年则加一天。

### 代码

```python3
class Solution:
    def dayOfYear(self, date: str) -> int:
        monthdays = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        year, month, day = map(int, date.split("-"))
        if year % 400 ==0 or year % 4 == 0 and year % 100 != 0:
            monthdays[1] += 1
        return sum(monthdays[:month-1]) + day
        


        




```