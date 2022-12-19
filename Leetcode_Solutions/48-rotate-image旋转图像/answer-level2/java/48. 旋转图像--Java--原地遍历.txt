
```java
    /**
     * 解题思路：
     * 因为需要原地旋转（不借助另一个矩阵），可以考虑借助一个临时的存储位，接受被旋转位的数据
     * 考虑：如何找到旋转规律？==>纸上比划比划
     * 发现旋转规律：下一位的行等于上一位的列，下一位的列=n-上一位的行-1（-1是从0开始）
     * 代码实现：先从外部循环，结束后再逐步向内走，直到循环结束
     * <p>
     * 需要注意：循环结束条件
     *
     * @param matrix
     */
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        if (n == 1) return;
        int hn = n % 2 == 0 ? n / 2 : (n / 2 + 1);//一半取偶数的一半，奇数一半+1
        int rowI = 0, colI = 0;
        int nrowI, ncolI, tempI;//循环的下标
        int temp, preTemp;
        while (colI < n - 1 && rowI < n - 1) {
            nrowI = rowI;
            ncolI = colI;
            preTemp = matrix[nrowI][ncolI];
            //旋转遍历四次
            for (int i = 0; i < 4; i++) {
                //取旋转的位置
                tempI = nrowI;
                nrowI = ncolI;
                ncolI = n - 1 - tempI;
                temp = matrix[nrowI][ncolI];
                matrix[nrowI][ncolI] = preTemp;
                preTemp = temp;
            }
            //取下一位循环位置
            colI++;
            if (colI - rowI > n - rowI * 2 - 2) {  //每次向内缩一圈，少两位
                rowI++;
                colI = rowI;
                if (rowI >= hn) {
                    break;
                }
            }
        }
    }
```
