我们可以直接计算，不管是大角（大于180°）或者小角，最后如果大于180° 直接用360°减去即可。
另外只考虑时针领先于分针时，当时针落后于分针时，可以将时针数值加上 12


领先时，角度即是时针走过的分（时间）的数目减去分钟走过的分，加上时针继续走过的角度
分钟数  $hour*5-minutes$
继续走过的 $minutes/60*30$


```
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        if hour*5+minutes/12 <minutes:
            hour+=12
        angle = (hour*5-minutes)*6+minutes/2
        return angle if angle <=180 else 360-angle
```