当两个指针一个在 12 周围的时候需要特殊处理。

```python
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        hour %= 12
        hour_angle = hour * 30 + minutes / 2
        minute_angle = minutes * 6
        # 分针在 12 左边，时针在右边
        if minute_angle - hour_angle > 180:
            return 360 - minute_angle + hour_angle
        # 时针在 12 左边，分针在右边
        if hour_angle - minute_angle > 180:
            return 360 - hour_angle + minute_angle
        # 普通情况
        return abs(minute_angle - hour_angle)
```
