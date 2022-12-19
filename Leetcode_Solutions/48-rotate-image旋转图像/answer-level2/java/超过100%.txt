### 解题思路
由最外层不断往最里层旋转，四次旋转的方向要一致。。但用了一个一维的辅助数组
![image.png](https://pic.leetcode-cn.com/7e47801208ec1063fb625084ebd2be59991d8b7e513b35353f75496ea6423d73-image.png)


### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        if(matrix == null || matrix.length == 0)
            return ;
        int start = 0;
        while(start < matrix.length / 2){
            rotateMatrix(matrix, start++);
        }
    }
    public void rotateMatrix(int[][] matrix, int start){
        int len = matrix.length;
        int[] temp = new int[len - 1];
        for(int i = start; i < len - start - 1; i ++){
            temp[i] = matrix[start][i];
        }
        for(int i = start; i < len - start - 1; i ++){
            matrix[start][i] = matrix[len - 1 - i][start];
            matrix[len - 1 - i][start] = matrix[len - 1 - start][len - 1 - i];
            matrix[len - 1 - start][len - 1 - i] = matrix[i][len - 1 - start];
            matrix[i][len - 1 - start] = temp[i];
        }
    }
}
```