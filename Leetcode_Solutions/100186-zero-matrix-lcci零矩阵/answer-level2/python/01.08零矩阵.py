### 解题思路
记录为0的位置，再进行遍历，纵横改为0

### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        mlen = len(matrix[0])
        ls=[]
        for x in range(len(matrix)):
            for y in range(mlen):
                if matrix[x][y] == 0:
                    ls.append([x,y])
        for (x,y) in ls:
            matrix[x] = [0]*mlen
            for i in range(len(matrix)):
                matrix[i][y] = 0
```