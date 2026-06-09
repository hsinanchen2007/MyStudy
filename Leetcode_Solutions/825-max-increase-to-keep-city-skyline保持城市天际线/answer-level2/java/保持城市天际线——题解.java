思路：此题应属简单题，重点在于理解题意的天际线是什么意思，按题意来讲，天际线其实就是某一行，或者某一列上的最大值。明白了天际线的概念之后，我们来看题目要求我们求什么，题目说，求建筑物高度可以增加的最大总和是多少，很显而易见了，题目要求就是把二维数组中所有比天际线小的，全部增大到天际线的高度，然后求和。注意：此题容易被坑到的地方在于天际线是同时和行、列都相关的，所以答案应把二维数组中所有值都增大到等于该行、该列两个天际线中的小者为止。所以倒过来想，答案应该等于所有二维数组中该行、该列天际线的小者减去原始该行、该列的值之和，所以解题代码如下：
```
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        if (grid == null || grid.length < 1 || grid[0] == null || grid[0].length < 1) {
            return 0;
        }
        
        int ans = 0;
        
        // 垂直天际线，行
        int maxR[] = new int[grid.length];
        for (int i = 0;i < grid.length;i++) {
            maxR[i] = maxRow(grid,i);
        }
        
        // 水平天际线，列
        int maxC[] = new int[grid[0].length];
        for (int i = 0;i < grid[0].length;i++) {
            maxC[i] = maxCol(grid,i);
        }
        
        for (int i = 0;i < grid.length;i++) {
            for (int j = 0;j < grid[i].length;j++) {
                ans += Math.min(maxR[i],maxC[j]) - grid[i][j];
            }
        }
        
        return ans;
    }
    
    // 获取某一行的最大值
    private int maxRow(int[][] grid,int row) {
        int max = 0;
        
        for (int i = 0;i < grid[row].length;i++) {
            if (max < grid[row][i]) {
                max = grid[row][i];
            }
        }
        
        return max;
    }
    
    // 获取某一列的最大值
    private int maxCol(int[][] grid,int col) {
        int max = 0;
        
        for (int i = 0;i < grid.length;i++) {
            if (max < grid[i][col]) {
                max = grid[i][col];
            }
        }
        
        return max;
    }
}
```