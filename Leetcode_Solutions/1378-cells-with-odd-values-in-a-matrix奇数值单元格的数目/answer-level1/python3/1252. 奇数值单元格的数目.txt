### 解题思路

### 代码

```python3
class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        num = 0
        for i in range(0, n):
            for j in range(0, m):
                mat = 0
                for k in indices:
                    if k[0] == i: mat += 1
                    if k[1] == j: mat += 1
                if mat % 2 == 1: num += 1
        return num

        
                
```