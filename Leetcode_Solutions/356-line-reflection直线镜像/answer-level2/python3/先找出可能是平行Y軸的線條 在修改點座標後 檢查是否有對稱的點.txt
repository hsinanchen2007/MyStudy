### 解题思路
先找出可能是平行Y軸的線條 
在修改點座標後 
檢查是否有對稱的點

### 代码

```python3
class Solution:
    def isReflected(self, points: List[List[int]]) -> bool:

        if not points:
            return True

        points_set = set()
        
        summ_y = 0
        count = 0
        for pi, pj in points:
            if (pi, pj) in points_set:
                continue
            else:
                points_set.add((pi, pj))
                summ_y += pi
                count += 1
        mean_x = summ_y / count

        for p in points:
            p[0] -= mean_x
        
        count = 0
        points_pair = []
        for p in points:
            if [-p[0], p[1]] in points:
                count+=1

        if count == len(points):
            return True
        else:
            return False        


            
```