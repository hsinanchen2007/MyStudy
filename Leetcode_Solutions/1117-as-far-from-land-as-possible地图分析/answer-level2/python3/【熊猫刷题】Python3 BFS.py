```
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int: 
        from collections import deque
        length=len(grid)
        temp_queue=deque()
        #find all islands
        for row in range(length):
            for col in range(length):
                if grid[row][col]==1:
                    temp_queue.append([row,col])
        hasOcean=False
        temp_point=None
        while temp_queue:
            temp_point=temp_queue.popleft()
            x,y=temp_point
            for x_bias,y_bias in [[0,1],[0,-1],[1,0],[-1,0]]:
                new_x=x+x_bias
                new_y=y+y_bias
                if new_x<0 or new_x>=length or new_y<0 or new_y>=length or grid[new_x][new_y]!=0:
                    continue
                grid[new_x][new_y]=grid[x][y]+1
                hasOcean=True
                temp_queue.append([new_x,new_y])
        if temp_point==[] or not hasOcean:
            return -1
        else:
            return grid[temp_point[0]][temp_point[1]]-1

```
