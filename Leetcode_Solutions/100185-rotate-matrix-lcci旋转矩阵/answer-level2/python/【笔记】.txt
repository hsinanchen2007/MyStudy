### 知识点
1.inplace需要[:]，可查看id(matrix)
2.zip()
3.tolist()
4.*序列解包

### 代码
法一
```python
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        matrix[::] = zip(*matrix[::-1]) 
```
法二
```
import numpy as np
matrix[:] = np.rot90(matrix,-1).tolist()
```
