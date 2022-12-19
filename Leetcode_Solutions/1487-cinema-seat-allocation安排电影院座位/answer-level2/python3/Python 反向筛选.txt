比赛的时候脑子里都是正向操作，一直没过，回想起来突然发现，可以反向操作呀，筛选被预约的位置，然后马上就过了

```python
class Solution(object):
    def maxNumberOfFamilies(self, n, res):
        left = set()
        right = set()
        mid = set()
        count = 0
        min_, max_ = n, 0
        for r, c in res:
            min_ = min(r, min_)
            max_ = max(r, max_)
            if r in left and r in right and r in mid:
                continue
            if (c < 6) and (c > 1): left.add(r)
            if (c < 10) and (c > 5): right.add(r)
            if (c < 8) and (c > 3): mid.add(r)
        for i in range(min_, max_+1):
            if i not in left and i not in right:
                count += 2
            elif i not in mid:
                count += 1
            elif i not in left or i not in right:
                count += 1
        count += 2*(min_-1)
        count += 2*(n-max_)
        return count
```