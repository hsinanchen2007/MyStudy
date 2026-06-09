### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        // 按深度搜索
        int max = 0;
        // 图的高度
        int height = grid.length;
        if(height == 0){
            return 0;
        }
        // 图的宽度
        int width = grid[0].length;
        if(width == 0){
            return 0;
        }
        // 图里可以走动的方向
        int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        // 按深度搜索
        int len = 0;
        Stack<int[]> stack = new Stack<>();
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(grid[i][j] == 1){
                    stack.push(new int[]{i, j});
                    grid[i][j] = 0;
                    while(!stack.isEmpty()){
                        int[] point = stack.pop();
                        len++;
                        for(int[] direction : directions){
                            int x = point[0] + direction[0];
                            int y = point[1] + direction[1];
                            if(x >= 0 && x < height && y >= 0 && y < width && grid[x][y] == 1){
                                stack.push(new int[]{x, y});
                                // 标记走过了
                                grid[x][y] = 0;
                            }
                        }
                    }    
                }
                max = len > max ? len : max;
                len = 0;
            }
        }
        return max;


    }
}
```