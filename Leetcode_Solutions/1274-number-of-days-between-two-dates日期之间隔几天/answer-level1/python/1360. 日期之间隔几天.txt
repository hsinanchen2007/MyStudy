系统函数

```python []
from datetime import datetime as d
class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        return abs((d.strptime(date2, "%Y-%m-%d") - d.strptime(date1, "%Y-%m-%d")).days)
```