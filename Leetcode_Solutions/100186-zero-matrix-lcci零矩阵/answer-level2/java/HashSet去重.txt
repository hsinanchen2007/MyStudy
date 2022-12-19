# 代码
```java
class Solution {
    public void setZeroes(int[][] matrix) {
        HashSet<Integer> row_set = new HashSet<>(), col_set = new HashSet<>();
        int row = matrix.length, col = matrix[0].length;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (matrix[i][j] == 0) {
                    row_set.add(i);
                    col_set.add(j);
                }
        for (int row_idx : row_set)
            Arrays.fill(matrix[row_idx], 0);
        for (int col_idx : col_set) {
            for (int i = 0; i < row; ++i)
                matrix[i][col_idx] = 0;
        }
    }
}
```
