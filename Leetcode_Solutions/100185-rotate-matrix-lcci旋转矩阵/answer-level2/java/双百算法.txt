### 解题思路
每次移动四个点

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                // 第一个
                int leftup = matrix[i][j];
                // 第二个
                int rightup = matrix[j][n-1-i];
                // 第三个
                int rightDown = matrix[n-1-i][n-1-j];
                // 第四个
                int leftDown = matrix[n-1-j][i];

                matrix[i][j] = leftDown;
                matrix[j][n-1-i] = leftup;
                matrix[n-1-i][n-1-j] = rightup;
                matrix[n-1-j][i] = rightDown;
            }
        }
    }
}
```