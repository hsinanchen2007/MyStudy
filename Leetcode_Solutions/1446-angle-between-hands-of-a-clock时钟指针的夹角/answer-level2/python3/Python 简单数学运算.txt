![image.png](https://pic.leetcode-cn.com/d946b13253dba1a767de70e8536985a2e12949dd23c7e254b5617a5da7c5aa28-image.png)


```
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:

        if hour == 12:
            hour = 0
        h_angle = 30 * hour
        h_angle += 30 * (minutes / 60)
        m_angle = 360 * (minutes / 60)
        ans = abs(h_angle - m_angle)
        return 360 - ans if ans >= 180 else ans


print(Solution().angleClock(1, 57))
```
