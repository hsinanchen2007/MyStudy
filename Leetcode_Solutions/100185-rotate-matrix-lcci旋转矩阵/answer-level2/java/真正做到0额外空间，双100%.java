### 解题思路
这题主要就是要做到“不占用额外内存空间”。
基本的思路就是，如果要交换a，b两个整型数，但是又不额外占用空间的方法，如下：
a = a + b;
b = a - b;
a = a - b;

于是这道题的解法就是通过两次变换将矩阵变换成目标样式：
第一次变换：将矩阵以左上到右下的对角线为中线，进行对称变换
第二次变换：将矩阵以纵向中线为中线，进行对称变换

![image.png](https://pic.leetcode-cn.com/e6a1df7182c9d8f53848cc4fec3f6381fcc88dd7930a8fec586427f49f9a672d-image.png)


### 代码

```java
public class Solution {
    public void rotate(int[][] matrix) {
        if (matrix.length < 2) {
            return;
        }

        // 将矩阵以左上到右下的对角线为中线，进行对称变换
        for (int row = 0; row < matrix.length; row++) {
            for (int col = row; col < matrix.length; col++) {
                exchange(matrix, row, col, col,row);
            }
        }

        // 将矩阵以纵向中线为中线，进行对称变换
        for (int col = 0; col < matrix.length / 2; col++) {
            for(int row = 0; row < matrix.length; row++) {
                exchange(matrix, row, col, row, matrix.length - 1 - col);
            }
        }
    }

    // 无需新增额外内存的交换方法
    private void exchange(int[][] matrix, int fromRow, int fromCol, int toRow, int toCol) {
        if (fromRow == toRow && fromCol == toCol) {
            return;
        }
        matrix[fromRow][fromCol] = matrix[fromRow][fromCol] + matrix[toRow][toCol];
        matrix[toRow][toCol] = matrix[fromRow][fromCol] - matrix[toRow][toCol];
        matrix[fromRow][fromCol] = matrix[fromRow][fromCol] - matrix[toRow][toCol];
    }
}
```