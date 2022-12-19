### 解题思路
暴力求解，待会试试不用字典存，看看能不能快点。。

### 代码

```python3
import numpy as np
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        # 防止越界，建一个大点的扩容的矩阵
        max_area = 0
        x, y = len(grid[0]), len(grid)
        self.grid_plus = np.zeros([y+2, x+2])
        for i in range(0, y):
            for j in range(0, x):
                self.grid_plus[i+1][j+1] = grid[i][j]
        # 用一个字典来存 那些不需要再去核查的1
        self.memory = dict()
        for i in range(1 ,y+1):
            for j in range(1 ,x+1):
                if (str(i)+','+str(j)) not in self.memory.keys():
                    if self.grid_plus[i][j] == 1:
                        self.memory[(str(i)+','+str(j))] = 1
                        k = 1 + self.check_1(i, j)
                        #print(k)
                        if k > max_area:
                            max_area= k
        return max_area
    
    def check_1(self, i, j):
        k1,k2,k3,k4 = 0,0,0,0
        if (str(i+1)+','+str(j)) not in self.memory.keys() and self.grid_plus[i+1][j] == 1:
            self.memory[(str(i+1)+','+str(j))] = 1
            k1 = 1 + self.check_1(i+1, j)
        if (str(i)+','+str(j+1)) not in self.memory.keys() and self.grid_plus[i][j+1] == 1:
            self.memory[(str(i)+','+str(j+1))] = 1
            k2 = 1 + self.check_1(i, j+1)
        if (str(i-1)+','+str(j)) not in self.memory.keys() and self.grid_plus[i-1][j] == 1:
            self.memory[(str(i-1)+','+str(j))] = 1
            k3 = 1 + self.check_1(i-1, j)
        if (str(i)+','+str(j-1)) not in self.memory.keys() and self.grid_plus[i][j-1] == 1:
            self.memory[(str(i)+','+str(j-1))] = 1
            k4 = 1 + self.check_1(i, j-1)
        #print('k2', k2)
        return k1+k2+k3+k4
            



        
        


```