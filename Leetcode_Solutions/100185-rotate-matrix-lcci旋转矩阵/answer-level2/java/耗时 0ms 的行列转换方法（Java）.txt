### 解题思路
先看看效果哈
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :39.7 MB, 在所有 Java 提交中击败了100.00%的用户

这个是我之前在处理计算机坐标系和实际坐标系的时候，用的就是这种方法
计算机坐标系的原点在左上角，而实际坐标系的原点再左下角
就需要矩阵旋转的方法来解决同步问题

新建立一个矩阵
将原矩阵的第一行，赋值到新矩阵的的倒数第一列
将原矩阵的第二行，赋值到新矩阵的的倒数第二列
依次操作
最后新矩阵就是旋转之后的结果
然后再将新矩阵中的值，全部赋值到原矩阵中即可
### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int length = matrix.length;
        int[][] matrixTemp = new int[length][length];

        for (int i = 0 ; i < length ; i++) {
            for (int j = 0 ; j < length ; j++) {
                matrixTemp[j][matrix.length - i - 1] = matrix[i][j];
            }
        }
        for (int i = 0 ; i < matrixTemp.length ; i++) {
            for (int j = 0; j < matrixTemp.length; j++) {
                matrix[i][j] = matrixTemp[i][j];
            }
        }
    }
}
```