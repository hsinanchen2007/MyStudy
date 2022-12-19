### 解题思路
此处撰写解题思路
题干要求两点：1.旋转  2.不开辟新空间
我的思路是：按照对角线做置换，然后再把二维数组行数据置换就可以了；
![旋转算法截图.png](https://pic.leetcode-cn.com/06a2a0d73281dbec2c7d3033bed8d3599ab74e35c6b7c1819f451dd07cdef5d6-%E6%97%8B%E8%BD%AC%E7%AE%97%E6%B3%95%E6%88%AA%E5%9B%BE.png)

请各位大神批评指正，也可以赞一发 哈哈。




### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return;
        }

        //对角线置换
        int totalLenth = matrix.length;
        for (int i = 0; i < matrix.length; i ++) {
            int[] rowMatrix = matrix[i];
            if (rowMatrix == null || rowMatrix.length == 0 ||rowMatrix.length != totalLenth) {
                return;
            }

            int changeLength = rowMatrix.length - (i + 1);
            for (int j = 0; j < changeLength; j ++) {
                int temp = matrix[i + (changeLength - j)][changeLength];
                int current = rowMatrix[j];
                matrix[i + (changeLength - j)][changeLength] = current;
                matrix[i][j] = temp;
            }
        }
        //行置换
        //置换次数
        int placeTimes = matrix.length / 2;
        for (int m = 0; m < placeTimes; m ++) {
            int[] temp = matrix[m];
            matrix[m] = matrix[matrix.length - m - 1];
            matrix[matrix.length - m - 1] = temp;
        }
    }
}
```