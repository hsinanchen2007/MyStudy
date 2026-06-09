由于不像机器人运动范围一题，冯进入一个格子加一，可以用回溯算法，深度优先搜索算法dfs实现。但是这一题是向四个方向传染一次，又或者说同一父节点的孩子节点全都给一个值，所以这里用广度优先算法bfs实现。
bds通常要用到队列来实现，模板如下：

初始化队列Q；
Q={起点s}；
标志s已访问;
while(Q非空){
    取队首元素u; //u出列
    if(u == 目标状态){......}
    所有与u相邻未被访问的点进入队列;
    标记u已访问;
}

本题由于还要计算橘子被污染时间，所以用Map(腐烂的橘子位置 ，被腐烂的时间)记录.
```
import java.util.LinkedList;
import java.util.HashMap;

class Solution {
    public int orangesRotting(int[][] grid) {
        LinkedList<Integer> queue = new LinkedList<Integer>();
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int i=0; i<grid.length; ++i){
            for (int j=0; j<grid[0].length; ++j){
                if (grid[i][j] == 2){
                    queue.add(i * grid[0].length + j);
                    map.put(i* grid[0].length+ j, 0);
                }
            }
        }

        int[] di = {-1, 1, 0, 0};
        int[] dj = {0, 0, -1, 1};
        int minute = 0;
        while(!queue.isEmpty()){
            int point = queue.remove();
            int i = point / grid[0].length, j=point % grid[0].length;
            for (int k=0; k<4; ++k){
                int r = i + di[k], c = j + dj[k];
                if (r>=0 && r<grid.length && c>=0 && c<grid[0].length && grid[r][c]==1){
                    grid[r][c] = 2;
                    queue.add(r * grid[0].length + c);
                    map.put(r * grid[0].length + c, map.get(point) + 1);
                    minute = minute>map.get(point) + 1? minute: map.get(point) + 1;
                }
            }
        }


        for (int i=0; i<grid.length; ++i){
            for (int j=0; j<grid[0].length; ++j){
                if (grid[i][j] == 1) return -1;
            }
        }

        return minute;
    }
}
```
