先把初始位置和速度处理进数组，然后按位置降序排序。

然后扫描记录最慢用时，每次变更最慢用时时车队数加1（位置小，时间大则说明追不上前面的车，故车队加1）。

```py
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        ans, slowest = 0, 0.0
        for p, s in sorted([*zip(position, speed)], reverse = True):
            timei = (target - p) / s    #某车到达终点的时间
            if timei > slowest:         #大于最慢时间，说明跟不上前车
                ans += 1
                slowest = timei         #变更最慢用时
        return ans
```
