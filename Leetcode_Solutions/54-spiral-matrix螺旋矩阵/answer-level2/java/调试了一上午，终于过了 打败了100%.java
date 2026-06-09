### 解题思路
思路很传统，按照从内到外 循环的层数 一层一层遍历
难点在于：
1，矩阵为空-做特殊判断
2，怎么样确定层数，m 和 n的最小值 即需要遍历的层数
3，当只有一行或者只有一列 做特殊情况判断 

### 代码

```java
import java.util.List;
import java.util.ArrayList;
import java.lang.Math;
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        
        //保存要打印的数据
        List<Integer> list = new ArrayList<Integer>();

        //矩阵打印
        //行数
        int row = matrix.length;

        if (row <= 0) {
            return list;
        }

        //列数
        int col = matrix[0].length;

        //定义行开始索引
        int iStart = 0;
        //定义列开始索引
        int jStart = 0;
        //定义行结束索引
        int iEnd = row-1; 
        //定义列开始索引
        int jEnd = col-1;

        //需要循环的层数
        int level = Math.min(row/2 + row%2, col/2 + col%2);
        //当前层数
        int currentLevel = 0;

        //循环 分别遍历每一层打印矩阵数组 
        while (currentLevel < level) {
             
             //第一行从左到右
             for (int j = jStart; j <= jEnd; j++) {
                 list.add(matrix[iStart][j]);
             }

             //最后一列从上到下
             for (int i = iStart + 1; i <= iEnd; i++) {
                 list.add(matrix[i][jEnd]);
             }

            //最后一行从右向左
            if (iStart < iEnd) {//只有一行的情况下 避免重复打印
                for (int j = jEnd - 1; j >= jStart; j--) {
                    list.add(matrix[iEnd][j]);
                }
            }

            //第一列从下到上 只有一列的情况下 避免重复打印
            if (jStart < jEnd) {
                for (int i = iEnd - 1; i > iStart; i--) {
                    list.add(matrix[i][jStart]);
                }
            }

             iStart++;
             jStart++;
             iEnd--;
             jEnd--;
             currentLevel++;
        } 

        return list;
    }
}
```