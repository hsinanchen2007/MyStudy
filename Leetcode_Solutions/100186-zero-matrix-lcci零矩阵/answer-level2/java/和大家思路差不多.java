### 解题思路
用两个一维数组来做标记
### 代码

```java
class Solution {
        public void setZeroes(int[][] matrix) {

        int l = matrix.length;
        int k = matrix[0].length;
        int [] lineMark = new int[l];
        int [] rowMark = new int[k];
        for( int i = 0; i < l; i++) {
            for(int j = 0; j < k; j ++) {
                if(matrix[i][j] == 0) {
                    lineMark[i] = 1;
                    rowMark[j] = 1;
                }
            }
        }

        for( int i = 0; i < l; i++) {
            for(int j = 0; j < k; j ++) {
                if(lineMark[i] == 1 || rowMark[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
}
```