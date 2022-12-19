```
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m=matrix.length;
        if (m==0) return false;
        int n=matrix[0].length;
        if (n==0) return false;
        int row=m-1;
        while (row>=0&&matrix[row][0]>target) row--;
        if (row==-1) return false;
        int cols=0;
        while (cols<n&&matrix[row][cols]!=target) cols++;
        if (cols==n) return false;
        return true;
    }
}

```
