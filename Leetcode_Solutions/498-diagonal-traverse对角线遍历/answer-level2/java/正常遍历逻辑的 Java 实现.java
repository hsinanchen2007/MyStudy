### 解题思路
尝试寻找本题中 (row,col) => i 的映射规律失败后，决定使用题目所述的正常遍历逻辑来实现。

##### 参数定义：
1. rLen、cLen：二维数组行数、列数；
1. row、col：二维数组的当前坐标；
2. len：所有数字的数量，`len == row * col`；
1. i：当前要添加的元素在一维数组中的位置，`0 <= i < len`。

##### 遍历方向：
首先明确一点，本题题目中的遍历方向只有两种：
1. 向上遍历：左下到右上
``` Java
row = row - 1;
col = col + 1;
```
2. 向下遍历：左上到右下
``` Java
row = row + 1;
col = col - 1;
```

##### 边界条件：
与「遍历方向」对应，在遍历中出界的情况也只有两种：向上出界、向下出界。
1. 向上出界
    由于向上遍历是 row - 1，col + 1 的操作，所以遍历的出界情况只可能是 `col >= cLen || row < 0`。
1. 向下出界
    由于向下遍历是 row + 1，col - 1 的操作，所以遍历的出界情况只可能是 `col < 0 || row >= rLen`。
    
##### 处理边界条件
为直观了解对应的出界情况，假设有两种极端数组：
**数组一**：cLen 远大于 rLen
``` Java
[[1, 2, 3]]
```
这种情况下，向上出界更多是因为 `row < 0` 出界，此时只需要重置 row 即可：`row = 0`。

**数组二**：rLen 远大于 cLen
``` Java
[[1],
 [2],
 [3]]
```
这种情况下，向上出界更多是因为 `col >= cLen` 出界, 此时只需要同时修正 row 和 col，如果这里不太理解，只用尝试遍历「数组二」即可明白：
``` Java
row = row + 2;
col = cLen - 1;
```

所以， 处理「向上出界」的代码如下：
``` Java
if (col == cLen) {
    row = row + 2;
    col = cLen - 1;
} else if (row < 0) {
    row = 0;
}
```
同样尝试「向下出界」的遍历情况分析后，得出处理「向下出界」的代码如下：
``` Java
if (row == rLen) {
    row = rLen - 1;
    col = col + 2;
} else if (col < 0) {
    col = 0;
}
```

##### 结束条件
将要返回的一维数组填充完毕就算结束，即：`i == len`

### 代码

``` Java
class Solution {

    static final boolean UP = true;
    static final boolean DOWN = false;

    int[] ans;
    int i = 0;
    int len;
    int rLen;
    int cLen;

    public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return new int[0];
        }
        rLen = matrix.length;
        cLen = matrix[0].length;

        len = rLen * cLen;
        ans = new int[len];
        
        helper(matrix, 0, 0, UP);
        return ans;
    }

    private void helper(int[][] matrix, int row, int col, boolean isUp) {
        boolean isUpOut = col >= cLen || row < 0;
        boolean isDownOut = col < 0 || row >= rLen;
        boolean out = isUpOut || isDownOut;

        if (out) {
            if (isUpOut) {
                if (col == cLen) {
                    row = row + 2;
                    col = cLen - 1;
                } else if (row < 0) {
                    row = 0;
                }
                helper(matrix, row, col, DOWN);
            } else {
                if (row == rLen) {
                    row = rLen - 1;
                    col = col + 2;
                } else if (col < 0) {
                    col = 0;
                }
                helper(matrix, row, col, UP);
            }
            return; 
        }

        ans[i++] = matrix[row][col];

        if (i == len) {
            return;
        }

        if (isUp) {
            helper(matrix, row - 1, col + 1, UP);
        } else {
            helper(matrix, row + 1, col - 1, DOWN);
        }
    }
}
```