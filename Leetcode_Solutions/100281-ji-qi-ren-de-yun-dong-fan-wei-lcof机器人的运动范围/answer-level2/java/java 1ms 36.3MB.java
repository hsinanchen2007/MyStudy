### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        int[][] grid = new int[m][n];
        return dfs(0,0,grid,k);
    }

    public int dfs(int i, int j, int[][] grid,int c) {
        int counti = i / 100 + i % 100 / 10 + i % 10;
        int countj = j / 100 + j % 100 / 10 + j % 10;
        if(i < 0 || i >= grid.length || j < 0 || j >= grid[0].length 
            || grid[i][j] == 1 || counti + countj > c) {
                return 0;
            }
        int res = 1;
        grid[i][j] = 1;
        res += dfs(i+1,j,grid,c);
        res += dfs(i,j+1,grid,c);
        return res;
    }

}
```