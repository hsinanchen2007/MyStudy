相似题目：[Leetcode-994-腐烂的橘子](https://leetcode-cn.com/problems/rotting-oranges/)
更多小白解题思路以及面试经验更新中[Mereder](https://mereder.github.io)
## 思路

首选是BFS，因为这个跟距离门的远近有关，如果都跟门直接相连，那么距离就是1，所以确定基本思路是BFS

其次，使用`多源BFS`，意思也就是几个起点同时开始BFS，其实不是严格意义的同时，如果把他们看成树的话，同时的含义是指在同一层，然后由这一层同时向下遍历。

这里有一个隐藏的思考点：多源BFS，那么距离某一个源最近的点的值肯定会先被修改为距离，后面的源再遍历到这里的时候就已经有距离值了，而且再遍历到这个点时候的距离肯定大于等于该点已有的距离值。 所以不需要进行比较值大小

```python
from collections import deque
class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        if not rooms:
            return rooms
        dr = [-1,1,0,0]
        dc = [0,0,-1,1]

        m = len(rooms)
        n = len(rooms[0])
        # 先把有门的地方都放进来，定义有门的地方path距离是0
        q = deque()
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    q.append((i,j,0))
        # 多源同时进行BFS
        while q:
            r,c,path = q.popleft()
            for i in range(4):
                newr,newc = r+dr[i],c+dc[i]
                if 0<=newr<m and 0<=newc<n and 2147483647 == rooms[newr][newc]:
                    rooms[newr][newc] = path+1
                    q.append((newr,newc,path+1)
```


