可以用约束了方向的深度遍历来做,但是搞了半天发现递归的回退条件想不清楚 监(尴)介(尬))一笑

于是乎 用最蠢的方法来做,需注意三点
- 约束遍历方向 右 下 左 上 
- 注意下标越界 循环内的++ --操作通常都会达到数组的界限外 
- 注意往内圈走  不然一直在外圈转 实际上就是不要重复遍历

蠢是蠢了点 但至少满足功能 至于性能,emmm...

执行用时 :
43 ms
, 在所有 Java 提交中击败了
5.09%
的用户
内存消耗 :
43.7 MB
, 在所有 Java 提交中击败了
100.00%
的用户

```
public int[] spiralOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return new int[0];
        }
        int[] result = new int[matrix[0].length * matrix.length];
        int index = 0;
        int row = 0;
        int col = 0;
        //用来做路径判重 避免重复走
        Set<String> filterSet = new HashSet<>();
        while (index < result.length) {
            //右
            while (col < matrix[row].length && !filterSet.contains(row + "-" + col)) {
                filterSet.add(row + "-" + col);
                result[index++] = matrix[row][col++];
            }
            row += 1;
            col -= 1;
            //下
            while (row < matrix.length && !filterSet.contains(row + "-" + col)) {
                filterSet.add(row + "-" + col);
                result[index++] = matrix[row++][col];
            }
            row -= 1;
            col -= 1;
            //左
            while (col >= 0 && !filterSet.contains(row + "-" + col)) {
                filterSet.add(row + "-" + col);
                result[index++] = matrix[row][col--];
            }
            row -= 1;
            col += 1;
            //上
            while (row >= 0 && !filterSet.contains(row + "-" + col)) {
                filterSet.add(row + "-" + col);
                result[index++] = matrix[row--][col];
            }
            row += 1;
            col += 1;
        }
        return result;
    }
```
