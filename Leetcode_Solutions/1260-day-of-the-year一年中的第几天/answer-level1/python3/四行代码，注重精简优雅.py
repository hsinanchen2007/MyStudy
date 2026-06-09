
```python
class Solution:
    def dayOfYear(self, date: str) -> int:
        d = list(map(int, date.split('-')))
        leap = bool((d[0]%4 == 0 and d[0]%100 != 0) or d[0]%400 == 0)
        monthday = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334]
        return monthday[d[1] - 1] + d[2] + (leap and d[1] > 2)
```
