### 解题思路
官方题解还提供了其他的思路，例如 动态规划。



这一题同 [994. 腐烂的橘子](https://leetcode-cn.com/problems/rotting-oranges/solution/gelthin-dai-xiu-gai-by-gelthin/) 和 [面试题32 - II. 从上到下打印二叉树 II](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/)
1. 若不用 for _ in range(len(queue)), 也可以用 new_queue 来新暂存要加入的点，最后用 queue = new_queue, 来保证层次遍历
2. BFS 根本就不需要写辅助函数。在进队列前就可以判断是否要处理。




### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        ## 有点像 腐烂的橘子，宽度优先遍历，or DP
                
        n = len(grid)
        queue = []
        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    queue.append([i,j])
        if len(queue) == 0 or len(queue) == n*n:
            return -1 

        dx, dy = [0,0,1,-1], [1,-1,0,0]
        #result = [[0]*n for _ in range(n)]
        v = 0
        while queue: # wrapper  # 类似二叉树的层次遍历
            for _ in range(len(queue)):
                i, j = queue.pop(0)
        #        result[i][j] = v
                for h in range(4):
                    nx, ny = i+dx[h], j+dy[h]
                    if 0<=nx<n and 0<=ny<n and grid[nx][ny] == 0:
                        queue.append([nx, ny])
                        grid[nx][ny] = -1  # 不再进入
            v += 1

        return v-1
        
        # res = 0
        # for i in range(n):
        #     for j in range(n):
        #         res = max(res, result[i][j])
        # return res
```