```
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        hour_angle = (hour * 30 + minutes/2)%360
        minutes_angle = minutes * 6
        min_angle = abs(hour_angle - minutes_angle)
        if min_angle >= 180:
            return 360-min_angle
        else:
            return min_angle
```
