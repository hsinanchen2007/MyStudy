### 解题思路
和前面有一道题差不多，前面一道题用bfs可以通过，这道题不行，这道题要换个思路bfs

### 代码

```java
class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        Queue<int[]> queue = new LinkedList<>();
        // 对每个点bfs
        final int[][] direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    queue.add(new int[]{i, j});
                } else {
                    matrix[i][j] = Integer.MAX_VALUE;
                }
            }
        }
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] axis = queue.poll();
                int x = axis[0];
                int y = axis[1];
                for (int[] ints : direction) {
                    int a = ints[0] + x;
                    int b = ints[1] + y;
                    if (a >= 0 && a < matrix.length && b >= 0 && b < matrix[0].length) {
                        if (matrix[a][b] > matrix[x][y] + 1) {
                            matrix[a][b] = matrix[x][y] + 1;
                            queue.add(new int[]{a, b});
                        }
                    }
                }
            }
        }
        return matrix;
    }
}
```