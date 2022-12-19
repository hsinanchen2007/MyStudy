给定一个包含`非负整数`的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能`向下或者向右`移动一步。

非负整数和只能向下向右是能使用dp的关键
# 自顶向下 TML
```java
int row,col;
public int minPathSum(int[][] grid) {
    row = grid.length;
    col = grid[0].length;
    return helper(grid, row-1, col-1);
}

private int helper(int[][] grid, int r, int c){
    if (r==0 && c==0){
        return grid[r][c];
    }
    int up = Integer.MAX_VALUE, left = Integer.MAX_VALUE;
    if (r!=0)
        up = helper(grid, r-1, c);
    if (c!=0)
        left = helper(grid, r, c-1);
    return Math.min(up, left)+grid[r][c];
}
```

# 自顶向下，记忆化搜索 AC
```java
int row,col;
Integer[][] memo;
public int minPathSum(int[][] grid) {
    row = grid.length;
    col = grid[0].length;
    memo = new Integer[row][col];
    return helper(grid, row-1, col-1);
}

private int helper(int[][] grid, int r, int c){
    if (memo[r][c]!=null)
        return memo[r][c];
    if (r==0 && c==0){
        return memo[r][c] = grid[r][c];
    }
    int up = Integer.MAX_VALUE, left = Integer.MAX_VALUE;
    if (r!=0)
        up = helper(grid, r-1, c);
    if (c!=0)
        left = helper(grid, r, c-1);
    return memo[r][c] = Math.min(up, left)+grid[r][c];
}
```

# 自底向上 DP AC
```java
public int minPathSum(int[][] grid) {
    int row = grid.length;
    int col = grid[0].length;
    int[][] ans = new int[row][col];
    ans[0][0]=grid[0][0];
    for (int i = 1;i<col;i++)   ans[0][i] = ans[0][i-1]+grid[0][i];
    for (int i = 1;i<row;i++)   ans[i][0] = ans[i-1][0]+grid[i][0];
    for (int i = 1;i<row;i++){
        for(int j = 1;j<col;j++){
            ans[i][j] = Math.min(ans[i-1][j], ans[i][j-1])+grid[i][j];
        }
    }
    return ans[row-1][col-1];
}
```


