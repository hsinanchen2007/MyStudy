### 解题思路
转置矩阵的核心就是交换元素：B[j][i] = A[i][j];

### 代码

```java
class Solution {
    public int[][] transpose(int[][] A) {
        int rowLen = A.length;
        int colLen = A[0].length;
        int[][] B = new int[colLen][rowLen];
        for (int i = 0; i < rowLen; i++) {
            for (int j = 0; j < colLen; j++) {
                B[j][i] = A[i][j];
            }
        }
        return B;
    }
}
```