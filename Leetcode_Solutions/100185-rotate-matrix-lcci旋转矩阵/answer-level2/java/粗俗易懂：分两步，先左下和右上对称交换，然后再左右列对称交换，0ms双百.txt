```
class Solution {
    public void rotate(int[][] matrix) {
        // 思路:先对角进行交换，然后再进行左右列对称交换
        int rowNum = matrix.length;
        if (rowNum < 1) return;
        int colNum = matrix[0].length;
        if (colNum < 2) return;

        for (int row = 0; row < rowNum; row++){
            for (int col = row + 1; col < colNum; col++){
                swap(matrix, row, col);
            }
        }

        int leftCol = 0, rightCol = colNum-1;
        while (leftCol < rightCol){
            int curRow = 0;
            while (curRow < rowNum){
                int temp = matrix[curRow][leftCol];
                matrix[curRow][leftCol] = matrix[curRow][rightCol];
                matrix[curRow][rightCol] = temp;
                curRow++;
            }
            leftCol++;
            rightCol--;
        }
    }

    private void swap(int[][] matrix, int i, int j){
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
    }
}
```
