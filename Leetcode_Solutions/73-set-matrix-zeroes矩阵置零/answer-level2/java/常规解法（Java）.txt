```
class Solution {
    public void setZeroes(int[][] matrix) {
        int rows = matrix.length;
        if(rows == 0) return;
        int cols = matrix[0].length;

        //寻找含0的行和列
        Set<Integer> zRow = new HashSet<Integer>();
        Set<Integer> zCol = new HashSet<Integer>();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    zRow.add(i);
                    zCol.add(j);
                }
            }
        }
        for(Integer i : zRow) {
            for(int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
        }
        for(Integer i : zCol) {
            for(int j = 0; j <rows; j++) {
                matrix[j][i] = 0;
            }
        }
    }
}
```
