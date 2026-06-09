用数组控制填充方向，按上右下左的顺序、当下一个单元格值为0亦即没有填充过时，递归填充就好了。详见注释
```
class Solution {
    int[][] dir = {
            {-1, 0},//上
            {0, 1},//右
            {1, 0},//下
            {0, -1}//左
    };

    public int[][] generateMatrix(int n) {
        if (n <= 0) return new int[0][];
        int[][] reuslt = new int[n][n];
        fillMatrix(0, 0, 1, n, 0, reuslt);
        return reuslt;
    }

    private void fillMatrix(int row, int col, int index, int n, int direction, int[][] result) {
        
        result[row][col] = index;//填充本行
        if (index == (n * n)) return;//递归终止条件
        //填充下一行
        int nextRow = row + dir[direction][0];//下一行号
        int nextCol = col + dir[direction][1];//下一列号
        if (checkBorder(nextRow, nextCol, n) && result[nextRow][nextCol] == 0) {//下一格可以填充
            fillMatrix(nextRow, nextCol, index + 1, n, direction, result);
        } else {//不能填充
            for (int i = 1; i < 4; i++) {
                direction = (direction + 1) % 4;//更新direction，填充方向
                nextRow = row + dir[direction][0];
                nextCol = col + dir[direction][1];
                if (!(checkBorder(nextRow, nextCol, n) && result[nextRow][nextCol] == 0)) continue;//这个direction不能用，继续换方向
                fillMatrix(nextRow, nextCol, index + 1, n, direction, result);
            }
        }

    }

    //检验下一个单元格是否在矩阵内
    private boolean checkBorder(int row, int col, int n) {
        return (row >= 0 && row < n) && (col >= 0 && col < n);
    }
}
```
