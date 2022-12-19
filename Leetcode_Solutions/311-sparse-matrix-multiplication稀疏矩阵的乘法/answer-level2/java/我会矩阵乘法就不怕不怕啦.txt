### 解题思路
矩阵乘法

### 代码

```java
class Solution {
    public int[][] multiply(int[][] A, int[][] B) {
        int rows = A.length;
        int cols = B[0].length;
        int times = B.length;
        int[][] res = new int[rows][cols];
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // 要得到这么多个元素
                for (int i = 0; i < times; i++) {
                    res[row][col]+=A[row][i]*B[i][col];
                }
            }
        }
        return res;
    }
}
```