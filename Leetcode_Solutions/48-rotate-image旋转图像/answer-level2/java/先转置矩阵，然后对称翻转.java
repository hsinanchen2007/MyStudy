### 解题思路
此处撰写解题思路

时间复杂度：O(n^2)
空间复杂度：O(1)
### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        for(int i=0;i<matrix.length;i++){
            for(int j=i;j<matrix.length;j++){
                int s=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=s;
            }
        }
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix.length/2;j++){
                int s=matrix[i][j];
                matrix[i][j]=matrix[i][matrix.length-1-j];
                matrix[i][matrix.length-1-j]=s;
            }
        }
    }
}
```