```
    public boolean searchMatrix(int[][] matrix, int target) {
        int row1 = 0, h = matrix.length;
        if (h == 0 || matrix[0].length == 0) return false;
        if (target < matrix[0][0] ||
                target > matrix[h - 1][matrix[0].length-1]) {
            return false;
        }
        if (h > 1){
            int row2 = row1 + 1;
            while (row2 < h){
                if (matrix[row1][0] <= target && matrix[row2][0] > target){
                    return find(matrix, row1, target);
                }
                row1 ++; row2 ++;
            }
            if (matrix[row1][0] <= target)
                return find(matrix, row1, target);
        }else {
            return find(matrix, 0, target);
        }
        return false;
    }

    private boolean find(int[][] matrix, int row, int target){
        int left = 0, right = matrix[row].length - 1;
        int mid = (left + right) >> 1;
        while (left <= right){
            if (matrix[row][mid] < target){
                left = mid + 1;
            }else if (matrix[row][mid] > target){
                right = mid - 1;
            }else if (matrix[row][mid] == target){
                return true;
            }
            mid = (left + right) >> 1;
        }
        return false;
    }
```
