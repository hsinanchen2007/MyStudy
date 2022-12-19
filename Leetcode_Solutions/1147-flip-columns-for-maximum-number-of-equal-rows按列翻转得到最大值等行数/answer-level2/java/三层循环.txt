```java
class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int ans = 0;
        int rows = matrix.length;
        int cols = matrix[0].length;
        int[] row;
        int[] cur;
        for (int i = 0; i < rows; i++) {
            row = matrix[i];
            int num = 1;
            for (int j = i + 1; j < rows; j++) {
                cur = matrix[j];
                int k;
                if (row[0] == cur[0]) {
                    for (k = 0; k < cols; k++) {
                        if (row[k] != cur[k]) {
                            break;
                        }
                    }
                } else {
                    for (k = 0; k < cols; k++) {
                        if (row[k] + cur[k] != 1) {
                            break;
                        }
                    }
                }
                if (k == cols) {
                    num++;
                }
            }
            ans = Math.max(ans, num);
        }
        return ans;
    }

}
```
