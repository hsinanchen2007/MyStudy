```python
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        import datetime
        return ["Monday", "Tuesday","Wednesday", "Thursday", "Friday", "Saturday", "Sunday"][datetime.datetime(year, month, day).weekday()]
```
