### 解题思路
使用一个队列，先把腐烂的橘子（的坐标）依次入队，然后从队头开始，弹出一个腐烂的橘子，同时将其四周的好橘子腐蚀并入队，时间time+1，依次进行直到队空，最后如果grid中好有好橘子则返回-1，否则返回time;   
time可以看作橘子是在第几批腐烂，因此，每次加入腐烂橘子四周的好橘子时，需要将time+1;

### 代码
```java []
class Solution {
    public int orangesRotting(int[][] grid) {
        int h=grid.length, w=grid[0].length, time=0;
        int[][] D = {{1,0},{-1,0},{0,1},{0,-1}};
        Queue<int[]> q = new LinkedList<>();
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(grid[i][j]==2){
                    q.offer(new int[]{i,j,time});
                }
            }
        }
        while(q.size()!=0){
            int[] tmp = q.poll();
            time = tmp[2];
            for(int[] d: D){
                int x = tmp[0]+d[0];
                int y = tmp[1]+d[1];
                if(x>=0 && x<h && y>=0 && y<w && grid[x][y]==1){
                    grid[x][y] = 2;
                    q.offer(new int[]{x,y,time+1});
                }
            }
        }
        for(int[] l: grid){
            for(int n: l){
                if(n==1) return -1;
            }
        }
        return time;
    }
}
```
```Python []
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        x,y,time = len(grid),len(grid[0]),0
        D,queue = [[-1,0],[0,-1],[0,1],[1,0]],[]  #四个方向的坐标和队列
        for i in range(x):
            for j in range(y):
                if grid[i][j] == 2:
                    queue.append((i,j,0))
        while queue:  
            i,j,time = queue.pop(0)
            for d in D:
                loc_i,loc_j = i+d[0],j+d[1]
                if 0 <=loc_i<x and 0<=loc_j<y and grid[loc_i][loc_j]==1:
                    grid[loc_i][loc_j] = 2
                    queue.append((loc_i,loc_j,time+1))
        for g in grid:  
            if 1 in g:
                return -1
        return time
```
