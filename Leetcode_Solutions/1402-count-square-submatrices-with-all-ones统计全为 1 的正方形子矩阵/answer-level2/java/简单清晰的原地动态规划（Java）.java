可以用动态规划的思路。

遍历每一个位置ij时，将该位的数值置为从该位起左边的1的总个数，例如对于矩阵
```
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
```
遍历结束后效果为：
```
  [0,1,2,3],
  [1,2,3,4],
  [0,1,2,3]
```
为了统计正方形矩阵的个数，可以假定当前位置ij为正方形的右下角点，其值为可能的最大边长maxlen = matrix[i][j]。

沿着同一列j向上遍历，遍历行数即为当前正方形的边长curlen，当遍历过程的最小边长minlen >= curlen时，可以构成当前正方形。

```java

public int countSquares(int[][] matrix) {
    int result = 0;
    for(int i = 0; i < matrix.length; i++) {
        for(int j = 0; j < matrix[0].length; j++) {
            if(matrix[i][j] != 1){
                continue;
            }
            result++;
            if(j == 0){
                matrix[i][j] = 1;
                continue;
            }
            matrix[i][j] = matrix[i][j - 1] + 1;
            if(i == 0){
                continue;
            }
            int maxlen = matrix[i][j];
            int minlen = maxlen;
            int row = i - 1;
            int curlen = 2;
            while(row >= 0 && curlen <= maxlen){
                minlen = Math.min(matrix[row][j], minlen);
                if(minlen < curlen){
                    break;
                }
                result++;
                row--;
                curlen++;
            }
        }
    }
    return result;
}

```

欢迎与我交流~

[LeetCode 从零单刷个人笔记整理（持续更新）](https://blog.csdn.net/qq_20304723/article/details/89401203)

github：[https://github.com/ChopinXBP/LeetCode-Babel](https://github.com/ChopinXBP/LeetCode-Babel)
