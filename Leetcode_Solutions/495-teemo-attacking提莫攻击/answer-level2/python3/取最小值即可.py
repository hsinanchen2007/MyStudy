### 解题思路
每次叠加间隔和中毒时间的较小值

### 代码

```python3
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        durationTime=0
        size=len(timeSeries)
        if size<1:
            return 0


        for i in range(size-1):
            durationTime+=min(duration, timeSeries[i+1]-timeSeries[i])
        return durationTime+duration
```