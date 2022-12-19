### 解题思路

常规的BFS流程，但是性能不够优化

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if (z < 0) or (z > (x+y)): 
            return False

        # - quick check without more caculation
        if z in [0, x, y, x+y]: 
            return True

        # - use seen to keep all possible pair
        seen = set()

        q = [(0,0)]
        while q:
            cx,cy = q.pop(0)

            # - if seen before, skip
            if (cx,cy) in seen: continue
            seen.add((cx,cy))

            # - if meet the requirement, return True
            if (cx==z) or (cy==z) or ((cx+cy)==z):
                return True

            # - try all possible cases
            for xy in set([
                (x,cy),     # - fill a
                (cx,y),     # - fill b
                (0,cy),     # - empty a
                (cx,0),     # - empty b
                (           # - a -> b
                    cx - min(cx, y-cy),
                    cy + min(cx, y-cy)
                ),
                (           # - b -> a
                    cx + min(cy, x-cx),
                    cy - min(cy, x-cx)
                ),
            ]):
                if xy not in seen:
                    q.append(xy)

        return False
```