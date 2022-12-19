### 解题思路
原数组改写成一维数组就能判断了

### 代码

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        a = []
        for i in range(len(matrix)):
            a += matrix[i]
        if target not in a:
            return False
        else:
            return True


            
```