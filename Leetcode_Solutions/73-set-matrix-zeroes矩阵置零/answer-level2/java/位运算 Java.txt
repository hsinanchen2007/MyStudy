`执行用时 :
2 ms
, 在所有 Java 提交中击败了
98.72%
的用户`
`内存消耗 :
52.4 MB
, 在所有 Java 提交中击败了
50.51%
的用户`
原理很简单，题目无非就是让我们保存数组需要赋值为0的行号和列号，考虑到针对任意一行，处理结果必为清零（0）和不清零（1）两种结果之一，非此即彼，又想省空间，位运算是个不错的选择。
但是，位运算**不是O(1)的**，因为如果标记数组大小还是跟矩阵大小有关的，为**O(m/30+n/30)**;
各位权当拓宽一种思路吧。

```
class Solution {
    public void setZeroes(int[][] matrix) {
        //6位int存储180行和列（这里取巧了，试出来的）
        int[] rowSigns = new int[6];
        int[] columnSigns = new int[6];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    //分别计算该行该列存放的数组下标
                    int row = i / 30;
                    int column = j / 30;
                    //使用或运算保存标记
                    rowSigns[row] |= 1 << (i % 30);
                    columnSigns[column] |= 1 << (j % 30);
                }
            }
        }
        //针对每一行从行数组中取出标记值，通过位运算识别该行是否要赋值位0；
        for (int i = 0; i < matrix.length; i++) {
            int row = i / 30;
            if ((rowSigns[row] & (1 << (i % 30))) != 0) {
                Arrays.fill(matrix[i], 0);
            }
        }
        //针对每一列从行数组中取出标记值，通过位运算识别该行是否要赋值位0；
        for (int j = 0; j < matrix[0].length; j++) {
            int column = j / 30;
            //列与行不同无法用数组的fill方法，因此需要按行一次判断。
            if ((columnSigns[column] & (1 << (j % 30))) != 0) {
                for (int i = 0; i < matrix.length; i++) {
                    if (matrix[i][j] != 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
}
```
