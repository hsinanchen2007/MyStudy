### 解题思路
重点：需要转换思维
任何一个节点（grid[i][j]）都会有上下左右四个方向的分支，四个方向上的任意节点都会衍生更多的分支，在纸上画一下就能看出其实是个树形结构。
树形结构遍历有两种，BFS，DFS。本题两种方式都可以，目的就是遍历整个树的节点而已，BFS呢一般用于最短路径搜索，还得借用队列，所以本题用DFS解答。

### 步骤
1. 建立主循环，用于遍历整个表格
2. 如果遇到陆地，那么res++；同时向四个方向搜索是否都为陆地（递归深度搜索）。
3. 为了避免出现四个方向扩展过程发生重复计算或死循环，所以将陆地周围的陆地都变成水（不光解决问题，而且对结果无影响，也是巧解本题的主要思路，否则得再用一个数组记录某个节点是否被访问过）
4. 主循环结束时，res就是所有遇到过的陆地数量。

### 代码

```java
class Solution {
    public int numIslands(char[][] grid) {
        int count = 0;
        for (int i = 0; i < grid.length; i++){
            for (int j = 0; j < grid[0].length; j++){
                if (grid[i][j] == '1'){
                    dfs (grid,i,j);
                    count ++;
                }
            }
        }
        return count;
    }
    public void dfs (char[][] grid, int i,int j){
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs (grid,i-1,j);
        dfs (grid,i+1,j);
        dfs (grid,i,j-1);
        dfs (grid,i,j+1);
    }
}
```