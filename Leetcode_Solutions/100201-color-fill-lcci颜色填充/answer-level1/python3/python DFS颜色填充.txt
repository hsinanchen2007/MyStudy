### 解题思路
深度优先搜索问题

### 代码

```python3
import numpy as np
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        xlen=len(image)
        ylen=len(image[0])
        
        def dfs(x,y,newColor,source):
            #右->下->左->上
            zuobiao=[[0,1],[1,0],[0,-1],[-1,0]]
            if(image[x][y]!=source):
                return
            image[x][y]=newColor
            #枚举四种走法
            for i in range(len(zuobiao)):
                #更新结点
                tx=x+zuobiao[i][0]
                ty=y+zuobiao[i][1]
                #判断是否是边界
                if(tx<0 or tx>=xlen or ty<0 or ty>=ylen):
                    continue
                dfs(tx,ty,newColor,source)
            return
        
        source=image[sr][sc]
        #如果初始颜色和想要涂的颜色一样，不做修改直接返回图片。
        if(source==newColor):
            return image
        dfs(sr,sc,newColor,source)
        return image


            
```