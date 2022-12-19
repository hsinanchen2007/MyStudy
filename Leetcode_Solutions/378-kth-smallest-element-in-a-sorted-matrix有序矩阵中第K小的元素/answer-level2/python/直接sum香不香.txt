### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        return sorted((sum(matrix, [])))[k-1]
```