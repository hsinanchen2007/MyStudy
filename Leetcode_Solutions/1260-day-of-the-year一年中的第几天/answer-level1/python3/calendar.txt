### 解题思路
用calendar
```python3
import calendar
class Solution:
    def dayOfYear(self, date: str) -> int:
        t = date
        t = t.strip('date = "')
        t = t.split('-')
        y = int(t[0])
        m = int(t[1])
        d = int(t[2])

        sum = 0
        if m == 1:
            sum = sum + d
        else:
            for i in range(1, m):
                sum = sum + calendar.monthrange(y, i)[1]

            sum = sum + d;
        print(sum)
        return sum
```

### 代码

```python3
import calendar
class Solution:
    def dayOfYear(self, date: str) -> int:
        t = date
        t = t.strip('date = "')
        t = t.split('-')
        y = int(t[0])
        m = int(t[1])
        d = int(t[2])

        sum = 0
        if m == 1:
            sum = sum + d
        else:
            for i in range(1, m):
                sum = sum + calendar.monthrange(y, i)[1]

            sum = sum + d;
        print(sum)
        return sum
```