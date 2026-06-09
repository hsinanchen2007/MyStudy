### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for(int i=0; i<n;i++){
            for(int j=i; j <n;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        int mid = n >>1;
        for(int i=0; i< n;i++){
            for(int j=0;j < mid;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-j-1] = tmp;
            }
        }
    }
}
```