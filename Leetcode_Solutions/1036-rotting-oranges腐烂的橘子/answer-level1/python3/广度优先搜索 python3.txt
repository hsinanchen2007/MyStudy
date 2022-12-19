```


class Solution(object):
    def orangesRotting(self, grid):
        #判断第0分钟就是最后结果的情况
        flag = 1
        for i in range(len(grid)):
            for j in range (len(grid[0])):
                if grid[i][j] == 1:
                    flag = 0
        if flag == 1:
            return 0     

        my_queque = []
        result = 0
        #将坏橘子加入队列
        for i in range(len(grid)):
            for j in range (len(grid[0])):
                if grid[i][j] == 2:
                    my_queque.append((i,j))
        #遍历当前队列，对其中的每一个坏橘子，让感染其上下左右的橘子，并将感染后的橘子加入队列，直到队列为空
        while my_queque:
            count = len(my_queque)
            result += 1
            for i in range(count):
                cur = my_queque.pop(0)
                if cur[0]-1 >= 0 and grid[cur[0]-1][cur[1]] == 1:
                    grid[cur[0]-1][cur[1]] = 2 if grid[cur[0]-1][cur[1]] == 1 else 0
                    my_queque.append((cur[0]-1,cur[1]))

                if cur[0]+1 <len(grid) and grid[cur[0]+1][cur[1]] == 1:
                    grid[cur[0]+1][cur[1]] = 2 if grid[cur[0]+1][cur[1]] == 1 else 0
                    my_queque.append((cur[0]+1,cur[1]))

                if cur[1] -1 >= 0 and grid[cur[0]][cur[1]-1] == 1:
                    grid[cur[0]][cur[1]-1] = 2 if grid[cur[0]][cur[1]-1] == 1 else 0
                    my_queque.append((cur[0],cur[1]-1))

                if cur[1]+1 <len(grid[0]) and grid[cur[0]][cur[1]+1] == 1:
                    grid[cur[0]][cur[1]+1] = 2 if grid[cur[0]][cur[1]+1] == 1 else 0
                    my_queque.append((cur[0],cur[1]+1))
        #如果结果仍有未感染的橘子，返回-1
        for i in range(len(grid)):
            if 1 in grid[i]:
                return -1
        
        return result-1
```
