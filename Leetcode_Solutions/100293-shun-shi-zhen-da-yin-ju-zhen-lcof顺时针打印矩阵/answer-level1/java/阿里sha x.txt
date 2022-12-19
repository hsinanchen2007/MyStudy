### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if (matrix.length == 0)
            return new int[0] ;
        int m = matrix.length ;
        int n = matrix[0].length ;
        int[] ret = new int[m*n] ;
        int circleTimes = 0 ;
        boolean rightFlag = true ;
        boolean  downFlag = false ;
        boolean leftFlag = false ;
        boolean upFlag = false ;
        int i = 0 ;
        int j = 0 ;
        int k = 0 ;
        while (i >=0 && i < m && j >= 0 && j<n && k < m * n) {
            ret[k++] = matrix[i][j] ;  
            if (k == m*n )
                break ;
            if(rightFlag) {
                if (j == n - 1 - circleTimes ){
                    rightFlag = false ;
                    downFlag = true ;
                    i ++ ;
                    continue ;
                }
                j ++  ;
            }else if (downFlag){
                if (i == m  -  1  - circleTimes) {
                    downFlag = false ;
                    leftFlag = true ;
                    j -- ;
                    continue ;
                }
                i ++ ;
            }else if (leftFlag){
                if (j == circleTimes) {
                    leftFlag = false ;
                    upFlag = true ;
                    i -- ;
                    continue ;
                }
                j -- ;

            }else if (upFlag){
                if (i == circleTimes + 1) {
                    upFlag = false ;
                    rightFlag = true ;
                    j ++ ;
                    circleTimes ++ ;
                    continue ;
                }
                i -- ;
            }
        }
        return ret ;
    }
}
```