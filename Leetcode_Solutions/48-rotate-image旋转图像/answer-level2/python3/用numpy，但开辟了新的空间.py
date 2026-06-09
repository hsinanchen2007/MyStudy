### 解题思路
转置+水平翻转
### 代码

```python3
import numpy


class Solution:
    def rotate(self, matrix) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        temp = numpy.array(matrix)
        temp = temp.T
        temp = numpy.fliplr(temp)
        matrix[:] = temp.tolist()
```