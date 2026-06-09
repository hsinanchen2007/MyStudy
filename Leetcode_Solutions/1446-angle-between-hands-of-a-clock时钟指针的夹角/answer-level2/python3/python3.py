### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        ah = (hour+minutes/60)/12*360
        am = minutes/60*360
        a = abs(ah-am)
        if a >180:
            return 360-a
        return a
```