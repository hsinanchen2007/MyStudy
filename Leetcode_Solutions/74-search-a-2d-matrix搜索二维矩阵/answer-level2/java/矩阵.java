```
public boolean searchMatrix(int[][] matrix, int target) {
    int l = matrix.length;
    if (matrix.length == 0) {
        return false;
    }
    int i = 0;
    int j = matrix[0].length;

    while(i < l && j >= 0) {
        if (target == matrix[i][j] ) {
            return true;
        } else if (target < matrix[i][j]) {
            j--;
        } else {
            i++;
        }
    }
    return false;
}
```
