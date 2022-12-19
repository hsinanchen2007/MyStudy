### 解题思路
1. 左边移到上边
2. 下边移到左边
3. 右边移到下边
4. 上边移到右边
### 代码

```python []
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if len(matrix) == 0 or len(matrix) != len(matrix[0]):
            return False
        
        n = len(matrix)
        for layer in range(n // 2):
            first = layer
            last = n - 1 - layer
            for i in range(first, last):
                offset = i - first
                top = matrix[first][i] # 存储上边

                # 左边移到上边
                matrix[first][i] = matrix[last - offset][first]
                # 下边移到左边
                matrix[last - offset][first] = matrix[last][last - offset]
                # 右边移到下边
                matrix[last][last - offset] = matrix[i][last]
                # 上边移到右边
                matrix[i][last] = top
        return True

```