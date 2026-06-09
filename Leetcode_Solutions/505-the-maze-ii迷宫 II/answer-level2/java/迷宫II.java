### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        //建立一个函数distance，表示该点到迷宫终点的距离
        int [][]distance =new int[maze.length][maze[0].length];
        for(int [] row:distance)
            Arrays.fill(row,Integer.MAX_VALUE);
        distance[start[0]][start[1]]=0;
        dfs(maze,start,distance);
        return distance[destination[0]][destination[1]]==Integer.MAX_VALUE? -1:distance[destination[0]][destination[1]];
    }

    public void dfs(int [][] maze,int [] start,int [][]distance){
        int [][]dirs={{0,1},{0,-1},{-1,0},{1,0}};
        for(int [] dir:dirs)
        {
            int x=start[0]+dir[0];
            int y=start[1]+dir[1];
            int count=0;
            while(x>=0&&y>=0&&x<maze.length&&y<maze[0].length&&maze[x][y]==0){
                x+=dir[0];
                y+=dir[1];
                count++;
            }
            if(distance[start[0]][start[1]]+count<distance[x-dir[0]][y-dir[1]])
            {
                distance[x-dir[0]][y-dir[1]]=distance[start[0]][start[1]]+count;
                dfs(maze,new int[]{x-dir[0],y-dir[1]},distance);
            }
        }
    }
}
```