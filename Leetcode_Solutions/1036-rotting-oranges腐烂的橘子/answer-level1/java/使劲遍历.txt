### 解题思路
1.找出所有腐烂橘子的坐标
2.循环腐烂橘子的坐标，将其相邻的上下左右格子的鲜橘子腐烂；
3.如果已经没有鲜橘子或者鲜橘子无法被腐烂，则结束循环

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        int result = 0;
        boolean done = false;
        while (!done) {
            List<int[]> rottingIdx = new ArrayList<>();
            int xx = 0;
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    if (grid[i][j] == 2) {
                        int[] arr = {i, j};
                        rottingIdx.add(arr);
                        xx++;
                    }
                }
            }
            int spreadCount = 0;
            if (rottingIdx != null && rottingIdx.size() > 0) {
                for (int i = 0; i < rottingIdx.size(); i++) {
                    if (rottingIdx.get(i)[0] - 1 >= 0 && grid[rottingIdx.get(i)[0] - 1][rottingIdx.get(i)[1]] == 1) {
                        spreadCount++;
                        grid[rottingIdx.get(i)[0] - 1][rottingIdx.get(i)[1]] = 2;
                    }
                    if (rottingIdx.get(i)[0] + 1 < grid.length && grid[rottingIdx.get(i)[0] + 1][rottingIdx.get(i)[1]] == 1) {
                        spreadCount++;
                        grid[rottingIdx.get(i)[0] + 1][rottingIdx.get(i)[1]] = 2;
                    }
                    if (rottingIdx.get(i)[1] - 1 >= 0 && grid[rottingIdx.get(i)[0]][rottingIdx.get(i)[1] - 1] == 1) {
                        spreadCount++;
                        grid[rottingIdx.get(i)[0]][rottingIdx.get(i)[1] - 1] = 2;
                    }
                    if (rottingIdx.get(i)[1] + 1 < grid[0].length && grid[rottingIdx.get(i)[0]][rottingIdx.get(i)[1] + 1] == 1) {
                        spreadCount++;
                        grid[rottingIdx.get(i)[0]][rottingIdx.get(i)[1] + 1] = 2;
                    }
                }
            }
            if (spreadCount == 0) {
                int yy = 0;
                for (int i = 0; i < grid.length; i++) {
                    for (int j = 0; j < grid[i].length; j++) {
                        if (grid[i][j] == 1) {
                            yy++;
                        }
                    }
                }
                if (yy > 0) {
                    result = -1;
                }
                done = true;
                break;
            }
            result++;
            int zz = 0;
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    if (grid[i][j] == 1) {
                        zz++;
                    }
                }
            }
            if (zz == 0) {
                done = true;
            }
        }
        return result;
    }
}
```