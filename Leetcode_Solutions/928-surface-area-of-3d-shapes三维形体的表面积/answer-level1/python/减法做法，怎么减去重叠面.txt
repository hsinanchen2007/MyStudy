### 解题思路
看了甜姨的思路，写了python3代码，具体写在注释

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        res = 0 # 总表面积
        sideLen = len(grid) # 边长
        for i in range(sideLen): # 二重循环遍历
            for j in range(sideLen):  
                if grid[i][j]>0: # 有正方体才需要处理
                    res += grid[i][j]*4 + 2 # 先不管四周有重叠的问题，直接计算每一格子的柱状表面积
                    # 接下来减去每一格和四周重叠的表面积，两个相邻柱子取矮的那一个x2就是重合的表面积
                    # 重叠面由上下（左右）两个格子各减去一面，x2之后则可以每个格子只处理左和上，
                    # 右和下则会在后面遍历到的下方和右方格子处理，控制好边界即可
                    res -= min(grid[i-1][j],grid[i][j])*2 if i-1>=0 else 0
                    res -= min(grid[i][j-1],grid[i][j])*2 if j-1>=0 else 0
        return res 
                
```