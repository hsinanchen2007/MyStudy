```
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];

        if(matrix.length == 0)
            return matrix;

        int m = n;
        int top = 0;
        int left = 0;
        int num = 1;

        while(top < m){
            for(int i = left; i < n; i++)
                matrix[top][i] = num++;
            top++;

            for(int i = top; i < m; i++)
                matrix[i][n-1] = num++;
            n--;

            for(int i = n-1; i >= left; i--)
                matrix[m-1][i] = num++;
            m--;

            for(int i = m-1; i >= top; i--)
                matrix[i][left] = num++;
            left++;
        }
        return matrix;
    }
}
```
