# 方法一：
    **暴力破解**：从最大的阶数往最小的阶数依次遍历，扫描所有能组成指定阶数的正方形，查看正方形的边是否含有 0。（40 ms，46.7 MB）
```
public static int largest1BorderedSquare1(int[][] grid) {
    // 矩阵的高
    int height = grid.length;
    // 矩阵的宽
    int wide=grid[0].length;
    // 需要求正方形的阶数
    int orderNumber = height;
    while (orderNumber > 0) {
        // 行， 当前位置加要寻找的阶数不能大于行总长度
        for (int i = 0; i <= height - orderNumber; i++) {
            col:
            // 列， 当前位置加要寻找的阶数不能大于宽总长度
            for (int j = 0;j <= wide - orderNumber ;j++) {
                // 指针
                int row = i;
                int col = j;
                // 计算对角坐标
                int diagonalAngleRow = row + orderNumber - 1;
                int diagonalAngleCol = col + orderNumber - 1;
                // 检查上边是否含有0
                while (col <= diagonalAngleCol) {
                    if (grid[row][col++] == 0) {
                        continue col;
                    }
                }
                // 越界后，归位
                col = diagonalAngleCol;
                // 检查右边是否含有0
                while (row <= diagonalAngleRow) {
                    if (grid[row++][col] == 0) {
                        continue col;
                    }
                }
                // 检测下边是否含有0
                while (diagonalAngleCol >= j) {
                    if (grid[diagonalAngleRow][diagonalAngleCol--] == 0) {
                        continue col;
                    }
                }
                // 越界后，归位
                diagonalAngleCol = j;
                // 检测左边是否含有0
                while (diagonalAngleRow >= i) {
                    if (grid[diagonalAngleRow--][diagonalAngleCol] == 0) {
                        continue col;
                    }
                }
                // 返回阶数
                return orderNumber;
            }
        }
        orderNumber--;
    }
    return 0;
}
```
# 方法二：
    **动态规划**：我们可以维护一个三维数组对矩阵做预处理，第一维是矩阵的行的个数，第二维是矩阵列的个数，第三维长度为二，分别存储该下标对应于矩阵指定位置，右边 1 的个数和下边 1 的个数（包含自己）。当判断正方形的边是否都是 1 的时候，只需要判断正方形的左上角、右上角、左下角在三维数组值是否满足条件即可，不需要再遍历正方形的每条边。（15 ms，44.2 MB）
```
    public static int largest1BorderedSquare(int[][] grid) {
        if (grid.length == 0) {
            return 0;
        }
        int height = grid.length;
        int wide = grid[0].length;
        // 创建临时数组来对矩阵进行预处理，防止越界
        int[][][] temp = new int[height + 1][wide + 1][2];
        for (int i = height - 1; i >= 0; i--) {
            for (int j = wide - 1; j >= 0; j--) {
                // 如果当前数为1，则将其右边
                if (grid[i][j] == 1) {
                    // 右边
                    temp[i][j][0] = 1 + temp[i][j + 1][0];
                    // 下边
                    temp[i][j][1] = 1 + temp[i + 1][j][1];
                }
            }
        }
        // 要寻找的正方形的阶数
        int orderNumber = height;
        while (orderNumber > 0) {
            // 行， 当前位置加要寻找的阶数不能大于行总长度
            for (int i = 0; i <= height - orderNumber; i++) {
                // 列， 当前位置加要寻找的阶数不能大于宽总长度
                for (int j = 0; j <= wide - orderNumber; j++) {
                    // 左上角往右数1的个数要>=n
                    // 左上角往下数1的个数要>=n
                    // 左下角往右数1的个数要>=n
                    // 右上角往下数1的个数要>=n
                    if (temp[i][j][0] >= orderNumber && temp[i][j][1] >= orderNumber && temp[i + orderNumber-1][j][0] >= orderNumber && temp[i][j + orderNumber-1][1] >= orderNumber){
                        return orderNumber;
                    }
                }
            }
            orderNumber--;
        }
        return 0;
    }
```

