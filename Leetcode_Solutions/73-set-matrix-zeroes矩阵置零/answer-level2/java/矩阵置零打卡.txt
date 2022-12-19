### 解题思路


### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {

        int[][] tmp = new int[matrix.length][matrix[0].length];
        boolean flag = false;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    flag = true;
                    break;
                }
            }
            while (flag) {
                for (int j = 0; j < matrix[0].length; j++) {
                    tmp[i][j]=1;
                }
                flag = false;
            }
        }
        for (int i = 0; i < matrix[0].length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                if (matrix[j][i] == 0) {
                    flag = true;
                    break;
                }
            }
            while (flag) {
                for (int j = 0; j < matrix.length; j++) {
                    tmp[j][i] = 1;
                }
                flag = false;
            }
        }
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if(tmp[i][j]==1)
                    matrix[i][j]=0;
            }
        }

 

    }
}
```