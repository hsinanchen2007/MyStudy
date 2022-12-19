曼哈顿距离有个特点：水平距离与垂直距离独立，因此分别计算水平的最佳点和垂直的最佳点，组合起来就是最佳的见面地点。
1. 先遍历一遍数组，记下每个人的位置 [i,j]；
2. 计算行最佳见面地点，用 res_row 来记录行最少步数：遍历行，用每个人位置中的 i 减去当前行就是每个人需要横向走的步数，并把每个人需要走的步数相加，如果和小于 res_row 就将 res_row 换为当前累加和；
3. 计算列最佳见面地点，用 res_col 来记录列最少步数：遍历列，用每个人位置中的 j 减去当前列就是每个人需要纵向走的步数，并把每个人需要走的步数相加，如果和小于 res_col 就将 res_col 换为当前累加和；
4. 返回 res_row + res_col。
```
class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        
        # 先遍历记录下每个人的位置
        people = []
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    people.append([i,j])
        # 计算行最优
        res_row = float('inf')
        for i in range(len(grid)):
            ans = 0
            for person in people:
                ans += abs(person[0]-i)
            res_row = ans if ans < res_row else res_row
        # 计算列最优
        res_col = float('inf')
        for j in range(len(grid[0])):
            ans = 0
            for person in people:
                ans += abs(person[1]-j)
            res_col = ans if ans < res_col else res_col
        # 返回行列和
        return res_row + res_col
```
