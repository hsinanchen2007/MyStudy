### 解题思路
分两步做，先交换行再转置

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length ;
        changeRows(matrix,n) ;
        transposition(matrix,n) ;
    }
    public void changeRows(int[][] matrix,int n){
        for(int i = 0 ; i < n / 2 ; i++){
            int[] temp = Arrays.copyOf(matrix[i],n) ;
            matrix[i] = Arrays.copyOf(matrix[n-i-1],n) ;
            matrix[n-i-1] = Arrays.copyOf(temp,n) ;
        }
    }
    public void transposition(int[][] matrix,int n){
        for(int i = 0 ; i < n ; i++)
            for(int j = i ; j < n ; j++){
                int temp = matrix[i][j] ;
                matrix[i][j] = matrix[j][i] ;
                matrix[j][i] = temp ;
            }
    }
}
```