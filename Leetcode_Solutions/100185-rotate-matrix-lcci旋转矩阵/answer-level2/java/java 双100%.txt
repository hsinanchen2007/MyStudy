```
class Solution {
    public void rotate(int[][] matrix) {
        int count = -1;
        int n = matrix[0].length;
        for (int round = n - 1; round > 0; round -= 2) {
            ++count;
            for (int i = 0; i < round; i++) {
                int temp = matrix[count + i][count];
                matrix[count + i][count] = matrix[n - 1 - count][count + i];
                matrix[n - 1 - count][count + i] = matrix[n - 1 - count - i][n - 1 - count];
                matrix[n - 1 - count - i][n - 1 - count] = matrix[count][n - 1 - count - i];
                matrix[count][n - 1 - count - i] = temp;
            }
        }
    }
}
```
