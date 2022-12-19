import java.util.HashMap;
import java.util.Set;



class Solution {
 
    public int maximalSquare(char[][] matrix) {
           if(matrix==null || matrix.length==0 || matrix[0]==null) return 0;
        int column=matrix[0].length;
         int row=matrix.length;

         int maxBlock=Math.min(row,column);
         int n=0;
         int max=0;
         boolean[] isFindMax=new boolean[maxBlock+1];
         for(int i=0;i<row;i++){
             n=0;
             for(int j=0;j<column;j++){
               if(matrix[i][j]=='1'){
                   n++;
                   if( n<=maxBlock && !isFindMax[n] && i+n<=row) {
                       if (findSquard(n, matrix, i, j)) {
                           max = Math.max(n * n, max);
                           isFindMax[n] = true;
                       }else{
                           n--;
                       }
                   }
               }else{
                   n=0;
               }
             }
         }
         return max;
    }

    public boolean findSquard(int n,char[][] matrix,int i,int j){
        if(n==1) return true;
        for(int row=i+1;row<i+n;row++){
           for(int column=j-n+1;column<=j;column++){
               if(matrix[row][column]=='0'){
                   return false;
               }
           }
        }
        return true;
    }
}
