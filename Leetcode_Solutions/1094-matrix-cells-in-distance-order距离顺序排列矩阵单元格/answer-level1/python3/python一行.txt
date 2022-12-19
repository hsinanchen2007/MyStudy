### 解题思路
python一行求解

### 代码

```python3
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        return sorted([[i, j] for i in range(R) for j in range(C)], key = lambda i : abs(i[0] - r0) + abs(i[1] - c0))
```