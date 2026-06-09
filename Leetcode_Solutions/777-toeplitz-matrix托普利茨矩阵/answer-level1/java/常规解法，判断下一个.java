执行用时 :
4 ms
, 在所有 Java 提交中击败了
73.00%
的用户
内存消耗 :
41.3 MB
, 在所有 Java 提交中击败了
89.04%
的用户


```
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
      boolean isTM = true;
      int i = 0,j = 0;
      for(j=0,i=0;j<matrix[0].length+1&&i<matrix.length;j++){
          if(j==matrix[0].length){
            i++;
            j=0;
          }
          int k=i,l=j;
          while(k+1<matrix.length&&l+1<matrix[0].length){
              if(matrix[k+1][l+1]!=matrix[k][l]){
                isTM = false;
                return isTM;
              }else{
                k++;
                l++;
              }
          }
      }
    
        return isTM;
    }
}``
```

可以优化到（m+n-1）*0.5min(m,n)次判断，但我懒