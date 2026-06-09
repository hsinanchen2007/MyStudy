### 解题思路
利用内置函数list.count()

### 代码

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        for v in matrix:
            if v.count(target):
                return True
        return False
```