### 解题思路
沉岛思想 + 非递归 + 栈 + 方向向量

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        // 沉岛思想，递归，参照题解来的，记录一下
        int ans = 0;
        // 遍历所有的土地
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                // 发现是陆地才去进行探索，否则不探索
                if(grid[i][j] == 1){
                    ans = Math.max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }

    private int dfs(int[][] grid, int i, int j){
        //判断下标是否越界以及是否满足是陆地的条件，也就是边界条件
        if(i < 0 || j < 0 || i >= grid.length || j >= grid[i].length || grid[i][j] == 0){
            return 0;
        }
        grid[i][j] = 0;
        // 定义一个方向向量
        int nums = 1;
        // 往四周探索
        int[][] vector = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int k = 0; k < vector.length; k++){
            nums += dfs(grid, vector[k][0] + i, vector[k][1] + j);
        }

        return nums;
    }
}
```