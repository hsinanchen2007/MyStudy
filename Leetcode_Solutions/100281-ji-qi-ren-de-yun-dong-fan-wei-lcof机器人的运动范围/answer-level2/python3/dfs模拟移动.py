### 解题思路
把大于k的格子理解为障碍物，构建一个长m，宽n的布尔矩阵，值为True的点是障碍物。
由于起点是(0,0)，所以机器人一开始只能向右或向下移动，之后的每次移动也都是在前一次的基础上向右或向下移动。
把机器人到达过的点置为True，同时计数器加一，可以理解为到达一次后这个点就变成障碍物了，因为之后不会再重复计数。


### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        matrix=[[sum([int(_) for _ in str(i)+str(j)])>k for j in range(n)] for i in range(m)]
        # c1=sum([_.count(True) for _ in matrix])
        res=0
        directions=[(1,0),(0,1)]
        def dfs(i,j):
            if matrix[i][j]:
                return
            matrix[i][j]=True
            nonlocal res
            res+=1
            for dx,dy in directions:
                if i+dx<m and j+dy<n:
                    dfs(i+dx,j+dy)
        dfs(0,0)
        return res
                    
            
```