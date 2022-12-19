**逆时针旋转矩阵：先转置，再上下翻转。**
**顺时针旋转矩阵：先上下翻转，再转置。**

```py
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        while matrix:
            res += matrix.pop(0)
            matrix = list(map(list, zip(*matrix)))[::-1]
        return res
```