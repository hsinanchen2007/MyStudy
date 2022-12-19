### 解题思路
转换为1维列表求对应位置元素即可

### 代码

```python3
import numpy as np

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        return sorted(np.array(matrix).reshape(1, len(matrix) * len(matrix[0]))[0])[k - 1]
```