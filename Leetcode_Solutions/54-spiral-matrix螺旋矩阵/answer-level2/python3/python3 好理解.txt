```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) == 0:
            return []
        
        above_row = 0 #上边界index
        below_row = len(matrix)-1 #下边界index
        left_col = 0 #左边界index
        right_col = len(matrix[0])-1 #右边界index
        total = sum([len(e) for e in matrix]) #matrix元素的个数,元素个数到了就返回
        res =[]

        while above_row <= below_row and left_col <= right_col:
            # 从左到右
            for i in range(left_col, right_col + 1):
                res.append(matrix[above_row][i])
            # 上行加1
            above_row += 1
            if len(res) == total:
                break   #退出循环

            # 从上到下
            for i in range(above_row, below_row + 1):
                res.append(matrix[i][right_col])
            right_col -= 1
            if len(res) == total:
                break   #退出循环

            # 从右到左
            for i in range(right_col, left_col - 1, -1):
                res.append(matrix[below_row][i])
            below_row -= 1
            if len(res) == total:
                break   #退出循环

            # 从下到上
            for i in range(below_row, above_row - 1, -1):
                res.append(matrix[i][left_col])
            left_col += 1
            if len(res) == total:
                break   #退出循环

        return res
```