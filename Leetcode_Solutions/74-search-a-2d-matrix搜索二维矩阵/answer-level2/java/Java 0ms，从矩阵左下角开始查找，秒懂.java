    /**
     * 注意到：从矩阵左下角起，往上数值减少，往下数值增加，于是便可以从左下角起始点开始寻找
     */
    public boolean searchMatrix(int[][] matrix, int target) {
        int rowNum = matrix.length;
        if (rowNum == 0) return false;
        int colNum = matrix[0].length;
        if (colNum == 0) return false;

        int i = rowNum - 1;
        int j = 0;
        while (i >= 0 && j <= colNum - 1) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                j++;
            } else {
                i--;
            }
        }
        return false;
    }