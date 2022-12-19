```python [g1]
class Solution:
    def ordinalOfDate(self, date: str) -> int:
        y, m, d = map(int, date.split('-'))
        a = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        if y != 1900 and y % 4 == 0:
            a[2] += 1
        return sum(a[: m]) + d
```

```python [g2]
class Solution:
    def ordinalOfDate(self, date: str) -> int:
        import datetime
        return datetime.date(*map(int, date.split('-'))).strftime('%j').lstrip('0')
```

都一样差不多快48ms这样，毕竟数据太小了。