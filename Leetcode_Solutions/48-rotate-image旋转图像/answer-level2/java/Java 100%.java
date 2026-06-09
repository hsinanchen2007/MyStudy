### 解题思路
对角线翻转再行内翻转 因为要沿着对角线翻转所以 j=i 

 
### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
       int  n = matrix.length;        
       //对角线翻转
       for( int i = 0; i < n; i++){
           for(int j =i; j < n; j++){
               int tmp = matrix[i][j];
               matrix[i][j] = matrix[j][i];
               matrix[j][i] = tmp;
           }
       }
       // reverse 每一行
       for(int i = 0; i < n; i++){
           for(int j = 0; j < n/2; j++){
                int tmp = matrix[i][n-1-j];
                matrix[i][n-1-j] = matrix[i][j];
                matrix[i][j] = tmp;
           }
       }
    }
}
```