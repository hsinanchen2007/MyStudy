### 解题思路
此处撰写解题思路
借助内置的排序函数，非常清爽

### 代码

```python3
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        return sorted(points, key=lambda x: x[0] * x[0] + x[1] * x[1])[:K]
```