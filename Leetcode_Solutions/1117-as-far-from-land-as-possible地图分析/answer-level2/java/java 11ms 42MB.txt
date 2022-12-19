### 解题思路
每一步扩大一圈海岸线，直到全部填成陆地，步数就是最大距离
数组记录单指针 代替每一步的集合类

### 代码

```java
class Solution {
    private static final int[][] DIRECTIONS = new int[][]{
            new int[]{-1, 0},
            new int[]{1, 0},
            new int[]{0, -1},
            new int[]{0, 1}
    };

    /**
     * BFS 每一步扩大一圈陆地，直到全部填成陆地，步数就是最大距离
     * @param grid
     * @return
     */
    public int maxDistance(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;
        int total = height * width;
        int[] nextLands = new int[total];
        int ptr = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 1)
                    nextLands[ptr++] = i * width + j;
            }
        }
        if (ptr == total) //全部是陆地
            return -1;
        int step = -1;
        while (ptr > 0) {
            int p = 0;
            int[] lands = new int[total];
            for (int i = 0; i < ptr; i++) {
                int x = nextLands[i] / width;
                int y = nextLands[i] % height;
                for (int[] d : DIRECTIONS) {
                    int dx = x + d[0], dy = y + d[1];
                    if (dx >= 0 && dx < height && dy >= 0 && dy < width && grid[dx][dy] == 0) {
                        grid[dx][dy] = 1;
                        lands[p++] = dx * width + dy;
                    }
                }
            }
            ptr = p;
            nextLands = lands;
            step++;
        }
        return step;
    }
}
```