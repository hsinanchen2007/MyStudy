我的思路：
顺时针打印，上下左右四个方向有自己的顺序：右下左上
有两种情况：矩阵为1xn的，这个时候它只有向右的方向，如果之后接着向左判断，会出现重复；nx1的矩阵，这个时候只有向下的方向，如果加了向上判断，也会出现重复。
所以在向右和向下的方向上遍历的，需要加两个if语句，判断是否需要向左或向下。
```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        a,b = 0,0
        if len(matrix)==0:
            return res
        row,column = len(matrix)-a,len(matrix[0])-b
        while 0<row and 0<column:
            x,y = a,b
            res.append(matrix[x][y])
            for i in range(1,column): #右
                res.append(matrix[x][y+i])
            y = y+column-1
            for i in range(1,row): #下
                res.append(matrix[x+i][y])
            if row>1:
                x = x+row-1
                for i in range(1,column): #左
                    res.append(matrix[x][y-i])
            if column>1:
                y = y-column+1
                for i in range(1,row-1): #上
                    res.append(matrix[x-i][y])
            row-=2
            column-=2
            a+=1
            b+=1
        return res
```
