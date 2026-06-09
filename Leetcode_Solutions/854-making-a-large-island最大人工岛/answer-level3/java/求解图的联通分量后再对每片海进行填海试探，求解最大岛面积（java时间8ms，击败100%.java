思路：将整个二维数组看作一个图，通过dfs遍历整个图求解该图所有连通分量，并标记id；
        再次对整个二维数组进行遍历，对其中每一片"海"进行试探性填海，遍历所"填海"的四个相邻节点，若该节点为陆地，则判断其            联通分量id，与之前遍历过的相邻节点若不重复，则可以加上这片联通分量的面积；
        最后再通过这次"填海"获得的陆地面积与之前获得的最大陆地面积相比较，获得到目前为止的最大陆地面积；
具体代码如下：
```
//leetcode 827

import java.util.Arrays;
import java.util.Collections;

class Solution {
    private int[][] grid;
    private int[][] visited; //记录每一块陆地所对应的id
    private int R, C;
    private int cccount; //记录联通分量个数的变量
    private int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    public int largestIsland(int[][] grid) {
        this.grid = grid;
        R = grid.length;
        C = grid[0].length;
        visited = new int[R][C];
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C ; j ++)
                visited[i][j] = -1; //试图通过visited为每个联通分量赋值id

        for(int x = 0; x < R; x ++)
            for(int y = 0 ; y < C; y ++){
                if(visited[x][y] == -1 && grid[x][y] == 1) {
                    dfs(x, y);
                    cccount++;//联通分量数量
                }
            }
        if(cccount == 0) return 1;//如果图中全是海，直接返回1
        Integer[] area = new Integer[cccount];//记录各个联通分量面积大小
        for(int i = 0; i < area.length; i ++)
            area[i] = 0;
        for(int x = 0; x < R; x ++)
            for (int y = 0; y < C; y++)
                if(visited[x][y] != -1)
                    area[visited[x][y]] ++;

        int maxArea = Collections.max(Arrays.asList(area));//这里不能先+1，因为可能整个数组都是陆地
        for(int x = 0; x < R; x ++) {
            for (int y = 0; y < C; y++)
                if (visited[x][y] == -1) {
                    maxArea++;
                    break;
                }
            break;
        }
        for(int x = 0; x < R; x ++) {
            for (int y = 0; y < C; y++){
                if(visited[x][y] == -1) {
                    int curarea = 1;
                    //必须保证(x, y)相邻节点不是同一个联通分量的节点才能够相加
                    boolean[] flag = new boolean[cccount];//通过flag数组记录某个联通分量是否已经被加过
                    for (int d = 0; d < 4; d++) {
                        int netx = x + dirs[d][0], nety = y + dirs[d][1];
                        if (inArea(netx, nety) && visited[netx][nety] != -1 && !flag[visited[netx][nety]]) {
                            curarea += area[visited[netx][nety]];
                            flag[visited[netx][nety]] = true;
                        }
                    }
                    maxArea = Math.max(maxArea, curarea);
                }
            }
        }
        return maxArea;
    }
    private boolean inArea(int x, int y){return x >= 0 && x < R && y >= 0 && y < C;}
    private void dfs(int x, int y){
        visited[x][y] = cccount;
        for(int d = 0; d < 4; d ++){
            int netx = x + dirs[d][0], nety = y + dirs[d][1];
            if(inArea(netx, nety) && visited[netx][nety] == -1 && grid[netx][nety] == 1)
                dfs(netx, nety);
        }
    }
}
```

