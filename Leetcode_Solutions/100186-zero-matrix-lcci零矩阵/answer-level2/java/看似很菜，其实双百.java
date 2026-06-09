
    //就是弄个等于老数组的新数组判断是否为0  为0就把老数组相应位置清零即可。我自己都觉得很蠢，结果跑出来是双百
    // 注意不能直接new个数组等于老数组  必须挨个赋值  直接等于那就指向一个地址 就是一个数组了。
    public void setZeroes(int[][] matrix) {
        int row = matrix.length;
        int col = matrix[0].length;
        int[][] tmp = new int[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                tmp[i][j] = matrix[i][j];
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (tmp[i][j] == 0) {
                    for (int m = 0; m < row; m++) {
                        matrix[m][j] = 0;
                    }
                    for (int n = 0; n < col; n++) {
                        matrix[i][n] = 0;
                    }
                }
            }
        }
    }