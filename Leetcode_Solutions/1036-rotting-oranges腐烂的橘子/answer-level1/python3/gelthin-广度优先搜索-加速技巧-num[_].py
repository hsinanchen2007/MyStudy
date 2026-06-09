### 解题思路
题解来自于[评论区](https://leetcode-cn.com/problems/rotting-oranges/comments/72199)

我附加了一条评论， [rotlist = newrotlist[:] 可改为 rotlist = newrotlist, 仍然正确](https://leetcode-cn.com/problems/rotting-oranges/comments/268444/)

我的原始代码有 bug, 不知为何。后来发现是错打了 dx = [0,0,1-1] 忘了逗号。

此广度优先遍历也非常重要的一题。

#### 加速技巧:

if else 高概率的事件 if， 立马判断。 来自数组搜索题，某一个人的回答。
n<0 or n>l-1 or 短路表达式
m = len(grid) 后面调用 m
if left == None 变成 if left 来自链表的某一题
x1 = x + dx[i] 后面调用 x1, 避免每次都查找 dx[i]


### 代码

```python3 评论区代码
class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        rotlist = list()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    rotlist.append([i, j])
        minute = 0
        while(rotlist): #BFS循环
            newrotlist = list()
            for rotnode in rotlist:
                x0 = rotnode[0]
                y0 = rotnode[1]
                
                for k in range(4):
                    x = x0 + dx[k]
                    y = y0 + dy[k]
                    
                    if 0 <= x < len(grid) and 0 <= y < len(grid[0]) and grid[x][y] == 1:
                        grid[x][y] = 2
                        newrotlist.append([x,y])
            if not newrotlist:
                break
                
            rotlist = newrotlist[:]   # 这里没必要，画蛇添足
            minute += 1
            
        for row in grid:
            for i in row:
                if i == 1:#还有新鲜的
                    return -1
        return minute
        
```



```python3 我自己的代码
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        #dx = [0,0,1-1]  # 此 bug 先前一直未调节出来
        dx = [0,0,1,-1]
        dy = [1,-1,0,0]
        rotlist = []
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    rotlist.append([i,j])
        
        minute = 0
        while True:
            new_rotlist = []
            for x, y in rotlist:
                for i in range(4):
                    x1, y1 = x+dx[i], y+dy[i]   # 写这个从 100ms 下降到 64 ms 神奇啊！
                    if (0<= x1 <m) and (0<= y1 <n) and (grid[x1][y1] == 1):
                        grid[x1][y1] = 2
                        new_rotlist.append([x1, y1])
            if not new_rotlist:   # 记录新腐烂的，而不是记录腐烂的 4个边界。没必要用 BFS 递归解答，过于复杂。
                break             # 自己之前写 BFS 递归解答，很混乱，一直不对劲。
            else:
                minute += 1
                rotlist = new_rotlist  # 仍然是正确的。
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    return -1
        return minute         
```