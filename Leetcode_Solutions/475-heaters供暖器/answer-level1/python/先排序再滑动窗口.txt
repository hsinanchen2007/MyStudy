```
class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        
        l = 0
        r = 0
        m = 0
        
        houses.sort()
        heaters.sort()
        
        for h in houses:
            if h < heaters[l]:
                m = max(m, heaters[l] - h)
            elif h == heaters[l]:
                continue
            elif h > heaters[l]:
                while r < len(heaters):
                    if h < heaters[r]:
                        l = r - 1
                        m = max(m, min(heaters[r] - h, h - heaters[l]))
                        break
                    else:
                        if r == len(heaters) - 1:
                            m = max(m, h - heaters[r])
                            break
                    r += 1
        return m
```

执行用时 :276 ms, 在所有 python 提交中击败了95.89%的用户