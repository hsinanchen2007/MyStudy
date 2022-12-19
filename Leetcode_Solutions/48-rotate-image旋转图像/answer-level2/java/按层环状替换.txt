**1. 定义**：将矩阵由外向内的每一圈定义为一层（level），层序号从0开始计。每层有 4*(matrix.length-2*level-1) 个元素
**2. 类比**：将每一层从左上角开始顺时针遍历想象成首尾闭合的一维序列，则旋转就相当于一维数组的循环移位，每层移动 matrix.length-2*level-1 位
**3. 规律**：对于位置 [i][j] 的元素，其最终要移动到的位置是 [j][matrix.length-i-1]
**4. 环状替换**：对每一层level来说，所要做的操作是将m个元素顺指针移动k=m/4位。所以可以从左上角的元素[startRow][startColumn]开始，将其按3中找到的规律直接赋值到最终位置，并用临时变量保存最终位置[curRow][curColumn]上被覆盖的值。然后再将临时变量中的值赋给下一个最终位置，重复此过程。【注意】因为m和k不互质，所以在未遍历完该层所有元素的时候（具体是4次）就会回到初始位置，此时只需要从顺时针方向的下一位（列索引+1）开始再重复上述过程，或者结束该层遍历
**5.终止条件**：
- level：总共需要遍历 matrix.length/2 层，最内层是单元素时不需要遍历。 0 <= level < matrix.length / 2
- startColumn：每层总共需要 matrix.length-level-1 - level 轮移动。 level <= startColumn < matrix.length - level - 1
- curRow、curColumn：每层的每轮移动总共移动4个元素，当回到初始位置时，该轮结束。 curRow == startRow && curColumn == startColumn

```
class Solution {
    public void rotate(int[][] matrix) {
        for (int level = 0; level < matrix.length / 2; level++) {
            int startRow = level, startColumn = level, curRow = startRow;
            for (; startColumn < matrix.length - level - 1; startColumn++) {
                int curColumn = startColumn;
                int pre = matrix[startRow][startColumn];
                do {
                    int tempIndex = curRow;
                    curRow = curColumn;
                    curColumn = matrix.length - tempIndex - 1;
                    int temp = matrix[curRow][curColumn];
                    matrix[curRow][curColumn] = pre;
                    pre = temp;
                } while (!(curRow == startRow && curColumn == startColumn));
            }
        }
    }
}
```
