#### 遍历整个矩阵, 当遇到grid[i][j]==1时, 从(i,j)向四周扩散,寻找相邻的1, 扩散的过程可以用bfs模拟或者dfs模拟, 这里采用的是bfs, 
#### 扩散过程中使用boolean[][]数组记录已访问过的坐标

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        if(grid==null || grid.length==0 || grid[0]==null || grid[0].length==0){
            return 0;
        }
        int n = grid.length, m = grid[0].length;
        // 记录已访问过的坐标
        boolean[][] flag = new boolean[n][m];
        // 最终结果, 初始值为0
        int max=0;
        //遍历矩阵
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //如果当前位置是0或者当前位置访问过, 则进入下一轮循环
                if(grid[i][j]==0 || flag[i][j]==true){
                    continue;
                }
                //当前位置是1, 并且没有访问过, 从这里开始向四周扩散, 返回扩散的最大面积
                int cur = bfs(grid, flag, i, j);
                max = Math.max(max, cur);
            }
        }
        return max;
    }

    // 用来表示上下左右四个移动方向
    private int[][] moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    // 使用bfs进行扩散, 并返回扩散结束后占据的面积
    private int bfs(int[][] grid, boolean[][] flag, int i, int j){
        int n = grid.length, m = grid[0].length;
        // 扩散面积初始值是1, 因为grid[i][j]==1
        int res = 1;
        // 辅助bfs的队列
        LinkedList<int[]> queue = new LinkedList<>();
        queue.add(new int[]{i,j});
        flag[i][j] = true;
        // bfs主体循环
        while(!queue.isEmpty()){
            int[] cur = queue.poll();
            // 当前位置进行上下左右移动
            for(int[] move : moves){
                int x = cur[0]+move[0];
                int y = cur[1]+move[1];
                // 如果移动后的坐标不越界并且移动后的坐标对应的值为1, 同时还没有访问过, 说明该位置有效
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && flag[x][y]==false){
                    queue.add(new int[]{x, y});
                    flag[x][y] = true;
                    //扩散面积加1
                    res++;
                }
            }
        }
        return res;
    }
}
```