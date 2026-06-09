```
class Solution(object):
    def shiftGrid(self, g, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        r = len(g)
        c = len(g[0])
        t = []
        for l in g:
            t += l
        k %= r*c
        # 循环移位
        t = t[-k:] + t[:-k]
        
        res = []
        cur = 0
        # 重建
        for i in range(r):
            res.append(t[cur:cur+c])
            cur +=  c
        return res
```
