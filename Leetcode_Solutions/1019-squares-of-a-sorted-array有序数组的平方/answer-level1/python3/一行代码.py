### 解题思路
一行代码

### 代码

```python3
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        return sorted([i * i for i in A])
```