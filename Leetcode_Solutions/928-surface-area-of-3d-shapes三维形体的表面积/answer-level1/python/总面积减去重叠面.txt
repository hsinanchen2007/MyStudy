### 解题思路
先求出grid[i][j]的面积，对所有grid[i][j] 求和，然后再减去相邻格子被覆盖的面积

### 代码

```python
class Solution(object):
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if(len(grid)==0):
            return 0
        #各个格子之间重叠的面积
        cover=0
        #总面积
        total=0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    #每层四个面+上下两个底
                    total+=4*grid[i][j]+2
                if j>0:
                    # 左右重叠
                    cover+=min(grid[i][j-1],grid[i][j])
                if(i>0):
                    #上下重叠
                    cover+=min(grid[i][j],grid[i-1][j])
        # 每个重叠面牵涉到两个立方体
        return total-2*cover


```