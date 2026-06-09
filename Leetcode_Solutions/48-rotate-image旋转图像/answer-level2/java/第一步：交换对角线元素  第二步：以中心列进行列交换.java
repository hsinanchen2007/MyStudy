执行用时 :0 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :36 MB, 在所有 java 提交中击败了59.69%的用户
```
class Solution {
    public void rotate(int[][] matrix) {
        if(matrix == null || matrix.length < 1 || matrix[0].length < 1)
            return;
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j <= i; j++){
                swap(matrix, i, j);
            }
        }
        int start = 0;
        int end = matrix[0].length-1;
        while(start < end){
            for(int i = 0; i < matrix.length; i++){
                int temp = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = temp;
            }
            start++;
            end--;
        }
    }
    public void swap(int[][] matrix, int i, int j){
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
    }
}
```
