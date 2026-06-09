### 解题思路
![image.png](https://pic.leetcode-cn.com/0257d3b3b10948858c021533f600f5db0a68ba996292215794cd3f9e3a350f81-image.png)

### 代码

```java
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int result = 0;
        int[] rowMax = new int[grid.length];
        int[] colMax = new int[grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if(grid[i][j] > rowMax[i]){
                    rowMax[i] = grid[i][j];
                }
                if(grid[j][i] > colMax[i]){
                    colMax[i] = grid[j][i];
                }
            }
        }
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                result += Math.min(rowMax[i],colMax[j]) - grid[i][j];
            }
        }
        return result;
    }
}
```