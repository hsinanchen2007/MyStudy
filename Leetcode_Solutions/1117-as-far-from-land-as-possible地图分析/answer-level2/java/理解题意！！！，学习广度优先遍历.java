### 解题思路
题意就是找一个海洋到最近的的陆地，拥有最远的距离。返回该距离
所以从每个陆地同时开始四周扩散找，最后找到的就是距离最近陆地最远的

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        //题意就是找一个海洋到最近的的陆地，拥有最远的距离。返回该距离
        //所以从每个陆地同时开始四周扩散找，最后找到的就是距离最近陆地最远的。
        int length = grid.length;
        Queue<int[]> lands = new ArrayDeque<>();
        for(int i = 0;i < length;i++){
            for(int j  = 0;j < length;j++){
                if(grid[i][j] == 1){
                    //这里不用add原因，offer对于满队列不会异常，返回false;
                    lands.offer(new int[]{i,j});
                }
            }
        }
        //没有陆地或全是陆地
        if(lands.size() == 0 || lands.size() == length * length){
            return -1;
        }
        //定义四周移动方向
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        int[] temp = null;
        while(!lands.isEmpty()){
            //以每一个陆地为起点，开始四周寻找
            temp = lands.poll();
            int x= temp[0];
            int y = temp[1];
            for(int i=0;i<4;i++){
                int nextX = x + dx[i];
                int nextY = y + dy[i];
                //防止越界，找到海洋，将海洋丢入
                if(nextX < length && nextX >= 0 && nextY < length && nextY >= 0 && grid[nextX][nextY] ==0){
                    grid[nextX][nextY] = grid[x][y] + 1; //标记距离;每一轮+1
                    lands.offer(new int[]{nextX,nextY});
                }
            }
        }
        //由于本身是从陆地开始的，初始值为1,反减回去
        return grid[temp[0]][temp[1]] - 1;

    }
}
```