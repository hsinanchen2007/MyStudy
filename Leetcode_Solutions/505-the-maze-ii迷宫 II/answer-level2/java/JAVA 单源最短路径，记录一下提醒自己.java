上次做打卡题的多源最短路径的时候已经超时过一次，没有逆转思路还是按照以前的DFS思维做题，这次也没有转过来
下次碰到最短路径题目一定要回想起来。

DFS 430ms
```
class Solution {
    int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int m;
    int n;
    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        m = maze.length;
        if(m == 0)return  -1;
        n = maze[0].length;
        int[][] dist = new int[m][n];
        for(int i=0;i<m;i++){
            Arrays.fill(dist[i],-1);
        }
        dist[start[0]][start[1]] = 0;
        DFS(maze,start,dist);
        return dist[destination[0]][destination[1]];
    }

    public void DFS(int[][] maze,int[] cur,int[][] dist){  
        //System.out.println(cur[0] + " "+cur[1]);
        for(int i=0;i<4;i++){
            int x = cur[0];
            int y = cur[1];
            int temp = 0;
            while((x + dirs[i][0])>=0 && (x + dirs[i][0])<m && (y + dirs[i][1])>=0 && (y + dirs[i][1])<n
                    && maze[x + dirs[i][0]][y + dirs[i][1]] == 0){
                x = x + dirs[i][0];
                y = y + dirs[i][1];
                temp++;
            }       
            if(dist[x][y] == -1 || dist[x][y] > (dist[cur[0]][cur[1]] + temp)){
                //System.out.println(x + " "+y + " "+ temp);
                dist[x][y] = dist[cur[0]][cur[1]] + temp;
                DFS(maze,new int[]{x,y},dist);  
            }
        }

        return;
    }
}
```

BFS 11ms
```
class Solution {
    int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int m;
    int n;
    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        m = maze.length;
        if(m == 0)return  -1;
        n = maze[0].length;
        int[][] dist = new int[m][n];
        for(int i=0;i<m;i++){
            Arrays.fill(dist[i],-1);
        }
        dist[start[0]][start[1]] = 0;
        Deque<int[]> que = new LinkedList();
        que.offer(start);
        while(!que.isEmpty()){
            int[] cur = que.poll();
            for(int i=0;i<4;i++){
                int x = cur[0];
                int y = cur[1];
                int temp = 0;
                while((x + dirs[i][0])>=0 && (x + dirs[i][0])<m && (y + dirs[i][1])>=0 && (y + dirs[i][1])<n
                        && maze[x + dirs[i][0]][y + dirs[i][1]] == 0){
                    x = x + dirs[i][0];
                    y = y + dirs[i][1];
                    temp++;
                }       
                if(dist[x][y] == -1 || dist[x][y] > (dist[cur[0]][cur[1]] + temp)){
                    dist[x][y] = dist[cur[0]][cur[1]] + temp;
                    que.offer(new int[]{x,y});
                }
            }
        }
        return dist[destination[0]][destination[1]];
    }
}
```

