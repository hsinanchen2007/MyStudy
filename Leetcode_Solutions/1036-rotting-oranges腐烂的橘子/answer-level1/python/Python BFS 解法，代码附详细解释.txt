可以把输入网格想象成如下的样子：
![image.png](https://pic.leetcode-cn.com/dc2548401e0d5db7fd3933378d6ba0d262acda3f1cb3d68fa9f4a41781b8d6bc-image.png)

```
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # 网格的长，宽
        m, n = len(grid), len(grid[0])
        # 网格每一个坐标的访问状态
        visit = [[False] * n for y in range(m)]
        # 找出最开始时，网格中所有坏橘子的坐标
        stack = [[y,x] for y in range(m) for x in range(n) if grid[y][x]==2]
        # 坏橘子传染好橘子的四个方向，上下左右
        direction = [[-1,0], [1,0], [0,-1], [0,1]]
        # 初始时间
        minute = 0
        
        # 开始坏橘子传染好橘子的循环，直到没有好橘子可以被传染
        while True:
            # 初始化一个stack_next，把这一轮变坏的橘子装进里面
            stack_next = []
            # 开始对坏橘子进行审查，主要是看上下左右有没有好橘子
            while stack:
                # 拿出坏橘子的坐标点
                y, x = stack.pop()
                # 再看坏橘子上下左右的坐标对应的坐标
                for d in direction:
                    y_new, x_new = y + d[0], x + d[1]
                    # 如果坐标在网格范围内，而且坐标没有被访问过，且这个坐标确实有个好橘子
                    if -1 < y_new < m and -1 < x_new < n and not visit[y_new][x_new] and grid[y_new][x_new] == 1:
                        # 观察慰问一下这个好橘子，表示已经访问过了
                        visit[y_new][x_new] = True
                        # 告诉这个好橘子，你已被隔壁的坏橘子感染，现在你也是坏橘子了
                        grid[y_new][x_new] = 2
                        # 放进stack_next里面，集中管理，精准隔离，方便排查下一轮会变坏的橘子
                        stack_next.append([y_new, x_new])
            # 如果橘子们都检查完了发现再无其他坏橘子，终止循环，宣布疫情结束
            if not stack_next: break
            # 把这一轮感染的坏橘子放进stack里，因为我们每一轮都是从stack开始搜索的
            stack = stack_next
            # 看来橘子们还没凉透，来，给橘子们续一秒，哦不，续一分钟
            minute += 1
        
        # 经过传染，审查，隔离的循环后，如果还有好橘子幸存，返回-1宣布胜利，否则返回橘子们的存活时间
        return -1 if ['survive' for y in range(m) for x in range(n) if grid[y][x]==1] else minute
```
