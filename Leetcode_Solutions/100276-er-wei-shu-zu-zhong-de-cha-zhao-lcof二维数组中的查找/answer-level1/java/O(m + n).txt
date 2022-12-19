```
public boolean findNumberIn2DArray(int[][] matrix, int target) {
        int m = matrix.length;
        int n = 0;
        if (m == 0 || (n = matrix[0].length) == 0) {
            return false;
        }
        
        int i = 0;
        int j = n - 1;
        while(i < m && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
```
