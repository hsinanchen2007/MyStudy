### 解题思路
由于是从左上角到右下角，被访问过的元素不会再被访问，因此可以利用原数组上的空间
需要注意的地方就是边界判断的问题

### 代码

```java
class Solution {
    public int maxValue(int[][] grid) {
        for(int i = 0;i < grid.length;i++){
            for(int j = 0;j < grid[0].length;j++){
                // 边界判断
                if(i == 0 && j == 0)
                    continue;
                else if(i == 0 && j != 0)
                    grid[i][j] += grid[i][j-1];
                else if(i != 0 && j == 0)
                    grid[i][j] += grid[i-1][j];
                else
                    grid[i][j] = Math.max(grid[i-1][j],grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[grid.length-1][grid[0].length-1];
    }
}
```