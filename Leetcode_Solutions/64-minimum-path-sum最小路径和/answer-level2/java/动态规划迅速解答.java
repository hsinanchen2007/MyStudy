### 解题思路
利用动态规划可以迅速解决这种路劲最小问题。即本原问题划分为子问题。

观察不难发现，除了第一行或第一列的步数是固定的（即步数为等于上或左值加上它自身），其它行和列的值和它
位置的上或左值相关。这样我们就很容易解决该问题了。只需让走到当前位置保持路径最短即可。

那么可以让当前位置的值加上它位置上或左的最小一个值，则是它当前的最小值。

公式： grid[i][j] += grid[i-1][j] < grid[i][j-1] ? grid[i-1][j]: grid[i][j-1];

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        
        for(int i=1; i<grid[0].length; i++){
            grid[0][i] += grid[0][i-1];
        }
        for(int j=1; j<grid.length; j++){
            grid[j][0] += grid[j-1][0];
        }

        for(int j=1; j<grid[0].length; j++){
            for(int i=1; i<grid.length; i++){
                grid[i][j] += ((grid[i-1][j] < grid[i][j-1]) ? grid[i-1][j]: grid[i][j-1]);
            }
        }
        return grid[grid.length-1][grid[0].length-1];
    }
}
```