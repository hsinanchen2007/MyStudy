### 解题思路
需要记录最后要置为0的行数与列数，如果要节省空间的话就用每一行列的头元素去记录，但这样在最后遍历的时候就要从第二行第二列开始，不能包括记录的元素，不然会全部置0。
另外第一行第一列的元素只能用来记录第一行的元素是否有0，需要单独设置一个变量记录第一列是否有0

### 代码

```python
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        is_col = False
        R = len(matrix)
        C = len(matrix[0])
        for i in range(R):
            if matrix[i][0] == 0:
                is_col = True
            for j in range(1, C):
                if matrix[i][j]  == 0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0
        for i in range(1, R):
            for j in range(1, C):
                if not matrix[i][0] or not matrix[0][j]:
                    matrix[i][j] = 0
        if matrix[0][0] == 0:
            for j in range(C):
                matrix[0][j] = 0       
        if is_col:
            for i in range(R):
                matrix[i][0] = 0
```