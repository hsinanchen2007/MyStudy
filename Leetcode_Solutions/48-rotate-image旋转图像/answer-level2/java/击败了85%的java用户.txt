```
leetcode 48. 旋转图像

public void rotate(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return;
        }
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = matrix.length - 1;
        int colEnd = matrix[0].length - 1;

        while (rowStart < rowEnd) {
            help(matrix,rowStart,colStart,rowEnd,colEnd);
            rowStart++;
            colStart++;
            rowEnd--;
            colEnd--;
        }
    }

    private void help(int[][] matrix, int rowStart, int colStart, int rowEnd, int colEnd) {
        int time = rowEnd - rowStart;
        for (int i = 0; i < time; i++) {
            int tmp = matrix[rowStart][colStart + i];
            matrix[rowStart][colStart + i] = matrix[rowEnd - i][colStart];
            matrix[rowEnd - i][colStart] = matrix[rowEnd][colEnd - i];
            matrix[rowEnd][colEnd - i] = matrix[rowStart + i][colEnd];
            matrix[rowStart + i][colEnd] = tmp;

        }
    }
```
