### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        for (int i=0;i<matrix.length;i++){//对角线对称
            for (int j=0;j<i;j++){
                matrix[i][j]=matrix[i][j]+matrix[j][i];
                matrix[j][i]=matrix[i][j]-matrix[j][i];
                matrix[i][j]=matrix[i][j]-matrix[j][i];
            }
        }
        for (int i=0;i<matrix.length;i++) {//行翻过来
            for (int j = 0; j < matrix[0].length/2; j++) {
                matrix[i][j]=matrix[i][j]+matrix[i][matrix[0].length-1-j];
                matrix[i][matrix[0].length-1-j]=matrix[i][j]-matrix[i][matrix[0].length-1-j];
                matrix[i][j]=matrix[i][j]-matrix[i][matrix[0].length-1-j];
            }
        }
    }
}
```