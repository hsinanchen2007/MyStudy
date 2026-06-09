子矩阵表示：上边界i1，下边界i2，左边界j1，右边界j2

递归逻辑：
1. 找到当前矩阵的中心：i, j = (i1+i2)//2, (j1+j2)//2
2. 若target小于该中心，则可排除M[i:i2, j:j2]
3. 若target大于该中心，则可排除M[i1:i, j1:j]
4. 若target等于该中心，return True

```
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False

        def search(i1, j1, i2, j2):
            if i1 > i2 or j1 > j2:
                return False
            i, j = (i1+i2)//2, (j1+j2)//2
            if target < matrix[i][j]:
                return search(i1, j1, i-1, j2) or search(i, j1, i2, j-1)
            elif target > matrix[i][j]:
                return search(i1, j+1, i2, j2) or search(i+1, j1, i2, j)
            return True

        return search(0, 0, len(matrix)-1, len(matrix[0])-1)
```

p.s. 哪位大神来帮算个时间复杂度