```python
class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        y1, m1, d1 = map(int, date1.split('-'))
        y2, m2, d2 = map(int, date2.split('-'))
        months = [0,31,28,31,30,31,30,31,31,30,31,30,31]
        def getDays(y, m, d): # get days from 1971
            res = 0
            # add year
            for i in range(1971, y):
                if (i % 4 == 0 and i % 100 != 0) or i % 400 == 0:
                    res += 366
                else:
                    res += 365
            # add month
            for i in range(1, m):
                if i == 2:
                    res += 29 if (y % 4 == 0 and y % 100 != 0) or y % 400 == 0 else 28
                else:
                    res += months[i]
            return res + d # add date
                        
        
        days1 = getDays(y1, m1, d1)
        days2 = getDays(y2, m2, d2)
        return abs(days1 - days2)
```