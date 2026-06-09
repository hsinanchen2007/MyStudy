### 解题思路
思路比较简单：
- 逐次遍历网格中的每个位置，假设当前遍历到位置(i,j)处，其叠加的方块数为v;
- 依次搜索当前位置上下左右四个位置是否有重叠的方块，然后计算每个位置所拥有的表面积；
- 假若没有，则当前位置的表面积和为4*v+2（中间4个侧面+上下两个底面）（此时我们称作理想状态）；
- 假若左边位置(i, j-1)处有叠加的方块，数量为k,则两个位置叠加的方块有min(k, v)个是紧挨着的，也就是说，这部分紧挨着的面就不能再计算入表面积了，此时，两个位置都应该减去这些挨着的面，并且减去的数量都为min(k,v)；
- 这个时候，可以有不同的操作；本文中的操作时，遍历到哪个位置，哪个位置仅减去自己被挨着的这一面的表面积，也就是当前位置的表面积由理想状态下的减去挨着的那一面的表面积，因为每一个面的面积都为1，所以有多少个堆叠的方块挨着，就减去多少个1，即(4*v+2)-min(k,v);
- 其他网格位置和方向的判断都与上述相同；
- 循环遍历完成即可；

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        if rows <= 0:
            return 0
        cols = len(grid[0])

        directs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        rst = 0
        for i in range(rows):
            for j in range(cols):
                v = grid[i][j]
                if v == 0:
                    continue
                
                cnt= 4*v + 2
                for (dx, dy) in directs:
                    nx = i + dx
                    ny = j + dy
                    if nx < 0 or nx >= rows:
                        continue
                    elif ny < 0 or ny >= cols:
                        continue

                    tmp = grid[nx][ny]
                    rst -= min(tmp, v)
                
                rst += cnt
        
        return rst
```