### 解题思路
如果没有攻击就被毒0秒
如果被攻击，攻击间隔小于中毒持续时间就用攻击间隔，不小于就用持续时间

### 代码

```python3
class Solution:
    def findPoisonedDuration(self, timeSeries, duration):
        if len(timeSeries) == 0:
            return 0
        con = 0
        index = 0
        for i in timeSeries:
            x = index + 1
            if x < len(timeSeries):
                sub = timeSeries[x] - timeSeries[index]
                if sub >= duration:
                    con += duration
                else:
                    con += sub
            index += 1
        else:
            con += duration
        return con


```