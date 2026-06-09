尽量满足大的饼干给胃口大的小朋友
```
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g = sorted(g)
        s = sorted(s)
        count = 0
        while g and s:
            if s[-1] >= g[-1]:
                s.pop()
                g.pop()
                count += 1
            elif s[-1] < g[-1]:
                g.pop()
        return count
```
