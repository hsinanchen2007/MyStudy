![螺旋矩阵.jpg](https://pic.leetcode-cn.com/bccc4ffc5e32c20359e24a7348323ec010ec53a24355ee085a511665ce73c25d-%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5.jpg)

```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return None
        # 设置两个对角坐标作为边界判定条件[col1,row2],[col2,row2]
        # 只要col1 <= col2 and row1 <= row2 就能保证正确螺旋遍历
        res = []
        col1 = 0
        row1 = 0
        col2 = len(matrix)-1
        row2 = len(matrix[0])-1
        while col1 <= col2 and row1 <= row2:
            for i in range(row1,row2):
                res.append(matrix[col1][i])
            for i in range(col1,col2):
                res.append(matrix[i][row2])
            # 说明属于情况1：
            if col1 != col2:
                for i in range(row2,row1,-1):
                    res.append(matrix[col2][i])
            # 说明属于情况3：
            elif col1 == col2 and row1 != row2:
                res.append(matrix[col1][row2])
            # 说明属于情况1：
            if row1 != row2:
                for i in range(col2,col1,-1):
                    res.append(matrix[i][row1])
            # 说明属于情况2：
            elif row1 == row2 and col1 != col2:
                res.append(matrix[col2][row1])
            # 说明属于情况4：
            if row1==row2 and col1==col2:
                res.append(matrix[col1][row1])
            # 边界对角坐标更新：
            col1 += 1
            row1 += 1
            col2 -= 1
            row2 -= 1
                
        return res
```
