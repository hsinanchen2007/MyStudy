看了下题意，大致思路如下
1. 首先正向对角线镜面交换
2. 然后将镜面交换后的结果进行，前后按行进行中点交换

```
public void rotate(int[][] matrix) {
        int rowLength = matrix.length;
        int colLength = matrix[0].length;
        // swap elements diagonally
        for (int row = 0; row < rowLength; row++) {
            for (int col = 0; col < row + 1; col++) {
                if (row == col) {
                    continue;
                }
                int tmp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = tmp;
            }
        }
        // swap element one by one from end to front
        for (int row = 0; row < rowLength; row++) {
            int colStart = 0;
            int colEnd = colLength - 1;
            while (colStart <= colEnd) {
                int tmp = matrix[row][colStart];
                matrix[row][colStart] = matrix[row][colEnd];
                matrix[row][colEnd] = tmp;
                colStart++;
                colEnd--;
            }
        }
    }
```
