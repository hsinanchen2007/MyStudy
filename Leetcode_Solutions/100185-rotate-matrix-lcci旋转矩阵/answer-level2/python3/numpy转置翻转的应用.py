### 解题思路
必须[:]才行 我也不知道为啥。。也可以学大佬的解包再压缩，也是一行。。
matrix[:] = [m[::-1] for m in zip(*matrix)]

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        import numpy as np
        matrix[:]=np.fliplr(np.array(matrix).T).tolist()
```