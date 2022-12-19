```python
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        def get_angle(a, b):
            return abs((a - b) / 12 * 360)
        hour_angle = (hour + minutes / 60) % 12
        min_angle = (minutes / 60) * 12
        return min(get_angle(hour_angle, min_angle), 360 - get_angle(hour_angle, min_angle))
```