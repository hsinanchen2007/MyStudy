首先运动顺序是右下左上，没有碰壁时一直运动，将当前位置打印。每次碰壁后就更换顺序，将现有顺序取出来并且放在顺序队列的最后(队列思想)。
判断碰壁：遇到边框，或者遇到以前已经打印过的值。
使用变量counter作为flag出现：没有打印但是连续四次转向说明已经打印完了。
```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if matrix ==[]:
            return([])
        row,col  = len(matrix),len(matrix[0])
        i,j = 0,0
        idx = [[0 for _ in range(col)] for __ in range(row)]
        #init
        counter=0
        idx[0][0] = 1
        res = [matrix[i][j]]
        direction = [(0,1),(-1,0),(0,-1),(1,0)]
        while counter<4:

            nowdirect = direction.pop(0)
            direction.append(nowdirect)
            counter=counter+1

            while i+nowdirect[0]<row and i+nowdirect[0]>-1 and j+nowdirect[1]<col\
             and j+nowdirect[1]>-1 and idx[i+nowdirect[0]][j+nowdirect[1]]==0: 
                i,j = i+nowdirect[0],j+nowdirect[1]
                res.append(matrix[i][j])
                idx[i][j]=1
                counter=0
        return(res)
```