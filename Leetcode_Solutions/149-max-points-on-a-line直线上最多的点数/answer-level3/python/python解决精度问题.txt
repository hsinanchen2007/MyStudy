
```python []
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        def gongyue(u,v):
            if u<v:
                u, v = v,u
            r=u%v
            while r!=0:
                u=v
                v=r
                r=u%v
            return v
        pcnt = len(points)
        if pcnt < 3:
            return pcnt
        res = 2
        for p1 in range(pcnt-1):
            d = {'chuizhi':0,'pingxing':0}
            samep1 = 1
            p1x, p1y = points[p1]
            mostpoints = 0
            for p2 in range(p1+1, pcnt):
                p2x, p2y = points[p2]
                if p1x == p2x and p1y == p2y:
                    samep1 += 1
                elif p1x == p2x:
                    d['chuizhi'] += 1
                    mostpoints = max(mostpoints,d['chuizhi'])
                elif p2y == p1y:
                    d['pingxing'] += 1
                    mostpoints = max(mostpoints,d['pingxing'])
                else:
                    hy = (p2y-p1y) 
                    hx = (p2x-p1x)
                    a = gongyue(abs(hy), abs(hx))
                    hy = hy//a
                    hx = hx//a
                    if hy <0:
                        hy = -hy
                        hx = -hx
                    d[(hy,hx)] = d.get((hy,hx), 0) + 1
                    mostpoints = max(mostpoints, d[(hy,hx)])
            res = max(res, mostpoints + samep1)
        return res

```
