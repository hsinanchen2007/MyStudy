### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
int[][] tmp = new int[matrix.length][matrix.length];
        for (int i = 0; i < matrix.length ; i++)
            for (int j = matrix.length - 1; j >= 0; j--) {
                tmp[i][matrix.length - 1 - j] = matrix[j][i];
            }
          for(int i=0;i<tmp.length;i++)
            for(int j=0;j<tmp.length;j++)
                matrix[i][j]=tmp[i][j];
    }
}
```