### 思路：

首先，将矩阵沿右上-左下对角线翻转；然后，沿水平中线上下翻转即可。难点在于设定的 in-place 操作，意思是所有的操作都是”就地“操作，不允许进行移动，所以在进行 swap 时，不建议通过声明临时变量的方式来实现。

### 代码：

```java
class Solution {
    public void rotate(int[][] matrix) {
        // n * n，行列数相等
        int row = matrix.length, col = matrix[0].length;
        // 沿右上-左下对角线交换
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row - i; j++) {
                // 如果用异或的方式交换元素，注意过滤掉对角线，否则对角线的元素就变成0了
                if (i + j != row - 1) {
                    matrix[i][j] = matrix[i][j] ^ matrix[row - j - 1][row - i - 1];
                    matrix[row - j - 1][row - i - 1] = matrix[i][j] ^ matrix[row - j - 1][row - i - 1];
                    matrix[i][j] = matrix[i][j] ^ matrix[row - j - 1][row - i - 1];
                }
            }
        }
        // 上下交换
        for (int i = 0; i < row / 2; i++) {
            for (int j = 0; j < row; j++) {
                matrix[i][j] = matrix[i][j] ^ matrix[row - i - 1][j];
                matrix[row - i - 1][j] = matrix[i][j] ^ matrix[row - i - 1][j];
                matrix[i][j] = matrix[i][j] ^ matrix[row - i - 1][j];
            }
        }
    }
}
```

```
// 写法二
class Solution {
    public void rotate(int[][] matrix) {
        // n * n，行列数相等
        int row = matrix.length, col = matrix[0].length;
        // 沿右上-左下对角线交换
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row - i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[row - j -1][row - i - 1];
                matrix[row - j -1][row - i -1] = temp;
            }
        }
        // 上下交换
        for (int i = 0; i < row / 2; i++) {
            for (int j = 0; j < row; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[row - i - 1][j];
                matrix[row - i - 1][j] = temp;
            }
        }
    }
}
```


### Result：

Runtime：0ms

Your runtime beats 100% of java submissions.