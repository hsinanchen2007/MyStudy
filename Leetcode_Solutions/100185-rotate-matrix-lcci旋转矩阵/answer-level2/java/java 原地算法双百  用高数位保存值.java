### 解题思路
我看别人的方法都很厉害，不过没看到跟我这个一样的。
用高数位保存旋转后该位置的数字和负号
最后再遍历摒弃后几位原本的数值

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        // 重点在于原地算法
        // 每个位置占用4字节，就又想到用一个数字保存两个信息，10000*a'+a;
        // 但是还需要额外解决负数的问题 那么额外增加一位
        int n = matrix.length-1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (matrix[i][j] < 0) matrix[i][j] = 0-matrix[i][j] + 1000;
            }
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                matrix[i][j] += (matrix[n-j][i] % 10000) * 10000;
            }
        }

        // 再调整回去
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                matrix[i][j] /= 10000;
                if (matrix[i][j] > 1000) {
                    matrix[i][j] -= 1000;
                    matrix[i][j] = 0 - matrix[i][j];
                }
            }
        }
    }
}
```