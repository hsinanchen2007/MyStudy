### 解题思路
尴尬 - 

### 代码

```java
class Solution {

public int maxDistance(int[][] grid) {
        //BFS 多起点的
        //定义数组 , 确定四个搜索的位置
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        //创建一个队列
        Queue<int[]> queue = new ArrayDeque<>();
        //将所有的陆地入队
        for (int m = 0; m < grid.length; m++) {
            for (int n = 0;n < grid.length;n ++) {
                //如果是陆地的话入队
                if (grid[m][n] == 1) {
                    int[] point = new int[]{m,n};
                    queue.offer(point);
                }
            }
        }
        //遍历队列
        int[] point = new int[2];
        //避免出现全是陆地,或者全是海洋的情况 , 增加标记
        boolean hasOceanus = false;
        while (!queue.isEmpty()) {
            //poll : 返回并移除 : 陆地出队
            point = queue.poll();
            int[] newpoint = new int[2];
            for (int i = 0; i < 4; i++) {
                //获取到新的四个位置
                newpoint[0] = point[0] + dx[i];
                newpoint[1] = point[1] + dy[i];
                //判断临界条件,以及是不是陆地(或者该路径走过)
                if (newpoint[0] < 0 || newpoint[1] < 0 ||
                        newpoint[0] >= grid.length || newpoint[1] >= grid.length ||
                        grid[newpoint[0]][newpoint[1]] != 0) {
                    continue;
                }
                hasOceanus = true;
                //记录距离 : 陆地 数值 1 海洋 数值 0 (原数值加1,表示距离加一了)
                grid[newpoint[0]][newpoint[1]] = grid[point[0]][point[1]] + 1;
                //新的四个位置入队
                queue.offer(new int[]{newpoint[0],newpoint[1]});
            }
        }
        //该结果即是最远的距离
        if (hasOceanus) {
            return grid[point[0]][point[1]] - 1;
        } else {
            return -1;
        }
    }
}
```