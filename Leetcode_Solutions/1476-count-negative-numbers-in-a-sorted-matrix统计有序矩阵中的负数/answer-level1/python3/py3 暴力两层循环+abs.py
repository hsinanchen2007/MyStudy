### 代码

```python3
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        jige=0
        for x in grid:
            for y in x:
                if abs(y)!=y:
                    jige+=1
        return jige
```