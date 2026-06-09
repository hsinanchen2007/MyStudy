### 解题思路
变种的一个深度搜索的实现。这里和岛屿的那道题不一样，因为岛屿那里代表了行和列是代表了不同的岛屿。此题中的row和col是可能代表相同的人。比如[1,3]和[3,1]代表的都是1和3这两个人的关系。如果用岛屿的方式实现，会存在重复的计算。
这里转换成图的思想，N个节点，二维数组是节点之间的联通关系。之后就比较好实现了。就是算联通性。
联通性可以采用DFS来实现，或者并查集。

### 代码

```java
class Solution {
    public int findCircleNum(int[][] M) {
        if (null == M || M.length == 0) {
            return 0;
        }
        boolean[] marked = new boolean[M.length];
        int rowLen = M.length;
        int maxNum = 0;
        for (int i = 0; i < rowLen; i++) {
            if (marked[i]) {
                continue;
            }
            maxNum++;
            dfs(M,i,marked);
        }

        return maxNum;
    }

    private void dfs(int[][] grid, int row, boolean[] marked) {
       marked[row] = true;
       int len = grid.length;
       for (int j=0; j<len; ++j) {
           if (grid[row][j] == 1 && !marked[j]) {
               dfs(grid, j, marked);
           }
       }
    }
}
```