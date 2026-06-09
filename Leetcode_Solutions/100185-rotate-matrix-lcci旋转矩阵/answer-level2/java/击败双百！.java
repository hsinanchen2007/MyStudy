### 解题思路
分层旋转，先从最外层开始旋转，再往下一层一层旋转。
每层需要旋转的次数=该层的长度减一，因为第一个转到最后一个，最后一个的旋转就不归该次了。
然后就是左上右下旋转位置的确定，可以用四阶矩阵来模拟观察位置的变化，就不一一列举了，代码自行参考。

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int len = matrix.length;
        int number = len >> 1;
        for (int k=0; k<number; k++) {
            for (int i=k; i<len-1-k; i++) {
                int temp = matrix[k][i];
                matrix[k][i] = matrix[len-1-i][k];
                matrix[len-1-i][k] = matrix[len-1-k][len-1-i];
                matrix[len-1-k][len-1-i] = matrix[i][len-1-k];
                matrix[i][len-1-k] = temp;
            }
        }
    }
}
```