**解题思路为先进行变换，再上下翻转。**
![图片.png](https://pic.leetcode-cn.com/eb59a2f250a921fe138038f5127693587757f8ac7c03b34468ae0ee7de9d48fe-%E5%9B%BE%E7%89%87.png)

**代码如下：**
```
class Solution {
    public void rotate(int[][] matrix) {
        int size = matrix.length;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                int swap = matrix[i][j];
                matrix[i][j] = matrix[size - j - 1][size - i - 1];
                matrix[size - j - 1][size - i - 1] = swap;
            }
        }
        for (int i = 0; i < size / 2; i++) {
            for (int j = 0; j < size; j++) {
                int swap = matrix[i][j];
                matrix[i][j] = matrix[size - i - 1][j];
                matrix[size - i - 1][j] = swap;
            }
        }
    }
}
```
