### 解题思路
排序key的计算

### 代码

```python3
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        return sorted(points,key=lambda p:p[0]*p[0]+p[1]*p[1])[:K]
```