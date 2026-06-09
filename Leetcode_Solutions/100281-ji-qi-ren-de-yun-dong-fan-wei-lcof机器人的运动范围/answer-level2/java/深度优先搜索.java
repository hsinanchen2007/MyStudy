### 解题思路
建立一个二维数组grid，用于标记某个位置是否已经访问过，初始化为0，若访问过，则标记为1；
优化方向：机器人从（0，0）位置出发，可以只考虑两个方向，向右和向下，所以dfs的终止条件简化为三个。

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        int[][] grid = new int[m][n];
        return dfs(grid, 0, 0, k);
    }
    public int dfs(int[][] grid, int i, int j, int k){
        if(i >= grid.length || j >= grid[0].length || grid[i][j] == 1){
            return 0;
        }
        grid[i][j] = 1;
        int num = 0;
        if(i % 10 + i / 10 + j % 10 + j /10 <= k){
            num = 1;
            num += dfs(grid, i+1, j, k) + dfs(grid, i, j+1, k); 
        }
        return num;
    }
}
```