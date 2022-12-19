思路：遍历每一行，
        遇到0时，将该元素所在列上方的元素置为0，并将haveZero设为true（变量标记该行是否出现过零）；
        遇到非0时，检查该元素上方的元素是否为0，若为0，说明该列出现过0，则该元素置为0
        遍历该行结束后，检查lastHaveZero(上一行是否出现过零的标记)，true则将上一行全置为0，然后将haveZero的值赋给
        lastHaveZero，开始遍历下一行。
        最后一行特殊处理一下即可    
```
/** 空间复杂度 O(1) */
    public void setZeroes(int[][] matrix) {
        // 标志当前行是否出现过0
        boolean haveZero;
        int lastHang;
        // 标志上一行是否应该全是0
        boolean lastHaveZero = false;
        for (int i = 0; i < matrix.length; i++) {
            haveZero = false;
            lastHang = i - 1;
            if (lastHang < 0){
                lastHang = 0;
            }
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == 0){
                    haveZero = true;
                    // 仅当0是该列首次出现时，才迭代当前元素上边的元素
                    if (matrix[lastHang][j] != 0){
                        for (int k = i - 1; k >= 0; k--) {
                            matrix[k][j] = 0;
                        }
                    }
                }
                if (matrix[lastHang][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if (lastHaveZero){
                for (int k = 0; k < matrix[lastHang].length; k++) {
                    matrix[lastHang][k] = 0;
                }
            }
            lastHaveZero = haveZero;
        }
        lastHang = matrix.length - 1;
        if (lastHaveZero){
            for (int k = 0; k < matrix[lastHang].length; k++) {
                matrix[lastHang][k] = 0;
            }
        }
    }
```
