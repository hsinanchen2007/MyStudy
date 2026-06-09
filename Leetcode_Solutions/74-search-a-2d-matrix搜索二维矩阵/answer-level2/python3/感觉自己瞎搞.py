### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for i in matrix:
            if target  in i:
                return True

        return False
```