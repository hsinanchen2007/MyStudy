### 解题思路
見注釋

### 代码

```python3
class Solution:
    def gameOfLife(self, g: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        r,c = len(g),len(g[0])#獲取row,col即行和列
        #拷貝一份棋盤到tmp變量
        tmp =[ [0] * c  for _ in range(r)]#tmp初始化爲0
        for y in range(r):
            for  x in range(c):    
                tmp[y][x] = g[y][x]
        def h():#helper函數判斷死活,默認全死,只需考慮活的兩種情況
            nonlocal g, tmp
            for y in range(r):
                for x in range(c):
                    cell = 0#默認全死
                    count = count_neighbors(g, y, x)
                    if (g[y][x] == 0 and count == 3 )or (g[y][x] == 1 and (count == 2 or count == 3)):
                    #要麼是死細胞周圍有3個活細胞,要麼活細胞周圍有2or3個活細胞
                            cell = 1#滿足上述兩種情況爲活
                    tmp[y][x]= cell#更新tmp
 
        def count_neighbors(grid, row, col):        
            #查看當前八個方向的格子狀態,活着就+1
            count = 0
            if row-1 >= 0:#上方格子
                count += g[row-1][col]
            if (row-1 >= 0) and (col-1 >= 0): #左斜上方格子
                count += g[row-1][col-1]
            if (row-1 >= 0) and (col+1 < c):#右斜上方格子
                count += g[row-1][col+1]
            if col-1 >= 0:#左邊格子
                count +=  g[row][col-1]
            if col + 1 < c: #右邊格子
                count += g[row][col+1]
            if row + 1 < r:#下方格子
                count += g[row+1][col]
            if (row + 1 < r) and (col-1 >= 0):#左下方格
                count += g[row+1][col-1]
            if (row + 1 < r) and (col+1 < c):#右下方格
                count += g[row+1][col+1]
            return count
        h()#完成tmp棋盤的更新
           #更新棋盤
        for i in range(r):
            for  j in range(c):    
                g[i][j] =tmp[i][j]
     


  

        
        
```