```
class Solution {
    public int matrixScore(int[][] A) {
        for(int[] row: A){
            if(isRowNeedK(row)){
                kRow(row);
            }
        }
        for (int col = 0; col < A[0].length; col++) {
            if(isRolNeedK(A, col)){
                kCol(A, col);
            }
        }
        // return Arrays.stream(A).mapToInt(this::sumRow).sum();

        int result = 0;
        for(int[] row: A){
            result += sumRow(row);
        }
        return result;
    }
    private int sumRow(int[] Arow){
        int result = 0;
        for (int i = 0; i < Arow.length; i++) {
            result = result*2 + Arow[i];
        }
        return result;
    }
    private boolean isRowNeedK(int[] row){
        return row[0] == 0;
    }


    private boolean isRolNeedK(int[][] A, int col){
        int c = 0;
        for (int[] ints : A) {
            if (ints[col] == 0) {
                c++;
            }
        }
        return c > A.length / 2;
    }

    private void kCol(int[][] A, int col) {
        for (int i = 0; i < A.length; i++) {
            A[i][col] = 1 - A[i][col];
        }
    }

    private void kRow(int[] row) {
        for (int i = 0; i < row.length; i++) {
            row[i] = 1 - row[i];
        }
    }
}
```