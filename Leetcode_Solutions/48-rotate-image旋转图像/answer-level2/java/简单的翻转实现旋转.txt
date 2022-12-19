![image.png](https://pic.leetcode-cn.com/2812a5b4eba4944dc0dec2effba232259cd6b54855fe9a16b43416bb654a5727-image.png)
思路：将矩阵沿着对角线反转之后，将每一行前后调换，即可实现矩阵的旋转。

```
class Solution {
    public void rotate(int[][] matrix) {
        int temp=0;

        //1。沿着对角线翻转
        for(int i=0;i<matrix.length;i++){
            for(int n=i;n<matrix[i].length;n++){
                temp=matrix[i][n];
                matrix[i][n]=matrix[n][i];
                matrix[n][i]=temp;
            }
        }

        //2.将矩阵沿着中轴线翻转
        for(int i=0;i<matrix.length;i++){
            for(int n=0;n<matrix[i].length/2;n++){
                temp=matrix[i][n];
                matrix[i][n]=matrix[i][matrix[i].length-1-n];
                matrix[i][matrix[i].length-1-n]=temp;
            }
        }
    }
}
```


