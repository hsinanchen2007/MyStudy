### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        if(matrix == null || matrix.length < 2){
            return ;
        }
        int n = matrix.length;
        int k = n / 2 ;
        int tmp;
        for(int i = 0 ; i < k ; i++){
            for(int j = i ; j < n - i -1 ; j++){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = tmp;
            }
        }
        return;
    }
}
```