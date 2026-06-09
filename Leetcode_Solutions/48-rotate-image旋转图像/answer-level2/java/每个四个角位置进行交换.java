```
class Solution {
    public void rotate(int[][] matrix) {
       if(matrix==null) return;
       int xs=0;int ys=0;
       int n=matrix.length-1;
       int xe=n-1;int ye=n-1;
       while(xs<=xe){
           for(int i=ys;i<ye;i++){
               int temp=matrix[xs][i];
               matrix[xs][i]=matrix[n-i][ys];
               matrix[n-i][ys]=matrix[xe][n-i];
               matrix[xe][n-i]=matrix[i][ye];
               matrix[i][ye]=temp;
           }
           xs=xs+1;ys=ys+1;
           xe=xe-1;ye=ye-1;
       }
    }
}
```
