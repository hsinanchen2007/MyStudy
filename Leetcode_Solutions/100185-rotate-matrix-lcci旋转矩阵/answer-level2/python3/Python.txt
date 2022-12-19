有用到辅助数组，
```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # 看起来就是变换顺序
        # 二维数组 按列访问
        matrix[:] = list(map(list, zip(*matrix)))
        for i in range(len(matrix)):
            matrix[i].reverse()
```