```python
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        if position == []: return 0
        group = list(zip(position, speed))
        group.sort(key = lambda x: (-x[0], -x[1]))
        cnt = 1
        preTime = (target - group[0][0]) / group[0][1]
        for i in range(1, len(group)):
            nowTime = (target - group[i][0]) / group[i][1]
            if nowTime > preTime:
                cnt += 1
                preTime = nowTime
        return cnt

```