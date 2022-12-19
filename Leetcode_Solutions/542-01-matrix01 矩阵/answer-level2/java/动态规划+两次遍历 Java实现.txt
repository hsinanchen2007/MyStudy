### 解题思路
1.当前元素如果是0则距离直接为0
2.当前元素如果不为0，则它的距离是 上左下右 元素中距离最小的 + 1，这里因为题目限定了矩阵元素个数不超过10000，所以上左下右元素距离赋值101，然后取较小值即可。
3.两次循环分别从上左和右下开始循环，最终取四个方向的最小值。

### 代码

```java
class Solution {
     public int[][] updateMatrix(int[][] matrix) {
        int[][] matrixs = Arrays.copyOf(matrix, matrix.length);
        int[][] res = new int[matrixs.length][];
        for (int i = 0; i < matrixs.length; i++) {
            res[i] = new int[matrixs[i].length];
            for (int j = 0; j < matrixs[i].length; j++) {
                if (matrixs[i][j] == 0) {
                    continue;
                }
                int l = 101, t = 101;
                if (i > 0) {
                    l = res[i - 1][j];
                }
                if (j > 0) {
                    t = res[i][j - 1];
                }
                res[i][j] = Math.min(l, t) + 1;
            }
        }
        for (int i = matrixs.length - 1; i >= 0; i--) {
            for (int j = matrixs[i].length - 1; j >= 0; j--) {
                if (matrixs[i][j] == 0) {
                    continue;
                }
                int r = 101, b = 101;
                if (i < matrixs.length - 1) {
                    r = res[i + 1][j];
                }
                if (j < matrixs[i].length - 1) {
                    b = res[i][j + 1];
                }
                res[i][j] = Math.min(Math.min(r, b) + 1, res[i][j]);
            }
        }
        return res;
     }
}
```