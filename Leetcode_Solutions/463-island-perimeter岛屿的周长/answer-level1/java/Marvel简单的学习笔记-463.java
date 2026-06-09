### 解题思路
比较直白的解法，根据题目提到的条件，遍历所有格子，每找到一块陆地，岛屿周长加4，同时检查该陆地格子，它的四周（水平垂直方向）每有一块陆地，周长减1（减少一条边）。如此这般，直至得到整个岛屿的周长。

### 代码

```java
class Solution {
    public int islandPerimeter(int[][] grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.length; i++)
        {
            for(int j = 0; j < grid[0].length; j++)
            {
                if(grid[i][j] == 1)
                {
                    perimeter += 4;
                    if(i > 0 && grid[i-1][j] == 1)                  perimeter--;
                    if(i < grid.length-1 && grid[i+1][j] == 1)      perimeter--;
                    if(j > 0 && grid[i][j-1] == 1)                  perimeter--;
                    if(j < grid[0].length-1 && grid[i][j+1] == 1)   perimeter--;
                }
            }
        }
        return perimeter;
    }
}
```