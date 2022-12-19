# 思路
根据每个点的旋转规律进行单步旋转。


# 代码
```
public void rotate(int[][] matrix) {
    int n = matrix.length;
    // 需要翻转的矩阵个数n/2，开始元素分别为(0,0),(1,1),...以此类推
    for (int i = 0; i < n / 2; i++) {
        // 起始元素(i,i)
        int row = i;
        // 需要从(i,i) 循环到 (i,m-1)进行旋转，因为(i,i)会旋转n-1格到(i,m)的位置上
        int m = n - i - 1;
        for (int column = i; column < m; column++) {
            int crt = matrix[row][column]; // 当前元素
            for (int j = 0; j < 4; j++) {
                // 每个元素都需要向前走m-i步
                int pre = crt;
                for (int k = 0; k < m - i; k++) {
                    if (row == i && column < m) {
                        column++;
                    } else if (column == m && row < m) {
                        row++;
                    } else if (row == m && column > i) {
                        column--;
                    } else if (column == i && row > i) {
                        row--;
                    }
                }
                crt = matrix[row][column];
                matrix[row][column] = pre;
            }
        }
    }
}
```
