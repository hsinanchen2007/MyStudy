### 解题思路

#逆时针旋转矩阵：先转置，再上下翻转。
#顺时针旋转矩阵：先上下翻转，再转置。

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        matrix[:] = zip(*matrix[::-1])
```