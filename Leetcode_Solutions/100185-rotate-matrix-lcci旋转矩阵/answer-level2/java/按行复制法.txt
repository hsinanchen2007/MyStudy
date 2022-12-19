### 解题思路
将旧矩阵的第1行复制到新矩阵的第3列；
将旧矩阵的第2行复制到新矩阵的第2列；
将旧矩阵的第3行复制到新矩阵的第1列；
然后用新矩阵替换旧矩阵。

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int len = matrix.length;
        int[][] newMatrix = new int[len][len];
        for(int i = 0 ; i < len ; i++){
            for(int j = 0 ; j < len ; j++){
                newMatrix[j][len - i - 1] = matrix[i][j];
            }
        }
        for(int i = 0 ; i < len ; i++){
            for(int j = 0 ; j < len ; j++){
                matrix[i][j] = newMatrix[i][j];
            }
        }
    }
}
```