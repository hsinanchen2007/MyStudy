     * 1. 一开始难以着手。后来想想，也就是下标找规律。
     * 2. 规律不好找。 首先分为一圈一圈的，截止的数字要想好。 另外，下标需要加上i,row,col; 再者，i的截止也有要求。这三点比较难想全。
     * 3. 时间：0ms，100%；36.1MB，59.12
     * 4. 不知道内存为啥消耗这么多

```
public void rotate(int[][] matrix) {

        int length = matrix.length;
        int row = 0;
        int col = 0;

        while (row < length / 2) {
            // 最后一个有重叠
            for (int i = 0; i < length - 1 - row * 2; i++) {
                int temp = matrix[row][col + i];
                matrix[row][col + i] = matrix[length - row - 1 - i][col];
                matrix[length - row - 1 - i][col] = matrix[length - row - 1][length - col - 1 - i];
                matrix[length - row - 1][length - col - 1 - i] = matrix[row + i][length - col - 1];
                matrix[row + i][length - col - 1] = temp;
            }
            row++;
            col++;
        }
    }
```
