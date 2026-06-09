对矩阵最外层转圈，转完之后操作里面的矩阵，对里面矩阵的最外层转圈，直到从外到里每一圈都转一遍。
感觉用递归的话比较好写，没啥边界条件要判断。
```
class Solution {
    int tmp = 0;
    public void rotate(int[][] matrix) {
        rotateOutter(matrix, 0, matrix.length);
    }

    // 旋转当前矩阵的最外圈（posPoint用于定位当前被旋转矩阵的左上角，左上角为matrix[posPoint][posPoint]）
    private void rotateOutter(int[][] matrix, int posPoint, int sideLen) {
        if (sideLen <= 1) {
            return;
        }
        int finalPoint = posPoint + sideLen - 1;
        for (int i = 0; i < sideLen - 1; i++) {
            tmp = matrix[posPoint][posPoint + i];
            matrix[posPoint][posPoint + i] = matrix[finalPoint - i][posPoint];
            matrix[finalPoint - i][posPoint] = matrix[finalPoint][finalPoint - i];
            matrix[finalPoint][finalPoint - i] = matrix[posPoint + i][finalPoint];
            matrix[posPoint + i][finalPoint] = tmp;
        }
        // 当前矩阵最外圈旋转完毕后，旋转内层矩阵的最外圈
        // (内层矩阵左上角为matrix[posPoint+1][posPoint+1]，同时边长比外层少2)
        rotateOutter(matrix, posPoint + 1, sideLen - 2);
    }
}
```
