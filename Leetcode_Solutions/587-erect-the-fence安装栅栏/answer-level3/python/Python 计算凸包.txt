用叉乘排除非凸点，时间为 O(n)，但排序为 O(n log n)，总体还是 O(n log n)
```
class Solution(object):
    def outerTrees(self, points):
  
      n = len(points)
        if n < 3: return points
        pts = sorted(set(points), key = lambda a: (a.x, a.y))
        
        cross = lambda o, a, b: (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x)
        
        low = []
        for p in pts:
            while len(low) > 1 and cross(low[-2], low[-1], p) < 0:
                low.pop()
            low.append(p)
        
        up = []
        for p in reversed(pts):
            while len(up) > 1 and cross(up[-2], up[-1], p) < 0:
                up.pop()
            up.append(p)
        
        return list(set(low[:-1] + up[:-1]))
              
```
