
    public boolean isToeplitzMatrix(int[][] matrix) {
        for(int i=matrix.length-1;i>=1;i--)
        {
            for(int j=matrix[0].length-1;j>=1;j--)
                if(matrix[i][j]!=matrix[i-1][j-1])
                    return false;
        }
        return true;
    }
