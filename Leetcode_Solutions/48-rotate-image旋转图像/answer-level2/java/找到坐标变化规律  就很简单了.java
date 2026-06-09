### 解题思路
观察第一行的变化规律:
    1. 第0行 -> matrix.length - 1列;
    2. 原来的纵坐标变为横坐标
    
得出坐标变化: `[i , j] -> [j, n - i] -> [n - i, n - j] -> [n - j, i] -> [i, j]`
然后变换a, b, c, d这四个坐标的值即可
int tmp = b; b = a; a = d; d = c; c = tmp;
然后遍历就结束了

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        // [i , j] -> [j, n - i] -> [n - i, n - j] -> [n - j, i] -> [i, j]
        int n = matrix.length - 1;
        for (int i = 0; i < matrix.length / 2; i++) {
            // 挪动第一行0到matrix.length - 2 后续就是1到matrix.length - 3
            for (int j = i; j < n - i; j++) {
                int tmp = matrix[j][n - i];
                matrix[j][n - i] = matrix[i][j];
                matrix[i][j] = matrix[n - j][i];
                matrix[n - j][i] = matrix[n - i][n - j];
                matrix[n - i][n - j] = tmp;
            }
        }
    }
}
```