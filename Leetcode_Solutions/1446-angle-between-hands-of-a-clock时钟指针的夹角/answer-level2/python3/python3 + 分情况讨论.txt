### 解题思路
分三种情况

### 代码

```python3
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        a = minutes // 5
        b = minutes % 5
        if hour > a:
            res = (hour - a) * 30 + minutes / 60 * 30 - b * 6
            return min(res,360-res)
        elif hour == a:
            res = abs(minutes / 60 * 30 - b * 6)
            return res
        elif hour < a:
            res = (a - hour) * 30 - minutes / 60 * 30 + b * 6
            return min(res,360-res)
```