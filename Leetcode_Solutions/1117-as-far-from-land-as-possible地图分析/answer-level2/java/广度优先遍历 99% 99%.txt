### 解题思路
关键思想及如何判断该位置是否遍历,我这里采用将二维数组变形，由于数组元素只存在0和1，则把所有为1的海洋变成-1，进行bfs的时候只需判断该位置是否为-1即可。

### 代码

```java
class Solution {
public int maxDistance(int[][] grid) {
        int N = grid.length;
        int count = 0;
        int k = 0;
        for (int[] i : grid) {
            for(int j=0;j<i.length;j++) {
                if (i[j]==1) {
                    i[j] = 0;
                    count++;
                } else
                    i[j] = -1;

            }
        }
        if (count == N * N || count == 0)
            return -1;
        while (count < N * N)
        {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (grid[i][j] == k) {
                        if (j > 0 && grid[i][j - 1] == -1) {
                            grid[i][j - 1] = k + 1;
                            count++;
                        }
                        if (i > 0 && grid[i - 1][j] == -1) {
                            grid[i - 1][j] = k + 1;
                            count++;
                        }
                        if (j < N - 1 && grid[i][j + 1] == -1) {
                            grid[i][j + 1] = k + 1;
                            count++;
                        }
                        if (i < N - 1 && grid[i + 1][j] == -1) {
                            grid[i + 1][j] = k + 1;
                            count++;
                        }

                    }


                }

            }
            k++;
        }
        int max = 0;
        for (int[] i : grid) {
            for (int j : i) {
                if (max < j)
                    max = j;
            }
        }
        return max;
    }
}
```