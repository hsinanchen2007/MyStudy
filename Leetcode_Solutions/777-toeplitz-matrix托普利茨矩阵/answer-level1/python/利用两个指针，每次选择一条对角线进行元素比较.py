初始化两个点A和B，位于矩阵的右上角。
每次循环A先向左走，走到最左侧后向下走；B先向下走，走到最下面后向左走；
因此每次循环中，A和B都是矩阵对角线的头尾两个点。
依次比较对角线上的元素，若不相等，直接返回False。若想等则继续循环比较。
```
class Solution(object):
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        # 只有1行或1列，返回True（每个对角线只有1个元素）
        if len(matrix) == 1 or len(matrix[0]) == 1:
            return True
        
        rows = len(matrix)
        cols = len(matrix[0])
        
        # 使用两个指针A，B，初始化在右上角。
        # 每次在各自的方向走一步，取出一条对角线。判断对角线上元素是否相同。
        rowA, colA = 0, cols - 1
        rowB, colB = 0, cols - 1
        for _ in range(rows + cols):
            if colA > 0:
                colA -= 1
            else:
                rowA += 1
            if rowB < rows - 1:
                rowB += 1
            else:
                colB -= 1
            # 判断对角线元素是否相等
            curRow, curCol = rowA, colA
            while curRow < rowB and curCol < colB:
                curRow, curCol = curRow + 1, curCol + 1
                if matrix[curRow][curCol] != matrix[curRow - 1][curCol - 1]:
                    return False
        return True
```