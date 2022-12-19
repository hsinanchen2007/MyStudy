### 解题思路
先遍历地图，找出陆地部分加入队列，再遍历队列，从每个陆地的上下左右向外搜索，若有海水(0)，将海水设为1，加入队列，直到地图中所有位置全为1，说明此时每个区域都已遍历，定义distance来记录距离陆地最遥远的海水区域，每遍历一次distance+1，distance初始值为-1，是因为最后一次遍历时，地图中已不再有海水区域了。

### 代码

```java
class Solution {
      public int maxDistance(int[][] grid) {
        int m = grid.length; // 行
        int n = grid[0].length; //列
        int distance = -1;
        int[][] direction = {{-1,0},{1,0},{0,-1},{0,1}};
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    queue.add(new int[]{i,j});
                }
            }
        }
        if(queue.isEmpty() || queue.size() == m*n) return -1;
        while(queue.size() != 0) {
            distance++;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] land = queue.poll();
                for (int j = 0; j < 4; j++) {
                    int x = direction[j][0] + land[0], y =direction[j][1]+land[1];
                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        queue.add(new int[]{x, y});
                    }
                }
            }
        }
        return distance;
    }
}
```