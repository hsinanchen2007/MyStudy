### 解题思路
根据题意可知，count记录机器人可以到达的方格数，从原点开始进行深度优先遍历，从上下左右四个方向进行搜索，当x与y坐标的位数和小于等于k时就使count加一，当该位数和大于k时可以判断该方向之后的坐标值的位数和一定会大于k，故可以停止遍历，为了防止重复遍历，将遍历过的位置的值置1。

### 代码

```java
class Solution {
    int[][] direction = {{0, 1},{0, -1},{1, 0},{-1, 0}};
    int count = 0;
    public int movingCount(int m, int n, int k) {
        int[][] grid = new int[m][n];
        dfs(grid, k, 0, 0, m, n);
        return count;
    }

    private void dfs(int[][] grid, int k, int i, int j, int m, int n) {
        grid[i][j] = 1;
        int sum = getSum(i) + getSum(j);
        if(sum <= k) count++;
        else return;
        for (int l = 0; l < 4; l++) {
            int x = direction[l][0] + i;
            int y = direction[l][1] + j;
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y] == 0) {
                dfs(grid, k, x, y, m, n);
            }
        }
    }

    public int getSum(int i) {
        int t = i, sum = 0;
        while(t != 0) {
            sum += t % 10;
            t = t / 10;
        }
        return sum;
    }
}
```