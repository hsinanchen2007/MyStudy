### 解题思路
![image.png](https://pic.leetcode-cn.com/28e0c639391e8608bbd7090bdf22027d47462190782ac7e5d5e5aceb91928393-image.png)
> calendar.weekday(year, month, day) 
Returns the day of the week (0 is Monday) for year (1970–…), month (1–12), day (1–31).

### 代码

```python3
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        d = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
        import calendar
        return d[calendar.weekday(year, month, day)]
```