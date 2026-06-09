### 解题思路
这题挺难的，难在转换，我是没想到，看了解答以后才知道应该设置一个pipe数组，然后赋一样的方向定义给dx和dy
所以我给出一份我写的比较简单的双100%的python代码
之后从起点开始DFS，起点任意方向开始能到终点就算成功

想到这种转换方式以后就不难了
很坑的地方是递归深度在特殊的情况下会很深，比如一直蛇形前进的时候，观察m，n最大乘积为90000
需要调用sys.setrecursionlimit函数
（妈蛋，我还以为我写错了）
### 代码

```python3
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        import sys
        sys.setrecursionlimit(100000) 

        #     2
        #   3   1
        #     0
        # 四个方向
        pipe = [[-1 for i in range(4)] for _ in range(6)]
        dx = [1,0,-1,0]
        dy = [0,1,0,-1]
        pipe[0][1] = 1
        pipe[0][3] = 3
        
        pipe[1][2] = 2 
        pipe[1][0] = 0
        
        pipe[2][2] = 3
        pipe[2][1] = 0
        
        pipe[3][2] = 1
        pipe[3][3] = 0
        
        pipe[4][1] = 2
        pipe[4][0] = 3
        
        pipe[5][0] = 1
        pipe[5][3] = 2
        
        def dfs(x,y,way,grid):
            if (x == m-1) and (y == n-1):
                return 1
            x = x + dx[way]
            y = y + dy[way]
            
            if(x<0 or x >= m or y<0 or y>=n):
                return 0
            
            cur = grid[x][y]
            if pipe[cur-1][way] != -1:
                return dfs(x,y,pipe[cur-1][way],grid)
            else:
                return 0
        
        m = len(grid)
        n = len(grid[0])
        start = grid[0][0]
        for i in range(4):
            if pipe[start-1][i] != -1:
                if(dfs(0,0,pipe[start-1][i], grid)):
                    return True
        
        return False
            

            
        
        
        
        
```