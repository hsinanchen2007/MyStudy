### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    Integer[][] memo;
    public int minPathSum(int[][] grid) {

        memo = new Integer[grid.length][grid[0].length];
        return minPathSums(0,0,grid);
    }
    private int minPathSums(int l,int h,int[][] grid){
        if (memo[h][l] != null ) return memo[h][l];

        if (l == grid[0].length - 1 && h == grid.length-1) return memo[h][l] =  grid[h][l];
        if (l >= grid[0].length -1  && h < grid.length-1) return memo[h][l] = minPathSums(l,h + 1,grid) + grid[h][l];
        if (h >= grid.length-1 && l < grid[0].length - 1) return memo[h][l] = minPathSums(l + 1,h,grid) + grid[h][l];

        int right = minPathSums(l + 1,h,grid );
        int down = minPathSums(l,h+1,grid);
        return memo[h][l] = Math.min(right,down) + grid[h][l];
    }

}
```