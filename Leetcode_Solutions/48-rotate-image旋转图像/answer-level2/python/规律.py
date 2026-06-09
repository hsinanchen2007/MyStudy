思路很简单，对于某个点(x,y)顺时针旋转90度, 对应的位置是(y, n-x)

```python3
class Solution:
    def rotate(self, matrix: list) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # rotate formulation (x,y) = (y,n-x)
        s, e = 0, len(matrix)-1
        n = len(matrix) - 1
        while s < e:
            for l in range(s,e):
                matrix[s][l], matrix[l][n-s], matrix[n-s][n-l], matrix[n-l][s] \
                    = matrix[n-l][s], matrix[s][l], matrix[l][n-s], matrix[n-s][n-l]
            s += 1
            e -= 1
```
