思路：此题是立体几何数学中三视图的应用。存在以下规律：

1. 从顶部看，由该形状生成的阴影将是网格中非零值的数目。
2. 从侧面看，由该形状生成的阴影将是网格中每一行的最大值。
3. 从前面看，由该形状生成的阴影将是网格中每一列的最大值。
<br/><br/>
代码：
```
class Solution {
    public int projectionArea(int[][] grid) {
        int ans = 0;
        
        for (int i = 0;i < grid.length;i++) {
            ans += getRowMax(grid,i);
        }
        
        for (int i = 0;i < grid[0].length;i++) {
            ans += getColMax(grid,i);
        }
        
        for (int i = 0;i < grid.length;i++) {
            for (int j = 0;j < grid[i].length;j++) {
                if (grid[i][j] != 0) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
    
    private int getRowMax(int[][] grid,int row) {
        int max = Integer.MIN_VALUE;
        
        for (int i = 0;i < grid[row].length;i++) {
            if (max < grid[row][i]) {
                max = grid[row][i];
            }
        }
        
        return max;
    }
    
    private int getColMax(int[][] grid,int col) {
        int max = Integer.MIN_VALUE;
        
        for (int i = 0;i < grid.length;i++) {
            if (max < grid[i][col]) {
                max = grid[i][col];
            }
        }
        
        return max;
    }
}
```

![image.png](https://pic.leetcode-cn.com/501f95e2840667a7f36bdb0730f721ea60794daa774eddf1577419812f761fc8-image.png)