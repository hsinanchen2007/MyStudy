该题最难理解的题意，外数组的下标表示行数（即Y坐标），里数组的下标表示列数（即X坐标），值代表立方体个数。
创建两层循环，在里层循环的时候：
1. 根据当前格子立方体个数计算表面积
2. 减去左侧重叠的表面积，取当前格子和左侧格子的立方体数中的最小值
3. 减去上侧重叠的表面积，取当前格子和上方格子的立方体数中的最小值
4. 更新左侧立方体数和下一个格子上方的立方体数
5. 里层循环结束时要重置左侧立方体数为0，上方立方体数为当前层的第一个格子的立方体数
6. 循环完毕，返回当前值
```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        left = top = now = 0 #初始化左边立方体个数，上边立方体个数，当前表面积
        for i,row in enumerate(grid):
            for j in range(len(row)):
                if row[j]:
                    now += 4 * row[j] + 2 #计算全部立方体的表面积
                if top: #如果存在top，就减去最小接触面积
                    now -= min(row[j], top) * 2
                if left: #如果存在left，就减去最小接触面积
                    now -= min(row[j], left) * 2
                left=row[j] #更新left为当前格子的立方体层数
                if i > 0 and j < len(grid[i-1])-1:#如果上一层存在，且不是最后一个
                    top = grid[i-1][j+1] #就更新top为当前格子的下一个格子的上方格子的立方体数
                else: #当上一层的格子不存在时，就更新top为0，表示没有立方体
                    top = 0
            left,top = 0,grid[i][0]  #在每一行循环完毕时重置left和top
        return now
```
