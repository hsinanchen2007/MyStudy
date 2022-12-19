思路：单独计算每个 grid 上的立方体的表面积并求和，然后减去重合部分（cover）的面积。在计算 cover 时，由于把每行和每列的第一个元素都加了一遍，因此在最后减去这部分冗余（residual），然后得到真正的 cover。
```
class Solution:
    def surfaceArea(self, grid) -> int:
        area = 0
        cover = 0
        row = len(grid)
        for i in range(row): #计算每个grid 上的立方体在不受相邻立方体影响时的表面积，
                            #顺便计算每‘行’立方体相邻两个之间重合的表面积
            minv = grid[i][0]
            for j in range(row):
                area += 4*grid[i][j] 
                area += 2 if grid[i][j] != 0 else  0
                cover += min(minv, grid[i][j])
                minv = grid[i][j]
        for i in range(row):  #这个 for 循环计算每‘列’立方体相邻两个之间重合部分的表面积
            minv = grid[0][i]
            for j in range(row):
                cover += min(minv,grid[j][i])
                print (cover)
                minv = grid[j][i]#注意行与列的下标不要写反，这里用 i 表示列，j 表示行

        r1=sum(grid[0])             #取第一行元素的和
        r3 = [x[0] for x in grid ] #取第一列元素的和
        residual = r1+sum(r3) #计算 cover 时产生的冗余，因为每次计算 cover 时都会把该行
                                # 或者列的首个元素加到 cover 里去。
        cover -= residual
        print(area,cover,residual)
        return area - 2*cover  #重合部分抵消掉了相邻两个立方体的表面积，故乘 2
```

