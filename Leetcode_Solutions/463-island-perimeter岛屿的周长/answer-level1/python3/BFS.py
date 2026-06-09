写完BFS，才发现不需要对值进行累计计算...
```
class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if grid == []:
            return 0

        next_step = [[0, 1],  # 向右走
                     [1, 0],  # 向下走
                     [0, -1],  # 向左走
                     [-1, 0]  # 向上走
                     ]
        visit = [[0] * grid[0].__len__() for i in range(grid.__len__())]
        row = grid.__len__()
        col = grid[0].__len__()
        def find1():
            for i in range(row):
                for j in range(col):
                    if grid[i][j]==1:
                        return i,j
            return -1,-1
        def get_perimeter(x,y):
            tmp=4
            for i in range(len(next_step)):
                next_x = x + next_step[i][0]
                next_y = y + next_step[i][1]
                if (next_x < 0 or next_y < 0 or next_x >= row or next_y >= col):
                    continue
                if grid[next_x][next_y]==1: #-1不会报错！
                    tmp-=1
            return tmp


        i,j=find1()
        if i==-1:
            return 0

        list1=[]
        node_step=0
        node_x,node_y=i,j
        node_sum=get_perimeter(node_x,node_y)
        list1.append((node_x,node_y,node_step,node_sum))
        visit[node_x][node_y]=1

        rs=0
        while list1:
            node_x, node_y, node_step, node_sum=list1.pop(0)
            rs+=node_sum

            for i in range(len(next_step)):
                next_x = node_x + next_step[i][0]
                next_y = node_y + next_step[i][1]

                if (next_x < 0 or next_y < 0 or next_x >= row or next_y >= col) or visit[next_x][next_y]==1:
                    continue

                if grid[next_x][next_y]==1:
                    # tmp_sum = node_sum + get_perimeter(next_x, next_y)
                    tmp_sum = get_perimeter(next_x, next_y)
                    list1.append((next_x,next_y,node_step+1,tmp_sum))
                    visit[next_x][next_y]=1
        return rs
```
