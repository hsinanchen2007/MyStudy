### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {

        for(int i = 0; i < matrix.length; ++i) {
            for(int j = i; j < matrix[0].length; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        for(int i = 0; i < matrix.length; ++i) {
            for(int j = 0; j < matrix[0].length/2; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j]=matrix[i][matrix[0].length - j - 1];
                matrix[i][matrix[0].length - j - 1] = tmp;
            }
        }
    }
}

//1 4 7
//2 5 8
//3 6 9

//7 4 1
//8 5 2
//9 6 3
```