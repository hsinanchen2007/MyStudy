### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int r = matrix.length;
        int c = matrix[0].length;

        for(int i = 0; i < r-1; i++){
            for(int j = 0; j < c-1; j++){
                if(matrix[i][j] != matrix[i+1][j+1]){
                    return false;
                }
            }
        }

        return true;
    }
}
```