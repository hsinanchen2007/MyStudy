### 解题思路
    

### 代码

```python3
import numpy as np
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        matrix = np.array(matrix)
        if target in matrix:
            return True
        return False
```