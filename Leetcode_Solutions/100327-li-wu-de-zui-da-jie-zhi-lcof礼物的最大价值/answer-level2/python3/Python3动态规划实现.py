### 解题思路
遍历每一个方格，计算出每个方格的最大价值，最后一个方格便是可以拿到的最多价值的礼物
![微信图片_20200213121129.png](https://pic.leetcode-cn.com/d42f8405c4bf33a7d92893672a9a8e548e20796e945100095256d89686fb2212-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200213121129.png)

### 代码

```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i==0 and j==0:
                    grid[i][j] = grid[i][j]
                elif i==0 and j>0:  # 考虑边界条件
                    grid[i][j] += grid[i][j-1]
                elif i>0 and j==0:  # 考虑边界条件
                    grid[i][j] += grid[i-1][j]
                else:
                    grid[i][j] += max(grid[i-1][j],grid[i][j-1]) # 用计算出的该方格的最大价值代替原有值
        return grid[-1][-1]

        # 附上递归代码，但是递归会超时
        # def mv(i,j):
        #     if i<0 or j <0:
        #         return 0
        #     if i==0 and j==0:
        #         return grid[0][0]
        #     return max(mv(i-1,j),mv(i,j-1))+grid[i][j]

        # max_val = mv(len(grid)-1,len(grid[0])-1)
        # return max_val

```