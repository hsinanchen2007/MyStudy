### 解题思路
我做完提交之后，很开心，双百。但是看了看别人的原地双百，我的代码似乎太过麻烦。不过好歹也是双百。

小知识：
1、n >> 1等价于n/2；
2、a = a ^ b;b = a ^ b; a = a ^ b;最后运行完，a和b的数字会交换。
3、为什么要用位运算呢，因为位运算相对更高效一点。

该做个图例，但是我不会，也懒得做。注释基本就说的挺清楚了。
大致就是一层一层的旋转，先转四个角再转边。确实是不如对角线交换，再让每行旋转来的好理解，而且这个思路代码也容易写。我写题解就图一乐。

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return;
        int n = matrix.length;
        int mid = n >> 1;
        int i = 0;
        while(i < mid){
            //旋转四个角
            //左上角->右上角
            matrix[i][i] = matrix[i][i] ^ matrix[i][n-1-i];
            matrix[i][n-1-i] = matrix[i][i] ^ matrix[i][n-1-i];
            matrix[i][i] = matrix[i][i] ^ matrix[i][n-1-i];
            //原右上角->右下角
            matrix[i][i] = matrix[i][i] ^ matrix[n-1-i][n-1-i];
            matrix[n-1-i][n-1-i] = matrix[i][i] ^ matrix[n-1-i][n-1-i];
            matrix[i][i] = matrix[i][i] ^ matrix[n-1-i][n-1-i];
            //剩余两个角
            matrix[i][i] = matrix[i][i] ^ matrix[n-1-i][i];
            matrix[n-1-i][i] = matrix[i][i] ^ matrix[n-1-i][i];
            matrix[i][i] = matrix[i][i] ^ matrix[n-1-i][i];
            //旋转四个边（不动角）
            //上边->右边
            for(int j = i+1; j < n-i-1; j++){
                matrix[i][j] = matrix[i][j] ^ matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j] ^ matrix[j][n-1-i];
                matrix[i][j] = matrix[i][j] ^ matrix[j][n-1-i];
            }
            //下边->左边
            for(int j = i+1; j < n-i-1; j++){
                matrix[n-1-i][j] = matrix[n-1-i][j] ^ matrix[j][i];
                matrix[j][i] = matrix[n-1-i][j] ^ matrix[j][i];
                matrix[n-1-i][j] = matrix[n-1-i][j] ^ matrix[j][i];
            }
            //剩下两边交换
            for(int j = i+1; j < n-i-1; j++){
                matrix[i][j] = matrix[i][j] ^ matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[i][j] ^ matrix[n-1-i][n-1-j];
                matrix[i][j] = matrix[i][j] ^ matrix[n-1-i][n-1-j];
            }
            i++;
        }
    }
}
```