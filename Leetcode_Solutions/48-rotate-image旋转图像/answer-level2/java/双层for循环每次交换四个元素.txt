### 解题思路
每次交互都是四个点的交互，找出四个点的关系，就可以轻松解决问题。

### 代码

```java
class Solution {
     public void rotate(int[][] matrix) {
        int len = matrix.length;
        if (len <= 1) return;
        for (int i = 0; i < len / 2; i++) {
            for (int j = i; j < len - i - 1; j++) {
                swap(matrix, len, i, j);
            }
        }
    }

    private void swap(int[][] matrix, int len, int row, int col) {
        len -= 1;
        int tmp = matrix[row][col];
        matrix[row][col] = matrix[len - col][row];
        matrix[len - col][row] = matrix[len - row][len - col];
        matrix[len - row][len - col] = matrix[col][len - row];
        matrix[col][len - row] = tmp;
    }
}
```