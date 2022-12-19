```
class Solution(object):
    def findRadius(self, houses, heaters):
        houses.sort()
        heaters.sort()
        ans, n = 0, len(heaters)
        for house in houses:
            # 查找第一个大于等于当前房屋的加热器
            tag = bisect.bisect_left(heaters, house)
            # 若非边界，则当前房屋位置必定在（大于等于当前位置的最近加热器）和（小于当前位置的最近加热器）之间
            if 0<tag<n:
                ans = max(ans, min(abs(heaters[tag]-house), abs(heaters[tag-1]-house)))
            # 若当前房屋位置小于等于第一个加热器位置
            elif tag==0:
                ans = max(ans, abs(heaters[tag]-house))
            # 若当前房屋位置大于等于最后一个加热器位置
            else:
                ans = max(ans, abs(heaters[tag-1]-house))
        return ans
```
