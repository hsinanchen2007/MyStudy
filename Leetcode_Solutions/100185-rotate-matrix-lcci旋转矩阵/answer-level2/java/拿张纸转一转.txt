### 解题思路
如果要是四条边一条一条的挪，再一层一层的转，那就费劲死了，把自己都绕进去了

简单的办法是 **顺时针旋转90度就等价于：沿对角线翻转 + 水平翻转**

不信拿张纸你试试？

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int N = matrix.length;
        if(N < 2) {
            return;
        }
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int i=0; i<N; i++) {
            for(int j=0; j<N/2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][N-1-j];
                matrix[i][N-1-j] = temp;
            }
        }
    }
}
```