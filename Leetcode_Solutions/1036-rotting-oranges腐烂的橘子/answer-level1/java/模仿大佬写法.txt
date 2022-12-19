### 解题思路
跟大佬学到了好多
给每个橘子加入一个记录腐败时间变量，值为2的点的初始腐败时间为0
### 代码

```java
class Orange{
    int x;
    int y;
    int time;
    public Orange(int x,int y,int time){
        this.x = x;
        this.y = y;
        this.time = time;
    }
}
class Solution {
   
    public int orangesRotting(int[][] grid) {
        int[][] Dir = {{-1,0},{1,0},{0,-1},{0,1}};
        int m = grid.length;
        int n = grid[0].length;
        int time = 0;
        
        Queue<Orange> q =  new LinkedList<>();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==2){
                    q.add(new Orange(i, j, time) );
                }
            }
        }
        
        while(!q.isEmpty()){
            Orange t = q.poll();
            time = t.time;
            for(int[] dir : Dir){
                if(t.x + dir[0]>=0 && t.x + dir[0]<m && t.y+dir[1]>=0 && t.y+dir[1] <n){
                    if(grid[t.x+dir[0]][t.y+dir[1]] == 1){
                        grid[t.x+dir[0]][t.y+dir[1]] = 2; 
                        q.add(new Orange(t.x+dir[0], t.y+dir[1], time+1));        
                    }
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
        
        
    }
}
```