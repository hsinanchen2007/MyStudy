 1.逐个遍历区域中的块
 2. 每一个区域一定会有上下两面，加入total中
 3. 每个区域中的四个侧面也加入到total中，一个正方体4个侧面，所有用4*正方体个数
 4. 侧面会有重叠情况，这种情况发生在两个相邻区域中，而边缘区域就是四周不会重叠，并且相邻区域一个正方体只有一个贴面，比如一个区域有3个正方体，相邻区域有两个正方体，那么贴面数就是2*1.加入到loss中
 5. 用总面数-贴面数得到最终解
```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        total=0
        loss=0
        step=[[0,1],[0,-1],[1,0],[-1,0]]#用于探索四周区域
        for i in range(len(grid)):
            for j in range(len(grid)):
                if grid[i][j]>0:
                    #每个区域的上下面
                    total+=2
                    #侧面 侧面量为个数x4
                    total+=4*grid[i][j]
                    #周围一圈
                    for stepx,stepy in step:
                        #该区域是边缘区域，边缘方向没有贴面
                        if i+stepx<0 or j+stepy<0 or (i+stepx)>=len(grid) or (j+stepy)>=len(grid):
                            continue
                        else:
                            #贴面以个数较少的区域正方体数为准
                            # print(i,j,stepx+i,stepy+j)
                            loss+=min(grid[i][j],grid[i+stepx][j+stepy])
        return max(0,(total-loss))
```
