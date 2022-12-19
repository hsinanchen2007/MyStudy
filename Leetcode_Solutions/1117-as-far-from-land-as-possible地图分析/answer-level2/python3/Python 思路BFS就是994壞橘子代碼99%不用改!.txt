### 解题思路
看了這題想到了壞橘子,修改兩處.
1.return修改成直接返回steps;
2.增加if判定是否全是1或0,返回-1
直接從壞橘子的簡單變成了地圖分析的中等難度.. 哈哈

本題思路:將所有的陸地看成一個整體,每步將附近即4個方向的海洋變成陸地.
新生成的陸地繼續添海造陸的步驟,每次每次海洋->陸地,則距離+1
知道再無海洋可以填,返回距離
使用的算法是bfs

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        visit = [[0]*cols for _ in range (rows)]
        batch = [(y,x) for y in range(rows) for x in range(cols) if grid[y][x] == 1]
        if len(batch) == rows**2 or len(batch) == 0:
            return -1
        choices = [[-1,0],[1,0],[0,-1],[0,1]]
        steps = 0
        while True:
            next_batch=[]
            while batch:
                y,x = batch.pop()
                for choice in choices:
                    y_,x_=y+choice[0],x+choice[1]
                    if -1<y_<rows and -1<x_<cols and not visit[y_][x_] and grid[y_][x_] == 0:
                        visit[y_][x_] = 1
                        grid[y_][x_] = 1
                        next_batch.append([y_,x_])
            if not next_batch:
                break
            steps += 1
            batch = next_batch
        return  steps


```