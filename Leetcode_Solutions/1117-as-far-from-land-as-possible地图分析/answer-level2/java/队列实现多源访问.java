### 解题思路
①先将陆地全部入列；
②从每个陆地/已被访问过的海洋出发，碰到未被访问过的海洋就对其访问：并将其标号设为，访问其的陆地/海洋标号+1；并更新最远距离；
③直到没有没被访问的海洋，结束。

### 代码

```java
class Solution {
    int[] dx = {1,0,-1,0};
    int[] dy = {0,1,0,-1};

    public int maxDistance(int[][] grid) {

        int res=0;
        int N = grid.length;
        Queue<int[]> queue = new ArrayDeque();

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==1){
                    queue.offer(new int[]{i,j});
                }
            }
        }

        res = 0;
        while(!queue.isEmpty()){
            int[] temp = queue.poll();
            int x0 = temp[0], y0 = temp[1];
            //System.out.println("x0:"+x0+" y0:"+y0+" grid[x0][y0]:"+grid[x0][y0]);

            for(int i=0;i<4;i++){
                int x1 = x0+dx[i];
                int y1 = y0+dy[i];
                if(x1>=N||y1>=N||x1<0||y1<0) continue;
                if(grid[x1][y1]==0){
                    queue.offer(new int[]{x1,y1});
                    grid[x1][y1] = grid[x0][y0]+1;
                    //System.out.println("grid[x1][y1]"+grid[x1][y1]);
                    res = Math.max(res,grid[x1][y1]);
                }
                
            }



        }


        
        return res-1;
    }
}





```