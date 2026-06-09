![批注 2020-02-26 234733.png](https://pic.leetcode-cn.com/ebd9ce75a76005e870947604018b17fe28bc1acfa3d3e2ef03e3a6c8c9768bdd-%E6%89%B9%E6%B3%A8%202020-02-26%20234733.png)

### 解题思路
除了第一行需要保存列号信息之外，其他行遍历完之后可以直接清零，全部矩阵遍历完之后，再根据第一行保存的列号清零列，最后再清零第一行。

### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        int h = matrix.length, w = matrix[0].length;
        boolean delRow = false, del1stRow = false;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (matrix[i][j] == 0) {
                    // 标记第一行是否清零
                    if (i == 0) del1stRow = true;
                    // 标记除第一行外的当前行是否清零
                    else delRow = true;
                    // 用第一行保存所需清零的列的下标
                    matrix[0][j] = 0;
                }
            }
            // 遍历完此行之后判断是否清零
            if (delRow && i != 0) {
                matrix[i] = new int[w];
                // 清零标记重置
                delRow = false;
            }
        }
        // 根据第一行保存的列下标清零
        for (int i = 1; i < h; i++)
            for (int j = 0; j < w; j++)
                if (matrix[0][j] == 0)
                    matrix[i][j] = 0;
        // 最后清零第一行
        if (del1stRow) matrix[0] = new int[w];
    }
}
```