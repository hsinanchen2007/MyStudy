### 解题思路
以陆地点为基础，向上下左右四个方向扩散，扩散到的海洋的将其改为陆地，并作为下一组遍历的基础，典型的广度优先搜索算法

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        int[] dx = new int[]{1, -1, 0, 0};
        int[] dy = new int[]{0, 0, 1, -1};
        int size = grid.length;

        //存放所有陆地坐标
        Queue<int[]> earthQueue = new LinkedList<>();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j] == 1) {
                    earthQueue.add(new int[]{i, j});
                }
            }
        }

        int earthCount = earthQueue.size();
        if (earthCount == 0 || earthCount == size * size) {
            return -1;
        }

        int minDistance = 0;
        while (!earthQueue.isEmpty()) {
            int curCount = earthQueue.size();

            //用来标记本次是否遍历到海洋,即如果遍历到海洋,则遍历次数加一,否则不用加一
            boolean hasOcean = false;

            //每一次以本轮遍历到的陆地为基础向四个方向遍历,如果遇到海洋,则将其置为陆地,并添加到队列中
            for (int i = 0; i < curCount; i++) {

                //从队列中拉取坐标
                int[] point = earthQueue.poll();
                for (int k = 0; k < 4; k++) {
                    int x = point[0] + dx[k];
                    int y = point[1] + dy[k];
                    if ((x >= 0 && x < size && y >= 0 && y < size) && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        earthQueue.add(new int[]{x, y});
                        hasOcean = true;
                    }

                }
            }

            if (hasOcean) {
                minDistance++;
            }
        }

        return minDistance;
    }
}

```