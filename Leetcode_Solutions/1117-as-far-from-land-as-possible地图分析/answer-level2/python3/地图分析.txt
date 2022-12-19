### 解题思路
学习广度搜索

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        # 作者：guliqianxun
        ans = 0
        stage = 1 #每陆地开始，第一个染色时stage+1，区分出陆地
        n = len(grid)

        for i in grid:
            ans += sum(i)
        if ans == 0 or ans == n*n:  # 判断是不是全是陆地或者海洋，是的话返回-1
            return -1
        
        while(1):
            for i in range(n):
                for j in range(n): #从每一批颜色出发，颜色逐渐扩散
                    if grid[i][j] == stage:
                        for move_i,move_j in [1,0],[-1,0],[0,1],[0,-1]:  # 方向向量
                            if i+move_i < 0 or i+move_i > n - 1 or j+move_j < 0 or j+move_j > n - 1:
                                continue
                            if grid[i+move_i][j+move_j] > stage + 1 or grid[i+move_i][j+move_j] == 0:
                                grid[i+move_i][j+move_j] = stage + 1
            for i in grid:
                if 0 in i:
                    break              
            else:
                break
            stage += 1
                                
        return stage  

```