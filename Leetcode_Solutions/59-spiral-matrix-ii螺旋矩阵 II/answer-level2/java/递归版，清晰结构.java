```
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        generate(ans, 0, 0, n - 1, n - 1, 1);
        return ans;
    }

    // 由左上方点和右下方点确定一个圈，以start数字开始填充这个圈就好了，结构清晰。
    private void generate(int[][] ans, int leftTopRow, int leftTopCol, int rightBottomRow, int rightBottomCol,int start) {
        if (leftTopRow > rightBottomRow) {
            return;
        }
        if (leftTopRow == rightBottomRow) {
            ans[leftTopRow][leftTopCol] = start;
            return;
        }
        for (int i = leftTopCol; i < rightBottomCol ; i++) {
            ans[leftTopRow][i] = start;
            start++;
        }
        for (int i = leftTopRow; i < rightBottomRow ; i++) {
            ans[i][rightBottomCol] = start;
            start++;
        }
        for (int i = rightBottomCol; i > leftTopCol ; i--) {
            ans[rightBottomRow][i] = start;
            start++;
        }
        for (int i = rightBottomRow; i > leftTopRow ; i--) {
            ans[i][leftTopCol] = start;
            start++;
        }
        generate(ans, leftTopRow + 1, leftTopCol + 1, rightBottomRow - 1, rightBottomCol - 1, start);
    }
}
```
